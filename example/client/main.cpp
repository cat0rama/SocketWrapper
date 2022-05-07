#include <socket_exception.hpp>
#include <sslClient.hpp>
#include <iostream>

using namespace socketlib;

int main(int argc, char** argv)
{
	try {
		SSLClient clt("127.0.0.1", 4444);

		if (clt.GetSSL().SetCert("cert.pem") <= 0) {
			std::cout << "Error to set cert" << std::endl;
		}

		if (clt.GetSSL().SetKey("key.pem") <= 0) {
			std::cout << "Error to set key" << std::endl;
		}

		if (clt.Connect() <= 0) {
			std::cout << "Failed to connect" << std::endl;
		}

		if (clt.SSLConnect() <= 0) {
			std::cout << "Failed to SSLConnect" << std::endl;
		}
	}
	catch (const ssl_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const socket_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const std::exception& er) {
		std::printf("%s", er.what());
	}

	system("pause");
}