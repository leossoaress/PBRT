#include "cook_torrance.h"
#define PI 3.14159265358979323846f


CookTorrance::CookTorrance(const glm::vec3 cor)
{
    emitancia_ = {0.0f, 0.0f, 0.0f};
    BRDF_ = cor/PI;
}

glm::vec3 CookTorrance::get_BRDF() const
{
    return BRDF_;
}

glm::vec3 CookTorrance::get_emitancia() const
{
    return emitancia_;
}

int CookTorrance::get_tipo() const
{
    return 4;
}

float CookTorrance::get_n() const
{
    return 1.0;
}