#ifndef PROJECT_COOK_TORRANCE_H
#define PROJECT_COOK_TORRANCE_H

#include <glm/glm.hpp>
#include "material.h"
#include "intersection_record.h"
#include <sstream>

class CookTorrance : public Material
{
public:

    CookTorrance( const glm::vec3 cor);

    glm::vec3 get_BRDF () const;
    glm::vec3 get_emitancia () const;

    int get_tipo() const;
    float get_n() const;

};

#endif


