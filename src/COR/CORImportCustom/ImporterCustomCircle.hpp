#ifndef _IMPORTERCUSTOMCIRCLE_HPP_
#define _IMPORTERCUSTOMCIRCLE_HPP_

#include "ImporterCustom.hpp"

class ImporterCustomCircle : public ImporterCustom {
protected:
	Shape* import(const char* line) const {
		return nullptr;
	}

public:
	ImporterCustomCircle(ImporterCustom* next) : ImporterCustom(next) {}
};


#endif //_IMPORTERCUSTOMCIRCLE_HPP_