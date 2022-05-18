#include "ISocket.hpp"

namespace socketlib
{
	ISocket::ISocket(const char* _ip, uint16_t _port, eAddrType _addr_type) : is_init(TRUE)
	{
		//add realization for ipv6

		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr(_ip);
		addr.sin_port = htons(_port);
	}

	ISocket::ISocket() : sock(NULL), is_init(FALSE)
	{   }

	ISocket::~ISocket()
	{
		close(sock);
	}

	int ISocket::Shutdown(cock _sock, eShutdownType _how) const
	{
		return shutdown(_sock, int(_how));
	}

	const cock& ISocket::operator*() const
	{
		return sock;
	}

	void ISocket::operator=(const ISocket& _base)
	{
		if (this != &_base) {
			this->addr = _base.addr;
			this->sock = _base.sock;
		}
	}
}
