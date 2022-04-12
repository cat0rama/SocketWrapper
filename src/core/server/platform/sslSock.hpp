#include "serverTcp.hpp"

#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

namespace socketlib
{
	class SSLsock : public ServerTcp 
	{
	public:
		SSLsock();

		~SSLsock();
	public:

	private:
		
	};
}