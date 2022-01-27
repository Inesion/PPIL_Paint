#ifndef _POLYGON_HPP_
#define _POLYGON_HPP_

#include "Shape.hpp"

class Polygon : public Shape {
public:
	Polygon(const Color Col) : Shape('P', Col) {}
	
	Polygon(const std::vector<Vecteur2D> point_list, const Color C) : Shape('P', C, point_list) {}

	void accept(VisitorShape *V) const override { V->visitPolygon(*this); }

	operator std::string() const {
		std::string res("Polygon : ");
		res += to_string_points();
		res += " Area : ";
		res += to_string(get_area());
		res += ", Color : ";
		res += to_string(color);

		return res;
	}
};

#endif //_POLYGON_HPP_