#include <socket_exception.hpp>
#include <serverTcp.hpp>
#include <sslServer.hpp>
#include <cstdint>
#include <memory>

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

int main()
{
	try {
		ServerTcp a("127.0.0.1", 4444);

		a._bind();

		a._listen();

		if (a._accept()) {
			std::printf("%s", "connected!");
		}
	}
	catch (const socket_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const std::exception& er) {
		std::printf("%s", er.what());
	}

	system("pause");
}