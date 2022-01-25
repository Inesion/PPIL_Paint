#ifndef _SEGMENT_HPP_
#define _SEGMENT_HPP_

#include "Shape.hpp"

class Segment : public Shape {
public:
	Segment(Vecteur2D A, Vecteur2D B, Color Col) : Shape(Col) {
		add_point(A);
		add_point(B);
	}

	
	void accept(VisitorDraw *V) const override { V->visitSegment(*this); }

	operator std::string() const {
		std::string res("Segment : ");
		res += to_string_points();
		res += ", Color : ";
		res += to_string(color);

		return res;
	}
};

#endif //_SEGMENT_HPP_