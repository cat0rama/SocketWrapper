#ifndef ISERVER_HPP_
#define ISERVER_HPP_

#include <cstdint>

#if defined(_WIN32) || defined(_WIN64)
 #include <winsock.h>
#elif defined(__linux__)
 #include <netinet/in.h>
#endif

#include "defines.hpp"

namespace socketlib
{
	class IServer
	{
	public:
		IServer() noexcept;

		IServer(const char* _ip, uint16_t) noexcept;

		virtual ~IServer() noexcept;
	public:
		virtual void init(eAddrType _addr_type = eAddrType::IPv4) = 0;

		virtual len_t send(cock _sock, const char* _buf, int _flags = 0) = 0;

		virtual len_t recv(const char* _buf, len_t _buf_len, int _flags = 0) = 0;
	protected:
		cock sock;
		bool is_init;
		sockaddr_in addr = { 0 };
	};
}

#endif // !ISERVER_HPP_
