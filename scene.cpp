#include "scene.h"
#include <iostream>


Scene::Scene( void )
{}

Scene::~Scene( void )
{}

bool Scene::intersect( const Ray &ray,
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
}

void Scene::load( void )
{

    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere(glm::vec3{ -0.35f, -0.5f, 0.00f }, 0.1f,  new Lightsource( glm::vec3{ 30, 30, 30 }) ) ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere(glm::vec3{ 0.3f, 1.1f, 0.5f }, 0.2f, new SmoothDielectric() ) ) );

//Luz
    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere( glm::vec3{  0.0f, 1.0f, -1.0f }, 0.5f, new Lightsource(glm::vec3{80.0f, 80.0f, 80.0f} ) ) ) );

//fundo
    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle( glm::vec3{-3.0f ,3.0f , -4.0f}, glm::vec3{3.0f,3.0f,-4.0f}, glm::vec3{3.0f, -3.0f,-4.0f}, new Diffuse(glm::vec3{0.9f, 0.89f , 0.24f} ) ) ) );

    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle( glm::vec3{-3.0f ,3.0f , -4.0f}, glm::vec3{-3.0f,-3.0f,-4.0f}, glm::vec3{3.0f, -3.0f,-4.0f}, new Diffuse (glm::vec3{0.9f, 0.89f , 0.24f} ) ) ) );

//parede direita
    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle( glm::vec3{3.0f ,3.0f , 5.0f}, glm::vec3{3.0f,3.0f,-4.0f}, glm::vec3{3.0f, -3.0f,-4.0f}, new Diffuse (glm::vec3{1.0f, 0.0f , 0.0f} ) ) ) );

    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle( glm::vec3{3.0f ,3.0f , 5.0f}, glm::vec3{3.0f,-3.0f,5.0f}, glm::vec3{3.0f, -3.0f,-4.0f}, new Diffuse (glm::vec3{1.0f, 0.0f , 0.0f} ) ) ) );

//parede esquerda
    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle( glm::vec3{-1.0f ,1.0f , -2.0f}, glm::vec3{-3.0f,3.0f,-1.0f}, glm::vec3{-1.0f, -1.0f,-2.0f}, new Mirror() ) ) );

    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle( glm::vec3{-1.0f ,1.0f , -2.0f}, glm::vec3{-3.0f,-3.0f,-2.0f}, glm::vec3{-1.0f, -1.0f,-2.0f}, new Mirror() ) ) );

//teto
    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle( glm::vec3{-3.0f ,3.0f , -4.0f}, glm::vec3{-3.0f,3.0f,4.0f}, glm::vec3{3.0f, 3.0f,4.0f}, new Diffuse(glm::vec3{0.9f, 0.89f , 0.24f} ) ) ) );

    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle( glm::vec3{-3.0f ,3.0f , -4.0f}, glm::vec3{3.0f,3.0f,4.0f}, glm::vec3{3.0f, 3.0f,-4.0f}, new Diffuse(glm::vec3{0.9f, 0.89f , 0.24f} ) ) ) );

//chao
    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle( glm::vec3{-3.0f ,-3.0f , -4.0f}, glm::vec3{3.0f,-3.0f,-4.0f}, glm::vec3{-3.0f, -3.0f,4.0f}, new Diffuse(glm::vec3{0.9f, 0.89f , 0.24f} ) ) ) );

    //primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle( glm::vec3{3.0f ,-3.0f , -4.0f}, glm::vec3{3.0f,-3.0f,4.0f}, glm::vec3{-3.0f, -3.0f,4.0f}, new Diffuse(glm::vec3{0.9f, 0.89f , 0.24f} ) ) ) );


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