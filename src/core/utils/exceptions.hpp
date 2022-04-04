#ifndef EXCEPTIONS_HPP_
#define EXCEPTIONS_HPP_

#include <stdexcept>
#include <string>

namespace socketlib
{
	class socket_error
	{
	public:
		explicit socket_error(const char* _error) : str_error(_error), error_code(0)
		{	}

		explicit socket_error(const char* _error, int _error_code) : str_error(_error), error_code(0)
		{	}

		socket_error(): str_error("unknown error"), error_code(0)
		{	}

		virtual ~socket_error() = default;
	public:
		virtual const char* what() const
		{
			return str_error;
		}
	protected:
		const char* str_error;
	public:
		int error_code;
	};
}

#endif // !EXCEPTIONS_HPP_
