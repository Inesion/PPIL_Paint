#ifndef _POLYGON_HPP_
#define _POLYGON_HPP_

#include "Shape.hpp"

class Polygone : public Shape {
public:
	Polygone(const int32_t Col) : Shape('P', Col) {}
	
	Polygone(const std::vector<Vecteur2D>& point_list, const int32_t C) : Shape('P', C, point_list) {}

	Polygone(const Shape& S) : Shape('P', S.get_color(), S.get_point_list()) {}

	void accept(VisitorShape *V) const override { V->visitPolygone(*this); }

	using Shape::add_point;
};

#endif //_POLYGON_HPP_