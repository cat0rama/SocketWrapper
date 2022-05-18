#ifndef WRAPPER_HPP_
#define WRAPPER_HPP_

#include "socket_exception.hpp"
#include "ISocket.hpp"

#include <memory>

namespace socketlib
{
	template<typename _type>
	class SocketPtr
	{
	public:
		explicit SocketPtr() noexcept : sock_ptr(nullptr)
		{	}

		SocketPtr(const char* _ip, uint16_t _port, eAddrType _addr = eAddrType::IPv4) : 
			sock_ptr(new _type(_ip, _port, _addr))
		{	}

		SocketPtr(_type* _sock) noexcept
		{
			sock_ptr = _sock;
			_sock = nullptr;
		}

		SocketPtr(SocketPtr<_type>&& _sock)
		{
			this->sock_ptr = std::move(_sock.sock_ptr);
			_sock.sock_ptr = nullptr;
		}
		
		~SocketPtr() noexcept
		{
			delete sock_ptr;
		}
	public:
		SocketPtr(const SocketPtr&) = delete;

		SocketPtr& operator=(const SocketPtr&) = delete;
	public:
		_type* operator->() const
		{
			return static_cast<_type*>(sock_ptr);
		}

		_type& operator*() const
		{
			return static_cast<_type&>(*sock_ptr);
		}

		SocketPtr<_type>& operator=(SocketPtr<_type>&& _sock) noexcept
		{
			if (this != &_sock) {
				this->sock_ptr = std::move(_sock.sock_ptr);
				_sock.sock_ptr = nullptr;
			}

			return *this;
		}
	private:
		ISocket* sock_ptr;
	};

	template<typename T>
	SocketPtr<T> MakeSocketPtr(const char* _ip, uint16_t _port, eAddrType _addr = eAddrType::IPv4)
	{
		return SocketPtr<T>(_ip, _port, _addr);
	}
}

#endif // !WRAPPER_HPP_
