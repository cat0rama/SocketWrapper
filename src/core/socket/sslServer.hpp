#ifndef SSLSERVER_HPP_
#define SSLSERVER_HPP_

#include "serverTcp.hpp"
#include "SSLPtr.hpp"

namespace socketlib
{
	class SSLServer : public ServerTcp 
	{
	public:
		SSLServer(const char* _ip, std::uint16_t _port, eAddrType _type = eAddrType::IPv4);

		~SSLServer();
	public:
		len_t _send(cock _sock, const char* _buf, int _flags = 0) const override;

		len_t _recv(cock _sock, char* _buf, len_t _buf_len, int _flags = 0) const override;

		int ssl_accept() const;

		const SSLPtr& get_ssl() const;
	private:
		SSLPtr ssl = eMachineType::SERVER;
	};
}

#endif	