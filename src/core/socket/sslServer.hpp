#ifndef SSLSERVER_HPP_
#define SSLSERVER_HPP_

#include "serverTcp.hpp"

#include <openssl/bio.h>	
#include <openssl/ssl.h>
#include <openssl/err.h>

namespace socketlib
{
	class SSLServer : public ServerTcp 
	{
	public:
		SSLServer();

		~SSLServer();
	public:
		len_t _send(cock _sock, const char* _buf, int _flags = 0) const override;

		len_t _recv(cock _sock, char* _buf, len_t _buf_len, int _flags = 0) const override;
	private:
		
	};
}

#endif	