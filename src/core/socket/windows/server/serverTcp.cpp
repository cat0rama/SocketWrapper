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
		this->addr = _serv.addr;
		this->connections = _serv.connections;
		this->sock = _serv.sock;
	}

	void ServerTcp::Bind() const
	{
		if (bind(sock, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
			throw socket_error("error to bind socket", WSAGetLastError());
		}
	}

	void ServerTcp::Listen(uint16_t _queue) const
	{
		if (listen(sock, _queue)) {
			throw socket_error("error to listen on socket", WSAGetLastError());
		}
	}

	cock ServerTcp::Accept() const
	{
		int addr_size = sizeof(addr);
		return accept(sock, (sockaddr*)(&addr), &addr_size);
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
			this->addr = _serv.addr;
			this->connections = _serv.connections;
			this->sock = _serv.sock;
		}

		return *this;
	}
}