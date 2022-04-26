#ifndef SSLPTR_HPP_
#define SSLPTR_HPP_

#include <openssl/bio.h>	
#include <openssl/ssl.h>
#include <openssl/err.h>

#include "socket_exception.hpp"
#include "defines.hpp"

namespace socketlib
{
	class SSLPtr
	{
		using ssl_context = SSL_CTX;
		using ssl = SSL;
	public:
		SSLPtr(eMachineType _type = eMachineType::NONE);

		~SSLPtr();
	public:
		SSLPtr(const SSLPtr&) = delete;
		SSLPtr(SSLPtr&&) = delete;

		SSLPtr& operator=(const SSLPtr&) = delete;
		SSLPtr& operator=(SSLPtr&&) = delete;
	public:
		ssl* operator*() const;
	public:
		int shutdown() const;

		int set_ssl_cert(const char* _cert_file_path) const;

		int set_private_key(const char* _key_file_path) const;
	private:
		ssl_context* ssl_ctx;
		ssl* ssl_obj;
		bool is_init;
	};
}

#endif