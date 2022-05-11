#ifndef SERVER_UDP_HPP_
#define SERVER_UDP_HPP_

#include "ISocket.hpp"

namespace socketlib
{
	class ServerUdp : ISocket
	{
	public:
		explicit ServerUdp(const char* _ip, uint16_t _port, eAddrType _addr_type = eAddrType::IPv4);
		
		~ServerUdp();
	public:
		void bind() const;

		virtual len_t Send(cock _sock, const char* _buf, sockaddr _to, int _to_len, int _flags = 0) const;

		virtual len_t Receive(cock _sock, const char* _buf, sockaddr _from, int _from_len, int _flags = 0) const;
	};
}

#endif // !SERVER_UDP_HPP_
