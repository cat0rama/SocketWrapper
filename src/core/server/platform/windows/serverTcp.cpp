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
		if ((bind(sock, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)) {
			throw socket_error("error to bind socket", WSAGetLastError());
		}
	}

	len_t ServerTcp::_send(cock _sock, const char* _buf, int _flags)
	{
		return len_t{};
	}

	len_t ServerTcp::_recv(const char* _buf, len_t _buf_len, int flags)
	{
		return len_t{};
	}

	void ServerTcp::_accept()
	{

	}

	void ServerTcp::_listen(uint16_t _queue)
	{

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