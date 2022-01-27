#ifndef _TRIANGLE_HPP_
#define _TRIANGLE_HPP_

#include "Shape.hpp"

class Triangle : public Shape {
public:
	Triangle(Vecteur2D A, Vecteur2D B, Vecteur2D C, Color Col) : Shape('T', Col) {
		add_point(A);
		add_point(B);
		add_point(C);
	}

	void accept(VisitorShape *V) const override { V->visitTriangle(*this); }

	operator std::string() const {
		std::string res("Triangle : ");
		res += to_string_points();
		res += ", Color : ";
		res += to_string(color);
		res += "\n";

		return res;
	}
};

#endif //_TRIANGLE_HPP_