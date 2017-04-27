#ifndef INTERSECTION_RECORD_H_
#define INTERSECTION_RECORD_H_

#include <glm/glm.hpp>
#include "material.h"

struct IntersectionRecord
{
    float t_;
    Material* material_;
    glm::vec3 position_;
    glm::vec3 normal_;
};

#endif /* INTERSECTION_RECORD_H_ */