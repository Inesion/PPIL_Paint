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

	Circle C(Vecteur2D(200, 200), 14, 0x0000FF00);
	Triangle T(Vecteur2D(0, 20), Vecteur2D(300, 400), Vecteur2D(600, 0), 0xFFFF2400);
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

	/*ImporterCustomCircle imp_circle;
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
	}*/

	WindowProperties W("Test", 0, 0, 600, 800);
	std::cout << (std::string)W << std::endl;
	VisitorDrawNetwork test("127.0.0.1", 9001, W);
	C.accept(&test);
	test.send_draw_command();

	return 0;
}