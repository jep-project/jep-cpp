#include "sockets/SocketFactory.h"

namespace jep_cpp
{
namespace sockets
{
    using interfaces::ISocket;

    /** static */
    ISocket* SocketFactory::tcp_socket(const std::string& ip_address, uint16_t port)
    {
        return 0L;
    }

} /** namespace sockets */
} /** namespace jep_cpp */


