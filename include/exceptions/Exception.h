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

#ifndef JEP_CPP_EXCEPTIONS_EXCEPTION_H__
#define JEP_CPP_EXCEPTIONS_EXCEPTION_H__

#include <string>

namespace jep_cpp
{
namespace exceptions
{
    /**
     * Base class for all exceptions.
     */
    class Exception
    {
        private:

            /**
             * Detailed message (what happend, why the exception was thrown, etc.)
             */
            std::string _message;

            /**
             * If NULL/0 it indicates that the cause is unknown or nonexistent.
             */
            Exception* _cause;

        public:

            /**
             * Creates a new exception.
             */
            Exception();

            /**
             * Creates a new exception with the specified message.
             * @param message: @see Exception#_message
             */
            Exception(const char* message);

            /**
             * Creates a new exception with the specified message and cause.
             * @param message: @see Exception#_message
             * @param cause:   @see Exception#_cause
             */
            Exception(const char* message, Exception* cause);

            /**
             * Creates a new exception with the specified cause.
             * @param cause:   @see Exception#_cause
             */
            Exception(Exception* cause);

            /** 
             * Returns Exception#_cause.
             */
            const Exception* get_cause() const;

            /**
             * Returns Exception#_message.
             */
            const std::string& get_message() const;

            /**
             * Cleans up the mess.
             */
            virtual ~Exception();
    };

} /** namespace exceptions */
} /** namespace jep_cpp */

#endif /* JEP_CPP_EXCEPTIONS_EXCEPTION_H__ */
