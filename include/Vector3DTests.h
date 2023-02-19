#pragma once

#include "TestManager.h"
#include "Vector3D.h"

namespace pxd
{
	class Vector3DTests
	{
	public:
		void AddTests(TestManager& testManager);

	private:
		void AdditionTests(TestManager& testManager);
		void SubTests(TestManager& testManager);
		void MulTests(TestManager& testManager);
		void DivTests(TestManager& testManager);
		void DotTests(TestManager& testManager);
		void CrossTests(TestManager& testManager);
		void MagnitudeTests(TestManager& testManager);
		void NormalizeTests(TestManager& testManager);
		void ProjectRejectTests(TestManager& testManager);

		std::string baseName = "Vector3D Tests";
		Vector3D testVector;
	};
}