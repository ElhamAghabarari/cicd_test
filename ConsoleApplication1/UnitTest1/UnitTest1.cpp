#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/myClass.h"
#include "../ConsoleApplication1/myClass.cpp"
#include "../ConsoleApplication1/ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			myClass a5("a5");
			myClass a7 = a5;
			Assert::AreEqual("a5",a7.getval());
		}

		TEST_METHOD(TestMethod2)
		{
			myClass a5("a5");
			myClass a6("a6");
			myClass a7 = a5;
			a7 += a6;

			Assert::AreEqual("a5a6", a7.getval());
		}
	};
}
