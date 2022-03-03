#ifndef _VISITORSHAPE_HPP_
#define _VISITORSHAPE_HPP_

#include <string>

class Circle;
class Polygone;
class Segment;
class Triangle;
class Group;

class VisitorShape {
protected:
	std::string description;

public:
	virtual void visitCircle(const Circle &C) = 0;
	virtual void visitPolygone(const Polygone &P) = 0;
	virtual void visitSegment(const Segment &S) = 0;
	virtual void visitTriangle(const Triangle &T) = 0;
	virtual void visitGroup(const Group &G) = 0;
};

#endif //_VISITORSHAPE_HPP_