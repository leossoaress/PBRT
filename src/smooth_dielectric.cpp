//
// Created by leo on 03/05/17.
//

#include "smooth_dielectric.h"
#define PI 3.14159265358979323846f


SmoothDielectric::SmoothDielectric()
{
    emitancia_ = {0.0f, 0.0f, 0.0f};
    BRDF_ = {0.0f, 0.0f, 0.0f};
}

glm::vec3 SmoothDielectric::get_BRDF() const
{
    return BRDF_;
}

glm::vec3 SmoothDielectric::get_emitancia() const
{
    return emitancia_;
}

int SmoothDielectric::get_tipo() const
{
    return 3;
}

float SmoothDielectric::get_n() const
{
    return 1.1;
}