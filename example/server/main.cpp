#include <socket_exception.hpp>
#include <serverTcp.hpp>
#include <serverUdp.hpp>
#include <iostream>

using namespace socketlib;

int main(int argc, char** argv)
{
	try {
		ServerUdp a("127.0.0.1", 4444);
		char arr[100] = { 0 };

		sockaddr_in client_addr;
		int addr_size = sizeof(client_addr);

		a.Bind();

		while (1) {
			std::cout << a.Receive(arr, 100 - 1, &client_addr);

			std::cout << arr << std::endl;
			
			std::cout << WSAGetLastError();

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