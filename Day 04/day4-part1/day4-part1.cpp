#include "../../AOCHeaders/stdafx.h"


std::tuple<std::vector<int>, std::string, int> getInput(const std::string& line)
{
	std::vector<int> letters(26, 0);
	std::istringstream iss(line);
	std::string checksum;
	int id{ 0 };
	char c{};

	// get letters for the encrypted name
	while ((iss >> c) && (!isdigit(c)))
	{
		if (islower(c))
		{
			letters[c - 'a']++;
		}
	}

	// get sector ID
	do
	{
		id = id * 10 + (c - '0');
	} while ((iss >> c) && (isdigit(c)));

	// get checksum
	while ((iss >> c) && (islower(c)))
	{
		checksum.push_back(c);
	}

	return{ letters, checksum, id };
}


int getSumIdRealRooms(std::fstream& input)
{
	std::vector<int> mostCommonValues(26, 0);
	std::string line;
	int sum{ 0 }, it{ 0 };

	while (std::getline(input, line))
	{
		auto [letters, checksum, id] = getInput(line);

		mostCommonValues = letters;
		std::sort(std::begin(mostCommonValues), std::end(mostCommonValues), std::greater<int>());

		for (it = 0; it < 5; it++)
		{
			if (letters[checksum[it] - 'a'] != mostCommonValues[it])
			{
				break;
			}
		}

		if (it == 5)
		{
			sum += id;
		}
	}

	return sum;
}


int main()
{
	std::fstream input("input.in", std::fstream::in);
	std::fstream output("output.out", std::fstream::out);

	output << getSumIdRealRooms(input);

	input.close();
	output.close();
}