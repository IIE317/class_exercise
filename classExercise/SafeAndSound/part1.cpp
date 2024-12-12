#include "part1.h"
#include <iostream>
#include <cstring>

char* string_copy(char* dest, unsigned int destsize, char* src)
{
	char* ret = dest;
	while (*dest++ = *src++)
		;
	return ret;
}

void part1()
{
	char password[] = "secret";
	/// --Explenation--
	///		Dest was too small.
	///		Which means, we cant fill a 12 chars array, with a 13 chars array.
	///		So, we could just changed its size this way:
	///		char dest[15];
	///		but we could do it BETTER 🤩:
	int i = 0;
	char src[] = "hello world!";
	char dest[sizeof(src)];
	///		This way, dest will be the size of the letters that will be implented there.

	string_copy(dest, 15, src);

	std::cout << src << std::endl;
	std::cout << dest << std::endl;
}
