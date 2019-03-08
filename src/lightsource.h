#ifndef LIGHTSOURCE_H_
#define LIGHTSOURCE_H_

#include <glm/glm.hpp>
#include "material.h"
#include "intersection_record.h"

class Lightsource : public Material
{
public:

    //Lightsource ( void );

    Lightsource( const glm::vec3 emitancia);

    glm::vec3 get_BRDF () const;
    glm::vec3 get_emitancia () const;

    int get_tipo() const;
    float get_n() const;
};

#endif