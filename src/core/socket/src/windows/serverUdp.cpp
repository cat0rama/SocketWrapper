#include "serverUdp.hpp"
#include "socket_exception.hpp"

namespace socketlib
{
	ServerUdp::ServerUdp(const char* _ip, uint16_t _port, eAddrType _addr_type): ISocket(_ip, _port, _addr_type)
	{	
		if (!is_init) {
			throw socket_error("failed to initialize winsock", WSAGetLastError());
		}

		//add realization for ipv6

		if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR){
			throw socket_error("failed to initialize socket", WSAGetLastError());
		}
	}

	ServerUdp::ServerUdp(const ServerUdp& _serv)
	{
		ISocket::operator=(_serv);
	}

	void ServerUdp::Bind() const
	{
		if (bind(sock, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
			throw socket_error("error to bind socket", WSAGetLastError());
		}
	}

	int ServerUdp::Send(const char* _buf, len_t _buf_len, int _flags) const
	{
		return sendto(sock, _buf, _buf_len, _flags, (sockaddr*)&addr, sizeof(addr));
	}

	int ServerUdp::Receive(char* _buf, len_t _buf_len, sockaddr_in * _from, int _flags) const
	{
		int from_size = sizeof(*_from);
		return recvfrom(sock, _buf, _buf_len, _flags, (sockaddr*)&_from, &from_size);
	}

	ServerUdp& ServerUdp::operator=(const ServerUdp& _client)
	{
		if (this != &_client) {
			ISocket::operator=(_client);
		}

		return *this;
	}
}