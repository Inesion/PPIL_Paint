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

	const Vecteur2D& operator+=(const Vecteur2D& V)
	{
		return *this = *this + V;
	}

	const Vecteur2D& operator-=(const Vecteur2D& V)
	{
		return *this += -V;
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

	static inline double det(const Vecteur2D& A, const Vecteur2D& B) { return A.x * B.y - A.y * B.x; }

	inline double det(const Vecteur2D& A) { return x * A.y - y * A.x; }

	static const Vecteur2D* parseVector(const char* data);

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

#endif //_VECTEUR2D_HPP_