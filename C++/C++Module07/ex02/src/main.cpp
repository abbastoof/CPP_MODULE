/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:53:13 by atoof             #+#    #+#             */
/*   Updated: 2024/03/04 12:31:21 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

/* My own test */

constexpr int TEST_SIZE = 5;
constexpr int LARGE_TEST_SIZE = 700;

void testEmptyArray()
{
	std::cout << "---- TEST EMPTY ----\n";
	Array<int> emptyInt;
	std::cout << "Testing empty int array... ";
	if (emptyInt.getSize() != 0)
		std::cout << "\033[33mFAIL\033[0m\n";
	else
		std::cout << "\033[32mOKAY\033[0m\n";

	Array<std::string> emptyString;
	std::cout << "Testing empty string array... ";
	if (emptyString.getSize() != 0)
		std::cout << "\033[33mFAIL\033[0m\n";
	else
		std::cout << "\033[32mOKAY\033[0m\n";
	std::cout << "-------------------\n";
}

void testArraySize()
{
	std::cout << "---- TEST SIZE ----\n";
	Array<int> sizedInt(TEST_SIZE);
	std::cout << "Testing int array with size " << TEST_SIZE << "... ";
	if (sizedInt.getSize() != TEST_SIZE)
		std::cout << "\033[33mFAIL\033[0m\n";
	else
		std::cout << "\033[32mOKAY\033[0m\n";

	Array<std::string> sizedString(TEST_SIZE);
	std::cout << "Testing string array with size " << TEST_SIZE << "... ";
	if (sizedString.getSize() != TEST_SIZE)
		std::cout << "\033[33mFAIL\033[0m\n";
	else
		std::cout << "\033[32mOKAY\033[0m\n";
	std::cout << "-------------------\n";
}

void testCopyConstructor()
{
	std::cout << "---- TEST COPY ----\n";
	Array<int> originalInt(TEST_SIZE);
	Array<int> copyInt(originalInt);
	std::cout << "Testing copy of int array... ";
	if (copyInt.getSize() != TEST_SIZE)
		std::cout << "\033[33mFAIL\033[0m\n";
	else
		std::cout << "\033[32mOKAY\033[0m\n";

	Array<std::string> originalString(TEST_SIZE);
	Array<std::string> copyString(originalString);
	std::cout << "Testing copy of string array... ";
	if (copyString.getSize() != TEST_SIZE)
		std::cout << "\033[33mFAIL\033[0m\n";
	else
		std::cout << "\033[32mOKAY\033[0m\n";
	std::cout << "-------------------\n";
}

void testAssignmentOperator()
{
	std::cout << "---- TEST ASSIGN ----\n";
	Array<int> originalInt(TEST_SIZE);
	Array<int> assignedInt;
	assignedInt = originalInt;
	std::cout << "Testing assignment of int array... ";
	if (assignedInt.getSize() != TEST_SIZE)
		std::cout << "\033[33mFAIL\033[0m\n";
	else
		std::cout << "\033[32mOKAY\033[0m\n";
	std::cout << "-------------------\n";
}

void testSubscriptAndExceptions()
{
	std::cout << "---- TEST SUBSCRIPT and EXCEPTIONS ----\n";
	Array<int> number(LARGE_TEST_SIZE);
	try
	{
		number[2] = 0;
		std::cout << "Access within bounds... \033[32mOKAY\033[0m\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << "Within bounds exception: " << e.what() << '\n';
	}

	try
	{
		number[LARGE_TEST_SIZE] = 0; // This should throw an exception
		std::cout << "\033[33mFAIL: Out of bounds access did not throw an exception\033[0m\n";
	}
	catch (const std::exception &e)
	{
		std::cout << "Out of bounds access... \033[32mOKAY\033[0m\n";
	}
	std::cout << "-------------------\n";
}

int main()
{
	testEmptyArray();
	testArraySize();
	testCopyConstructor();
	testAssignmentOperator();
	testSubscriptAndExceptions();
	return 0;
}
