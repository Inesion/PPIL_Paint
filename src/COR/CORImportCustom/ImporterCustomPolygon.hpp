#ifndef _IMPORTERCUSTOMPOLYGON_HPP_
#define _IMPORTERCUSTOMPOLYGON_HPP_

#include "ImporterCustom.hpp"

class ImporterCustomPolygon : public ImporterCustom {
protected:
	Shape* import(const std::string& line) const {
		const char* line_ptr = line.c_str();

		if (line[0] != 'P') return nullptr;

		Shape* res = importBase(&line_ptr);

		if (res == nullptr) return nullptr;

		return new Polygon(*res);
	}
};


#endif //_IMPORTERCUSTOMPOLYGON_HPP_