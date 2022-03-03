#ifndef _IMPORTERCUSTOMCIRCLE_HPP_
#define _IMPORTERCUSTOMCIRCLE_HPP_

#include "ImporterCustom.hpp"

class ImporterCustomCircle : public ImporterCustom {
protected:
	Shape* import(const std::string& line) const {
		const char* line_ptr = line.c_str();
		double rayon;

		if (line[0] != 'C') return nullptr;
		
		Shape* res = importBase(&line_ptr);

		if (res == nullptr) return nullptr;

		if (sscanf(line_ptr, "%lf", &rayon) != 1) {
			delete res;
			return nullptr;
		}

		return new Circle(*res, rayon);
	}
};


#endif //_IMPORTERCUSTOMCIRCLE_HPP_