#ifndef PROJECT_BBOX_H
#define PROJECT_BBOX_H

#include <glm/glm.hpp>
#include "ray.h"
#include "intersection_record.h"

//#include "primitive.h"

class BBox
{
public:

    BBox( void )
    {};

    BBox( const glm::dvec3 &min,
          const glm::dvec3 &max ) :
            min_{ min },
            max_{ max },
            centroid_{ 0.5 * ( min_ + max_ ) }
    {};

    ~BBox( void ){};

    double getArea( void ) const;

    bool intersect( const Ray &ray ) const;

    BBox operator + ( const BBox &rhs ) const
    {
        return BBox{ glm::min( min_, rhs.min_ ),
                     glm::max( max_, rhs.max_ ) };
    }

    glm::dvec3 min_;

    glm::dvec3 max_;

    glm::dvec3 centroid_;

};

#endif //PROJECT_BBOX_H
