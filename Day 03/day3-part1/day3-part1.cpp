#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream input("input.in", std::fstream::in);
	std::fstream output("output.out", std::fstream::out);
	int a{ 0 }, b{ 0 }, c{ 0 }, count{ 0 };

	while (input >> a >> b >> c)
	{
		if ((a + b > c) && (a + c > b) && (b + c > a))
		{
			count++;
		}
	}

	output << count;

	input.close();
	output.close();
}