#include <iostream>
#include "VisitorDrawNetwork.hpp"

using namespace std;

int main()
{
	VisitorDrawNetwork *V = new VisitorDrawNetwork();
	std::vector<Vecteur2D> L = {Vecteur2D(2,4), Vecteur2D(3,-8), Vecteur2D(1,2)};
	Polygon F(L, Color::BLACK);

	cout << (string)F << endl;

	return 0;
}

// void vector_test() {
// 	std::cout << "essai des vecteurs 2D \n";

// 	Vecteur2D u1(2, 3), u2(2, 3), v(5), w, u3(3, 4), u4(3, -4);
	
// 	/*
// 	std::cout << " u1 = " << u1 << std::endl;
// 	std::cout << " u2 = " << u2 << std::endl;
// 	std::cout << " u1 - u2 = " << u1 - u2 << std::endl;
// 	std::cout << " 5*u1 = " << 5 * u1 << std::endl;
// 	*/

// 	Vecteur2D v1(-3, 7), v2(11, 4), v3(8), v4;
// 	//v1 = 7; // v1 = Vecteur2D(7, 0); refuse
// 	v1 = (Vecteur2D)7;
// 	std::cout << "What the fuck v1 : " << v1 << std::endl;
// 	v4 = v1 + v2;        // v4 = v1.operator+(v2);
// 	v4 = (v1 + v2) + v3; // associativite
// 	v4 = -v1;            // v4 = v1.operator-();
// 	v2 = v1 * 4;         // v2 = v1.operator*(4);
// 	v4 = 4 * v1;  // v4 = 4.operator*(v1); v4 = operator*(4, v1);
// 	v4 = v1 - v2; // v4 = operator-(v1, v2);
// 	std::string s;
// 	s = v1; // s = v1.operator string();
// 	std::cout << (std::string)v1;
// 	std::cout << v1; // cout.operator<<(v1); operator<<(cout, v1);
// 	(std::cout << v1) << std::endl;
// 	operator<<(std::cout, v1) << std::endl;
// 	Vecteur2D eiteta = Vecteur2D::creePolaire(0.92722513089005);
// 	Vecteur2D z1(3, 2), z2;
// 	z2 = z1 ^ eiteta;
// 	std::cout << "z1 : " << z1 << ", eiteta : " << eiteta << ", z2 : " << z2 << std::endl;
// }