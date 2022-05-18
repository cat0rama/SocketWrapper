#ifndef SERVER_TCP_HPP_
#define SERVER_TCP_HPP_

#include "ISocket.hpp"

#include <vector>

namespace socketlib
{
	class ServerTcp : public ISocket
	{
	public:
		ServerTcp(const char* _ip, uint16_t _port, eAddrType _addr_type = eAddrType::IPv4);

		explicit ServerTcp(const ServerTcp& _serv);

		virtual ~ServerTcp() = default;
	public:
		void Bind() const;

		void Listen(uint16_t _queue = 5) const;

		cock Accept() const;

		int Send(cock _sock, const char* _buf, int _flags = 0) const;

		int Receive(cock _sock, char* _buf, len_t _buf_len, int _flags = 0) const;

		void AddConnection(cock _client);

		const std::size_t Size() const;

		const std::vector<cock>& GetConnections() const;
	public:
		const cock& operator[](int _index) const;

		ServerTcp& operator=(const ServerTcp& _serv);
	protected:
		std::vector<cock> connections;
	};
}

#endif // !_SERVER_TCP_HPP_
