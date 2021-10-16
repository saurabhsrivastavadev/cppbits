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
        TEST_METHOD(TestPhoneKeypadLetterCombinations)
        {
            using namespace std;
            using namespace cppbits::algos::str::PhoneKeypadLetterCombinations;
            using namespace cppbits::utils::str;

            vector<string> res = getAllLetterCombinations("23");
            Assert::AreEqual(9, (int)res.size());

            string s = printVector<string>(res);
            Assert::AreEqual(string("ad ae af bd be bf cd ce cf"), trim(s));
        }
    };
}
