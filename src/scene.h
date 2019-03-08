#ifndef SCENE_H_
#define SCENE_H_

#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <glm/glm.hpp>

#include "primitive.h"
#include "sphere.h"
#include "triangle.h"
#include "material.h"
#include "lightsource.h"
#include "diffuse.h"
#include "mirror.h"
#include "smooth_dielectric.h"
#include "bvh.h"
#include "cook_torrance.h"

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <assimp/vector3.h>

class Scene
{
public:

    enum AccelerationStructure
    {
        NONE,
        BVH_SAH
    };

    Scene( void );

    ~Scene( void );

    //bool intersect( const Ray &ray, IntersectionRecord &intersection_record ) const;

    void buildAccelerationStructure( void );

    bool intersect( const Ray &ray, IntersectionRecord &intersection_record) const;

    void load( void );

    void loadObj(const char* objFile);

    void loadObj(const char* obj, glm::vec3 cor,glm::vec3 position, float size, int type);

    std::vector< Primitive::PrimitiveUniquePtr > primitives_;

    AccelerationStructure acceleration_structure_ = AccelerationStructure::NONE;

private:

    void buildBVH( void );

    const aiScene *assimp_scene_ = nullptr;

    const BVH *bvh_ = nullptr;
};

#endif /* SCENE_H_ */