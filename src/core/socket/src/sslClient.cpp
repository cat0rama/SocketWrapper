#ifndef SSL_CLIENT_HPP_
#include "sslClient.hpp"

namespace socketlib
{
	SSLClient::SSLClient(const char* _ip, std::uint16_t _port) : ClientTcp(_ip, _port)
	{
		if (!ssl.is_init) {
			throw ssl_error("failed to initialize ssl object");
		}
	}

	int SSLClient::SSLConnect() const
	{
		return SSL_connect(*ssl);
	}

	int SSLClient::SSLSend(const char* _buf) const
	{
		return SSL_write(*ssl, _buf, strlen(_buf));
	}

	int SSLClient::SSLReceive(char* _buf, int _buf_len) const
	{
		return SSL_read(*ssl, _buf, _buf_len);
	}

	const SSLPtr& SSLClient::GetSSL() const
	{
		return ssl;
	}
}

#endif // !SSL_CLIENT_HPP_
