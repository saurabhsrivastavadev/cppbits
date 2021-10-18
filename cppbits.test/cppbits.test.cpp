#include "CppUnitTest.h"

#include <string>
#include <vector>

#include <StringAlgos.h>
#include <MergeAlgos.h>
#include <LinkedListAlgos.h>

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

        TEST_METHOD(TestMergeSortedLinkedLists)
        {
            using namespace std;
            using namespace cppbits::algos::merge::MergeSortedLinkedLists;

            Node m2(2, NULL), m1(1, &m2);
            Node n4(4, NULL), n3(3, &n4), n2(2, &n3), n1(1, &n2);
            Node o1(1, NULL);
            vector<Node*> sortedLists({ &m1, &n1, &o1 });
            Node* mergedMNO = mergeSortedLists(sortedLists);

            Assert::IsNotNull(mergedMNO);
            Assert::AreEqual(1, mergedMNO->val);
            Assert::AreEqual(1, mergedMNO->next->val);
            Assert::AreEqual(1, mergedMNO->next->next->val);
            Assert::AreEqual(2, mergedMNO->next->next->next->val);
            Assert::AreEqual(2, mergedMNO->next->next->next->next->val);
            Assert::AreEqual(3, mergedMNO->next->next->next->next->next->val);
            Assert::AreEqual(4, mergedMNO->next->next->next->next->next->next->val);
        }

        TEST_METHOD(TestReverseListPortions) 
        {
            using namespace std;
            using namespace cppbits::algos::linkedlist::ReversePortions;

            Node n4(4, NULL), n3(3, &n4), n2(2, &n3), n1(1, &n2);
            Node* reversed = reverseLinkedListPortions(&n1, 4);
            Assert::AreEqual(4, reversed->val);
            Assert::AreEqual(3, reversed->next->val);
            Assert::AreEqual(2, reversed->next->next->val);
            Assert::AreEqual(1, reversed->next->next->next->val);

            Node m4(4, NULL), m3(3, &m4), m2(2, &m3), m1(1, &m2);
            reversed = reverseLinkedListPortions(&m1, 2);
            Assert::AreEqual(2, reversed->val);
            Assert::AreEqual(1, reversed->next->val);
            Assert::AreEqual(4, reversed->next->next->val);
            Assert::AreEqual(3, reversed->next->next->next->val);
        }
    };
}
