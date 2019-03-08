//
// Created by leo on 02/05/17.
//

#include "mirror.h"
#define PI 3.14159265358979323846f


Mirror::Mirror()
{
    emitancia_ = {0.0f, 0.0f, 0.0f};
    BRDF_ = {0.0f, 0.0f, 0.0f};
}

glm::vec3 Mirror::get_BRDF() const
{
    return BRDF_;
}

glm::vec3 Mirror::get_emitancia() const
{
    return emitancia_;
}

int Mirror::get_tipo() const
{
    return 2;
}

float Mirror::get_n() const
{
    return 1.0;
}
