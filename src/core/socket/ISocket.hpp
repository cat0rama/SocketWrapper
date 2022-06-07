#ifndef ISERVER_HPP_
#define ISERVER_HPP_

#include <cstdint>

#if defined(_WIN32) || defined(_WIN64)
#include <Ws2tcpip.h>

#elif defined(__linux__)
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#endif

#include "defines.hpp"

namespace socketlib
{
	/*!
	\brief A socket base class that implements basic socket initialization.

	ISocket is the base class in which the main part of the socket is
	initialized (in the constructor), it also contains
	the socket descriptor and the addr structure.
	*/

	class ISocket
	{
	protected:
		ISocket();

		ISocket(const char* _ip, uint16_t _port, eAddrType _addr_type = eAddrType::IPv4);

		explicit ISocket(const ISocket& _serv);
	public:
		virtual ~ISocket();

		virtual int Shutdown(cock _sock, eShutdownType _how = eShutdownType::SHUT_ALL) const;
	public:
		const cock& operator*() const;
	protected:
		void operator=(const ISocket& _base);
	protected:
		cock sock;
		bool is_init;
		sockaddr_in addr = { 0 };
	};
}

#endif // !ISERVER_HPP_
