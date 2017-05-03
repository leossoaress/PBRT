#ifndef DIFFUSE_H_
#define DIFFUSE_H_

#include <glm/glm.hpp>
#include "material.h"
#include "intersection_record.h"
#include <sstream>

class Diffuse : public Material
{
public:

    Diffuse( const glm::vec3 cor);

    glm::vec3 get_BRDF () const;
    glm::vec3 get_emitancia () const;

    int get_tipo() const;
    float get_n() const;

};

#endif