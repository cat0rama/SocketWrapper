#ifndef DEFINES_HPP_
#define DEFINES_HPP_

namespace socketlib
{
	enum class eAddrType
	{
		IPV4, IPV6
	};

	enum class eExitStatus
	{
		_SUCCES, _ERROR = -1, _LIB_ERROR = -2
	};
}

#endif // !DEFINES_HPP_
