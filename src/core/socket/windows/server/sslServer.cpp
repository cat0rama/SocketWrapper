#include "sslServer.hpp"

namespace socketlib
{
	SSLServer::SSLServer(const char* _ip, std::uint16_t _port, eAddrType _type) 
		: ServerTcp(_ip, _port, _type)
	{	}
						
	SSLServer::~SSLServer()
	{	}

	len_t SSLServer::Send(cock _sock, const char* _buf, int _flags) const
	{
		return SSL_write(*ssl, _buf, strlen(_buf));
	}
	
	len_t SSLServer::Receive(cock _sock, char* _buf, len_t _buf_len, int _flags) const
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