#include "../../AOCHeaders/stdafx.h"


std::tuple<std::string, std::vector<int>, std::string, int> getInput(const std::string& line)
{
	std::vector<int> letters(26, 0);
	std::istringstream iss(line);
	std::string checksum, name;
	int id{ 0 };
	char c{};

	// get encrypted name and letters for the encrypted name
	while ((iss >> c) && (!isdigit(c)))
	{
		if (islower(c))
		{
			letters[c - 'a']++;
			name.push_back(c);
		}
		else
		{
			name.push_back(' ');
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

	return{ name, letters, checksum, id };
}


int getSumIdRealRooms(std::fstream& input)
{
	std::vector<int> mostCommonValues(26, 0);
	std::string line;
	int sum{ 0 }, it{ 0 };

	while (std::getline(input, line))
	{
		auto [name, letters, checksum, id] = getInput(line);

		std::copy(std::begin(letters), std::end(letters), std::begin(mostCommonValues));
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
			for (auto& c : name)
			{
				if (c != ' ')
				{
					c = ((c - 'a') + id) % 26 + 'a';
				}
			}

			if (name.compare("northpole object storage ") == 0)
			{
				return id;
			}
		}
	}

	return -1;
}


int main()
{
	std::fstream input("input.in", std::fstream::in);
	std::fstream output("output.out", std::fstream::out);

	output << getSumIdRealRooms(input);

	input.close();
	output.close();
}