#ifndef SSLCLIENT_HPP_
#define SSLCLIENT_HPP_

#include <clientTcp.hpp>

namespace socketlib
{
	class SSLClient : public ClientTcp
	{
	public:
		SSLClient(const char* _ip, std::uint16_t port);

		~SSLClient();
	public:

	};
}

#endif // !SSLCLIENT_HPP_
