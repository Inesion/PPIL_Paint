#include <sys/socket.h>

class SocketDrawClient {
private:
	int socketClient;

protected:
	SocketDrawClient() {
		socketClient = socket(AF_INET, SOCK_STREAM, 0);
	}

	static SocketDrawClient* singleton_;

public:
	SocketDrawClient(SocketDrawClient &other) = delete;

	void operator=(const SocketDrawClient &) = delete;

	static SocketDrawClient* get_instance() {
		if(singleton_ == nullptr) singleton_ = new SocketDrawClient();

		return singleton_;
	}
};

SocketDrawClient* SocketDrawClient::singleton_= nullptr;