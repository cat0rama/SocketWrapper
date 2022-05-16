#include "clientTcp.hpp"
#include "socket_exception.hpp"

#include <string.h>

namespace socketlib
{
    ClientTcp::ClientTcp(const char* _ip, uint16_t _port, eAddrType _addr_type):
        ISocket(_ip, _port, _addr_type)
    {
        if (!is_init) {
            throw socket_error("failed to initialize winsock", GetError());
        }

        //add realization for ipv6

        if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
            throw socket_error("failed to initialize socket", GetError());
        }
    }

    ClientTcp::ClientTcp(const ClientTcp& _client)
    {
        ISocket::operator=(_client);
    }

    int ClientTcp::Connect() const
    {
        return connect(sock, (sockaddr*)&addr, sizeof(addr));
    }

    int ClientTcp::Send(const char* _buf, int _flags) const
    {
        return send(sock, _buf, strlen(_buf), _flags);
    }

    int ClientTcp::Receive(char* _buf, len_t _buf_len, int _flags) const
    {
        return recv(sock, _buf, _buf_len, _flags);
    }
}
