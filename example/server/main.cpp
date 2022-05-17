#include <socket_ptr.hpp>
#include <serverTcp.hpp>
#include <iostream>

using namespace socketlib;

class Server
{
public:
	Server(const char* _ip, uint16_t _port, eAddrType _addr = eAddrType::IPv4)
	{
		serv = MakeSocketPtr<ServerTcp>(_ip, _port, _addr);

		serv->Bind();

		serv->Listen();

		std::cout << "Server start listen at: " << _ip << ":" << _port << std::endl;
	}

	~Server() = default;
public:
	void MessageHandler()
	{
		auto client = serv->Accept();

		if (client < 0) {
			std::cout << "Fail to accept client!" << std::endl;
			return;
		}
		else {
			std::cout << "Client has been accepted!" << std::endl;
		}

		while (1) {
			//do recv message
		}
	}
private:
	SocketPtr<ServerTcp> serv;
};

int main(int argc, char** argv)
{
	try {
		Server s("127.0.0.1", 4444);

		s.MessageHandler();
	}
	catch (const socket_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const std::exception& er) {
		std::printf("%s", er.what());
	}
	getchar();
}
