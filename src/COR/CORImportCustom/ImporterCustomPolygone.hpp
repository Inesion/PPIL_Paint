#ifndef _IMPORTERCUSTOMPOLYGONE_HPP_
#define _IMPORTERCUSTOMPOLYGONE_HPP_

#include "ImporterCustom.hpp"

class ImporterCustomPolygone : public ImporterCustom {
protected:
	Shape* import(const std::string& line) const {
		const char* line_ptr = line.c_str();

		if (line[0] != 'P') return nullptr;

		Shape* res = importBase(&line_ptr);

		if (res == nullptr) return nullptr;

		return new Polygone(*res);
	}
};


#endif //_IMPORTERCUSTOMPOLYGONE_HPP_