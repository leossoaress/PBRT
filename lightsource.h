#ifndef LIGHTSOURCE_H_
#define LIGHTSOURCE_H_

#include <glm/glm.hpp>
#include "material.h"

class Lightsource : public Material
{
public:

    //Lightsource ( void );

    Lightsource( const glm::vec3 emitancia);

    glm::vec3 get_BRDF () const;
    glm::vec3 get_emitancia () const;

};

#endif