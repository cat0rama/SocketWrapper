#ifndef SERVER_TCP_HPP_
#define SERVER_TCP_HPP_

#include "IServer.hpp"
#include "exceptions.hpp"

#include <vector>

namespace socketlib
{
	class ServerTcp : public IServer
	{
	public:
		ServerTcp() = default;

		ServerTcp(const char* _ip, uint16_t port);

		ServerTcp(const ServerTcp& _serv);

		~ServerTcp() = default;
	public:
		void _bind() const override;

		len_t _send(cock _sock, const char* _buf, int _flags = 0) override;

		len_t _recv(const char* _buf, len_t _buf_len, int _flags = 0) override;

		void _accept();

		void _listen(uint16_t _queue = 5);

		const std::size_t size() const;

		const std::vector<cock>& get_connections() const;
	public:
		const cock& operator[](int _index) const;

		ServerTcp& operator=(const ServerTcp& _serv);
	private:
		std::vector<cock> connections;
	};
}

#endif // !_SERVER_TCP_HPP_