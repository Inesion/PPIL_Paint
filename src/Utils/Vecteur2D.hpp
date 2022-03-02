#ifndef _VECTEUR2D_HPP_
#define _VECTEUR2D_HPP_

#include <string>
#include <sstream>
#include <ostream>
#include <math.h>

using namespace std;

template <class T>
inline const T operator - (const T& u, const T& v)
{
	return u + -v;
}

class Vecteur2D {
public:
	/**
	 * @brief Coordonnée x du vecteur
	*/
	double x;

	/**
	 * @brief Coordonnée y du vecteur
	*/
	double y;

	inline explicit Vecteur2D(const double& x = 0, const double& y = 0) : x(x), y(y) {}

	/**
	 * @brief Opérateur : Addition du vecteur u avec cette instance
	 * @param u 
	 * @return Vecteur résultant de cette instance + u
	*/
	inline const Vecteur2D operator +(const Vecteur2D& u) const { return Vecteur2D(x + u.x, y + u.y); }
	
	/**
	 * @brief Opérateur : Multiplication du réel a avec cette instance
	 * @param a 
	 * @return Vecteur résultant de cette instance * a
	*/
	inline const Vecteur2D operator *(const double& a) const { return Vecteur2D(x * a, y * a); }
	
	/**
	 * @brief Opérateur : Négation unaire (opposé du vecteur)
	 * @return 
	*/
	inline const Vecteur2D operator -() const { return Vecteur2D(-x, -y); }

	//autres méthodes

	/**
	 * @brief Constructeur : retourne un vecteur unitaire en fonction de l'angle theta
	 * 
	 * @param theta Angle en radian
	 * @return const Vecteur2D Vecteur unitaire avec un angle theta
	 */
	static const Vecteur2D creePolaire(const double theta) { return Vecteur2D(cos(theta), sin(theta)); }
	
	/**
	 * @brief Opérateur : Produit au sens des nombres complexes
	 * 
	 * @param v 
	 * @return const Vecteur2D 
	 */
	inline const Vecteur2D operator ^(const Vecteur2D& v) const { return Vecteur2D(x * v.x - y * v.y, x * v.y + y * v.x); }
	
	/**
	 * @brief Opérateur : Produit scalaire
	 * 
	 * @param A Vecteur avec lequel multiplier cette instance
	 * @return const double Résultat du produit scalaire
	 */
	inline const double operator *(const Vecteur2D &A) const {
		return x * A.x + y * A.y;
	}

	/**
	 * @brief Opérateur : Addition de cette instance et de V, puis stock le résultat dans cette instance
	 * @param V Vecteur à additionner
	 * @return Référence sur cette instance
	*/
	const Vecteur2D& operator+=(const Vecteur2D& V)
	{
		return *this = *this + V;
	}

	/**
	 * @brief Opérateur : Soustraction de cette instance et de V, puis stock le résultat dans cette instance
	 * @param V Vecteur à soustraire
	 * @return Référence sur cette instance
	*/
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

	/**
	 * @brief Calcul du déterminant de 2 vecteurs, méthode statique
	 * @param A
	 * @param B 
	 * @return Déterminant de A et B
	*/
	static inline double det(const Vecteur2D& A, const Vecteur2D& B) { return A.x * B.y - A.y * B.x; }

	/**
	 * @brief Calcul du déterminant de 2 vecteurs
	 * @param A 
	 * @return Déterminant de A et de cette instance
	*/
	inline double det(const Vecteur2D& A) { return x * A.y - y * A.x; }

	/**
	 * @brief Parse un vecteur sous la forme (xxxx.xxxx, yyyy.yyyy)
	 * @param data 
	 * @return 
	*/
	static const Vecteur2D* parseVector(const char* data);

	/**
	 * @brief Opérateur : to_string
	*/
	operator std::string() const
	{
		std::ostringstream os;
		os << "(" << x << ", " << y << ")";
		return os.str();
	}


}; // classe Vecteur2D

/**
 * @brief Opérateur : Multiplication du réel a avec le vecteur u
 * @param a 
 * @param u 
 * @return Vecteur résultant de u * a
*/
inline const Vecteur2D operator * (const double& a, const Vecteur2D& u) { return u * a; }

/**
 * @brief Opérateur : Envoie sur un ostream le vecteur u (to_string)
 * @param os 
 * @param u 
 * @return 
*/
inline ostream& operator << (ostream& os, const Vecteur2D& u)
{
	os << (string)u;
	return os;
}

#endif //_VECTEUR2D_HPP_