#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include <sstream>
#include <iomanip>
#include <cmath>

#include "camera.h"
#include "scene.h"
#include "buffer.h"

class RayTracer
{
public:

    RayTracer( Camera &camera,
               const Scene &scene,
               const glm::vec3 background_color,
               Buffer &buffer );

    void integrate( void );

    void progress ( void );

    double p=0;

    glm::vec3 L(Ray &ray, size_t curr_depth);

    Ray get_new_ray(IntersectionRecord &intersection_record);

    void integrate2(size_t inicio1, size_t final1);

    float number_rays = 100;
    int numero_threads=4;


private:



    const Camera &camera_;

    const Scene &scene_;

    glm::dvec3 background_color_;

    Buffer &buffer_;



};

#endif /* RAYTRACER_H_ */