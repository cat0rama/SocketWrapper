#ifndef DEFINES_HPP_
#define DEFINES_HPP_

namespace socketlib
{
	#if defined(_WIN32) || defined(_WIN64)
	  typedef unsigned long long socket;
	  typedef unsigned int len_t;
	#elif defined(__linux__)
	  typedef unsigned int socket;
	  typedef unsigned long long len_t;
	#endif

	enum class eAddrType
	{
		IPV4, IPV6
	};
	
	enum class eExitStatus {};
}

#endif // !DEFINES_HPP_
