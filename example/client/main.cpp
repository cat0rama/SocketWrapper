#include <socket_exception.hpp>
#include <clientTcp.hpp>
#include <clientUdp.hpp>
#include <iostream>

using namespace socketlib;

int main(int argc, char** argv)
{
	try {
        ClientTcp a("127.0.0.1", 4444);

        if(a.Connect() < 0){
            std::cout << "error to connect" << std::endl;
        }

        std::cout << "Send Result: " << a.Send("hello") << std::endl;
	}
	catch (const socket_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const std::exception& er) {
		std::printf("%s", er.what());
	}
	getchar();
}
