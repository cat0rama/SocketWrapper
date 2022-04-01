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
		typedef unsigned long long socket;
	public:
		IServer() noexcept;

		IServer(const char* _ip, uint16_t) noexcept;

		virtual ~IServer() noexcept;
	public:
		virtual eExitStatus init() = 0;

		virtual size_t send() const = 0;

		virtual size_t recv() const = 0;
	protected:
		socket sock;
		bool is_init;
		sockaddr_in addr = { 0 };
	};
}

#endif // !ISERVER_HPP_
