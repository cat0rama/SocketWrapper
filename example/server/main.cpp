#include <socket_exception.hpp>
#include <serverTcp.hpp>
#include <serverUdp.hpp>
#include <iostream>

using namespace socketlib;

int main(int argc, char** argv)
{
	try {
        ServerTcp a("127.0.0.1", 4444);

        a.Bind();

        a.Listen();

        int sock = 0;

        if((sock = a.Accept()) < 0){
            std::cout << "error to accept : " << sock << std::endl;
        }

        char buff[100] = {0};

        std::cout << "Socket: " << sock << std::endl;
        std::cout << "Recv Result: " << a.Receive(sock, buff, 100) << std::endl;
        std::cout << "Buffer: " << buff << std::endl;
	}
	catch (const socket_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const std::exception& er) {
		std::printf("%s", er.what());
	}
    getchar();
}
