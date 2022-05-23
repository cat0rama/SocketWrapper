#ifndef SERVER_UDP_HPP_
#define SERVER_UDP_HPP_

#include "ISocket.hpp"

namespace socketlib
{
	/*!
	\brief Derived class from ISocket, implements UDP server logic

	This class inherits the initialization part (ISocket),
	respectively adding its own part of the code,
	characteristic of the UDP protocol,
	thereby implementing the logic of the UDP client
	*/

	class ServerUdp : public ISocket
	{
	public:
		ServerUdp(const char* _ip, uint16_t _port, eAddrType _addr_type = eAddrType::IPv4);

		explicit ServerUdp(const ServerUdp& _serv);

		~ServerUdp() = default;
	public:
		void Bind() const;

		int Send(const char* _buf, len_t _buf_len, int _flags = 0) const;

		int Receive(char* _buf, len_t _buf_len, sockaddr_in* _from, int _flags = 0) const;
	public:
		ServerUdp& operator=(const ServerUdp& _client);
	};
}

#endif // !SERVER_UDP_HPP_
