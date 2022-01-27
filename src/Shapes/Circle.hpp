#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_

#include "Shape.hpp"

class Circle : public Shape {
private:
	double rayon;
public:
	Circle(const Vecteur2D centre, const double rayon, const Color Col) : rayon(rayon), Shape('C', Col) {
		add_point(centre);
	}
	
	Vecteur2D get_center() const {
		return point_list[0];
	}

	void accept(VisitorShape *V) const override { V->visitCircle(*this); }

	std::ostream& serialize_custom_attributes(std::ostream& os) const { return os.write(reinterpret_cast<const char*>(&rayon), sizeof rayon); }
	
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