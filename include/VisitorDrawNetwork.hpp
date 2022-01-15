#ifndef _VISITEURDESSIN_HPP_
#define _VISITEURDESSIN_HPP_

#include "VisitorDraw.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "Segment.hpp"
#include "Polygon.hpp"
#include <iostream>


class VisitorDrawNetwork : public VisitorDraw {
public:
	VisitorDrawNetwork() {}
	
	void visitCircle(const Circle &C) const override {
		std::cout << "Visiting Circle" << std::endl;
	}
	void visitPolygon(const Polygon &P) const override {
		std::cout << "Visiting Polygon" << std::endl;
	}
	void visitSegment(const Segment &S) const override {
		std::cout << "Visiting Segment" << std::endl;
	}
	void visitTriangle(const Triangle &T) const override {
		std::cout << "Visiting Triangle" << std::endl;
	}
};

#endif //_VISITEURDESSIN_HPP_