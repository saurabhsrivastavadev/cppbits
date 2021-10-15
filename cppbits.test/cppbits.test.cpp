#include "pch.h"
#include "CppUnitTest.h"

#include <string>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
using namespace cppbits::stringalgos::PhoneKeypadLetterCombinations;

import StringAlgos;

namespace cppbitstest
{
    TEST_CLASS(cppbitstest)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            vector<string> res = getAllLetterCombinations("2");
            Assert::AreEqual(3, (int)res.size());
        }
    };
}
