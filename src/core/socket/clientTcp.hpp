#ifndef CLIENT_TCP_HPP_
#define CLIENT_TCP_HPP_

#include "ISocket.hpp"

namespace socketlib
{
	class ClientTcp : public ISocket
	{
	public:
		ClientTcp() = default;

		ClientTcp(const char* _ip, std::uint16_t _port);
		
		~ClientTcp() = default;
	public:
		void _connect();

		len_t _send(cock _sock, const char* _buf, int _flags = 0) const override;

		len_t _recv(char* _buf, len_t _buf_len, int _flags = 0) const override;
	};
}

#endif // !CLIENT_TCP_HPP_
