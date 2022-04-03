#include "serverTcp.hpp"

namespace socketlib
{
	ServerTcp::ServerTcp(const char* _ip, uint16_t _port) : IServer(_ip, _port)
	{	}

	void ServerTcp::init()
	{

	}

	len_t ServerTcp::send(socket _sock, const char* _buf, int _flags)
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
}