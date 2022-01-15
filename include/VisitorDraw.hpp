#ifndef _VISITORDRAW_HPP_
#define _VISITORDRAW_HPP_

class Circle;
class Polygon;
class Segment;
class Triangle;

class VisitorDraw {
public:
	virtual void visitCircle(const Circle &C) const = 0;
	virtual void visitPolygon(const Polygon &P) const = 0;
	virtual void visitSegment(const Segment &S) const = 0;
	virtual void visitTriangle(const Triangle &T) const = 0;
};

#endif //_VISITORDRAW_HPP_