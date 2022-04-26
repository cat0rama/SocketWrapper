#include <socket_exception.hpp>
#include <serverTcp.hpp>
#include <sslServer.hpp>
#include <cstdint>
#include <memory>
#include <iostream>

using namespace socketlib;

class ExampleServer
{
public:
	ExampleServer(const char* _ip, std::uint16_t _port)
	{	
		srv = std::make_unique<ServerTcp>(_ip, _port);
	}

	ExampleServer() = default;

	~ExampleServer() = default;
public:
	void start() const
	{
		srv->_bind();
	}
public:
	std::unique_ptr<ServerTcp> srv;
};

int main(int argc, char** argv)
{
	try {
		ServerTcp a("127.0.0.1", 4444);

		a._bind();

		a._listen();

		cock soc;

		if (soc = a._accept()) {
			std::printf("%s %zu", "connected! sock: \n", soc);
		}

		char buffer[100] = { 0 };

		auto recv_result = a._recv(soc, buffer, sizeof(buffer));

		if (recv_result == SOCKET_ERROR) {
			std::cout << "WsaError: " << WSAGetLastError();
		}

		std::cout << buffer << std::endl;
	}
	catch (const socket_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const std::exception& er) {
		std::printf("%s", er.what());
	}

	system("pause");
}