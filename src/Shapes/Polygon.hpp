#ifndef _POLYGON_HPP_
#define _POLYGON_HPP_

#include "Shape.hpp"

class Polygon : public Shape {
public:
	Polygon(const int32_t Col) : Shape('P', Col) {}
	
	Polygon(const std::vector<Vecteur2D>& point_list, const int32_t C) : Shape('P', C, point_list) {}

	Polygon(const Shape& S) : Shape('P', S.get_color(), S.get_point_list()) {}

	void accept(VisitorShape *V) const override { V->visitPolygon(*this); }
};

#endif //_POLYGON_HPP_