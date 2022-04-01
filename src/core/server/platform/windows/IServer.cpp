#include "../IServer.hpp"

#pragma comment(lib, "ws2_32.lib")

#include <winsock.h>

namespace socketlib
{
	IServer::IServer(const char* _ip, uint16_t _port) noexcept : is_init(TRUE)
	{
		WSADATA ws_lib;
		
		if (WSAStartup(MAKEWORD(1, 1), &ws_lib) != 0) {
			is_init = FALSE;
		} else {
			addr.sin_family = AF_INET;
			addr.sin_addr.S_un.S_addr = INADDR_ANY;
			addr.sin_port = htons(_port);
		}
	}

	IServer::IServer() noexcept : sock(NULL), is_init(FALSE)
	{	}

	IServer::~IServer() noexcept
	{
		closesocket(sock);
		WSACleanup();
	}
}