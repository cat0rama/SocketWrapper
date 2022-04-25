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
		SSLPtr(eMachineType _type = eMachineType::NONE)
		{
			{
				SSL_load_error_strings();
				SSL_library_init();
				OpenSSL_add_all_algorithms();
			}

			switch (_type)
			{
			case eMachineType::SERVER:
				ssl_ctx = SSL_CTX_new(SSLv23_server_method());
				break;
			case eMachineType::CLIENT:
				ssl_ctx = SSL_CTX_new(SSLv23_client_method());
				break;
			default:
				ssl_ctx = SSL_CTX_new(SSLv23_method());
			}

			SSL_CTX_set_options(ssl_ctx, SSL_OP_SINGLE_DH_USE);

			//здесь надо сертификат засунуть
			//здесь надо приватный ключ засунуть

			if (!ssl_ctx) {
				throw socket_error("failed to initialize SSL");
			}
		}

		~SSLPtr()
		{
			ERR_free_strings();
			EVP_cleanup();
			SSL_free(cSSL);
		}
	public:
		SSLPtr(const SSLPtr&) = delete;
		SSLPtr(SSLPtr&&) = delete;

		SSLPtr& operator=(const SSLPtr&) = delete;
		SSLPtr& operator=(SSLPtr&&) = delete;
	public:
		ssl* operator*() const
		{
			return cSSL;
		}
	public:
		int shutdown() const
		{
			SSL_shutdown(cSSL);
		}
	private:
		ssl_context* ssl_ctx;
		ssl* cSSL;
	};
}