#include "clientTcp.hpp"
#include "socket_exception.hpp"

namespace socketlib
{
	ClientTcp::ClientTcp(const char* _ip, std::uint16_t _port) : ISocket(_ip, _port)
	{
		if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == SOCKET_ERROR){
			throw socket_error("failed to initialize socket", WSAGetLastError());
		}
	}

	ClientTcp::ClientTcp(const ClientTcp& _clt)
	{
		this->addr = _clt.addr;
		this->sock = _clt.sock;
	}

	void ClientTcp::_connect() 
	{
		if (connect(sock, (sockaddr*)&addr, sizeof(addr)) != NULL) {
			throw socket_error("failed to connect", WSAGetLastError());
		}
	}

	len_t ClientTcp::_send(cock _sock, const char* _buf, int _flags) const
	{
		return len_t{};
	}

	len_t ClientTcp::_recv(char* _buf, len_t _buf_len, int _flags) const
	{
		return len_t{};
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