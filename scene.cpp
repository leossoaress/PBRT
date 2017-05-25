#include "scene.h"
#include <iostream>


Scene::Scene( void )
{}

Scene::~Scene( void )
{
    if ( bvh_ )
    {
        delete bvh_;
        bvh_ = nullptr;
    }
}

/*bool Scene::intersect( const Ray &ray,
                       IntersectionRecord &intersection_record ) const
{
    bool intersection_result = false;
    IntersectionRecord tmp_intersection_record;
    std::size_t num_primitives = primitives_.size();

    // Loops over the list of primitives, testing the intersection of each primitive against the given ray
    for ( std::size_t primitive_id = 0; primitive_id < num_primitives; primitive_id++ )
        if ( primitives_[primitive_id]->intersect( ray, tmp_intersection_record ) )
            if ( ( tmp_intersection_record.t_ < intersection_record.t_ ) && ( tmp_intersection_record.t_ > 0.0 ) )
            {
                intersection_record = tmp_intersection_record;
                intersection_result = true; // the ray intersects a primitive!
            }

    return intersection_result;
}*/

bool Scene::intersect( const Ray &ray, IntersectionRecord &intersection_record) const
{
    bool intersection_result = false;
    IntersectionRecord tmp_intersection_record;
    std::size_t num_primitives = primitives_.size();

    switch( acceleration_structure_ )
    {
        case AccelerationStructure::NONE:
            for ( std::size_t primitive_id = 0; primitive_id < num_primitives; primitive_id++ )
            {

                if ( primitives_[primitive_id]->intersect( ray, tmp_intersection_record ) )
                {


                    if ( ( tmp_intersection_record.t_ < intersection_record.t_ ) && ( tmp_intersection_record.t_ > 0.0 ) )
                    {
                        intersection_record = tmp_intersection_record;
                        intersection_result = true;
                    }
                }
            }
            break;

        case AccelerationStructure::BVH_SAH:
            intersection_result = bvh_->intersect( ray, intersection_record);
            break;
    }

    return intersection_result;
}

void Scene::load( void )
{

    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere(glm::vec3{ -0.5f, 0.5f, 0.5f }, 0.3f,  new Mirror() ) ) );
    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere(glm::vec3{ 0.5f, 0.5f, 0.5f }, 0.3f, new SmoothDielectric() ) ) );

}

void Scene::buildAccelerationStructure( void )
{
    if ( acceleration_structure_ == Scene::AccelerationStructure::BVH_SAH )
    {
        buildBVH();
        std::clog << std::endl;
    }
}

void Scene::buildBVH( void )
{
    bvh_ = new BVH( primitives_ );
}

void Scene::loadObj(const char* obj)
{


    Assimp::Importer importer;


    //const aiScene* scene = importer.ReadFile(obj,aiProcess_Triangulate);

    const aiScene* scene = importer.ReadFile( obj,
                                              aiProcess_CalcTangentSpace       |
                                              aiProcess_Triangulate            |
                                              aiProcess_JoinIdenticalVertices  |
                                              aiProcess_SortByPType);


    if( !scene)
    {
        std::cout << "errouuuuu" << std::endl;
    }

    for (unsigned int i = 0; i < scene->mNumMeshes; i++)
    {
        aiColor3D diffuseColor = {0,0,0};
        aiColor3D emissiveColor = {0,0,0};
        aiColor3D reflectiveColor = {0,0,0};


        if (scene->mMaterials) {
            // Setting up the diffuse and emissive color used by the mesh
            scene->mMaterials[scene->mMeshes[i]->mMaterialIndex]->Get(AI_MATKEY_COLOR_EMISSIVE, emissiveColor);
            scene->mMaterials[scene->mMeshes[i]->mMaterialIndex]->Get(AI_MATKEY_COLOR_DIFFUSE, diffuseColor);
            scene->mMaterials[scene->mMeshes[i]->mMaterialIndex]->Get(AI_MATKEY_COLOR_REFLECTIVE, reflectiveColor);
        }



        for (unsigned int j = 0; j < scene->mMeshes[i]->mNumFaces; j++)
        {
            unsigned int i1, i2, i3;
            float xi1, xi2, xi3, yi1, yi2, yi3, zi1, zi2, zi3;

            i1 = scene->mMeshes[i]->mFaces[j].mIndices[0];
            i2 = scene->mMeshes[i]->mFaces[j].mIndices[1];
            i3 = scene->mMeshes[i]->mFaces[j].mIndices[2];

            // Coordenadas do primeiro vertice do triangulo
            xi1 = (float)scene->mMeshes[i]->mVertices[i1].x;
            yi1 = (float)scene->mMeshes[i]->mVertices[i1].y;
            zi1 = (float)scene->mMeshes[i]->mVertices[i1].z;
            glm::vec3 vertice1{ xi1,yi1,zi1 };

            // Coordenadas do segundo vertice do triangulo
            xi2 = (float)scene->mMeshes[i]->mVertices[i2].x;
            yi2 = (float)scene->mMeshes[i]->mVertices[i2].y;
            zi2 = (float)scene->mMeshes[i]->mVertices[i2].z;
            glm::vec3 vertice2{ xi2,yi2,zi2 };

            // Coordenadas do terceiro vertice do triangulo
            xi3 = (float)scene->mMeshes[i]->mVertices[i3].x;
            yi3 = (float)scene->mMeshes[i]->mVertices[i3].y;
            zi3 = (float)scene->mMeshes[i]->mVertices[i3].z;
            glm::vec3 vertice3{ xi3,yi3,zi3 };

            if(emissiveColor.r == 0 &&  emissiveColor.g == 0 && emissiveColor.b == 0 && diffuseColor.r == 0 && diffuseColor.g == 0 && diffuseColor.b==0 )
            {
                primitives_.push_back(Primitive::PrimitiveUniquePtr(new Triangle(  vertice1, vertice2,  vertice3, new Mirror ()  ) ) );
            }
            else if( emissiveColor.r == 0 &&  emissiveColor.g == 0 && emissiveColor.b == 0)
            {
                //std::printf("Difuso\n");
                glm::vec3 a = {diffuseColor.r, diffuseColor.g, diffuseColor.b};
                primitives_.push_back(Primitive::PrimitiveUniquePtr(new Triangle(  vertice1, vertice2,  vertice3, new Diffuse (a)  ) ) );
            }
            else
            {
                //std::printf("Emissor\n");
                glm::vec3 a = {emissiveColor.r, emissiveColor.g, emissiveColor.b};
                primitives_.push_back(Primitive::PrimitiveUniquePtr(new Triangle(  vertice1, vertice2,  vertice3, new Lightsource (a)  ) ) );
            }

        }
    }
}

void Scene::loadObj(const char* obj, glm::vec3 cor)
{


    Assimp::Importer importer;


    //const aiScene* scene = importer.ReadFile(obj,aiProcess_Triangulate);

    const aiScene* scene = importer.ReadFile( obj,
                                              aiProcess_CalcTangentSpace       |
                                              aiProcess_Triangulate            |
                                              aiProcess_JoinIdenticalVertices  |
                                              aiProcess_SortByPType);


    if( !scene)
    {
        std::cout << "errouuuuu" << std::endl;
    }

    for (unsigned int i = 0; i < scene->mNumMeshes; i++)
    {
        aiColor3D diffuseColor = {0,0,0};
        aiColor3D emissiveColor = {0,0,0};
        aiColor3D reflectiveColor = {0,0,0};


        if (scene->mMaterials) {
            // Setting up the diffuse and emissive color used by the mesh
            scene->mMaterials[scene->mMeshes[i]->mMaterialIndex]->Get(AI_MATKEY_COLOR_EMISSIVE, emissiveColor);
            scene->mMaterials[scene->mMeshes[i]->mMaterialIndex]->Get(AI_MATKEY_COLOR_DIFFUSE, diffuseColor);
            scene->mMaterials[scene->mMeshes[i]->mMaterialIndex]->Get(AI_MATKEY_COLOR_REFLECTIVE, reflectiveColor);
        }



        for (unsigned int j = 0; j < scene->mMeshes[i]->mNumFaces; j++)
        {
            unsigned int i1, i2, i3;
            float xi1, xi2, xi3, yi1, yi2, yi3, zi1, zi2, zi3;

            i1 = scene->mMeshes[i]->mFaces[j].mIndices[0];
            i2 = scene->mMeshes[i]->mFaces[j].mIndices[1];
            i3 = scene->mMeshes[i]->mFaces[j].mIndices[2];

            // Coordenadas do primeiro vertice do triangulo
            xi1 = (float)scene->mMeshes[i]->mVertices[i1].x;
            yi1 = (float)scene->mMeshes[i]->mVertices[i1].y;
            zi1 = (float)scene->mMeshes[i]->mVertices[i1].z;
            glm::vec3 vertice1{ xi1,yi1,zi1 };

            // Coordenadas do segundo vertice do triangulo
            xi2 = (float)scene->mMeshes[i]->mVertices[i2].x;
            yi2 = (float)scene->mMeshes[i]->mVertices[i2].y;
            zi2 = (float)scene->mMeshes[i]->mVertices[i2].z;
            glm::vec3 vertice2{ xi2,yi2,zi2 };

            // Coordenadas do terceiro vertice do triangulo
            xi3 = (float)scene->mMeshes[i]->mVertices[i3].x;
            yi3 = (float)scene->mMeshes[i]->mVertices[i3].y;
            zi3 = (float)scene->mMeshes[i]->mVertices[i3].z;
            glm::vec3 vertice3{ xi3,yi3,zi3 };

            glm::vec3 a = cor;
            primitives_.push_back(Primitive::PrimitiveUniquePtr(new Triangle(  vertice1, vertice2,  vertice3, new Diffuse (a)  ) ) );


        }
    }
}
