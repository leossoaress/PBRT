#ifndef PROJECT_MIRROR_H
#define PROJECT_MIRROR_H


#include <glm/glm.hpp>
#include "material.h"
#include "ray.h"
#include "intersection_record.h"
#include <sstream>

class Mirror : public Material
{
public:

    Mirror();

    glm::vec3 get_BRDF () const;
    glm::vec3 get_emitancia () const;

    int get_tipo() const;

};
#endif //PROJECT_MIRROR_H
