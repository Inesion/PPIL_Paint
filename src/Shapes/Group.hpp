#ifndef _GROUP_HPP_
#define _GROUP_HPP_

#include "Shape.hpp"

class Group : public Shape {
public:
	std::vector<Shape*> shape_list;

	Group(const int32_t Col) : Shape('G', Col) {}

	Group(const std::vector<Shape*>& shape_list, const int32_t Col) : shape_list(shape_list), Shape('G', Col) {}

	double get_area() override {
		double res = 0;

		for (auto i : shape_list)
			res += i->get_area();

		return res;
	}

	void add_shape(Shape* S) {
		if (S != nullptr && S->is_in_group == false) {
			S->set_color(this->color);
			S->is_in_group = true;
			shape_list.push_back(S);
		}
	}

	void rotation(const double rad, const Vecteur2D& invariant) override {
		for (auto i : shape_list)
			i->rotation(rad, invariant);
	}

	void homotetie(const double k, const Vecteur2D& invariant) override {
		for (auto i : shape_list)
			i->homotetie(k, invariant);
	}

	void translation(const Vecteur2D& u) override {
		for (auto i : shape_list)
			i->translation(u);
	}

	void accept(VisitorShape* V) const override { V->visitGroup(*this); }

	/**
	 * Normalement, affiche G [nb formes], mais parsing trop complexe, on affiche juste les formes
	*/
	operator std::string() const override {
		std::ostringstream res;
		
		//res << "G " << shape_list.size() << "\n";

		for (auto i : shape_list)
			res << (std::string)*i << "\n";

		return res.str();
	}
};

#endif //_GROUP_HPP_