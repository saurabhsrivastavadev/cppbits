#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

import PhoneKeypadLetterCombinations;

namespace cppbitstest
{
    TEST_CLASS(cppbitstest)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            cppbits::algos::PhoneKeypadLetterCombinations pk;
            vector<string> res = pk.letterCombinations("2");
            Assert::AreEqual(3, (int)res.size());
        }
    };
}
