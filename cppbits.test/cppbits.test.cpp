#include "CppUnitTest.h"

#include <string>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

import StringAlgos;

namespace cppbitstest
{
    TEST_CLASS(cppbitstest)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            using namespace cppbits::algos::str::PhoneKeypadLetterCombinations;

            vector<string> res = getAllLetterCombinations("2");
            Assert::AreEqual(3, (int)res.size());
        }
    };
}
