#include "lightsource.h"
#define PI 3.14159265358979323846f

//Lightsource::Lightsource( void )
//{}

Lightsource::Lightsource(glm::vec3 emitancia)
{
    emitancia_ = emitancia;

    BRDF_ = {0.0f, 0.0f, 0.0f};
}

glm::vec3 Lightsource::get_BRDF() const
{
    return BRDF_;
}

glm::vec3 Lightsource::get_emitancia() const
{
    return emitancia_;
}