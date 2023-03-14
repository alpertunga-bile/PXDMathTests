#include "../include/Vector2DTests.h"

namespace pxd
{
	void Vector2DTests::AddTests(TestManager& testManager)
	{
		testVector = Vector2D(1.0, 2.0);

		AdditionTests(testManager);
		SubTests(testManager);
		MulTests(testManager);
		DivTests(testManager);
		DotTests(testManager);
		MagnitudeTests(testManager);
		NormalizeTests(testManager);
	}

	void Vector2DTests::AdditionTests(TestManager& testManager)
	{
		testManager.AddTest(
			baseName,
			"Add With Z Component",
			CompareVectors(
				(testVector + Vector2D(0.0, 1.0)).v_ptr,
				Vector2D(1.0, 3.0).v_ptr,
				2
			)
		);

		testManager.AddTest(
			baseName,
			"Add With Another Vector",
			CompareVectors(
				(testVector + testVector).v_ptr,
				Vector2D(2.0, 4.0).v_ptr,
				2
			)
		);

		testManager.AddTest(
			baseName,
			"Add With Negative Itself",
			CompareVectors(
				(testVector + (-testVector)).v_ptr,
				Vector2D(0.0, 0.0).v_ptr,
				2
			)
		);
	}

	void Vector2DTests::SubTests(TestManager& testManager)
	{
		testManager.AddTest(
			baseName,
			"Sub From Z Component",
			CompareVectors(
				(testVector - Vector2D(0.0, 1.0)).v_ptr,
				Vector2D(1.0, 1.0).v_ptr,
				2
			)
		);

		testManager.AddTest(
			baseName,
			"Sub With Another Vector",
			CompareVectors(
				(testVector - Vector2D(2.0, 1.0)).v_ptr,
				Vector2D(-1.0, 1.0).v_ptr,
				2
			)
		);

		testManager.AddTest(
			baseName,
			"Sub With Itself",
			CompareVectors(
				(testVector - testVector).v_ptr,
				Vector2D(0.0, 0.0).v_ptr,
				2
			)
		);
	}

	void Vector2DTests::MulTests(TestManager& testManager)
	{
		testManager.AddTest(
			baseName,
			"Mul With Scalar",
			CompareVectors(
				(testVector * 3.0).v_ptr,
				Vector2D(3.0, 6.0).v_ptr,
				2
			)
		);

		testManager.AddTest(
			baseName,
			"Mul With 0",
			CompareVectors(
				(testVector * 0.0).v_ptr,
				Vector2D(0.0, 0.0).v_ptr,
				2
			)
		);

		testManager.AddTest(
			baseName,
			"Mul With -1",
			CompareVectors(
				(testVector * -1.0).v_ptr,
				Vector2D(-1.0, -2.0).v_ptr,
				2
			)
		);
	}

	void Vector2DTests::DivTests(TestManager& testManager)
	{
		testManager.AddTest(
			baseName,
			"Div With Scalar",
			CompareVectors(
				(testVector / 2.0).v_ptr,
				Vector2D(1.0 / 2.0, 1.0).v_ptr,
				2
			)
		);

		testManager.AddTest(
			baseName,
			"Div With 0",
			CompareVectors(
				(testVector / 0.0).v_ptr,
				testVector.v_ptr,
				2
			)
		);

		testManager.AddTest(
			baseName,
			"Div With -1",
			CompareVectors(
				(testVector / -1.0).v_ptr,
				Vector2D(-1.0, -2.0).v_ptr,
				2
			)
		);
	}

	void Vector2DTests::DotTests(TestManager& testManager)
	{
		testManager.AddTest(
			baseName,
			"Dot Test Orthogonality",
			Dot(Vector2D(1.0, 0.0), Vector2D(0.0, 1.0)) == 0.0
		);

		testManager.AddTest(
			baseName,
			"Dot Test Parallel",
			Dot(Vector2D(1.0, 0.0), Vector2D(1.0, 0.0)) == 1.0
		);

		testManager.AddTest(
			baseName,
			"Dot Test Reverse Direction",
			Dot(Vector2D(1.0, 0.0), Vector2D(-1.0, 0.0)) == -1.0
		);

		testManager.AddTest(
			baseName,
			"Dot Test With Two Vector",
			Dot(testVector, testVector) == 5.0
		);
	}

	void Vector2DTests::MagnitudeTests(TestManager& testManager)
	{
		testManager.AddTest(
			baseName,
			"Magnitude Basis Axis",
			Vector2D(1.0, 0.0).Magnitude() == 1.0
		);

		testManager.AddTest(
			baseName,
			"Magnitude Vector",
			testVector.Magnitude() == 2.2360679774997896964091736687313
		);
	}

	void Vector2DTests::NormalizeTests(TestManager& testManager)
	{
		testManager.AddTest(
			baseName,
			"Normalize Basis Axis",
			CompareVectors(
				Vector2D(1.0, 0.0).v_ptr,
				Vector2D(1.0, 0.0).v_ptr,
				2
			)
		);
	}
}