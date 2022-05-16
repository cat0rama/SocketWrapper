#include "clientUdp.hpp"
#include "socket_exception.hpp"

namespace socketlib
{
    ClientUdp::ClientUdp(const char* _ip, uint16_t _port, eAddrType _addr_type):
        ISocket(_ip, _port, _addr_type)
    {
        if (!is_init) {
            throw socket_error("failed to initialize winsock", GetError());
        }

        //add realization for ipv6

        if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
            throw socket_error("failed to initialize socket", GetError());
        }
    }

    ClientUdp::ClientUdp(const ClientUdp& _client)
    {
        ISocket::operator=(_client);
    }

    int ClientUdp::Receive(char* _buf, int _buf_len, sockaddr_in* _from, int _flags) const
    {
        uint32_t from_len = sizeof(_from);
        return recvfrom(sock, _buf, _buf_len, _flags, (sockaddr*)&_from, &from_len);
    }


    int ClientUdp::Send(const char* _buf, int _buf_len, int _flags) const
    {
        return sendto(sock, _buf, _buf_len, _flags, (sockaddr*)&addr, sizeof(addr));
    }

    ClientUdp& ClientUdp::operator=(const ClientUdp& _client)
    {
        if(this != &_client){
            ISocket::operator=(_client);
        }

        return *this;
    }
}
