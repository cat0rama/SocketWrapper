#include "sslServer.hpp"

namespace socketlib
{
	SSLServer::SSLServer()
	{	}
						
	SSLServer::~SSLServer()
	{	}

	len_t SSLServer::_send(cock _sock, const char* _buf, int _flags) const
	{
		return {};
	}

	len_t SSLServer::_recv(cock _sock, char* _buf, len_t _buf_len, int _flags) const
	{
		return {};
	}
}