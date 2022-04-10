#include <serverTcp.hpp>
#include <clientTcp.hpp>
#include <iostream>

using namespace socketlib;

class ExampleServer
{
public:
	ExampleServer(const char* _ip, std::uint16_t _port)
	{	}

	ExampleServer()
	{	}

	~ExampleServer() = default;
public:
	ServerTcp server;
};

class ExampleClient
{
public:
	ExampleClient(const char* _ip, std::uint16_t _port)
	{	}

	ExampleClient()
	{	}

	~ExampleClient() = default;
public:
	ClientTcp client;
};

int main()
{
	try {
		ServerTcp a("127.0.0.1", 4444);

		a._bind();

		a._listen();

	}
	catch (const socket_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const std::exception& er)
	{
		std::printf("%s", er.what());
	}
}