#ifndef CLIENT_TCP_HPP_
#define CLIENT_TCP_HPP_

namespace socketlib
{
	class ClientTcp
	{
	public:
		ClientTcp() = default;

		ClientTcp(const char* _ip, std::uint16_t _port);
		
		~ClientTcp() = default;
	private:
	};
}

#endif // !CLIENT_TCP_HPP_
