/**
 * \file
 * \author Nicola Coretti
 * \contact nico.coretti@googlemail.com
 * \version 0.0.1
 *
 * \copyright Copyright (c) 2015, Nicola Coretti. All rights reserved.
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

#ifndef JEP_CPP_TEST_FIXTURES_EXCEPTIONS_EXCEPTION_TEST_FIXTURE_H__
#define JEP_CPP_TEST_FIXTURES_EXCEPTIONS_EXCEPTION_TEST_FIXTURE_H__

#include "gmock/gmock.h"
#include "exceptions/Exception.h"

namespace jep_cpp
{
namespace test
{
namespace fixtures
{
namespace exceptions
{
    class ExceptionTestFixture : public ::testing::Test
    {
        public:

        virtual void SetUp()
        {
            _exception1 = 0L;
            _exception2 = 0L;
            _exception3 = 0L;
            _exception4 = 0L;
        }

        virtual void TearDown()
        {
            if (_exception1 != 0L) { delete _exception1; }
            if (_exception2 != 0L) { delete _exception2; }
            if (_exception3 != 0L) { delete _exception3; }
            if (_exception4 != 0L) { delete _exception4; }
        }

        protected:

        ::jep_cpp::exceptions::Exception* _exception1;
        ::jep_cpp::exceptions::Exception* _exception2;
        ::jep_cpp::exceptions::Exception* _exception3;
        ::jep_cpp::exceptions::Exception* _exception4;
    
    };
} /** namespace exceptions */
} /** namespace fixtures */
} /** namespace test */
} /** namespace jep_cpp */

#endif /** JEP_CPP_TEST_FIXTURES_EXCEPTIONS_EXCEPTION_TEST_FIXTURE_H__ */
