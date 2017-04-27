#ifndef DIFFUSE_H_
#define DIFFUSE_H_

#include <glm/glm.hpp>
#include "material.h"
#include <sstream>

class Diffuse : public Material
{
public:

    //Diffuse ( void );

    Diffuse( const glm::vec3 cor);

    glm::vec3 get_BRDF () const;
    glm::vec3 get_emitancia () const;

};

#endif