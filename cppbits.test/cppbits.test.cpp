#include "CppUnitTest.h"

#include <string>
#include <vector>

#include <StringAlgos.h>
#include <StringUtils.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace cppbitstest
{
    TEST_CLASS(cppbitstest)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            using namespace std;
            using namespace cppbits::algos::str::PhoneKeypadLetterCombinations;
            using namespace cppbits::utils::str;

            vector<string> res = getAllLetterCombinations("2");
            Assert::AreEqual(3, (int)res.size());

            string s = printVector(res);
            Assert::AreNotEqual(0, (int)s.size());
        }
    };
}
