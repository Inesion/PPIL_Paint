#ifndef _SEGMENT_HPP_
#define _SEGMENT_HPP_

#include "Shape.hpp"

class Segment : public Shape {
public:
	Segment(const Vecteur2D& A, const Vecteur2D& B, const Color Col) : Shape('S', Col) {
		add_point(A);
		add_point(B);
	}

	Segment(const Shape& S) : Shape('S', S.get_color(), S.get_point_list()) {}

	double get_area() override { return 0; }
	
	void accept(VisitorShape *V) const override { V->visitSegment(*this); }
};

#endif //_SEGMENT_HPP_