#include "serverTcp.hpp"

namespace socketlib
{
	ServerTcp::ServerTcp(const char* _ip, uint16_t _port) : IServer(_ip, _port)
	{	
		if (!is_init) {
			throw socket_error("failed to initialize lib");
		}
	}

	ServerTcp::ServerTcp(const ServerTcp& _serv)
	{
		this->addr = _serv.addr;
		this->connections = _serv.connections;
		this->sock = _serv.sock;
	}

	void ServerTcp::_bind() const
	{
		if (bind(sock, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
			throw socket_error("error to bind socket", WSAGetLastError());
		}
	}

	void ServerTcp::_listen(uint16_t _queue) const
	{
		if (listen(sock, _queue)) {
			throw socket_error("error to listen on socket", WSAGetLastError());
		}
	}

	cock ServerTcp::_accept() const
	{
		int addr_size = sizeof(addr);
		return accept(sock, (sockaddr*)(&addr), &addr_size);
	}

	len_t ServerTcp::_send(cock _sock, const char* _buf, int _flags) const
	{
		return send(_sock, _buf, strlen(_buf), _flags);
	}

	len_t ServerTcp::_recv(char* _buf, len_t _buf_len, int _flags) const
	{
		return recv(sock, _buf, _buf_len, _flags);
	}

	void ServerTcp::add_connection(cock _client)
	{
		connections.push_back(_client);
	}

	const std::size_t ServerTcp::size() const
	{
		return connections.size();
	}

	const std::vector<cock>& ServerTcp::get_connections() const
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