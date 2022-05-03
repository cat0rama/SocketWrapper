#include <socket_exception.hpp>
#include <clientTcp.hpp>
#include <sslClient.hpp>
#include <cstdint>
#include <memory>

using namespace socketlib;

int main(int argc, char** argv)
{
	try {
		//SSLClient a("127.0.0.1", 4444);

	}
	catch (const socket_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const std::exception& er) {
		std::printf("%s", er.what());
	}

	system("pause");
}