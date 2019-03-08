#ifndef PROJECT_SMOOTH_DIELECTRIC_H
#define PROJECT_SMOOTH_DIELECTRIC_H

#include <glm/glm.hpp>
#include "material.h"
#include "ray.h"
#include "intersection_record.h"
#include <sstream>

class SmoothDielectric: public Material
{
public:

    SmoothDielectric();

    glm::vec3 get_BRDF () const;
    glm::vec3 get_emitancia () const;

    int get_tipo() const;
    float get_n() const;
};

#endif //PROJECT_SMOOTH_DIELECTRIC_H
