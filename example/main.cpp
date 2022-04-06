#include <serverTcp.hpp>
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
	ServerTcp f;
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

};

int main()
{
	try {

	}
	catch (const socket_error& er) {
		std::cout << er.what() << ": " << er.error_code << std::endl;
	}
	system("pause");
}