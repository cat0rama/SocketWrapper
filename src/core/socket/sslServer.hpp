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
		void send(cock _sock, const char* _buf, int _flags = 0);

		void recv(char* _buf, len_t _buf_len, int _flags = 0);
	private:
		
	};
}

#endif	