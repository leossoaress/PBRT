#include "main.h"
#include <sys/time.h>
#include <stdio.h>

int main()
{
    struct timeval start, end;
    long seconds, minutes_final=0, seconds_final=0, hours_final=0;
    gettimeofday(&start, NULL);

    unsigned int x_resolution = 512;
    unsigned int y_resolution = 512;

    PerspectiveCamera camera{ -1.25f,
                              1.25f,
                              -1.25f,
                              1.25f,
                              glm::ivec2 { x_resolution, y_resolution },
                                  glm::vec3{ 0.0f, 0.5f,  1.0f },     // position
                                  glm::vec3{ 0.0f, 10.0f,  0.0f },     // up
                                  glm::vec3{ 0.0f, 0.5f, -1.0f } };   // look at
    Scene scene{};

    //char obj[25] = "buddha.obj";
    char obj1[25] = "CornellBox-Original.obj";
    scene.load();
    //scene.loadObj(obj,glm::vec3 {1.0f,0.86f,0.57f}, glm::vec3 {0.0f,0.0f,0.0f},0.1f,4);
    scene.loadObj(obj1);
    scene.acceleration_structure_ = scene.BVH_SAH;
    scene.buildAccelerationStructure();

    Buffer rendering_buffer{ x_resolution, y_resolution };
    glm::vec3 background_color{ 0.0f, 0.0f, 0.0f };

    // Set up the renderer.
    RayTracer rt( camera,
                  scene,
                  background_color,
                  rendering_buffer );

    rt.integrate(); // Renders the final image.

    // Save the rendered image to a .ppm file.
    rendering_buffer.save( "output_image.ppm" );

    gettimeofday(&end, NULL);
    seconds  = end.tv_sec  - start.tv_sec;

    if(seconds >= 60)
    {
        minutes_final = seconds/60;
        seconds_final = seconds - minutes_final*60;
    }
    else
    {
        seconds_final = seconds;
    }

    if(minutes_final >= 60)
    {
        hours_final = minutes_final/60;
        minutes_final = minutes_final - hours_final*60;
    }

    std::printf("Tempo gasto: %ld horas %ld minutos %ld segundos \n", hours_final, minutes_final, seconds_final);
    return EXIT_SUCCESS;
}