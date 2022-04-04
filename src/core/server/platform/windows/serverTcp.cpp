#include "serverTcp.hpp"

namespace socketlib
{
	ServerTcp::ServerTcp(const char* _ip, uint16_t _port) : IServer(_ip, _port)
	{	}

	void ServerTcp::init(eAddrType _addr_type)
	{
		if ((socket(AF_INET, SOCK_STREAM, int(_addr_type)) == SOCKET_ERROR)) {
			throw socket_error("error to socket init", WSAGetLastError());
		}

		if ((bind(sock, (sockaddr*)&addr, sizeof(addr))) == SOCKET_ERROR) {
			throw socket_error("error to bind socket", WSAGetLastError());
		}
	}

	len_t ServerTcp::send(cock _sock, const char* _buf, int _flags)
	{
		return len_t{};
	}

	len_t ServerTcp::recv(const char* _buf, len_t _buf_len, int flags)
	{
		return len_t{};
	}

	void ServerTcp::accept()
	{

	}

	void ServerTcp::listen(uint16_t _queue)
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
}