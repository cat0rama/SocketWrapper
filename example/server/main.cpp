#include <socket_exception.hpp>
#include <sslServer.hpp>
#include <cstdint>
#include <memory>
#include <iostream>

using namespace socketlib;

int main(int argc, char** argv)
{
	try {
		SSLServer srv("127.0.0.1", 4444);

		srv._bind();

		srv._listen();

		if (srv.get_ssl().set_ssl_cert("path") <= 0) {
			std::printf("error");
		}
		
		if (srv.get_ssl().set_private_key("path") <= 0) {
			std::printf("error");
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