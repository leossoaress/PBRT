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

    Ray refl_ray;

    if ( curr_depth < 5 ) {
        intersection_record.t_ = std::numeric_limits<double>::max();

        if (scene_.intersect(ray, intersection_record))
        {

            if (intersection_record.material_->get_tipo() == 1 || intersection_record.material_->get_tipo() == 0) //difuso e lightsource
            {
                refl_ray = get_new_ray(intersection_record);

                Lo = intersection_record.material_->get_emitancia() + 2.0f * PI *
                     intersection_record.material_->get_BRDF() *
                     L(refl_ray, ++curr_depth) *
                     glm::dot(intersection_record.normal_,
                     refl_ray.direction_);
            }

            else if(intersection_record.material_->get_tipo() == 2)
            {
                refl_ray = getnwerayreflected(ray,intersection_record);

                Lo = L(refl_ray, ++curr_depth);
            }

            else if(intersection_record.material_->get_tipo() == 3)// vidro
            {
                if (glm::dot(intersection_record.normal_, ray.direction_) < 0) //entrando do vidro
                {
                    float n1 = 1;
                    float n2 = intersection_record.material_->get_n();

                    float fresnel = function_fresnel(n1, n2, intersection_record, ray);

                    float r1 = ((double) rand() / (RAND_MAX));

                    if (fresnel > r1)
                    {
                        refl_ray = getnwerayreflected(ray,intersection_record);

                        Lo = L(refl_ray, ++curr_depth);
                    }
                    else
                    {
                        float a = 1;

                        refl_ray = get_new_ray_refracted(ray, intersection_record, n1, n2, a);

                        Lo = L(refl_ray, ++curr_depth);
                    }
                }
                else // saindo do virdro
                {
                    float n1 = intersection_record.material_->get_n();
                    float n2 = 1;


                    float fresnel = function_fresnel(n1, n2, intersection_record, ray);

                    float r1 = ((double) rand() / (RAND_MAX));

                    if (fresnel == 1)
                    {
                        refl_ray = getnwerayreflected(ray,intersection_record);

                        Lo = L(refl_ray, ++curr_depth);
                    }

                    else if (fresnel > r1)
                    {
                        refl_ray = getnwerayreflected(ray,intersection_record);

                        Lo = L(refl_ray, ++curr_depth);
                    }
                    else
                    {
                        float a=1;

                        refl_ray = get_new_ray_refracted(ray, intersection_record, n1, n2, a);

                        Lo = L(refl_ray, ++curr_depth);
                    }
                }
            }
            else
            {
                //roughness factor

                float m = 0.35f;

                //Importance sampling

                ONB tangent_frame;
                tangent_frame.setFromV( intersection_record.normal_ );

                glm::dmat3x3 tangent_to_universe_space = tangent_frame.getBasisMatrix();
                glm::dmat3x3 universe_to_tangent_space = glm::transpose( tangent_to_universe_space );

                glm::dvec3 w_i = universe_to_tangent_space * -ray.direction_;

                float r1 = ((double)rand()/(RAND_MAX));

                float r2 = ((double)rand()/(RAND_MAX));

                float phi = 2.0f * PI * r2;

                float theta = glm::atan(glm::sqrt( -(m * m) * glm::log(1 - r1)));

                glm::dvec3 p = {glm::cos(phi) * glm::sin(theta), glm::cos(theta), glm::sin(phi) *  glm::sin(theta)};

                glm::dvec3 w_r = 2.0 * p * glm::dot( p, w_i ) - w_i;

                glm::dvec3 new_dir = tangent_to_universe_space * w_r;


                refl_ray = { (glm::dvec3) intersection_record.position_ + new_dir * 0.00001, new_dir };


                glm::dvec3 h = glm::normalize( w_i + w_r );
                double nh = std::abs( h.y );
                double nv = std::abs( w_i.y );
                double nl = std::abs( w_r.y );
                double vh = std::abs( glm::dot( w_i, h ) );
                double lh = std::abs( glm::dot( w_r, h ) );

                // Beckmann normal distribution function
                double nh_2 = nh * nh;
                double m_2 = m * m;
                double d1 = 1.0 / ( M_PI * m_2 * nh_2 * nh_2 );
                double d2 = ( nh_2 - 1.0 ) / ( m_2 * nh_2 );
                double d = d1 * exp( d2 );

                // Cook-Torrance geometric attenuation
                double g1 = 2.0 * nh / vh;
                double g = std::min( 1.0, std::min( g1 * nv, g1 * nl ) );

                // Fresnel term
                glm::dvec3 r0 = intersection_record.material_->BRDF_;
                const double x = 1.0f - lh;
                glm::dvec3 F = r0 + ( 1.0 - r0 ) * x * x * x * x * x;

                glm::dvec3 rough_specular_term = ( F * d * g ) / ( 4.0 * nv * nl );

                //PDF
                double om = glm::dot( w_r, h );
                double a = ( d1 * exp( d2 ) * nh ) / ( 4.0 * ( om ) );

                //Cook-torrance
                glm::vec3 ct = 1.0 / a  * rough_specular_term;

                if ( w_r.y < 0.0 )
                    ct = glm::vec3{ 0.0, 0.0, 0.0 };


                Lo = intersection_record.material_->get_emitancia() +
                     ct * L(refl_ray, ++curr_depth) *
                     glm::dot(intersection_record.normal_,
                     refl_ray.direction_);


            }
        }

    }

    return Lo;
}

Ray RayTracer::getnwerayreflected(Ray ray_origin, IntersectionRecord &intersection_record)
{
    Ray refl_ray;

    ONB onb_;

    onb_.setFromV(intersection_record.normal_);

    glm::vec3 d = glm::transpose(onb_.getBasisMatrix()) * ray_origin.direction_;

    d.y = -d.y;

    refl_ray.origin_ = intersection_record.position_ + (intersection_record.normal_ * 0.001f);

    refl_ray.direction_ = glm::normalize(onb_.getBasisMatrix() * d);

    return refl_ray;
}

Ray RayTracer::get_new_ray_refracted(Ray ray, IntersectionRecord &intersection_record, float n1, float n2, float a)
{

    float n = n1/n2;

    float cos1 = glm::dot(intersection_record.normal_, ray.direction_);

    float sin1 = n * n * (1.0 - cos1 * cos1);

    float cost = sqrt(1.0 - sin1);

    return Ray{ intersection_record.position_ + (-intersection_record.normal_*0.001f), n* ray.direction_ + (n*cos1 - cost) * intersection_record.normal_};

}

float RayTracer::function_fresnel(float n1, float n2, IntersectionRecord &intersection_record, Ray ray)
{

    float r0 = (n1 - n2) / (n1 + n2);

    r0 *= r0;

    float cosx = -glm::dot(intersection_record.normal_, ray.direction_);

    if(n1>n2)
    {
        float n = n1/n2;
        float cos1 = glm::dot(intersection_record.normal_, ray.direction_);

        float a = n*n*(1.0 - cos1*cos1);

        if(a>1)             //TIR
            return 1;

        cosx = sqrt(1 - a);
    }

    float x = 1.0 - cosx;

    return r0 + (1.0 - r0) * x * x * x * x * x;
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