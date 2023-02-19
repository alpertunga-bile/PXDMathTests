#include "../include/TestManager.h"

namespace pxd
{
	void TestManager::AddTest(std::string baseTest, std::string testName, bool result)
	{
		tests[baseTest].insert({ testName, result });
	}

	void TestManager::Run()
	{
		for (auto [baseTest, baseMap] : tests)
		{
			std::cout << baseTest << "	----------------------------------------------------------------------------\n";
			int totalTests = baseMap.size();
			int totalPass = 0;
			const char* resultStr;

			for (const auto [name, result] : baseMap)
			{
				resultStr = result == true ? "True" : "False";
				if (result)
				{
					LOG_GREEN(name + " ==> " + resultStr);
					totalPass++;
				}
				else
				{
					LOG_RED(name + " ==> " + resultStr);
				}
			}

			std::cout << totalPass << " / " << totalTests << " are passed the tests\n";
		}
	}
}