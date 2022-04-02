#include "serverTcp.hpp"

namespace socketlib
{
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
}