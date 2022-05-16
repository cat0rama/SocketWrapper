#ifndef WRAPPER_HPP_
#define WRAPPER_HPP_

#include "socket_exception.hpp"
#include "serverTcp.hpp"
#include "serverUdp.hpp"
#include "clientTcp.hpp"
#include "clientUdp.hpp"

#include <memory>

//write it down

namespace socketlib
{
	template<typename _type>
	class SocketPtr
	{
	public:
		explicit SocketPtr() : sock_ptr(nullptr)
		{	}

		SocketPtr(const char* _ip, uint16_t _port, eAddrType _addr = eAddrType::IPv4) : sock_ptr(new _type(_ip, _port, _addr))
		{	}

		SocketPtr(SocketPtr&& _sock)
		{
			this->_ptr = _sock.sock_ptr;
			_sock.sock_ptr = nullptr;
		}

		~SocketPtr()
		{
			delete sock_ptr;
		}
	public:
		SocketPtr(const SocketPtr&) = delete;

		SocketPtr& operator=(const SocketPtr&) = delete;
	public:
		_type* operator->() const
		{
			return sock_ptr;
		}

		_type& operator*() const
		{
			return *sock;
		}

		_type operator=(SocketPtr&& _sock)
		{
			this->_ptr = _sock.sock_ptr;
			_sock.sock_ptr = nullptr;
		}
	private:
		ISocket* sock_ptr;
	};
}

#endif // !WRAPPER_HPP_
