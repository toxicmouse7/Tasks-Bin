#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* cities[] = { "astrahan\0", "vologda\0", "astana\0" };

int main()
{
	/*FILE* f;
	fopen_s(&f, "cities.txt", "r");*/
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
				continue;
			if (cities[i][strlen(cities[j])] == cities[j][0])
			{
				count++;
				break;
			}
			else continue;

		}
	}
	if (count != 2)
		printf("No\n");
	else printf("Yes\n");

}