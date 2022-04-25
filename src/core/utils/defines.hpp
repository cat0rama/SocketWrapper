#ifndef DEFINES_HPP_
#define DEFINES_HPP_

namespace socketlib
{
	#if defined(_WIN32) || defined(_WIN64)
	  typedef unsigned long long cock;
	  typedef unsigned int len_t;
	#elif defined(__linux__)
	  typedef unsigned int cock;
	  typedef unsigned long long len_t;
	#endif

	enum class eAddrType : unsigned int
	{
		  IPv4 = 2, IPv6 = 23
	};

	enum class eExitStatus : int
	{
		_SUCCES = 1, _ERROR = -1, UNKNOWN_ERROR = -2
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
