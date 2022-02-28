#ifndef _IMPORTERCUSTOM_HPP_
#define _IMPORTERCUSTOM_HPP_

#include "Shapes/Shape.hpp"
#include <string.h>

class ImporterCustom {
private:
	ImporterCustom* next;

protected:
	virtual Shape* import(const char* line) const = 0;

public:
	ImporterCustom(ImporterCustom *next) : next(next) {}

	virtual const Shape* importShape(const char* line) const {
		Shape* res;
		res = this->import(line);

		if (res != nullptr) {
			return res;
		}
		else {
			if (this->next != nullptr)
				return this->next->import(line);
			else
				return nullptr;
		}
	}
};

#endif //_IMPORTERCUSTOM_HPP_