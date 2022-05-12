#include "serverTcp.hpp"
#include "socket_exception.hpp"

#include <string.h>

namespace socketlib
{
    ServerTcp::ServerTcp(const char* _ip, uint16_t _port, eAddrType _addr_type): ISocket(_ip, _port, _addr_type)
    {
        if(!is_init){
            throw socket_error("failed to initialize lib");
        }

        //add realization for ipv6

        if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
            throw socket_error("failed to initialize socket", sock);
        }
    }

    ServerTcp::ServerTcp(const ServerTcp& _serv)
    {
        this->addr = _serv.addr;
        this->connections = _serv.connections;
        this->sock = _serv.sock;
    }

    void ServerTcp::Bind() const
    {
        if (auto res = bind(sock, (sockaddr*)&addr, sizeof(addr)) < 0) {
             throw socket_error("error to bind socket", res);
        }
    }

    void ServerTcp::Listen(uint16_t _queue) const
    {
        if (auto res = listen(sock, _queue) < 0) {
             throw socket_error("error to listen on socket", res);
        }
    }

    cock ServerTcp::Accept() const
    {
        int addr_size = sizeof(addr);
        return accept(sock, (sockaddr*)(&addr), (socklen_t*)&addr_size);
    }

    len_t ServerTcp::Send(cock _sock, const char* _buf, int _flags) const
    {
        return send(_sock, _buf, strlen(_buf), _flags);
    }

    len_t ServerTcp::Receive(cock _sock, char* _buf, len_t _buf_len, int _flags) const
    {
        return recv(_sock, _buf, _buf_len, _flags);
    }

    void ServerTcp::AddConnection(cock _client)
    {
        connections.push_back(_client);
    }

    const std::size_t ServerTcp::Size() const
    {
        return connections.size();
    }

    const std::vector<cock>& ServerTcp::GetConnections() const
    {
        return connections;
    }

    const cock& ServerTcp::operator[](int _index) const
    {
        return connections.at(_index);
    }

    ServerTcp& ServerTcp::operator=(const ServerTcp& _serv)
    {
        if (this != &_serv) {
            this->addr = _serv.addr;
            this->connections = _serv.connections;
            this->sock = _serv.sock;
        }

        return *this;
    }
}
