#ifndef _IMPORTERCUSTOMCIRCLE_HPP_
#define _IMPORTERCUSTOMCIRCLE_HPP_

#include "ImporterCustom.hpp"

class ImporterCustomCircle : public ImporterCustom {
protected:
	Shape* import(const std::string& line) const {
		const char* line_ptr = line.c_str();
		double rayon;
		
		Shape* res = importBase(&line_ptr);
		if (res->get_prefix() != 'C' || sscanf(line_ptr, "%lf", &rayon) != 1) {
			delete res;
			return nullptr;
		}

		return new Circle(res, rayon);
	}

public:
	ImporterCustomCircle(ImporterCustom* next) : ImporterCustom(next) {}
};


#endif //_IMPORTERCUSTOMCIRCLE_HPP_