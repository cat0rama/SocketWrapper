#include <socket_exception.hpp>
#include <clientTcp.hpp>
#include <cstdint>
#include <memory>

using namespace socketlib;

class ExampleClient
{
public:
	ExampleClient(const char* _ip, std::uint16_t _port)
	{
		clt = std::make_unique<ClientTcp>(_ip, _port);
	}

	ExampleClient()
	{	}

	~ExampleClient() = default;
public:
	void start()
	{
		
	}
private:
	std::unique_ptr<ClientTcp> clt;
};

int main()
{
	try {

	}
	catch (const socket_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const std::exception& er) {
		std::printf("%s", er.what());
	}

	system("pause");
}