#include <socket_exception.hpp>
#include <clientTcp.hpp>
#include <clientUdp.hpp>
#include <iostream>

using namespace socketlib;

int main(int argc, char** argv)
{
	try {
		ClientUdp a("127.0.0.1", 4444);
		char arr[] = "hello";

		while (1) {
			std::cout << a.Send(arr, sizeof(arr));
			Sleep(2000);
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