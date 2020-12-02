#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream input("input.in", std::fstream::in);
	std::fstream output("output.out", std::fstream::out);

	std::vector<std::vector<int>> lettersFrequency(8, std::vector<int>(26, 0));
	std::string line;

	while (std::getline(input, line))
	{
		for (int it = 0; it < line.size(); it++)
		{
			lettersFrequency[it][line[it] - 'a']++;
		}
	}

	for (const auto& letters : lettersFrequency)
	{
		int pos{ 0 };

		for (int it = 0; it < 26; it++)
		{
			if (letters[pos] < letters[it])
			{
				pos = it;
			}
		}
		output << (char)('a' + pos);
	}

	input.close();
	output.close();
}