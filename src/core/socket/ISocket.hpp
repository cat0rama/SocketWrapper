#ifndef ISERVER_HPP_
#define ISERVER_HPP_

#include <cstdint>

#if defined(_WIN32) || defined(_WIN64)
 #include <Ws2tcpip.h>
#elif defined(__linux__)
 #include <netinet/in.h>
 #include <sys/socket.h>	
#endif

#include "defines.hpp"

namespace socketlib
{
	class ISocket
	{
	public:
		ISocket();

		ISocket(const char* _ip, uint16_t _port, eAddrType _addr_type = eAddrType::IPv4);

		virtual ~ISocket();
	public:
		virtual int Shutdown(cock _sock, eShutdownType _how = eShutdownType::SHUT_ALL) const;
	public:
		const cock& operator*() const;
	protected:
		cock sock;
		bool is_init;
		sockaddr_in addr = { 0 };
	};
}

#endif // !ISERVER_HPP_
