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

		~ServerTcp() = default;
	public:
		void init(eAddrType _addr_type = eAddrType::IPv4) override;

		len_t send(cock _sock, const char* _buf, int _flags = 0) override;

		len_t recv(const char* _buf, len_t _buf_len, int _flags = 0) override;

		void accept();

		void listen(uint16_t _queue = 5);

		const std::size_t size() const;

		const std::vector<cock>& get_connections() const;
	public:
		const cock& operator[](int _index) const;
	private:
		std::vector<cock> connections;
	};
}

#endif // !_SERVER_TCP_HPP_