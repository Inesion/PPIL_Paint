#include "Vecteur2D.hpp"
#include "Matrice2x2.hpp"

/*Vecteur2D::Vecteur2D(const char* s) {
	if (sscanf(s, "%*c %lf %*c %lf", &x, &y) != 2) {
		x = 0;
		y = 0;
	}
}*/

const void Vecteur2D::rotation(const double rad, const Vecteur2D& invariant) {
	Matrice2x2 R = Matrice2x2::creeRotation(rad);
	*this = R * (*this - invariant) + invariant;
}

const void Vecteur2D::homotetie(const double k, const Vecteur2D& invariant) {
	*this = k * *this + (1 - k) * invariant;
}

const void Vecteur2D::translation(const Vecteur2D& u) {
	*this += u;
}