#include "Vecteur2D.hpp"

/*Vecteur2D::Vecteur2D(const char* s) {
	if (sscanf(s, "%*c %lf %*c %lf", &x, &y) != 2) {
		x = 0;
		y = 0;
	}
}*/

const Vecteur2D* Vecteur2D::parseVector(const char* data) {
	double x, y;

	if (sscanf(data + 1, "(%lf, %lf)", &x, &y) == 2)
		return new Vecteur2D(x, y);

	return nullptr;
}