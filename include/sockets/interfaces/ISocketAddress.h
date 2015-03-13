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

#ifndef JEP_CPP_SOCKETS_INTERFACES_I_SOCKET_ADDRESS_H__
#define JEP_CPP_SOCKETS_INTERFACES_I_SOCKET_ADDRESS_H__

#include <stdint.h>
#include "sockets/interfaces/ISocketAddress.h"
#include "sockets/SocketTypes.h"

namespace jep_cpp
{
namespace sockets
{
namespace interfaces
{
    /**
     * Implementing the ISocketAddress interface enables an object to be used as 
     * address information of an ISocket object.
     */
    struct ISocketAddress
    {
        /**
         * Cleans up the mess, provides base class destruction.
         */
        virtual ~ISocketAddress() {}

        /**
         * Gets the AddressFamily of this ISocketAddress object.
         * For further details \see #AddressFamily.
         *
         * \return AddressFamily of this ISocketAddress object.
         */
        virtual AddressFamily get_address_family() const = 0;

        /**
         * Gets the address data of this ISocketAddress object.
         *
         * \return the address data stored in this ISocketAddress object.
         */
        virtual const uint8_t* get_address_data() const = 0;

        /**
         * Gets the size of the address data stored in this ISocketAddress object.
         * 
         * \return the length of the address data which is set in this ISocketAddress object.
         */
        virtual uint16_t get_address_data_length() const = 0;

    };

} /** namespace interfaces */
} /** namespace sockets */
} /** namespace jep_cpp */
#endif /** JEP_CPP_SOCKETS_INTERFACES_I_SOCKET_ADDRESS_H__ */
