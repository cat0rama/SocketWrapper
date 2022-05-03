#include "ISocket.hpp"

#pragma comment(lib, "ws2_32.lib")

#include <winsock.h>
#include <cstdio>

namespace socketlib
{
	ISocket::ISocket(const char* _ip, uint16_t _port, eAddrType _addr_type) : is_init(TRUE)
	{
		WSADATA ws_lib;

		if (WSAStartup(MAKEWORD(1, 1), &ws_lib) != 0) {
			std::printf("%s %d", "failed to winsock init", WSAGetLastError());
			is_init = FALSE;
		}

		//write realization for ipv6

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

	len_t ISocket::Send(cock _sock, const char* _buf, int _flags) const
	{
		return send(_sock, _buf, strlen(_buf), _flags);
	}

	len_t ISocket::Receive(cock _sock, char* _buf, len_t _buf_len, int _flags) const
	{
		return recv(_sock, _buf, _buf_len, _flags);
	}

	int ISocket::Shutdown(cock _sock, eShutdownType _how) const
	{
		return shutdown(_sock, int(_how));
	}

	const cock& ISocket::operator*() const 
	{
		return sock;
	}
}