#include "ISocket.hpp"

#pragma comment(lib, "ws2_32.lib")

#include <winsock.h>
#include <cstdio>

namespace socketlib
{
	ISocket::ISocket(const char* _ip, uint16_t _port) : is_init(TRUE)
	{
		WSADATA ws_lib;

		if (WSAStartup(MAKEWORD(1, 1), &ws_lib) != 0) {
			std::printf("%s %d", "failed to winsock init:", WSAGetLastError());
			is_init = FALSE;
		}

		addr.sin_family = AF_INET;
		addr.sin_addr.S_un.S_addr = inet_addr(_ip);
		addr.sin_port = htons(_port);
	}

	ISocket::ISocket() : sock(NULL), is_init(FALSE)
	{	}

	ISocket::~ISocket()
	{
		closesocket(sock);
		WSACleanup();
	}
}