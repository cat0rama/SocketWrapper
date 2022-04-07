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
		ServerTcp a("127.0.0.1", 4343);

		a._bind();
	}
	catch (const socket_error& er) {
		std::cout << er.what() << ": " << er.error_code << std::endl;
	}
	getchar();
}