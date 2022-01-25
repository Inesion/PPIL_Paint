#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

#include "Utils/Vecteur2D.hpp"
#include "Visitors/VisitorDraw.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <ostream>

enum Color { BLACK, BLUE, RED, GREEN, YELLOW, CYAN };

class Shape {
protected:
	Color color;
	std::vector<Vecteur2D> point_list;

	void add_point(const Vecteur2D &P) { point_list.push_back(P); }

public:
	Shape(Color C) : color(C) {}
	Shape(std::vector<Vecteur2D> point_list, Color C) : point_list(point_list), color(C) {}
	virtual ~Shape() {}

	virtual void accept(VisitorDraw *V) const = 0;
	virtual operator std::string() const = 0;

	Color get_color() const { return color; }
	void set_color(const Color C) { color = C; }

	virtual double get_area() const {	//not good, must use other formula. Also find center of gravity, more complex but result less likely to suffer from imprecision
		/*double SL1 = 0, SL2 = 0;
		int i;

		if (point_list.size() < 3)
			return 0;

		for (i = 0; i < point_list.size(); i++)
			SL1 += point_list[i].x * point_list[i + 1].y;
		
		SL1 += point_list[i].x * point_list[0].y;

		SL2 += point_list[0].x * point_list[i].y;

		for (i = point_list.size() - 1; i >= 0; i--)
			SL2 += point_list[i].x * point_list[i - 1].y;

		return abs(SL1 - SL2);*/
		return 0;
	}

	std::string to_string_points() const {
		std::string res;

		for (auto i = 0; i < point_list.size() - 1; i++) {
			res += (std::string)point_list[i];
			res += ", ";
		}

		res += (std::string)point_list.back();

		return res;
	}
};

std::ostream& operator <<(std::ostream &os, const Shape &F) {
	return os << (std::string)F;
}

#endif //_SHAPE_HPP_