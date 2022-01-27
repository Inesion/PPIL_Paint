#ifndef _VISITORDRAWNETWORK_HPP_
#define _VISITORDRAWNETWORK_HPP_

#include "VisitorShape.hpp"
#include "Shapes/Circle.hpp"
#include "Shapes/Triangle.hpp"
#include "Shapes/Segment.hpp"
#include "Shapes/Polygon.hpp"
#include <iostream>


class VisitorDrawNetwork : public VisitorShape {
public:
	VisitorDrawNetwork() { description = "Drawing over the network : " }
	
	void visitCircle(const Circle &C) override {
		std::cout << description << C << std::endl;
	}
	void visitPolygon(const Polygon &P) override {
		std::cout << description << P << std::endl;
	}
	void visitSegment(const Segment &S) override {
		std::cout << description << S << std::endl;
	}
	void visitTriangle(const Triangle &T) override {
		std::cout << description << T << std::endl;
	}
};

#endif //_VISITORDRAWNETWORK_HPP_