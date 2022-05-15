#ifndef SERVER_UDP_HPP_
#define SERVER_UDP_HPP_

#include "ISocket.hpp"

namespace socketlib
{
	class ServerUdp : public ISocket
	{
	public:
		ServerUdp(const char* _ip, uint16_t _port, eAddrType _addr_type = eAddrType::IPv4);

		explicit ServerUdp(const ServerUdp& _serv);

		~ServerUdp() = default;
	public:
		void Bind() const;

		int Send(const char* _buf, int _buf_len, int _flags = 0) const;

		int Receive(char* _buf, int _buf_len, sockaddr_in* _from, int _flags = 0) const;
	public:
		ServerUdp& operator=(const ServerUdp& _client);
	};
}

#endif // !SERVER_UDP_HPP_
