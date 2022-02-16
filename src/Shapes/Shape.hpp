#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

#include "Utils/Vecteur2D.hpp"
#include "Utils/Matrice2x2.hpp"
#include "Visitors/VisitorShape.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>
#include <math.h>

enum Color { BLACK, BLUE, RED, GREEN, YELLOW, CYAN };

class Shape {
protected:
	Color color;
	std::vector<Vecteur2D> point_list;
	char shape_prefix;

	void add_point(const Vecteur2D &P) { point_list.push_back(P); }

	const Vecteur2D get_gravity_point() const
	{
		double x = 0;
		double y = 0;

		for (auto i : point_list) {
			x += i.x;
			y += i.y;
		}

		x = x / point_list.size();
		y = y / point_list.size();

		return Vecteur2D(x, y);
	}

public:
	Shape(const char shape_prefix, const Color C) : color(C), shape_prefix(shape_prefix) {}
	Shape(const char shape_prefix, const Color C, const std::vector<Vecteur2D> point_list) : point_list(point_list), color(C) {}
	virtual ~Shape() {}

	virtual void accept(VisitorShape *V) const = 0;

	Color get_color() const { return color; }
	void set_color(const Color C) { color = C; }


	virtual double get_area()
	{
		Vecteur2D gravity_point = get_gravity_point();
		double area = 0;

		for (auto& i : point_list)
			i -= gravity_point;
		
		for (auto i = 0; i < point_list.size() - 1; i++)
			area += abs(Matrice2x2::det(point_list[i], point_list[i + 1]));

		area += abs(Matrice2x2::det(point_list.front(), point_list.back()));

		for (auto& i : point_list)
			i += gravity_point;

		return area / 2;
	}

	std::string to_string_points() const {
		std::string res;

		for (auto i : point_list) {
			res += (std::string)i;
			res += " ";
		}

		return res;
	}

	operator std::string() const {
		std::string res;
		res += shape_prefix;
		res += " "
			+ to_string(color)
			+ " "
			+ to_string(point_list.size())
			+ " "
			+ to_string_points()
			+ serialize_custom_attributes();

		return res;
	}

	virtual const std::string serialize_custom_attributes() const { return std::string(); }
};

std::ostream& operator <<(std::ostream &os, const Shape &S) {
	return os << (std::string)S;
}

#endif //_SHAPE_HPP_