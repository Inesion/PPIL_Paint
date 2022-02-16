#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_

#include "Shape.hpp"
#define PI 3.14159265358979323846

class Circle : public Shape {
private:
	double rayon;
public:
	Circle(const Vecteur2D centre, const double rayon, const Color Col) : rayon(rayon), Shape('C', Col) {
		add_point(centre);
	}
	
	Vecteur2D get_center() const { return point_list[0]; }

	double get_area() override { return PI * rayon * rayon; }

	void accept(VisitorShape *V) const override { V->visitCircle(*this); }

	const std::string serialize_custom_attributes() const override { return std::string(to_string(rayon)); }
};

#endif //_CIRCLE_HPP_