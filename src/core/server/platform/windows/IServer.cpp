#include "IServer.hpp"

#pragma comment(lib, "ws2_32.lib")

#include <winsock.h>
#include <cstdio>

namespace socketlib
{
	IServer::IServer(const char* _ip, uint16_t _port) : is_init(TRUE)
	{
		WSADATA ws_lib;

		if (WSAStartup(MAKEWORD(1, 1), &ws_lib) != 0) {
			std::printf("%s %d", "failed to winsock init:", WSAGetLastError());
			is_init = FALSE;
		}
		
		if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == SOCKET_ERROR) {
			std::printf("%s %d", "failed to socket init:", WSAGetLastError());
			is_init = FALSE;
		}

		addr.sin_family = AF_INET;
		addr.sin_addr.S_un.S_addr = inet_addr(_ip);
		addr.sin_port = htons(_port);		
	}

	IServer::IServer() : sock(NULL), is_init(FALSE)
	{	}

	IServer::~IServer()
	{
		closesocket(sock);
		WSACleanup();
	}
}