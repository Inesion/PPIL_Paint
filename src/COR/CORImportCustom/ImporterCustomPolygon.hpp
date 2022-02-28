#ifndef _IMPORTERCUSTOMPOLYGON_HPP_
#define _IMPORTERCUSTOMPOLYGON_HPP_

#include "ImporterCustom.hpp"

class ImporterCustomPolygon : public ImporterCustom {
protected:
	Shape* import(const std::string& line) const {
		const char* line_ptr = line.c_str();

		Shape* res = importBase(&line_ptr);
		if (res->get_prefix() != 'P') {
			delete res;
			return nullptr;
		}

		return new Polygon(res);
	}

public:
	ImporterCustomPolygon(ImporterCustom* next) : ImporterCustom(next) {}
};


#endif //_IMPORTERCUSTOMPOLYGON_HPP_