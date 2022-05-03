#include <socket_exception.hpp>
#include <sslServer.hpp>
#include <iostream>
#include <stdio.h>
#include <memory>
#include <iostream>

using namespace socketlib;

int main(int argc, char** argv)
{
	try {
		SSLServer srv("127.0.0.1", 4444);

		if (srv.GetSSL().SetKey("domain.key") <= 0) {
			throw ssl_error("error to get private key");
		}

		if (srv.GetSSL().SetCert("cert.crt") <= 0) {
			throw ssl_error("error to get certifivate");
		}

		srv.Bind();

		srv.Listen();

		auto client = srv.Accept();

		if (client < 0) {
			std::puts("error to accept connection");
		}

		SSL_set_fd(*srv.GetSSL(), client);

		if (srv.SSLAccept() <= 0) {
			std::puts("error to SSLAccept");
		}
		else {
			srv.SSLSend("Hello");
		}
	}
	catch (const socket_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const ssl_error& er) {
		std::printf("%s: %d", er.what(), er.get_code());
	}
	catch (const std::exception& er) {
		std::printf("%s", er.what());
	}

	system("pause");
}