#pragma once

#include "Common.h"
#include <unordered_map>
#include <map>
#include <string>

namespace pxd
{
	class TestManager
	{
	public:
		// Rule of 5
		TestManager() = default; // default constructor
		TestManager(const TestManager& other) = delete; // copy constructor
		TestManager(TestManager&& other) = delete; // move constructor
		TestManager& operator=(const TestManager& other) = delete; // move assignment
		~TestManager() = default; // deconstructor

		void AddTest(std::string baseTest, std::string testName, bool result);

		void Run();

	private:
		std::unordered_map<std::string, std::map<std::string, bool>> tests;
	};
}