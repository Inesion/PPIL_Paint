#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

#include "Utils/Vecteur2D.hpp"
#include "Utils/Matrice2x2.hpp"
#include "Visitors/VisitorShape.hpp"
#include "../Utils/Transform.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <ostream>
#include <fstream>
#include <math.h>

class Shape {
protected:
	/**
	 * @brief Couleur RGBA
	*/
	int32_t color;

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
	Shape(const char shape_prefix, const int32_t C) : color(C), shape_prefix(shape_prefix) {}
	Shape(const char shape_prefix) : color(0), shape_prefix(shape_prefix) {}
	Shape(const char shape_prefix, const int32_t C, const std::vector<Vecteur2D>& point_list) : point_list(point_list), color(C), shape_prefix(shape_prefix) {}
	Shape(const char shape_prefix, const std::vector<Vecteur2D>& point_list) : point_list(point_list), color(0), shape_prefix(shape_prefix) {}
	virtual ~Shape() {}

	/**
	 * @brief Accepter le visiteur V. Utilser dans le contexte du DP visitor
	 * Fonction normalement virtuelle pure, mais besoin d'utiliser constructeur dans fonction importBase dans classe ImporterCustom
	*  Accepte le visiteur V pour les COR
	 * @param V 
	*/
	virtual void accept(VisitorShape *V) const {};

	const int32_t get_color() const { return color; }
	void set_color(const int32_t& C) { color = C; }
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

	/**
	 * @brief Applique une rotation en fonction d'un angle rad et d'un point invariant sur tous
	 * les points de la forme
	 * @param rad 
	 * @param invariant 
	*/
	void rotation_forme(const double rad, const Vecteur2D& invariant) {
		for (auto& i : point_list)
			i = rotation(i, rad, invariant);
	}

	/**
	 * @brief Applique une homotetie sur tous les points de la forme
	 * @param k 
	 * @param invariant 
	*/
	void homotetie_forme(const double k, const Vecteur2D& invariant) {
		for (auto& i : point_list)
			i = homotetie(i, k, invariant);
	}

	/**
	 * @brief Applique une translation par rapport à u sur tous les points de la forme
	 * @param u 
	*/
	void translation_forme(const Vecteur2D& u) {
		for (auto& i : point_list)
			i = translation(i, u);
	}

	/**
	 * @brief Opérateur : Retourne le point à l'indice i
	 * @param i 
	 * @return
	*/
	const Vecteur2D& operator[] (unsigned int i) const { return point_list[i]; }

	/**
	 * @brief Opérateur : Retourne la forme dans une string
	*/
	operator std::string() const {
		std::ostringstream res;
		res << shape_prefix;
		res << " "
			<< to_string_color()
			<< " "
			<< to_string(point_list.size())
			<< " "
			<< to_string_points()
			<< to_string_custom_attributes();

		return res.str();
	}

	/**
	 * @brief Retourne le code RGB en string
	 * @return
	*/
	std::string to_string_color() const {
		std::ostringstream res;

		res << +((uint8_t)(color >> 24));
		res << " ";
		res << +((uint8_t)(color >> 16));
		res << " ";
		res << +((uint8_t)(color >> 8));

		return res.str();
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