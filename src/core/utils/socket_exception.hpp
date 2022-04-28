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

		explicit socket_error(const char* _error, int _error_code) : str_error(_error), error_code(_error_code)
		{	}

		socket_error(): str_error("unknown error"), error_code(0)
		{	}

		virtual ~socket_error() = default;
	public:
		virtual const char* what() const
		{
			return str_error;
		}

		int get_code() const
		{
			return error_code;
		}
	protected:
		const char* str_error;
		int error_code;
	};

	class ssl_error : public socket_error
	{
	public:
		explicit ssl_error(const char* _error) : socket_error(_error)
		{	}

		explicit ssl_error(const char* _error, int _error_code): socket_error(_error, _error_code)
		{	}

		~ssl_error() = default;
	};
}

#endif // !EXCEPTIONS_HPP_
