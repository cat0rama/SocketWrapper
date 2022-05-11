#ifndef CLIENT_UDP_HPP_
#define CLIENT_UDP_HPP_

#include "ISocket.hpp"

namespace socketlib
{
	class ClientUdp : public ISocket 
	{
		explicit ClientUdp(const char* _ip, uint16_t _port, eAddrType _addr_type = eAddrType::IPv4);
		
		~ClientUdp();
	public:
		virtual len_t Send(cock _sock, const char* _buf, sockaddr _to, int _to_len, int _flags = 0) const;

		virtual len_t Receive(cock _sock, const char* _buf, sockaddr _from, int _from_len, int _flags = 0) const;
	};
}

#endif // !CLIENT_UDP_HPP_
