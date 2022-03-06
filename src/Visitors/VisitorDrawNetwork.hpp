#ifndef _VISITORDRAWNETWORK_HPP_
#define _VISITORDRAWNETWORK_HPP_

#include "Utils/SocketDrawClient.hpp"
#include "Utils/Erreur.hpp"
#include "Utils/WindowProperties.hpp"
#include "VisitorShape.hpp"
#include "Shapes/Circle.hpp"
#include "Shapes/Triangle.hpp"
#include "Shapes/Segment.hpp"
#include "Shapes/Polygone.hpp"
#include "Shapes/Group.hpp"
#include <iostream>
#include <stdexcept>

class VisitorDrawNetwork : public VisitorShape {
private:
	SOCKET sock;
	std::string data;
public:
	VisitorDrawNetwork(const std::string& host, const int port, const WindowProperties &W) { 
		description = "Drawing over the network : ";
		sock = SocketDrawClient::get_instance().create_socket(host.c_str(), port);

		data += (std::string)W;

		send_draw_command();
	}

	~VisitorDrawNetwork() { SocketDrawClient::get_instance().close_sock(sock); }

	void send_draw_command() {
		SocketDrawClient::get_instance().send_data(sock, data.c_str());
		data.clear();
	}
	
	void visitCircle(const Circle &C) override {
		std::cout << description << C << std::endl;
		data += (std::string)C;
		data += '\n';
	}
	void visitPolygone(const Polygone &P) override {
		std::cout << description << P << std::endl;
		data += (std::string)P;
		data += '\n';
	}
	void visitSegment(const Segment &S) override {
		std::cout << description << S << std::endl;
		data += (std::string)S;
		data += '\n';
	}
	void visitTriangle(const Triangle &T) override {
		std::cout << description << T << std::endl;
		data += (std::string)T;
		data += '\n';
	}
	void visitGroup(const Group& G) override {
		std::cout << description;

		for (auto i : G.shape_list) {
			data += (std::string)*i;
			data += '\n';
		}
	}
};

#endif //_VISITORDRAWNETWORK_HPP_