#ifndef SSL_SERVER_HPP_
#define SSL_SERVER_HPP_

#include "serverTcp.hpp"
#include "SSLPtr.hpp"

namespace socketlib
{
	class SSLServer : public ServerTcp 
	{
	public:
		SSLServer(const char* _ip, std::uint16_t _port, eAddrType _type = eAddrType::IPv4);

		~SSLServer() = default;
	public:
		SSLServer(const SSLServer&) = delete;
		SSLServer(SSLServer&&) = delete;

		SSLServer& operator=(const SSLServer&) = delete;
		SSLServer& operator=(SSLServer&&) = delete;
	public:
		int SSLSend(const char* buf) const;

		int SSLReceive(char* _buf, int _buf_len) const;

		std::size_t GetError() const;

		int SSLAccept() const;

		const SSLPtr& GetSSL() const;
	private:
		SSLPtr ssl = eMachineType::SERVER;
	};
}

#endif	