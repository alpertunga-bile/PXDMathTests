#pragma once

#include "TestManager.h"
#include "Vector2D.h"

namespace pxd
{
	class Vector2DTests
	{
	public:
		void AddTests(TestManager& testManager);

	private:
		void AdditionTests(TestManager& testManager);
		void SubTests(TestManager& testManager);
		void MulTests(TestManager& testManager);
		void DivTests(TestManager& testManager);
		void DotTests(TestManager& testManager);
		void MagnitudeTests(TestManager& testManager);
		void NormalizeTests(TestManager& testManager);

		std::string baseName = "Vector2D Tests";
		Vector2D testVector;
	};
}