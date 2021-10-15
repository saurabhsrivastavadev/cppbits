#include "CppUnitTest.h"

#include <string>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

import StringAlgos;
import CppBits.StringUtils;

namespace cppbitstest
{
    TEST_CLASS(cppbitstest)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            using namespace cppbits::algos::str::PhoneKeypadLetterCombinations;
            using namespace cppbits::utils::str;

            vector<string> res = getAllLetterCombinations("2");
            Assert::AreEqual(3, (int)res.size());

            string s = printVector(res);
            Assert::AreNotEqual(0, (int)s.size());
        }
    };
}
