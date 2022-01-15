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
		cout << (string)C;
	}
	void visitPolygon(const Polygon &P) const override {

	}
	void visitSegment(const Segment &S) const override {

	}
	void visitTriangle(const Triangle &T) const override {

	}
};

#endif //_VISITEURDESSIN_HPP_