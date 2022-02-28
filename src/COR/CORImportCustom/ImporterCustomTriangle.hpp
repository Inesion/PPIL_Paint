#ifndef _IMPORTERCUSTOMTRIANGLE_HPP_
#define _IMPORTERCUSTOMTRIANGLE_HPP_

#include "ImporterCustom.hpp"

class ImporterCustomTriangle : public ImporterCustom {
protected:
	Shape* import(const std::string& line) const {
		const char* line_ptr = line.c_str();

		Shape* res = importBase(&line_ptr);
		if (res->get_prefix() != 'S') {
			delete res;
			return nullptr;
		}

		return new Triangle(res);
	}

public:
	ImporterCustomTriangle(ImporterCustom* next) : ImporterCustom(next) {}
};

#endif //_IMPORTERCUSTOMTRIANGLE_HPP_