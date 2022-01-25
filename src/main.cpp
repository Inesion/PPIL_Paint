#include <iostream>
#include "Visitors/VisitorDrawNetwork.hpp"

using namespace std;

int main()
{
	VisitorDrawNetwork *V = new VisitorDrawNetwork();
	std::vector<Vecteur2D> L = {Vecteur2D(2,4), Vecteur2D(3,-8), Vecteur2D(1,2)};
	Polygon F(L, Color::BLACK);

	cout << (string)F << endl;

	F.accept(V);

	delete V;

	return 0;
}