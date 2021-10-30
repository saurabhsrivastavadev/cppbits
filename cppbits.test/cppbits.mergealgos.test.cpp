#include "CppUnitTest.h"

#include <string>
#include <vector>

#include <MergeAlgos.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace cppbitstest
{
    TEST_CLASS(cppbitstest)
    {
    public:
        TEST_METHOD(TestMergeIntervals)
        {
            using namespace std;
            using namespace cppbits::algos::merge::MergeIntervals;

            vector<Interval> intervals = { {2,3}, {3,4} };
            vector<Interval> expectedResult = { {2,4} };
            auto result = mergeUnsortedIntervals(intervals);
            Assert::IsTrue(expectedResult == result);

            intervals = { {2,3}, {5,5}, {2,2}, {3,4}, {3,4} };
            expectedResult = { {2,4}, {5,5} };
            result = mergeUnsortedIntervals(intervals);
            Assert::IsTrue(expectedResult == result);
        }

        TEST_METHOD(TestGroupAnagrams)
        {
            using namespace std;
            using namespace cppbits::algos::merge::GroupAnagrams;

            vector<string> strs = { "hey", "hello", "yeh", "leloh", "loleh", "eyh" };
            vector<vector<string>> expected = { {"hey", "eyh", "yeh"}, {"hello", "leloh", "loleh"} };
            auto result = groupAnagrams(strs);
            Assert::IsTrue(expected == result);
        }
    };
}

