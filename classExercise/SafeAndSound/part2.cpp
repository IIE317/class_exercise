#include "part2.h"
#include <iostream>
#include <stdexcept>
#include <cstring>

char* safe_string_copy(char* dest, unsigned int destsize, char* src)
{
    unsigned int srcsize = static_cast<unsigned int>(strlen(src));

    /// --Explenation--
    ///     The check `if (srcsize >= destsize)` fails to account for the null terminator.
    ///     Strings in C require an extra byte for the null terminator (`'\0`) at the end.
    ///     Without this, the function might not leave space for `'\0`, leading to undefined behavior.
    ///     Also, the loop does not copy the null terminator, causing `dest` to be improperly terminated.
    ///     These issues lead to potential buffer overflows or incorrect string behavior.
    if (srcsize + 1 > destsize) // Adjusted to include space for null terminator
        throw std::overflow_error("possible buffer overflow");

    // Safely copy the string including the null terminator
    for (unsigned int i = 0; i <= srcsize; i++)
    {
        dest[i] = src[i];
    }

    return dest;
}

#define BUF_SIZE 20
void part2()
{
    char password[] = "secret";
    char dest[BUF_SIZE];
    char src[] = "hello world!";

    safe_string_copy(dest, BUF_SIZE, src);

    std::cout << src << std::endl;
    std::cout << dest << std::endl;
}
