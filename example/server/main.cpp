#include <socket_exception.hpp>
#include <sslServer.hpp>
#include <iostream>

using namespace socketlib;

int main(int argc, char** argv)
{
	try {
		SSLServer srv("127.0.0.1", 4444);

		if (srv.GetSSL().SetCert("cert.pem") <= 0) {
			std::cout << "Error to set cert" << std::endl;
		}
		
		if (srv.GetSSL().SetKey("key.pem") <= 0) {
			std::cout << "Error to set key" << std::endl;
		}

		srv.Bind();

		srv.Listen();

		cock cl_sock = 0;

		if (!(cl_sock = srv.Accept())) {
			std::cout << "Error to accept client" << std::endl;
		}

		if (srv.SSLAccept() <= 0) {
			std::cout << "SSLaccept error: " << ERR_get_error() << std::endl;
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