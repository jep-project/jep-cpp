/**
 * \file
 * \author Nicola Coretti
 * \contact nico.coretti@googlemail.com
 * \version 0.0.1
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

#ifndef JEP_CPP_SOCKETS_INTERFACES_I_SOCKET_H__
#define JEP_CPP_SOCKETS_INTERFACES_I_SOCKET_H__

#include <string>
#include <stdint.h>
#include "sockets/interfaces/ISocketAddress.h"

namespace jep_cpp
{
namespace sockets
{
namespace interfaces
{
    /**
     * Basic platform independent socket interface (based on the BSD socket API).
     */
    struct ISocket
    {
        /**
         * Cleans up the mess, provide base ptr. deletion.
         */
        virtual ~ISocket() {}

        /**
         * Requests that address to be assinged to the socket.
         *
         * \param address which will be assinged to this socket.
         *
         * \pre the have to be unnamed (no name assinged so far).
         * \post if the call return's without error, the provided 
         *       address is assigned to this socket.
         *
         * \throw Exception if an error occurs during the bind process.
         */
        virtual void bind(const ISocketAddress& address) = 0;

        /**
         * Initiates a connection on this socket.
         *
         * \param  address of the peer with whom a "connection" (depending on the type) will be established. 
         *
         * \throw Exception if an error occurs while trying to "connect".
         */
        virtual void connect(const ISocketAddress& address) = 0;

        /**
         * Listen for connections on this socket.
         *
         * \param backlog defines the maximum length for the queue of pending connections.
         *
         * \throw Exception if an error occurs while the socket was set up for listeing.
         */
        virtual void listen(uint32_t backlog) = 0;

        /**
         * Accepts a connection on this socket.
         *
         * \param[out] address is updated with the address data of the connecting peer.
         *
         * \throw Exception if an error occurs during accepting the conection.
         */
        virtual ISocket* accept(ISocketAddress& address) = 0;

        /**
         * Receive a message/data from this socket.
         *
         * \param[out] buffer which will be updated with the message data.
         * \param buffer_length length of the provided buffer.
         * \param flags -
         *
         * \throw Exception if an error occured during receiving the message/data.
         */
        virtual uint32_t recv(uint8_t* buffer, uint32_t buffer_length, uint32_t flags) = 0;

        /**
         * Sends a message/data from this socket.
         *
         * \param[in] buffer which contains the message/data to be sent.
         * \param buffer_length length of the buffer or data which shall be sent.
         * \param flags -
         *
         * \throw Exception if an error occured during sending the message/data.
         */
        virtual uint32_t send(const uint8_t* buffer, uint32_t buffer_length, uint32_t flags) = 0;

        /**
         * Shut down part of the full-duplex connection of this socket.
         *
         * \param how it will be shutdown, for further details \see #ShutDownHint.
         *
         * \throw Exception if an error occured during shuting down the "connection" of this socket.
         */
        virtual void shutdown(ShutdownHint how) = 0;
    };

} /** namespace interfaces */
} /** namespace sockets */
} /** namespace jep_cpp */

#endif /** JEP_CPP_SOCKETS_INTERFACES_I_SOCKET_H__ */
