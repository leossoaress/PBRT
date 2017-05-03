#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <glm/glm.hpp>
#include "ray.h"

class Material
{
public:


    Material ( void );

    Material (glm::vec3 emitancia, glm::vec3 BRDF);

    virtual ~Material( void );

    virtual glm::vec3 get_BRDF() const = 0;
    virtual glm::vec3 get_emitancia() const = 0;

    virtual int get_tipo() const = 0;

    glm::vec3 emitancia_;
    glm::vec3 BRDF_;

};

#endif;