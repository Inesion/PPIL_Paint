#ifndef _VECTEUR2D_HPP_
#define _VECTEUR2D_HPP_

#include <string>
#include <sstream>
#include <ostream>
#include <stdexcept>
#include <math.h>

using namespace std;

template <class T>
inline const T operator - (const T& u, const T& v)
{
	return u + -v;
}

class Vecteur2D {
public:
	double x, y;

	inline explicit Vecteur2D(const double& x = 0, const double& y = 0) : x(x), y(y) {}

	/**
	 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
	 **/
	Vecteur2D(const char* s);

	inline const Vecteur2D operator +(const Vecteur2D& u) const { return Vecteur2D(x + u.x, y + u.y); }
	inline const Vecteur2D operator *(const double& a) const { return Vecteur2D(x * a, y * a); }
	//inline const Vecteur2D operator =(const int x) const { return Vecteur2D(x, 0); }
	
	/**
	 * - unaire (c'est-à- dire opposé d'un vecteur)
	 **/
	inline const Vecteur2D operator -() const { return Vecteur2D(-x, -y); }

	//autres méthodes

	/**
	 * @brief Constructeur retourne vecteur unitaire en fonction de l'angle theta
	 * 
	 * @param theta
	 * @return const Vecteur2D 
	 */
	static const Vecteur2D creePolaire(const double theta) { return Vecteur2D(cos(theta), sin(theta)); }
	
	/**
	 * @brief Produit au sens des nombres complexes
	 * 
	 * @param v 
	 * @return const Vecteur2D 
	 */
	inline const Vecteur2D operator ^(const Vecteur2D& v) const { return Vecteur2D(x * v.x - y * v.y, x * v.y + y * v.x); }
	
	/**
	 * @brief Produit scalaire
	 * 
	 * @param A 
	 * @return const double 
	 */
	inline const double operator *(const Vecteur2D &A) const {
		return x * A.x + y * A.y;
	} 

	/**
	 * @brief Longueur au carré du Vecteur
	 * 
	 * @return double 
	 */
	inline double longueur2() const { return (*this) * (*this); }

	/**
	 * @brief Longueur du vecteur (Pythagore)
	 * 
	 * @return double 
	 */
	inline double longueur() const { return sqrt(longueur2()); }

	operator std::string() const
	{
		std::ostringstream os;
		os << "(" << x << ", " << y << ")";
		return os.str();
	}


}; // classe Vecteur2D

inline const Vecteur2D operator * (const double& a, const Vecteur2D& u) { return u * a; }

inline ostream& operator << (ostream& os, const Vecteur2D& u)
{
	os << (string)u;
	return os;
}

// const Vecteur2D rotation(const Vecteur2D &V, const double rad, const Vecteur2D &invariant) {
// 	Matrice2x2 R = Matrice2x2::creeRotation(rad);
// 	return Vecteur2D(R * (V - invariant) + invariant);
// }

// const Vecteur2D homotetie(const Vecteur2D &V, const double k, const Vecteur2D &invariant) {
// 	return Vecteur2D(k * V + (1 - k) * invariant);
// }

// const Vecteur2D translation(const Vecteur2D &V, const Vecteur2D &u) {
// 	return Vecteur2D(V + u);
// }

#endif //_VECTEUR2D_HPP_