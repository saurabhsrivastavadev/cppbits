#include "CppUnitTest.h"

#include <string>
#include <vector>

#include <SearchAlgos.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace cppbitstest
{
    TEST_CLASS(cppbitstest)
    {
    public:
        TEST_METHOD(TestSearchInPivotedSortedArray)
        {
            using namespace std;
            using namespace cppbits::algos::search;

            vector<int> sortedPivotedArrayToSearch = { 4,5,0,1,2,3 };
            int target = 0, targetIdx = 2;
            int result = searchInPivotedSortedArray(sortedPivotedArrayToSearch, target);
            Assert::AreEqual(targetIdx, result);

            sortedPivotedArrayToSearch = { 1,2,3 };
            target = 0; targetIdx = -1;
            result = searchInPivotedSortedArray(sortedPivotedArrayToSearch, target);
            Assert::AreEqual(targetIdx, result);

            sortedPivotedArrayToSearch = { 1,2,3 };
            target = 1, targetIdx = 0;
            result = searchInPivotedSortedArray(sortedPivotedArrayToSearch, target);
            Assert::AreEqual(targetIdx, result);
        }
    };
}
