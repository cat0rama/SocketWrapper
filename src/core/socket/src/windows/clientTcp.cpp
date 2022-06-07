#include "clientTcp.hpp"
#include "socket_exception.hpp"

namespace socketlib
{
	ClientTcp::ClientTcp(const char* _ip, std::uint16_t _port, eAddrType _addr_type) : ISocket(_ip, _port, _addr_type)
	{
		if (!is_init) {
			throw socket_error("failed to initialize winsock", GetError());
		}

		sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		if (!IsValidSocket(sock)) {
			throw socket_error("failed to initialize socket", GetError());
		}
	}

	ClientTcp::ClientTcp(const ClientTcp& _clt)
	{
		ISocket::operator=(_clt);
	}

	int ClientTcp::Connect() const
	{
		return connect(sock, (sockaddr*)&addr, sizeof(addr));
	}

	int ClientTcp::Send(const char* _buf, int _flags) const
	{
		return send(sock, _buf, strlen(_buf), _flags);
	}

	int ClientTcp::Receive(char* _buf, len_t _buf_len, int _flags) const
	{
		return recv(sock, _buf, _buf_len, _flags);
	}

	ClientTcp& ClientTcp::operator=(const ClientTcp& _client)
	{
		if (this != &_client) {
			ISocket::operator=(_client);
		}

		return *this;
	}
}