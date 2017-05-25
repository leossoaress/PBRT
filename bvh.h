#ifndef PROJECT_BVH_H
#define PROJECT_BVH_H

#include <sstream>
#include <iostream>
#include <iomanip>
#include <deque>
#include <queue>
#include <algorithm>

#include "primitive.h"
#include "bbox.h"

class BVH
{
public:

    struct BVHNode
    {
        ~BVHNode( void )
        {
            if ( left_ )
            {
                delete left_;
                left_ = nullptr;
            }

            if ( right_ )
            {
                delete right_;
                right_ = nullptr;
            }
        }

        std::size_t first_;                       // index of the first primitive
        std::size_t last_;                        // number of primitives into this node (whose index start at "first_").
        BBox aabb_;                               // AABB represeted by the current node.
        BVHNode *left_ = nullptr;                 // Pointer to the left child node (if the current node is a inner node).
        BVHNode *right_ = nullptr;                // Pointer to right inner node (if the current node is a inner node).
    };

    struct PrimitiveAABBArea
    {
        std::size_t primitive_id_;
        glm::dvec3 centroid_;
        BBox aabb_;
        double left_area_;
        double right_area_;

        BBox left_aabb_;
        BBox right_aabb_;

    };

    BVH( const std::vector< Primitive::PrimitiveUniquePtr > &primitives );

    ~BVH( void );

    bool intersect( const Ray &ray, IntersectionRecord &intersection_record) const;

    void dump( void ) const;

private:

    struct Comparator
    {
        static bool sortInX( const PrimitiveAABBArea &lhs, const PrimitiveAABBArea &rhs )
        {
            return lhs.centroid_.x < rhs.centroid_.x;
        }

        static bool sortInY( const PrimitiveAABBArea &lhs, const PrimitiveAABBArea &rhs )
        {
            return lhs.centroid_.y < rhs.centroid_.y;
        }

        static bool sortInZ( const PrimitiveAABBArea &lhs, const PrimitiveAABBArea &rhs )
        {
            return lhs.centroid_.z < rhs.centroid_.z;
        }
    };

    double SAH( std::size_t s1_size,
                double s1_area,
                std::size_t s2_size,
                double s2_area,
                double s_area  );

    void splitNode( BVHNode **node,
                    std::deque< PrimitiveAABBArea > &s,
                    std::size_t first,
                    std::size_t last,
                    double s_area );

    bool traverse( const BVHNode *node,
                   const Ray &ray,
                   IntersectionRecord &intersection_record ) const;

    BVHNode *root_node_ = nullptr;

    double cost_intersec_tri_ = 0.8;

    double cost_intersec_aabb_ = 0.2;

    std::deque< long unsigned int > primitive_id_;

    const std::vector< Primitive::PrimitiveUniquePtr > &primitives_;

    std::size_t primitives_inserted_ = 0;
};


#endif //PROJECT_BVH_H
