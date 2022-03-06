#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_

#include "Shape.hpp"
#define PI 3.14159265358979323846

class Circle : public Shape {
private:
	double rayon;
public:
	Circle(const Vecteur2D& centre, const double rayon, const int32_t Col) : rayon(rayon), Shape('C', Col) {
		add_point(centre);
	}

	Circle(const Shape& S, const double rayon) : rayon(rayon), Shape('C', S.get_color(), S.get_point_list()) {}
	
	Vecteur2D get_center() const { return point_list[0]; }

	double get_area() override { return PI * rayon * rayon; }

	void homotetie(const double k, const Vecteur2D& invariant) {
		point_list[0].homotetie(k, invariant);
		rayon = rayon * k;
	}

	void accept(VisitorShape *V) const override { V->visitCircle(*this); }

	const std::string to_string_custom_attributes() const override { return std::string(to_string(rayon)); }
};

#endif //_CIRCLE_HPP_