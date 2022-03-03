#ifndef _IMPORTERCUSTOMSEGMENT_HPP_
#define _IMPORTERCUSTOMSEGMENT_HPP_

#include "ImporterCustom.hpp"

class ImporterCustomSegment : public ImporterCustom {
protected:
	Shape* import(const std::string& line) const {
		const char* line_ptr = line.c_str();

		if (line[0] != 'S') return nullptr;

		Shape* res = importBase(&line_ptr);

		if (res == nullptr) return nullptr;

		return new Segment(*res);
	}
};

#endif //_IMPORTERCUSTOMSEGMENT_HPP_