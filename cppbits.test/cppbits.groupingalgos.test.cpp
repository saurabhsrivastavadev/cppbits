#include "CppUnitTest.h"

#include <string>
#include <vector>
#include <iostream>

#include <GroupingAlgos.h>
#include <StringUtils.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace cppbitstest
{
    TEST_CLASS(cppbitstest)
    {
    public:
        TEST_METHOD(TestGroupAnagrams)
        {
            using namespace std;
            using namespace cppbits::algos::grouping::GroupAnagrams;
            using namespace cppbits::utils::str;

            vector<string> strs = { "hey", "hello", "yeh", "leloh", "loleh", "eyh" };
            vector<vector<string>> expected = { {"hey", "eyh", "yeh"}, {"hello", "leloh", "loleh"} };
            auto result = groupAnagrams(strs);
            for (auto anagrams : result) {
                Logger::WriteMessage((printVector(anagrams) + "\n").c_str());
            }
            Assert::IsTrue(expected.size() == result.size());
        }
    };
}

