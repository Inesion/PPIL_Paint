#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

#include "Utils/Vecteur2D.hpp"
#include "Utils/Matrice2x2.hpp"
#include "Visitors/VisitorShape.hpp"
#include "Utils/Transform.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>
#include <math.h>

enum Color { BLACK, BLUE, RED, GREEN, YELLOW, CYAN };

class Shape {
protected:
	/**
	 * @brief Couleur enum
	*/
	Color color;

	/**
	 * @brief Vecteur représentant la liste des points de la forme
	*/
	std::vector<Vecteur2D> point_list;

	/**
	 * @brief Préfix de forme (ex : C pour cercle, T pour triangle...)
	*/
	char shape_prefix;

	/**
	 * @brief Ajoute un point P dans la liste de point
	 * @param P 
	*/
	void add_point(const Vecteur2D &P) { point_list.push_back(P); }

	/**
	 * @brief Calcul le point du centre de gravité de la forme. La forme doit être valide (avoir au minimum 1 point)
	 * @return 
	*/
	const Vecteur2D get_gravity_point() const
	{
		double x = 0;
		double y = 0;

		for (auto i : point_list) {
			x += i.x;
			y += i.y;
		}

		x = x / point_list.size();
		y = y / point_list.size();

		return Vecteur2D(x, y);
	}

public:
	Shape(const char shape_prefix, const Color C) : color(C), shape_prefix(shape_prefix) {}
	Shape(const char shape_prefix, const Color C, const std::vector<Vecteur2D> &point_list) : point_list(point_list), color(C), shape_prefix(shape_prefix) {}
	virtual ~Shape() {}

	/**
	 * @brief Accepter le visiteur V. Utilser dans le contexte du DP visitor
	 * Fonction normalement virtuelle pure, mais besoin d'utiliser constructeur dans fonction importBase dans classe ImporterCustom
	*  Accepte le visiteur V pour les COR
	 * @param V 
	*/
	virtual void accept(VisitorShape *V) const {};

	const Color get_color() const { return color; }
	void set_color(const Color& C) { color = C; }
	const char get_prefix() const { return shape_prefix; }
	const std::vector<Vecteur2D>& get_point_list() const { return point_list; }

	/**
	 * @brief Calcul l'air de la forme
	 * @return L'aire de la forme en réel
	*/
	virtual double get_area()
	{
		Vecteur2D gravity_point = get_gravity_point();
		double area = 0;

		for (auto& i : point_list)
			i -= gravity_point;
		
		for (auto i = 0; i < point_list.size() - 1; i++)
			area += abs(Matrice2x2::det(point_list[i], point_list[i + 1]));

		area += abs(Matrice2x2::det(point_list.front(), point_list.back()));

		for (auto& i : point_list)
			i += gravity_point;

		return area / 2;
	}

	void rotation(const double rad, const Vecteur2D& invariant) {
		
	}

	/**
	 * @brief Retourne la liste de points dans une string
	 * @return 
	*/
	std::string to_string_points() const {
		std::string res;

		for (auto i : point_list) {
			res += (std::string)i;
			res += " ";
		}

		return res;
	}

	/**
	 * @brief Opérateur : Retourne la forme dans une string
	*/
	operator std::string() const {
		std::string res;
		res += shape_prefix;
		res += " "
			+ to_string(color)
			+ " "
			+ to_string(point_list.size())
			+ " "
			+ to_string_points()
			+ to_string_custom_attributes();

		return res;
	}

	/**
	 * @brief Données additionnelles à ajouter au to_string
	 * Par exemple pour le cercle, on ajouter le rayon
	 * @return 
	*/
	virtual const std::string to_string_custom_attributes() const { return std::string(); }
};

/**
 * @brief Opérateur : Envoie sur un ostream os la forme S (to_string0
 * @param os 
 * @param S 
 * @return 
*/
std::ostream& operator <<(std::ostream &os, const Shape &S) {
	return os << (std::string)S;
}

#endif //_SHAPE_HPP_