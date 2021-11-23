#pragma warning(disable : 4996)
#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8.1Rec/Lab_08_1_Rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT81Rec
{
	TEST_CLASS(UT81Rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;

			t = Count("FFFFF", 1);

			Assert::AreEqual(t, 0);
		}
	};
}