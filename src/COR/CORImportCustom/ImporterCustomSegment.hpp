#ifndef _IMPORTERCUSTOMSEGMENT_HPP_
#define _IMPORTERCUSTOMSEGMENT_HPP_

#include "ImporterCustom.hpp"

class ImporterCustomSegment : public ImporterCustom {
protected:
	Shape* import(const std::string& line) const {
		const char* line_ptr = line.c_str();

		Shape* res = importBase(&line_ptr);
		if (res->get_prefix() != 'S') {
			delete res;
			return nullptr;
		}

		return new Segment(res);
	}

public:
	ImporterCustomSegment(ImporterCustom* next) : ImporterCustom(next) {}
};

#endif //_IMPORTERCUSTOMSEGMENT_HPP_