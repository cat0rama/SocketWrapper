#include <iostream>
#include <string>
#include <clientTcp.hpp>
#include <socket_ptr.hpp>

using namespace socketlib;

class Client
{
public:
	Client(const char* _ip, uint16_t _port, eAddrType _addr = eAddrType::IPv4)
	{
		clt = MakeSocketPtr<ClientTcp>(_ip, _port, _addr);

		std::cout << "Client start listen at: " << _ip << ":" << _port << std::endl;
	}

	~Client() = default;
public:
	void MessageHandler()
	{
		if (clt->Connect() < 0) {
			throw socket_error("Connect error! Time out");
		}

		std::cout << "Connect succesful!" << std::endl;

		while (1) {
			std::string str;

			std::getline(std::cin, str);

            clt->Send(str.c_str());
		}
	}
private:
	SocketPtr<ClientTcp> clt;
};

int main(int argc, char** argv)
{
	try {
		Client cl("127.0.0.1", 4444);

		cl.MessageHandler();
	}
	catch (const socket_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const std::exception& er) {
		std::printf("%s", er.what());
	}
	getchar();
}
