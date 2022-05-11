#ifndef CLIENT_TCP_HPP_
#define CLIENT_TCP_HPP_

#include "ISocket.hpp"

namespace socketlib
{
	class ClientTcp : public ISocket
	{
	public:
		ClientTcp() = default;

		ClientTcp(const char* _ip, std::uint16_t _port, eAddrType _addr_type = eAddrType::IPv4);
		
		explicit ClientTcp(const ClientTcp& _client);

		~ClientTcp() = default;
	public:
		int Connect() const;
	public:
		ClientTcp& operator=(const ClientTcp& _client);
	};
}

#endif // !CLIENT_TCP_HPP_
