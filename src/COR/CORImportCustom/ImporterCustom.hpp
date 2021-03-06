#ifndef _IMPORTERCUSTOM_HPP_
#define _IMPORTERCUSTOM_HPP_

#include "Shapes/Shape.hpp"
#include <sstream>

class ImporterCustom {
private:
	ImporterCustom* next;

protected:
	virtual Shape* import(const std::string& line) const = 0;

	static Shape* importBase(const char** line_ptr) {
		char prefix;
		int32_t color;
		int nb_points;
		unsigned int offset;
		std::vector<Vecteur2D> point_list;
		double tmp_x, tmp_y;
		char r, g, b;
		
		if (sscanf(*line_ptr, "%c %hhd %hhd %hhd %d %n", &prefix, &r, &g, &b, &nb_points, &offset) != 5)
			return nullptr;

		*line_ptr += offset;

		for (auto i = 0; i < nb_points; i++) {
			if (sscanf(*line_ptr, "(%lf, %lf) %n", &tmp_x, &tmp_y, &offset) != 2)
				return nullptr;

			point_list.push_back(Vecteur2D(tmp_x, tmp_y));

			*line_ptr += offset;
		}

		color = (unsigned char)(r) << 24 |
			(unsigned char)(g) << 16 |
			(unsigned char)(b) << 8;

		return new Shape(prefix, color, point_list);
	}

public:
	ImporterCustom() : next(nullptr) {}

	ImporterCustom* set_next(ImporterCustom* next) {
		this->next = next;

		return this->next;
	}

	virtual const Shape* importShape(const std::string& line) const {
		Shape* res;
		res = this->import(line);

		if (res != nullptr) {
			return res;
		}
		else {
			if (this->next != nullptr)
				return this->next->importShape(line);
			else
				return nullptr;
		}
	}
};

#endif //_IMPORTERCUSTOM_HPP_