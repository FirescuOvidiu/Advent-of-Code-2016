#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream input("input.in", std::fstream::in);
	std::fstream output("output.out", std::fstream::out);
	std::vector < std::vector< int >> triangle(3, std::vector<int>(3, 0));
	int count{ 0 };

	while (input >> triangle[0][0] >> triangle[0][1] >> triangle[0][2])
	{
		for (int it = 1; it < 3; it++)
		{
			input >> triangle[it][0] >> triangle[it][1] >> triangle[it][2];
		}

		for (int it = 0; it < 3; it++)
		{
			if ((triangle[0][it] + triangle[1][it] > triangle[2][it]) &&
				(triangle[1][it] + triangle[2][it] > triangle[0][it]) &&
				(triangle[2][it] + triangle[0][it] > triangle[1][it]))
			{
				count++;
			}
		}
	}

	output << count;

	input.close();
	output.close();
}