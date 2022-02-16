#ifndef _VISITOREXPORTCUSTOM_HPP_
#define _VISITOREXPORTCUSTOM_HPP_

#include "VisitorShape.hpp"
#include "Shapes/Circle.hpp"
#include "Shapes/Triangle.hpp"
#include "Shapes/Segment.hpp"
#include "Shapes/Polygon.hpp"
#include <fstream>


class VisitorExportCustom : public VisitorShape {
private:
	std::ofstream out;

public:
	VisitorExportCustom(const char *filename) {
		out.open(filename, ios::out | ios::binary | ios::trunc);
		description = "Exporting to file : ";
	}

	~VisitorExportCustom() { out.close(); }

	void visitCircle(const Circle& C) override {
		std::cout << description << C << std::endl;
		out << C << std::endl;
	}
	void visitPolygon(const Polygon& P) override {
		std::cout << description << P << std::endl;
		out << P << std::endl;
	}
	void visitSegment(const Segment& S) override {
		std::cout << description << S << std::endl;
		out << S << std::endl;
	}
	void visitTriangle(const Triangle& T) override {
		std::cout << description << T << std::endl;
		out << T << std::endl;
	}
};

#endif //_VISITOREXPORTCUSTOM_HPP_