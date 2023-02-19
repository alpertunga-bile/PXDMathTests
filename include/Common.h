#pragma once

#include <limits>
#include <iostream>

inline bool CompareVectors(double* a, double* b, int size, double epsilon = std::numeric_limits<double>::epsilon())
{
	double absolute = 0.0;

	for (int i = 0; i < size; i++)
	{
		absolute = std::abs(a[i] - b[i]);
		if (absolute > epsilon)
		{
			return false;
		}
	}
	
	return true;
}

inline bool CompareMatrices(float* a, float* b, int size, float epsilon = std::numeric_limits<float>::epsilon())
{
	float absolute = 0.0f;

	for (int i = 0; i < size; i++)
	{
		absolute = std::abs(a[i] - b[i]);
		if (absolute > epsilon)
		{
			return false;
		}
	}

	return true;
}

inline void LOG_GREEN(std::string text)
{
	std::cout << "\033[1;32m" << text << "\033[0m\n";
}

inline void LOG_RED(std::string text)
{
	std::cout << "\033[1;31m" << text << "\033[0m\n";
}

inline void LOG_YELLOW(std::string text)
{
	std::cout << "\033[1;33m" << text << "\033[0m\n";
}
