#ifndef _VISITOREXPORTCUSTOM_HPP_
#define _VISITOREXPORTCUSTOM_HPP_

#include "VisitorShape.hpp"
#include "Shapes/Circle.hpp"
#include "Shapes/Triangle.hpp"
#include "Shapes/Segment.hpp"
#include "Shapes/Polygone.hpp"
#include "Shapes/Group.hpp"
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
	void visitPolygone(const Polygone& P) override {
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
	void visitGroup(const Group& G) override {
		std::cout << description << G << std::endl;
		out << G << std::endl;
	}
};

#endif //_VISITOREXPORTCUSTOM_HPP_