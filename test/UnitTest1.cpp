#include "pch.h"
#include "CppUnitTest.h"
#include "../intersect/intersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Line line1(0, 0, 1, 1);
			Line line2(1, 1, 2, -2);
			node a = findIntersection(line1, line2);
			Assert::AreEqual(judge(line1,line2,a), 1);
		}

		TEST_METHOD(TestMethod2)
		{
			Line line1(0, 0, 1000, -1);
			Line line2(1, 1, 2, -2);
			node a = findIntersection(line1, line2);
			Assert::AreEqual(judge(line1, line2, a), 1);
		}

		TEST_METHOD(TestMethod3)
		{
			Line line1(0, 0, 1, 1);
			Line line2(19, 23, 2033, -2);
			node a = findIntersection(line1, line2);
			Assert::AreEqual(judge(line1, line2, a), 1);
		}

		TEST_METHOD(TestMethod4)
		{
			Line line1(0, 8, 1, 3);
			Line line2(1, 7845, 2, 29);
			node a = findIntersection(line1, line2);
			Assert::AreEqual(judge(line1, line2, a), 1);
		}

		TEST_METHOD(TestMethod5)
		{
			Line line1(0, 0, 1, 6);
			Line line2(1, 1, 2, -2);
			node a = findIntersection(line1, line2);
			Assert::AreEqual(judge(line1, line2, a), 1);
		}

		TEST_METHOD(TestMethod6)
		{
			Line line1(-581, 0, -98, 1);
			Line line2(41, 541, 2, -2);
			node a = findIntersection(line1, line2);
			Assert::AreEqual(judge(line1, line2, a), 1);
		}

		TEST_METHOD(TestMethod7)
		{
			Line line1(0, 60, 1543, 1);
			Line line2(122, 1, 2978, -2);
			node a = findIntersection(line1, line2);
			Assert::AreEqual(judge(line1, line2, a), 1);
		}

		TEST_METHOD(TestMethod8)
		{
			Line line1(0, 9756, 815, 1);
			Line line2(1, 1, 65, -987);
			node a = findIntersection(line1, line2);
			Assert::AreEqual(judge(line1, line2, a), 1);
		}

		TEST_METHOD(TestMethod9)
		{
			Line line1(0, 8, 1, 9);
			Line line2(1345, 1234, 2, -2);
			node a = findIntersection(line1, line2);
			Assert::AreEqual(judge(line1, line2, a), 1);
		}

		TEST_METHOD(TestMethod10)
		{
			Line line1(0, 0, 65, -2);
			Line line2(1551, -89, 65, -2);
			node a = findIntersection(line1, line2);
			Assert::AreEqual(judge(line1, line2, a), 1);
		}
	};
}
