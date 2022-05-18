#include "serverTcp.hpp"
#include "socket_exception.hpp"

namespace socketlib
{
	ServerTcp::ServerTcp(const char* _ip, uint16_t _port, eAddrType _addr_type) : ISocket(_ip, _port, _addr_type)
	{
		if (!is_init) {
			throw socket_error("failed to initialize winsock");
		}

		//realize socket for ipv6 version

		if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == SOCKET_ERROR) {
			throw socket_error("failed to initialize socket", WSAGetLastError());
		}
	}

	ServerTcp::ServerTcp(const ServerTcp& _serv)
	{
		ISocket::operator=(_serv);
		this->connections = _serv.connections;
	}

	void ServerTcp::Bind() const
	{
		if (bind(sock, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
			throw socket_error("error to bind socket", GetError());
		}
	}

	void ServerTcp::Listen(uint16_t _queue) const
	{
		if (listen(sock, _queue)) {
			throw socket_error("error to listen on socket", GetError());
		}
	}

	cock ServerTcp::Accept() const
	{
		int addr_size = sizeof(addr);
		return accept(sock, (sockaddr*)(&addr), &addr_size);
	}

	int ServerTcp::Send(cock _sock, const char* _buf, int _flags) const
	{
		return send(_sock, _buf, strlen(_buf), _flags);
	}

	int ServerTcp::Receive(cock _sock, char* _buf, len_t _buf_len, int _flags) const
	{
		return recv(_sock, _buf, _buf_len, _flags);
	}

	void ServerTcp::AddConnection(cock _client)
	{
		connections.push_back(_client);
	}

	const std::size_t ServerTcp::Size() const
	{
		return connections.size();
	}

	const std::vector<cock>& ServerTcp::GetConnections() const
	{
		return connections;
	}

	const cock& ServerTcp::operator[](int _index) const
	{
		return connections.at(_index);
	}

	ServerTcp& ServerTcp::operator=(const ServerTcp& _serv)
	{
		if (this != &_serv) {
			ISocket::operator=(_serv);
			this->connections = _serv.connections;
		}

		return *this;
	}
}