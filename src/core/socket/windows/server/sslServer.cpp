#include "sslServer.hpp"

namespace socketlib
{
	SSLServer::SSLServer(const char* _ip, std::uint16_t _port, eAddrType _type) 
		: ServerTcp(_ip, _port, _type)
	{	}
						
	SSLServer::~SSLServer()
	{	}

	int SSLServer::SSLSend(const char* _buf) const
	{
		return SSL_write(*ssl, _buf, strlen(_buf));
	}

	int SSLServer::SSLReceive(char* _buf, int _buf_len) const
	{
		return SSL_read(*ssl, _buf, _buf_len);
	}

	std::size_t SSLServer::GetError() const
	{
		return ERR_get_error();
	}

	int SSLServer::SSLAccept() const
	{
		return SSL_accept(*ssl);
	}

 	const SSLPtr& SSLServer::GetSSL() const
	{
		return ssl;
	}
}