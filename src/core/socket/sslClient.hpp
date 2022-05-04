#ifndef SSLCLIENT_HPP_
#define SSLCLIENT_HPP_

#include "clientTcp.hpp"
#include "SSLPtr.hpp"

namespace socketlib
{
	class SSLClient : public ClientTcp
	{
	public:
		SSLClient(const char* _ip, std::uint16_t port);

		~SSLClient() = default;
	public:
		SSLClient(const SSLClient&) = delete;
		SSLClient(SSLClient&&) = delete;

		SSLClient& operator=(const SSLClient&) = delete;
		SSLClient& operator=(SSLClient&&) = delete;
	public:
		int SSLConnect() const;

		int SSLSend(const char* buf) const;

		int SSLReceive(char* _buf, int _buf_len) const;

		const SSLPtr& GetSSL() const;
	private:
		SSLPtr ssl = eMachineType::CLIENT;
	};
}

#endif // !SSLCLIENT_HPP_
