#include <iostream>
#include "Visitors/VisitorExportCustom.hpp"

using namespace std;

int main()
{
	/*VisitorDrawNetwork* V = new VisitorDrawNetwork();
	std::vector<Vecteur2D> L = {Vecteur2D(2,4), Vecteur2D(3,-8), Vecteur2D(1,2)};
	Polygon F(L, Color::BLACK);

	cout << (string)F << endl;

	F.accept(V);

	delete V;*/

	VisitorShape* V = new VisitorExportCustom("C:\\Users\\Inesion\\Desktop\\test.txt");

	Circle C(Vecteur2D(1.125, 2.75), 4, Color::BLACK);
	Triangle T(Vecteur2D(0, 2), Vecteur2D(3, 4), Vecteur2D(6, 0), Color::BLUE);
	Segment S(Vecteur2D(1, 2), Vecteur2D(7, 10), Color::RED);

	std::cout << C << std::endl;
	std::cout << T << std::endl;
	std::cout << S << std::endl;

	std::cout << "Area of triangle (" << T << ") " << T.get_area() << std::endl;

	//C.accept(V);
	//T.accept(V);
	//S.accept(V);

	return 0;
}