#include "perspective_camera.h"

PerspectiveCamera::PerspectiveCamera( void )
{}

PerspectiveCamera::PerspectiveCamera( const float min_x,
                                      const float max_x,
                                      const float min_y,
                                      const float max_y,
                                      const glm::ivec2 &resolution,
                                      const glm::vec3 &position,
                                      const glm::vec3 &up_vector,
                                      const glm::vec3 &look_at ) :
        Camera::Camera(resolution, position, up_vector, look_at),
        min_x_{ min_x },
        max_x_{ max_x },
        min_y_{ min_y },
        max_y_{ max_y }
{}

Ray PerspectiveCamera::getWorldSpaceRay( const glm::vec2 &pixel_coord ) const
{

    float width = max_x_ - min_x_;
    float height = max_y_ - min_y_;


    float distancia = -2.0f;

    float u = (pixel_coord[0]) / static_cast<float>( resolution_[0] ) * width + min_x_ ;
    float v = (pixel_coord[1]) / static_cast<float>( resolution_[1] ) * -height + max_y_;

    glm::vec3 s (u,v,distancia);

    return Ray{ position_, glm::normalize( onb_.getBasisMatrix() * s) };
}