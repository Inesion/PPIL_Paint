#ifndef _MATRICE2X2_HPP_
#define _MATRICE2X2_HPP_

#include "Vecteur2D.hpp"

class Matrice2x2 {
private:
	Vecteur2D ligneHaut, ligneBas;

public:
	Matrice2x2(const Vecteur2D &ligneHaut, const Vecteur2D &ligneBas) : ligneHaut(ligneHaut), ligneBas(ligneBas) {}

	static const Matrice2x2 creeRotation(double theta) {
		double cosTheta, sinTheta;
		cosTheta = cos(theta);
		sinTheta = sin(theta);

		return Matrice2x2(Vecteur2D(cosTheta, -sinTheta), 
				  Vecteur2D(sinTheta, cosTheta));
	}

	inline const Vecteur2D operator * (const Vecteur2D& V) const {
		return Vecteur2D(ligneHaut * V, ligneBas * V);
	}

	inline double det() const {
		return ligneHaut.x * ligneBas.y - ligneHaut.y * ligneBas.x;
	}

	static inline double det(const Vecteur2D& A, const Vecteur2D& B) { return A.x * B.y - A.y * B.x; }
};


#endif //_MATRICE2X2_HPP_