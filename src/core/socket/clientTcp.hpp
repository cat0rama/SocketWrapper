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
		
		explicit ClientTcp(const ClientTcp& _client);

		~ClientTcp() = default;
	public:
		int _connect() const;

		len_t _send(cock _sock, const char* _buf, int _flags = 0) const override;

		len_t _recv(cock _sock, char* _buf, len_t _buf_len, int _flags = 0) const override;
	public:
		ClientTcp& operator=(const ClientTcp& _client);
	};
}

#endif // !CLIENT_TCP_HPP_
