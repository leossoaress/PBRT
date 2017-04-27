#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <glm/glm.hpp>
#include "primitive.h"
#include "intersection_record.h"
#include "ray.h"

class Triangle : public Primitive
{
public:

    Triangle( void );

    Triangle( const glm::vec3 &aa, const glm::vec3 &bb, const glm::vec3 &cc, Material* material);


    //glm::vec3 corin = glm::vec3(rand()%256/255.0f, rand()%256/255.0f, rand()%256/255.0f;

    bool intersect( const Ray &ray,
                    IntersectionRecord &intersection_record ) const;

    glm::vec3 aa_ = { 0.0f, 0.0f, 0.0f };
    glm::vec3 bb_ = { 0.0f, 0.0f, 0.0f };
    glm::vec3 cc_ = { 0.0f, 0.0f, 0.0f };
    glm::vec3 em = { 0.0f, 0.0f, 0.0f };


private:

    static const float kIntersectionTestEpsilon_;
};

#endif /* TRIANGLE_H_ */