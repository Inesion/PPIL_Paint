#ifndef _IMPORTERCUSTOMGROUP_HPP_
#define _IMPORTERCUSTOMGROUP_HPP_

#include "ImporterCustom.hpp"

class ImporterCustomGroup : public ImporterCustom {
protected:
	Shape* import(const std::string& lines) const {
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


#endif //_IMPORTERCUSTOMGROUP_HPP_