#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_

#include "Shape.hpp"

class Circle : public Shape {
private:
	double rayon;
public:
	Circle(Vecteur2D centre, double rayon, Color Col) : rayon(rayon), Shape(Col) {
		add_point(centre);
	}
	
	Vecteur2D get_center() const {
		return point_list[0];
	}

	void accept(VisitorDraw *V) const override { V->visitCircle(*this); }
	
	operator std::string() const {
		std::string res("Circle : ");
		res += (std::string)get_center();
		res += ", ";
		res += to_string(rayon);
		res += ", Color : ";
		res += to_string(color);

		return res;
	}
};

#endif //_CIRCLE_HPP_