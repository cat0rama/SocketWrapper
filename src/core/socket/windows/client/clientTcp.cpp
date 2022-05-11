#include "clientTcp.hpp"
#include "socket_exception.hpp"

namespace socketlib
{
	ClientTcp::ClientTcp(const char* _ip, std::uint16_t _port, eAddrType _addr_type) : ISocket(_ip, _port, _addr_type)
	{
		//add realization for ipv6

		if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == SOCKET_ERROR){
			throw socket_error("failed to initialize socket", WSAGetLastError());
		}
	}

	ClientTcp::ClientTcp(const ClientTcp& _clt)
	{
		this->addr = _clt.addr;
		this->sock = _clt.sock;
	}

	int ClientTcp::Connect() const
	{
		return connect(sock, (sockaddr*)&addr, sizeof(addr));
	}

	ClientTcp& ClientTcp::operator=(const ClientTcp& _client)
	{
		if (this != &_client) {
			this->addr = _client.addr;
			this->sock = _client.sock;
		}

		return *this;
	}
}