#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>
#include "../8.1 рек/8.1 рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test81rec
{
	TEST_CLASS(test81rec)
	{
	public:

		TEST_METHOD(TestExist_OGO)
		{
			Assert::IsTrue(Exist("xOGOy", 0));
		}

		TEST_METHOD(TestExist_AGA)
		{
			Assert::IsTrue(Exist("zAGAz", 0));
		}

		TEST_METHOD(TestExist_None)
		{
			Assert::IsFalse(Exist("OGAGO", 0));
		}

		TEST_METHOD(TestChange_One)
		{
			char dest[101];
			char* result = Change(dest, "xOGOy", dest, 0);
			Assert::AreEqual(0, strcmp(dest, "x**y"));
			Assert::AreEqual(0, strcmp(result, "x**y"));
		}

		TEST_METHOD(TestChange_Both)
		{
			char dest[101];
			Change(dest, "AGAOGO", dest, 0);
			Assert::AreEqual(0, strcmp(dest, "****"));
		}

		TEST_METHOD(TestChange_NoTriple)
		{
			char dest[101];
			Change(dest, "hello", dest, 0);
			Assert::AreEqual(0, strcmp(dest, "hello"));
		}
	};
}