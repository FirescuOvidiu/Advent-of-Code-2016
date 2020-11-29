#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream input("input.in", std::fstream::in);
	std::fstream output("output.out", std::fstream::out);

	std::vector<std::vector<char>> keypad{
		{'1','2','3'} ,
		{'4','5','6'} ,
		{'7','8','9'}
	};
	std::string line;
	size_t row{ keypad.size() }, column{ keypad[0].size() };
	int x{ (int)row / 2 }, y{ (int)column / 2 };
	char dir{};

	while (std::getline(input, line))
	{
		std::stringstream ss{ line };

		while (ss >> dir)
		{
			switch (dir)
			{
			case 'L':
				if (y - 1 >= 0)
				{
					y--;
				}
				break;

			case 'R':
				if (y + 1 < column)
				{
					y++;
				}
				break;

			case 'U':
				if (x - 1 >= 0)
				{
					x--;
				}
				break;

			case 'D':
				if (x + 1 < row)
				{
					x++;
				}
				break;
			}
		}
		output << keypad[x][y];
	}

	input.close();
	output.close();
}