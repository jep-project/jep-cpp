/**
 * \file
 * \author Nicola Coretti
 * \contact nico.coretti@googlemail.com
 * \version 0.0.1
 *
 * This file contains basic type necessary for the socket classes.
 *
 * \copyright Copyright (c) 2014, Nicola Coretti. All rights reserved.
 * \section LICENSE
 *
 *  Redistribution and use in source and binary forms, with or without modification,
 *  are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its contributors may be
 *     used to endorse or promote products derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 *  OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 *  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef JEP_CPP_SOCKETS_SOCKET_TYPES_H__
#define JEP_CPP_SOCKETS_SOCKET_TYPES_H__

namespace jep_cpp
{
namespace sockets
{
    /**
     * The SocketDomain enum contains available socket domains.
     *
     * @attention depending on the platform not all socket domains will
     *            be supported or available. 
     */
    enum SocketDomain
    {
        SocketDomain_Local,

        SocketDomain_Unix,

        SocketDomain_Inet,

        SocketDomain_Inet6,
    };

    /**
     * The SocketType enum contains all supported socket types. 
     */
    enum SocketType 
    {
        SocketType_Stream,

        SocketType_Dgram,
    };

    /**
     * The SocketProtocol enum contains all supported socket protocols.
     */
    enum SocketProtocol
    {
        SocketProtocol_Default
    };

    /**
     * The AddressFamily enum contains all supported socket address families.
     */
    enum AddressFamily
    {
        AddressFamily_Inet,

        AddressFamily_Inet6,

        AddressFamily_Unix
    };

    /**
     * The ShutdownHint enum contains all supported shutdown hint.
     */
    enum ShutdownHint
    {
        ShutdownHint_Shut_WR,

        ShutdownHint_Shut_RDWR,
    };

} /** namespace sockets */
} /** namespace jep_cpp */

#endif /** JEP_CPP_SOCKETS_SOCKET_TYPES_H__ */
