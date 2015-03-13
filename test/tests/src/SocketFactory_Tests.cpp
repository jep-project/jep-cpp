#include "gmock/gmock.h"
#include "sockets/SocketFactory.h" 

using ::testing::IsNull;

using jep_cpp::sockets::SocketFactory;


TEST(SocketFactory_tcp_socket, returns_null_pointer)
{
    EXPECT_THAT(SocketFactory::tcp_socket("192.168.0.1", 9999U), IsNull());
}
