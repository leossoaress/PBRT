#include "material.h"

Material::Material( void )
{}

Material::Material(glm::vec3 emitancia, glm::vec3 BRDF):
        emitancia_(emitancia),
        BRDF_(BRDF)
{}

Material::~Material( void )
{}