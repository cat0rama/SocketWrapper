#ifndef SERVER_TCP_HPP_
#define SERVER_TCP_HPP_

#include "../IServer.hpp"

#include <vector>

namespace socketlib
{
	class ServerTcp : public IServer
	{
	public:
		ServerTcp() = default;

		~ServerTcp() = default;
	private:
		std::vector<socket> connections;
	};
}

#endif // !_SERVER_TCP_HPP_