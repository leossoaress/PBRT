#include "diffuse.h"
#define PI 3.14159265358979323846f

//Diffuse::Diffuse( void )
//{}

Diffuse::Diffuse(glm::vec3 cor)
{
    emitancia_ = {0.0f, 0.0f, 0.0f};
    BRDF_ = cor/PI;
}

glm::vec3 Diffuse::get_BRDF() const
{
    return BRDF_;
}

glm::vec3 Diffuse::get_emitancia() const
{
    return emitancia_;
}

int Diffuse::get_tipo() const
{
    return 0;
}

float Diffuse::get_n() const
{
    return 1.0;
}