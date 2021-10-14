#include "pch.h"
#include "CppUnitTest.h"

import PhoneKeypadLetterCombinations;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace cppbits::algos;

namespace cppbitstest
{
	TEST_CLASS(cppbitstest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(GetNumberGreaterThanZero() > 0);
		}
	};
}
