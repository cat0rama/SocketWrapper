#ifndef SSLWRAPPER_HPP_
#define SSLWRAPPER_HPP_

#include <openssl/bio.h>	
#include <openssl/ssl.h>
#include <openssl/err.h>

#include "socket_exception.hpp"
#include "defines.hpp"
	
namespace socketlib
{
	class SSLWrapper
	{
		using ssl_context = SSL_CTX;
		using ssl = SSL;
	public:
		SSLWrapper(eMachineType _type = eMachineType::NONE);

		~SSLWrapper();
	public:
		SSLWrapper(const SSLWrapper&) = delete;
		SSLWrapper(SSLWrapper&&) = delete;

		SSLWrapper& operator=(const SSLWrapper&) = delete;
		SSLWrapper& operator=(SSLWrapper&&) = delete;
	public:
		ssl* operator*() const;
	public:
		int Shutdown() const;

		int SetCert(const char* _cert_file_path) const;

		int SetKey(const char* _key_file_path) const;

		std::size_t GetError() const;

		const ssl_context* GetSSLCtx() const;
	private:
		ssl_context* ssl_ctx;
		ssl* ssl_obj;
	public:
		bool is_init;
	};
}

#endif