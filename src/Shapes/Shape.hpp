#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

#include "Utils/Vecteur2D.hpp"
#include "Visitors/VisitorShape.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>

enum Color { BLACK, BLUE, RED, GREEN, YELLOW, CYAN };

class Shape {
protected:
	Color color;
	std::vector<Vecteur2D> point_list;
	char shape_prefix;

	void add_point(const Vecteur2D &P) { point_list.push_back(P); }

public:
	Shape(const char shape_prefix, const Color C) : color(C), shape_prefix(shape_prefix) {}
	Shape(const char shape_prefix, const Color C, const std::vector<Vecteur2D> point_list) : point_list(point_list), color(C) {}
	virtual ~Shape() {}

	virtual void accept(VisitorShape *V) const = 0;
	virtual operator std::string() const = 0;

	Color get_color() const { return color; }
	void set_color(const Color C) { color = C; }

	int serialize(char buffer[]) const;
	static Shape* deserialize(const char buffer[], const int size);

	int serialize(std::ostream &os) const;	// dabord nb octet puis data
	static Shape* deserialize(std::istream &is);


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
			res += " ";
		}

		res += (std::string)point_list.back();

		return res;
	}

	std::ostream& serialize(std::ostream& os) const {
		os.put(shape_prefix);
		os.write(reinterpret_cast<const char*>(&color), sizeof color);
		os.put(point_list.size());

		for (auto i = 0; i < point_list.size(); i++) {
			os.write(reinterpret_cast<const char*>(&point_list[i]), sizeof point_list[i]);
		}

		serialize_custom_attributes(os);

		return os;
	}

	virtual std::ostream& serialize_custom_attributes(std::ostream& os) const { return os; }
};

std::ostream& operator <<(std::ostream &os, const Shape &F) {
	return os << (std::string)F;
}

#endif //_SHAPE_HPP_