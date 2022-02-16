#ifndef _SEGMENT_HPP_
#define _SEGMENT_HPP_

#include "Shape.hpp"

class Segment : public Shape {
public:
	Segment(Vecteur2D A, Vecteur2D B, Color Col) : Shape('S', Col) {
		add_point(A);
		add_point(B);
	}

	double get_area() override { return 0; }
	
	void accept(VisitorShape *V) const override { V->visitSegment(*this); }
};

#endif //_SEGMENT_HPP_