#ifndef _IMPORTERCUSTOMTRIANGLE_HPP_
#define _IMPORTERCUSTOMTRIANGLE_HPP_

#include "ImporterCustom.hpp"

class ImporterCustomTriangle : public ImporterCustom {
protected:
	Shape* import(const std::string& line) const {
		const char* line_ptr = line.c_str();

		if (line[0] != 'T') return nullptr;

		Shape* res = importBase(&line_ptr);

		if (res == nullptr) return nullptr;

		return new Triangle(*res);
	}
};

#endif //_IMPORTERCUSTOMTRIANGLE_HPP_