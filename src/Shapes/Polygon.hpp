#ifndef _POLYGON_HPP_
#define _POLYGON_HPP_

#include "Shape.hpp"

class Polygon : public Shape {
public:
	Polygon(const Color Col) : Shape('P', Col) {}
	
	Polygon(const std::vector<Vecteur2D> point_list, const Color C) : Shape('P', C, point_list) {}

	void accept(VisitorShape *V) const override { V->visitPolygon(*this); }
};

#endif //_POLYGON_HPP_