#include "gmock/gmock.h"
#include "exceptions/Exception.h"
#include "exceptions/ExceptionTestFixture.h"

using ::testing::Eq;
using ::testing::StrEq;
using ::testing::IsNull;

using jep_cpp::exceptions::Exception;
using jep_cpp::test::fixtures::exceptions::ExceptionTestFixture;

TEST_F(ExceptionTestFixture, ExceptionConstructorsWork)
{
    const char* msg_exception1 = "exception1";
    const char* msg_exception2 = "exception2";
    const char* msg_exception3 = "";
    const char* msg_exception4 = "";

   _exception1 = new Exception(msg_exception1);
   _exception2 = new Exception(msg_exception2, _exception1);
   _exception3 = new Exception();
   _exception4 = new Exception(_exception1);

   EXPECT_THAT(_exception1->get_message(), StrEq(msg_exception1));
   EXPECT_THAT(_exception2->get_message(), StrEq(msg_exception2));
   EXPECT_THAT(_exception3->get_message(), StrEq(msg_exception3));
   EXPECT_THAT(_exception4->get_message(), StrEq(msg_exception4));

   EXPECT_THAT(_exception1->get_cause(), IsNull());
   EXPECT_THAT(_exception2->get_cause(), Eq(_exception1));
   EXPECT_THAT(_exception3->get_cause(), IsNull());
   EXPECT_THAT(_exception4->get_cause(), Eq(_exception1));
}
