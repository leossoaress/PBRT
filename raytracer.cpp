#include "raytracer.h"
#include "thread"

# define PI 3.14159265358979323846f


RayTracer::RayTracer( Camera &camera,
                      const Scene &scene,
                      const glm::vec3 background_color,
                      Buffer &buffer ) :
        camera_( camera ),
        scene_( scene ),
        background_color_{ background_color },
        buffer_( buffer )
{}

glm::vec3 RayTracer::L( Ray &ray, size_t curr_depth)
{
    IntersectionRecord intersection_record;

    glm::vec3 Lo = {0.0f, 0.0f, 0.0f};

    float pdf = 1.0f/(2.0f * PI);

    Ray refl_ray;

    if ( curr_depth < 5 )
    {
        intersection_record.t_ = std::numeric_limits< double >::max();

        if ( scene_.intersect( ray, intersection_record ) )
        {

            if(intersection_record.material_->get_tipo() == 1 || intersection_record.material_->get_tipo() == 0)
            {
                refl_ray = get_new_ray(intersection_record);

                Lo = intersection_record.material_->get_emitancia() + 2.0f * PI *
                     intersection_record.material_->get_BRDF() *
                     L(refl_ray, ++curr_depth) *
                     glm::dot(intersection_record.normal_, refl_ray.direction_);
            }
            else
            {
                ONB onb_;

                onb_.setFromV(intersection_record.normal_);

                glm::vec3 d =  glm::vec3 {ray.direction_.x, -ray.direction_.y, ray.direction_.z};

                refl_ray.origin_ = intersection_record.position_ + (intersection_record.normal_*0.001f);

                refl_ray.direction_ =  d;

                Lo = L(refl_ray, ++curr_depth);
            }
        }
    }

    return Lo;
}

Ray RayTracer::get_new_ray(IntersectionRecord &intersection_record)
{
    ONB onb_;

    onb_.setFromV(intersection_record.normal_);

    float r1 = ((double) rand()  / (RAND_MAX));
    float r2 = ((double) rand()  / (RAND_MAX));

    float teta = glm::acos (1- r1);
    float phi = (2*PI*r2);

    glm::vec3 cartesian_coordinate = { glm::sin(teta) * glm::cos(phi), glm::cos(teta) , glm::sin(teta) * glm::sin(phi)};

    return Ray{ intersection_record.position_ + (intersection_record.normal_*0.001f),
                onb_.getBasisMatrix() * cartesian_coordinate};
}

void RayTracer::integrate2(size_t inicio1, size_t final1)
{
    for ( std::size_t y = inicio1; y < final1; y++ )
    {
        progress();

        for ( std::size_t x=0; x < buffer_.h_resolution_; x++ )
        {
            buffer_.buffer_data_[x][y] = glm::vec3{0.0f};

            for(std::size_t i=0; i<number_rays; i++)
            {

                float random = ((double) rand()  / (RAND_MAX));
                float random1 = ((float) rand()  / (RAND_MAX));

                Ray ray{ camera_.getWorldSpaceRay( glm::vec2{ x + random, y + random1 } ) };

                buffer_.buffer_data_[x][y] += L( ray, 0);
            }

            buffer_.buffer_data_[x][y] =  buffer_.buffer_data_[x][y]/number_rays;

        }
    }
}

void RayTracer::progress()
{
    p++;
    std::stringstream progress_stream;
    progress_stream << "\r  progress .........................: "
                    << std::fixed << std::setw( 6 )
                    << std::setprecision( 2 )
                    << 100*p/(buffer_.v_resolution_ - 1)
                    << "%";

    std::clog << progress_stream.str();
}
void RayTracer::integrate( void )
{

    size_t a = buffer_.v_resolution_/numero_threads;
    size_t b = 0;
    size_t c = a;

    std::thread thread[numero_threads];

    for(int i = 0; i <numero_threads ; i++)
    {
            thread[i] = std::thread {&RayTracer::integrate2, this, b,c};
            b = c;
            c += a;
    }

    for(int i = 0; i <numero_threads ; i++)
    {
        thread[i].join();
    }

    std::clog << std::endl;
}