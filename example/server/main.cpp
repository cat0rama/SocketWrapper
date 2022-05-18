#include <socket_ptr.hpp>
#include <serverTcp.hpp>
#include <cstring>
#include <iostream>

using namespace socketlib;

constexpr len_t buffer_size = 1024;

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

		char* buffer = new char[buffer_size]();
		buffer[buffer_size - 1] = '\0';

		if (client < 0) {
			throw socket_error("Failed to accept client");
		} else {
			std::cout << "Client has been accepted!" << std::endl;
		}

		while (client) {
			auto re_sz = serv->Receive(client, buffer, buffer_size);
			
			if (re_sz <= 0) {
				std::cout << "Receive Error!" << std::endl;
				break;
			}

			std::cout << "Client message: " << buffer << std::endl;
			std::cout << re_sz << std::endl;
			memset(buffer, 0, buffer_size);
		}
		
		delete[] buffer;
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
