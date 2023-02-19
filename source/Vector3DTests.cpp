#include "../include/Vector3DTests.h"

namespace pxd
{
	void Vector3DTests::AddTests(TestManager& testManager)
	{
		testVector = Vector3D(1.0, 2.0, 3.0);

		AdditionTests(testManager);
		SubTests(testManager);
		MulTests(testManager);
		DivTests(testManager);
		DotTests(testManager);
		CrossTests(testManager);
		MagnitudeTests(testManager);
		NormalizeTests(testManager);
		ProjectRejectTests(testManager);
	}

	void Vector3DTests::AdditionTests(TestManager& testManager)
	{
		testManager.AddTest(
			baseName,
			"Add With Z Component",
			CompareVectors(
				(testVector + Vector3D(0.0, 0.0, 1.0)).v_ptr,
				Vector3D(1.0, 2.0, 4.0).v_ptr,
				3
			)
		);

		testManager.AddTest(
			baseName,
			"Add With Another Vector",
			CompareVectors(
				(testVector + testVector).v_ptr,
				Vector3D(2.0, 4.0, 6.0).v_ptr,
				3
			)
		);

		testManager.AddTest(
			baseName,
			"Add With Negative Itself",
			CompareVectors(
				(testVector + (-testVector)).v_ptr,
				Vector3D(0.0, 0.0, 0.0).v_ptr,
				3
			)
		);
	}
	
	void Vector3DTests::SubTests(TestManager& testManager)
	{
		testManager.AddTest(
			baseName,
			"Sub From Z Component",
			CompareVectors(
				(testVector - Vector3D(0.0, 0.0, 1.0)).v_ptr,
				Vector3D(1.0, 2.0, 2.0).v_ptr,
				3
			)
		);

		testManager.AddTest(
			baseName,
			"Sub With Another Vector",
			CompareVectors(
				(testVector - Vector3D(3.0, 2.0, 1.0)).v_ptr,
				Vector3D(-2.0, 0.0, 2.0).v_ptr,
				3
			)
		);

		testManager.AddTest(
			baseName,
			"Sub With Itself",
			CompareVectors(
				(testVector - testVector).v_ptr,
				Vector3D(0.0, 0.0, 0.0).v_ptr,
				3
			)
		);
	}

	void Vector3DTests::MulTests(TestManager& testManager)
	{
		testManager.AddTest(
			baseName,
			"Mul With Scalar",
			CompareVectors(
				(testVector * 3.0).v_ptr,
				Vector3D(3.0, 6.0, 9.0).v_ptr,
				3
			)
		);

		testManager.AddTest(
			baseName,
			"Mul With 0",
			CompareVectors(
				(testVector * 0.0).v_ptr,
				Vector3D(0.0, 0.0, 0.0).v_ptr,
				3
			)
		);

		testManager.AddTest(
			baseName,
			"Mul With -1",
			CompareVectors(
				(testVector * -1.0).v_ptr,
				Vector3D(-1.0, -2.0, -3.0).v_ptr,
				3
			)
		);
	}

	void Vector3DTests::DivTests(TestManager& testManager)
	{
		testManager.AddTest(
			baseName,
			"Div With Scalar",
			CompareVectors(
				(testVector / 2.0).v_ptr,
				Vector3D(1.0 / 2.0, 1.0, 3.0 / 2.0).v_ptr,
				3
			)
		);

		testManager.AddTest(
			baseName,
			"Div With 0",
			CompareVectors(
				(testVector / 0.0).v_ptr,
				testVector.v_ptr,
				3
			)
		);

		testManager.AddTest(
			baseName,
			"Div With -1",
			CompareVectors(
				(testVector / -1.0).v_ptr,
				Vector3D(-1.0, -2.0, -3.0).v_ptr,
				3
			)
		);
	}

	void Vector3DTests::DotTests(TestManager& testManager)
	{
		testManager.AddTest(
			baseName,
			"Dot Test Orthogonality",
			Dot(Vector3D(1.0, 0.0, 0.0), Vector3D(0.0, 1.0, 0.0)) == 0.0
		);

		testManager.AddTest(
			baseName,
			"Dot Test Parallel",
			Dot(Vector3D(1.0, 0.0, 0.0), Vector3D(1.0, 0.0, 0.0)) == 1.0
		);

		testManager.AddTest(
			baseName,
			"Dot Test Reverse Direction",
			Dot(Vector3D(1.0, 0.0, 0.0), Vector3D(-1.0, 0.0, 0.0)) == -1.0
		);

		testManager.AddTest(
			baseName,
			"Dot Test With Two Vector",
			Dot(testVector, testVector) == 14.0
		);
	}

	void Vector3DTests::CrossTests(TestManager& testManager)
	{
		testManager.AddTest(
			baseName,
			"Cross Test Find X Axis",
			CompareVectors(
				Cross(Vector3D(0.0, 1.0, 0.0), Vector3D(0.0, 0.0, 1.0)).v_ptr,
				Vector3D(1.0, 0.0, 0.0).v_ptr,
				3
			)
		);
	}

	void Vector3DTests::MagnitudeTests(TestManager& testManager)
	{
	}

	void Vector3DTests::NormalizeTests(TestManager& testManager)
	{
	}

	void Vector3DTests::ProjectRejectTests(TestManager& testManager)
	{
	}
}