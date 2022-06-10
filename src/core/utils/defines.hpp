#ifndef DEFINES_HPP_
#define DEFINES_HPP_

#define TRUE 1
#define FALSE 0

namespace socketlib
{
	/*!
	\brief Header file with definitions
	This header file contains cross-platform definitions and enum sets for more convenient work
	*/
#define SOCKET_ERROR -1

#if defined(_WIN32) || defined(_WIN64)
	#define GetError() (WSAGetLastError())
	#define IsValidSocket(sock)  ((sock) != INVALID_SOCKET)
	#define CloseSocket(sock) closesocket(sock);

	typedef unsigned long long cock;
	typedef unsigned int len_t;
	typedef int socklen_t;
#elif defined(__linux__)
	#define GetError() (errno)
	#define IsValidSocket(sock)  ((sock) >= 0)
	#define CloseSocket(sock) close(sock);

	typedef unsigned int cock;
	typedef unsigned long long len_t;
	typedef unsigned int socklen_t;
#endif

	enum class eAddrType : unsigned int
	{
		IPv4 = 2, IPv6 = 23
	};

	enum class eShutdownType : unsigned int
	{
		SHUT_RECV, SHUT_SEND, SHUT_ALL
	};

	enum class eMachineType : int
	{
		NONE = -1, SERVER, CLIENT
	};
}

#endif // !DEFINES_HPP_
