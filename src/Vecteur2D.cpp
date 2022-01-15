#include "Vecteur2D.hpp"

Vecteur2D::Vecteur2D(const char* s) {
	if (sscanf(s, "%*c %lf %*c %lf", &x, &y) != 2) {
		x = 0;
		y = 0;
	}
}