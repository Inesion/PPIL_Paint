#ifndef _IMPORTERCUSTOMCIRCLE_HPP_
#define _IMPORTERCUSTOMCIRCLE_HPP_

#include "ImporterCustom.hpp"

class ImporterCustomCircle : public ImporterCustom {
protected:
	Shape* import(const char* line) const {
		Color col;
		double rayon;
		char* token;
		char delim[2] = " ";

		token = strtok(line, delim);

		if (token[0] == 'C') {
			token = strtok(nullptr, delim);
			col = atoi(token);
			token = strtok(nullptr, delim) 
		}
		else {
			return nullptr;
		}
	}

public:
	ImporterCustomCircle(ImporterCustom* next) : ImporterCustom(next) {}
};


#endif //_IMPORTERCUSTOMCIRCLE_HPP_