#include "clientTcp.hpp"
#include "exceptions.hpp"

namespace socketlib
{
	ClientTcp::ClientTcp(const char* _ip, std::uint16_t _port)
	{
		if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == SOCKET_ERROR){
			throw socket_error("failed to initialize socket", WSAGetLastError());
		}
	}
}