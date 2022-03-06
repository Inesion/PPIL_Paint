#ifndef _SOCKETDRAWCLIENT_HPP_
#define _SOCKETDRAWCLIENT_HPP_

#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <stdexcept>

class SocketDrawClient {
private:
	SocketDrawClient() {
		WSADATA wsa_data;

		if (WSAStartup(MAKEWORD(2, 2), &wsa_data) < 0)
			throw std::runtime_error("Winsock startup error");
	}

	static SocketDrawClient* instance;

public:
	~SocketDrawClient() { WSACleanup(); }

	static SocketDrawClient& get_instance() {
		if (instance == nullptr)
			instance = new SocketDrawClient();

		return *instance;
	}

	SOCKET create_socket(const char* host, int port) {
		SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

		struct hostent* hostinfo = NULL;
		SOCKADDR_IN sin = { 0 };

		hostinfo = gethostbyname(host);
		if (hostinfo == NULL)
			throw std::runtime_error("Name resolution failed");

		sin.sin_addr = *(IN_ADDR*)hostinfo->h_addr;
		sin.sin_port = htons(port);
		sin.sin_family = AF_INET;

		if (connect(sock, (SOCKADDR*)&sin, sizeof(SOCKADDR)) == SOCKET_ERROR)
			throw std::runtime_error("Error trying to connect to distant host");

		return sock;
	}

	void send_data(SOCKET socket, const char* data) {
		uint32_t n_byte = send(socket, data, strlen(data), 0);

		if (n_byte < 0)
			throw std::runtime_error("Error whilst trying to send data to socket");

		std::cout << "Number of bytes sent from socket : " << n_byte << std::endl;
	}

	void close_sock(SOCKET sock) { closesocket(sock); }
};

#endif //_SOCKETDRAWCLIENT_HPP_


SocketDrawClient* SocketDrawClient::instance = nullptr;