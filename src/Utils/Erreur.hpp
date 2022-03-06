/**
classe Erreur
*/

#ifndef ERREUR_H
#define ERREUR_H

using namespace std;

#include <string>
#include <iostream>
#include <exception>

class Erreur : public exception
{
public:
	string message;
	Erreur() : message("Erreur !") { exit(-1); }
	Erreur(const string& messageErreur) : Erreur() { this->message += " " + messageErreur; exit(-1);
	}
	Erreur(const char* messageErreur) : Erreur((string)messageErreur) { exit(-1); }

	/**
	 * lance une exception si d est vide
	 * */

	inline static void testeNonVide(const void* d, const char* message);

	operator string() const { return this->message; }

	virtual const char* what() const noexcept { return ((string)(*this)).c_str(); }
};

inline ostream& operator << (ostream& os, const Erreur& erreur) { return os << (string)erreur; }

/**
 * lance une exception si d est vide
 * */

inline /*static*/ void Erreur::testeNonVide(const void* d, const char* message)
{
#ifdef DEBUG
	if (!d) throw Erreur(message);
#endif
}

#endif