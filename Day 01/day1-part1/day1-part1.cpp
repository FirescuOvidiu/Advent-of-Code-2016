#include "../../AOCHeaders/stdafx.h"


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	const std::vector<int> dx{ 0,1,0,-1 }, dy{ -1,0,1,0 };
	std::string sequence;
	int x{ 0 }, y{ 0 }, numBlocks{ 0 }, direction{ 3 };
	char dir{};

	while (in >> sequence)
	{
		std::stringstream ss{ sequence };
		ss >> dir >> numBlocks;

		if (dir == 'L')
		{
			direction = (direction + 1) % 4;
			x += dx[direction] * numBlocks;
			y += dy[direction] * numBlocks;
		}
		else
		{
			direction = (direction + 3) % 4;
			x += dx[direction] * numBlocks;
			y += dy[direction] * numBlocks;
		}
	}

	out << std::abs(x) + std::abs(y);

	in.close();
	out.close();
}