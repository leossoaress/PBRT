#include "triangle.h"
#include <iostream>
# define PI 3.14159265358979323846

Triangle::Triangle( void )
{}

Triangle::Triangle( const glm::vec3 &aa, const glm::vec3 &bb, const glm::vec3 &cc, Material* material):

	Primitive::Primitive{material},
  aa_{ aa },
	bb_{ bb },
	cc_{ cc }


{}

bool Triangle::intersect( const Ray &ray,
                        IntersectionRecord &intersection_record ) const
{

	float a, b, c, d, e, f, g, h, i, j, k, l;

	a = aa_.x - bb_.x;
	b = aa_.y - bb_.y;
	c = aa_.z - bb_.z;
	d = aa_.x - cc_.x;
	e = aa_.y - cc_.y;
	f = aa_.z - cc_.z;

	g = ray.direction_.x;
	h = ray.direction_.y;
	i = ray.direction_.z;

	j = aa_.x - ray.origin_.x;
	k = aa_.y - ray.origin_.y;
	l = aa_.z - ray.origin_.z;

	float m, gama, beta, teta;

	m = a*(e*i-h*f) + b*(g*f-d*i) + c*(d*h-e*g);

	gama = (i*(a*k - j*b) + h*(j*c - a*l) + g*(b*l - k*c))/m;

	if( gama<0.0f || gama>1.0f)
		return false;

	beta = (j*(e*i - h*f ) + k*(g*f - d*i) + l*(d*h - e*g))/m;

	if( beta<0.0f || beta> 1.0f - gama)
		return false;

	teta = -(f*(a*k - j*b) + e*(j*c - a*l) + d*(b*l - k*c))/m;

	glm::vec3 center_ = glm::vec3((aa_.x + bb_.x + cc_.x)/3.0f , (aa_.y + bb_.y + cc_.y)/3.0f , (aa_.z + bb_.z + cc_.z)/3.0f);

  	intersection_record.t_ = teta;
   	intersection_record.position_ = ray.origin_ + ray.direction_ * intersection_record.t_;

		intersection_record.normal_ = glm::normalize(glm::cross(bb_ - aa_, cc_ - aa_));

		float testnormaldirection = glm::dot(ray.direction_, intersection_record.normal_);
		if(testnormaldirection > 0.0f)
		{
			 intersection_record.normal_ = -intersection_record.normal_;
		}

		intersection_record.material_ = material_;

    	return true;
}

BBox Triangle::getAABB( void ) const
{
	BBox aabb;

	aabb.min_ = glm::min( glm::min( aa_, bb_ ), cc_ );
	aabb.max_ = glm::max( glm::max( aa_, bb_ ), cc_ );
	aabb.centroid_ = ( 1.0f / 3.0f ) * ( aa_ + bb_ + cc_ );
	return aabb;
}