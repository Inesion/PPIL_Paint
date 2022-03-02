#ifndef _TRIANGLE_HPP_
#define _TRIANGLE_HPP_

#include "Shape.hpp"

class Triangle : public Shape {
public:
	Triangle(const Vecteur2D& A, const Vecteur2D& B, const Vecteur2D& C, int32_t Col) : Shape('T', Col) {
		add_point(A);
		add_point(B);
		add_point(C);
	}

	Triangle(const Shape& S) : Shape('T', S.get_color(), S.get_point_list()) {}

	void accept(VisitorShape *V) const override { V->visitTriangle(*this); }
};

#endif //_TRIANGLE_HPP_