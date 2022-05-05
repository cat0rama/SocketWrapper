#include <socket_exception.hpp>
#include <clientTcp.hpp>
#include <sslClient.hpp>
#include <cstdint>
#include <iostream>
#include <memory>

using namespace socketlib;

int main(int argc, char** argv)
{
	try {
		int sd = 0;

		SSLClient a("127.0.0.1", 4444);

		if (a.GetSSL().SetKey("domain.key") <= 0) {
			throw ssl_error("error to get private key");
		}

		if (a.GetSSL().SetCert("cert.crt") <= 0) {
			throw ssl_error("error to get certifivate");
		}

		if (a.Connect() < 0) {
			std::cout << "Error to connect!" << std::endl;
		}

		SSL_set_fd(*a.GetSSL(), sd);

		SSL_set_connect_state(*a.GetSSL());

		if (a.SSLConnect() < 0) {
			std::cout << "SSL connect error : " << ERR_get_error() << std::endl;
		}

		char buf[100] = {0};

		a.SSLReceive(buf, 100);

		std::cout << buf << std::endl;
	}
	catch (const socket_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const std::exception& er) {
		std::printf("%s", er.what());
	}

	system("pause");
}