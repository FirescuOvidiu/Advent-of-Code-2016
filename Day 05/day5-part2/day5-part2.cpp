#include "../../AOCHeaders/stdafx.h"
#include "md5.h"


int main()
{
	std::fstream input("input.in", std::fstream::in);
	std::fstream output("output.out", std::fstream::out);

	std::string doorId, hashDoorId, password(8, 'a');
	int number{ 0 }, times{ 0 };

	input >> doorId;

	while (times < 8)
	{
		hashDoorId = md5(doorId + std::to_string(number));
		if ((hashDoorId.substr(0, 5) == "00000") && (isdigit(hashDoorId[5]))
			&& (hashDoorId[5] - '0' < 8) && (password[hashDoorId[5] - '0'] == 'a'))
		{
			password[hashDoorId[5] - '0'] = hashDoorId[6];
			times++;
		}

		number++;
	}

	output << password;

	input.close();
	output.close();
}