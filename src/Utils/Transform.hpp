#include "Vecteur2D.hpp"
#include "Matrice2x2.hpp"

const Vecteur2D rotation(const Vecteur2D& V, const double rad, const Vecteur2D& invariant)
{
	Matrice2x2 R = Matrice2x2::creeRotation(rad);
	return Vecteur2D(R * (V - invariant) + invariant);
}

const Vecteur2D homotetie(const Vecteur2D& V, const double k, const Vecteur2D& invariant)
{
	return Vecteur2D(k * V + (1 - k) * invariant);
}

const Vecteur2D translation(const Vecteur2D& V, const Vecteur2D& u)
{
	return Vecteur2D(V + u);
}