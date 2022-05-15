#ifndef CLIENT_UDP_HPP_
#define CLIENT_UDP_HPP_

#include "ISocket.hpp"

namespace socketlib
{
	class ClientUdp : public ISocket
	{
	public:
		ClientUdp(const char* _ip, uint16_t _port, eAddrType _addr_type = eAddrType::IPv4);

		explicit ClientUdp(const ClientUdp& _client);

		~ClientUdp() = default;
	public:
		int Send(const char* _buf, int _buf_len, int _flags = 0) const;

		int Receive(char* _buf, int _buf_len, sockaddr_in* _from, int _flags = 0) const;
	public:
		ClientUdp& operator=(const ClientUdp& _client);
	};
}

#endif // !CLIENT_UDP_HPP_
