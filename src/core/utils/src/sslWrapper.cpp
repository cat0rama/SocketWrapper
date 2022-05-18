#include "sslWrapper.hpp"

namespace socketlib
{
	SSLWrapper::SSLWrapper(eMachineType _type) : is_init(true)
	{
		SSL_library_init();
		SSL_load_error_strings();
		OpenSSL_add_all_algorithms();

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

		if (!ssl_ctx) {
			std::printf("%s %d", "failed to init SSL context", ERR_get_error());
			is_init = false;
		}

		if (!(ssl_obj = SSL_new(ssl_ctx))) {
			std::printf("%s %d", "failed to init SSL", ERR_get_error());
			is_init = false;
		}
	}

	SSLWrapper::~SSLWrapper()
	{
		ERR_free_strings();
		EVP_cleanup();
		SSL_free(ssl_obj);
		SSL_CTX_free(ssl_ctx);
	}

	SSLWrapper::ssl* SSLWrapper::operator*() const
	{
		return ssl_obj;
	}

	int SSLWrapper::Shutdown() const
	{
		return SSL_shutdown(ssl_obj);
	}

	int SSLWrapper::SetCert(const char* _cert_file_path) const
	{
		return SSL_CTX_use_certificate_file(ssl_ctx, _cert_file_path, SSL_FILETYPE_PEM);
	}

	int SSLWrapper::SetKey(const char* _key_file_path) const
	{
		return SSL_CTX_use_PrivateKey_file(ssl_ctx, _key_file_path, SSL_FILETYPE_PEM);
	}

	std::size_t SSLWrapper::GetError() const
	{
		return ERR_get_error();
	}

	const SSLWrapper::ssl_context* SSLWrapper::GetSSLCtx() const
	{
		return ssl_ctx;
	}
}
