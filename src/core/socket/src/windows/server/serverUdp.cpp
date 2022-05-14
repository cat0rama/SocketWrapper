#include "serverUdp.hpp"

namespace socketlib
{
	ServerUdp::ServerUdp(const char* _ip, uint16_t _port, eAddrType _addr_type): ISocket(_ip, _port, _addr_type)
	{	}
}