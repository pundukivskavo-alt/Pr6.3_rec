// Unit-тест до завдання 6.3 (рекурсивний спосіб). Варіант 20
// Функція знаходить найбільший з елементів масиву (звичайна функція і шаблон).
#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr6.3_rec/Pr6.3_rec.cpp"      // шлях і назву файлу змініть на свої

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63_rec
{
	TEST_CLASS(UnitTest63_rec)
	{
	public:

		TEST_METHOD(TestMaxInt)
		{
			int a[6] = { 3, -1, 7, 2, 7, 0 };
			int t = Max(a, 6, 0, a[0]);
			Assert::AreEqual(7, t);
		}

		TEST_METHOD(TestMaxIntTemplate)
		{
			int a[6] = { -5, -3, -9, -1, -7, -4 };
			int t = Max<int>(a, 6, 0, a[0]);
			Assert::AreEqual(-1, t);
		}

		TEST_METHOD(TestMaxDouble)
		{
			double b[4] = { 1.1, 2.2, 9.9, 4.3 };
			double t = Max<double>(b, 4, 0, b[0]);
			Assert::AreEqual(9.9, t, 1e-9);
		}

		TEST_METHOD(TestMaxString)
		{
			string c[3] = { "apple", "pear", "banana" };
			string t = Max<string>(c, 3, 0, c[0]);
			Assert::AreEqual(string("pear"), t);
		}
	};
}