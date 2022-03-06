#ifndef _WINDOWPROPERTIES_HPP_
#define _WINDOWPROPERTIES_HPP_

#include "Erreur.hpp"

class WindowProperties {
private:
	int x, y, width, height;
	std::string title;

public:
	WindowProperties(const std::string &title, int x, int y, int height, int width) : title(title), x(x), y(y), width(width), height(height) {
	}

	operator std::string() const {
		std::ostringstream res;

		std::cout << "Debug : " << x << std::endl;

		res << title << ',' << x << ',' << y << ',' << width << ',' << height << '\n';

		return res.str();
	}
};

#endif //_WINDOWPROPERTIES_HPP_