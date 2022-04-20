#ifndef SERVER_TCP_HPP_
#define SERVER_TCP_HPP_

#include "ISocket.hpp"

#include <vector>

namespace socketlib
{
	class ServerTcp : public ISocket
	{
	public:
		ServerTcp() = default;

		ServerTcp(const char* _ip, uint16_t port);

		explicit ServerTcp(const ServerTcp& _serv);

		~ServerTcp() = default;
	public:
		void _bind() const;

		void _listen(uint16_t _queue = 5) const;

		cock _accept() const;

		virtual len_t _send(cock _sock, const char* _buf, int _flags = 0) const override;

		virtual len_t _recv(cock _sock, char* _buf, len_t _buf_len, int _flags = 0) const override;

		void add_connection(cock _client);

		const std::size_t size() const;

		const std::vector<cock>& get_connections() const;
	public:
		const cock& operator[](int _index) const;

		ServerTcp& operator=(const ServerTcp& _serv);
	protected:
		std::vector<cock> connections;
	};
}

#endif // !_SERVER_TCP_HPP_