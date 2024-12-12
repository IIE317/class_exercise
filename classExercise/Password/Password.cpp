#include <iostream>
#include <string.h> // Required for strcmp

struct Password
{
	char value[16]; // Character array to store the password, max length of 15 characters + null terminator
	bool incorrect;  // Boolean flag indicating if the entered password is incorrect
	Password() : value(""), incorrect(true) // Constructor to initialize password and incorrect flag
	{
	}
};

int main()
{
	std::cout << "Enter your password to continue:" << std::endl; // Prompt the user to enter a password
	Password pwd; // Create an instance of the Password structure
	std::cin >> pwd.value; // Read the user input and store it into the value field of the Password structure

	// Compare the entered password with the hardcoded password "********" using strcmp.
	// If the strings match, strcmp returns 0, the negation (!) inverts it into true, 
	// and therefore, the incorrect flag becomes false
	if (!strcmp(pwd.value, "********"))
		pwd.incorrect = false;

	// If the incorrect flag is false (meaning the password was correct)
	if (!pwd.incorrect)
		std::cout << "Congratulations\n"; // Print "Congratulations" to the console

	//This is the vulnerability: the program allows access if we input "********" but there is no way to know this unless we go through the code.

	return 0; // End of program
}

/// --Explanation--
///		1. The program initializes the incorrect flag to true, indicating an incorrect password, which is ok.
///		2. The program reads password input from the user.
///		3. The program checks if the input matches "********" using strcmp. This is the vulnerability,
///		   the program should not have a hardcoded password in the code.
///		4. The program allows access if the user entered "********", which is the only way to obtain the message.