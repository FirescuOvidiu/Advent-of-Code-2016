#include "../../AOCHeaders/stdafx.h"


struct Coordinate
{
	Coordinate(int x = 0, int y = 0) : x(x), y(y) {}

	bool operator<(const Coordinate& c) const
	{
		return (this->x == c.x ? this->y < c.y : this->x < c.x);
	}

	int x, y;
};


int main()
{
	std::fstream in("input.in", std::fstream::in);
	std::fstream out("output.out", std::fstream::out);

	const std::vector<int> dx{ 0,1,0,-1 }, dy{ -1,0,1,0 };
	std::set<Coordinate> visited;
	std::string sequence;
	int x{ 0 }, y{ 0 }, numBlocks{ 0 }, direction{ 3 };
	char dir{};

	visited.insert({ 0,0 });

	while (in >> sequence)
	{
		std::istringstream ss{ sequence };
		ss >> dir >> numBlocks;

		if (dir == 'L')
		{
			direction = (direction + 1) % 4;
			for (int it = 0; it < numBlocks; it++)
			{
				x += dx[direction];
				y += dy[direction];

				if (visited.find({ x,y }) != std::end(visited))
				{
					out << std::abs(x) + std::abs(y);
					exit(0);
				}
				else
				{
					visited.insert(Coordinate(x, y));
				}
			}
		}
		else
		{
			direction = (direction + 3) % 4;
			for (int it = 0; it < numBlocks; it++)
			{
				x += dx[direction];
				y += dy[direction];
				if (visited.find({ x,y }) != std::end(visited))
				{
					out << std::abs(x) + std::abs(y);
					exit(0);
				}
				else
				{
					visited.insert(Coordinate(x, y));
				}
			}
		}
	}

	in.close();
	out.close();
}