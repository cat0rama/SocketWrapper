#include "sslServer.hpp"

namespace socketlib
{
	SSLServer::SSLServer()
	{	}
						
	SSLServer::~SSLServer()
	{	}

	len_t SSLServer::_send(cock _sock, const char* _buf, int _flags) const
	{
		return SSL_write(*ssl, _buf, strlen(_buf));
	}
	
	len_t SSLServer::_recv(cock _sock, char* _buf, len_t _buf_len, int _flags) const
	{
		return SSL_read(*ssl, _buf, _buf_len);
	}

	int SSLServer::ssl_accept() const
	{
		return SSL_accept(*ssl);
	}
}