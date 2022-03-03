#include <iostream>
#include <fstream>
#include <string>
#include "Visitors/VisitorExportCustom.hpp"
#include "COR/CORImportCustom/ImporterCustom.hpp"
#include "COR/CORImportCustom/ImporterCustomCircle.hpp"
#include "COR/CORImportCustom/ImporterCustomPolygone.hpp"
#include "COR/CORImportCustom/ImporterCustomSegment.hpp"
#include "COR/CORImportCustom/ImporterCustomTriangle.hpp"
#include "Visitors/VisitorDrawNetwork.hpp"

using namespace std;

int main()
{
	VisitorShape* V = new VisitorExportCustom("C:\\Users\\toxic\\Desktop\\test.txt");

	Circle C(Vecteur2D(1.125, 2.75), 4, 0x12FF5600);
	Triangle T(Vecteur2D(0, 2), Vecteur2D(3, 4), Vecteur2D(6, 0), 0xFFFF2400);
	Segment S(Vecteur2D(1, 2), Vecteur2D(7, 10), 0xFFFF2400);
	Group G(0xFF00FF00);

	G.shape_list.push_back(&C);
	G.shape_list.push_back(&T);
	G.shape_list.push_back(&S);

	std::cout << "Area of all 3 shapes : " << G.get_area() << std::endl;
	std::cout << G << std::endl;

	G.translation(Vecteur2D(1, 2));

	std::cout << G << std::endl;

	std::cout << C << std::endl;
	std::cout << T << std::endl;
	std::cout << S << std::endl;

	C.accept(V);
	T.accept(V);
	S.accept(V);

	ImporterCustomCircle imp_circle;
	ImporterCustomPolygone imp_polygon;
	ImporterCustomSegment imp_segment;
	ImporterCustomTriangle imp_triangle;

	imp_circle.set_next(&imp_polygon)->set_next(&imp_segment)->set_next(&imp_triangle);

	fstream newfile;
	newfile.open("C:\\Users\\toxic\\Desktop\\test.txt", ios::in);

	std::string test;
	while (getline(newfile, test)) {
		const Shape* oui = imp_circle.importShape(test);

		if (oui != nullptr)
			std::cout << *oui << std::endl;
		else
			std::cout << "Man fuck this shit im jerking off" << std::endl;
	}

	return 0;
}