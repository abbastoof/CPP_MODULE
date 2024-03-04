/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:53:13 by atoof             #+#    #+#             */
/*   Updated: 2024/03/04 18:53:08 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

// struct ComplexType
// {
//     int id;
//     std::string name;

//     // Default constructor
//     ComplexType() : id(0), name("") {}

//     // Parameterized constructor
//     ComplexType(int id, std::string name) : id(id), name(name) {}
// };


#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

/* My own test */

// constexpr int TEST_SIZE = 5;
// constexpr int LARGE_TEST_SIZE = 700;

// void testEmptyArray()
// {
// 	std::cout << "---- TEST EMPTY ----\n";
// 	Array<int> emptyInt;
// 	std::cout << "Testing empty int array... ";
// 	if (emptyInt.getSize() != 0)
// 		std::cout << "\033[33mFAIL\033[0m\n";
// 	else
// 		std::cout << "\033[32mOKAY\033[0m\n";

// 	Array<std::string> emptyString;
// 	std::cout << "Testing empty string array... ";
// 	if (emptyString.getSize() != 0)
// 		std::cout << "\033[33mFAIL\033[0m\n";
// 	else
// 		std::cout << "\033[32mOKAY\033[0m\n";
// 	std::cout << "-------------------\n";
// }

// void testArraySize()
// {
// 	std::cout << "---- TEST SIZE ----\n";
// 	Array<int> sizedInt(TEST_SIZE);
// 	std::cout << "Testing int array with size " << TEST_SIZE << "... ";
// 	if (sizedInt.getSize() != TEST_SIZE)
// 		std::cout << "\033[33mFAIL\033[0m\n";
// 	else
// 		std::cout << "\033[32mOKAY\033[0m\n";

// 	Array<std::string> sizedString(TEST_SIZE);
// 	std::cout << "Testing string array with size " << TEST_SIZE << "... ";
// 	if (sizedString.getSize() != TEST_SIZE)
// 		std::cout << "\033[33mFAIL\033[0m\n";
// 	else
// 		std::cout << "\033[32mOKAY\033[0m\n";
// 	std::cout << "-------------------\n";
// }

// void testCopyConstructor()
// {
// 	std::cout << "---- TEST COPY ----\n";
// 	Array<int> originalInt(TEST_SIZE);
// 	Array<int> copyInt(originalInt);
// 	std::cout << "Testing copy of int array... ";
// 	if (copyInt.getSize() != TEST_SIZE)
// 		std::cout << "\033[33mFAIL\033[0m\n";
// 	else
// 		std::cout << "\033[32mOKAY\033[0m\n";

// 	Array<std::string> originalString(TEST_SIZE);
// 	Array<std::string> copyString(originalString);
// 	std::cout << "Testing copy of string array... ";
// 	if (copyString.getSize() != TEST_SIZE)
// 		std::cout << "\033[33mFAIL\033[0m\n";
// 	else
// 		std::cout << "\033[32mOKAY\033[0m\n";
// 	std::cout << "-------------------\n";
// }

// void testAssignmentOperator()
// {
// 	std::cout << "---- TEST ASSIGN ----\n";
// 	Array<int> originalInt(TEST_SIZE);
// 	Array<int> assignedInt;
// 	assignedInt = originalInt;
// 	std::cout << "Testing assignment of int array... ";
// 	if (assignedInt.getSize() != TEST_SIZE)
// 		std::cout << "\033[33mFAIL\033[0m\n";
// 	else
// 		std::cout << "\033[32mOKAY\033[0m\n";
// 	std::cout << "-------------------\n";
// }

// void testSubscript()
// {
// 	std::cout << "---- TEST SUBSCRIPT and EXCEPTIONS ----\n";
// 	Array<int> number(LARGE_TEST_SIZE);
// 	try
// 	{
// 		number[2] = 0;
// 		std::cout << "Access within bounds... \033[32mOKAY\033[0m\n";
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cerr << "Within bounds exception: " << e.what() << '\n';
// 	}

// 	try
// 	{
// 		number[LARGE_TEST_SIZE] = 0; // This should throw an exception
// 		std::cout << "\033[33mFAIL: Out of bounds access did not throw an exception\033[0m\n";
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << "Out of bounds access... \033[32mOKAY\033[0m\n";
// 	}
// 	std::cout << "-------------------\n";
// }

// void testConstArrayAccess()
// {
// 	std::cout << "---- TEST CONST ARRAY ACCESS ----\n";

// 	// Initialize a const Array with some values
// 	const Array<int> constArray(5);
// 	for (size_t i = 0; i < constArray.getSize(); ++i)
// 	{
// 		// This should compile and work, because we are only reading from the const instance
// 		std::cout << "Element at index " << i << " is: " << constArray[i] << std::endl;
// 	}

// 	// The following line should cause a compile-time error if uncommented, as it attempts to write to a const instance
// 	// constArray[0] = 10;

// 	std::cout << "Read-only access to const Array instance... \033[32mOKAY\033[0m\n";
// 	std::cout << "---------------------------------\n";
// }

// void testReadWriteAccess()
// {
// 	std::cout << "---- TEST READ/WRITE ACCESS WITH EXCEPTION ----\n";
// 	Array<int> numbers(5);
// 	// Write
// 	for (int i = 0; i < 5; ++i)
// 		numbers[i] = i * 10;

// 	try
// 	{
// 		// Intentionally access out of bounds to trigger an exception
// 		numbers[10] = 100;
// 		std::cout << "Exception was not thrown for out-of-bounds access.\n";
// 	}
// 	catch (const std::out_of_range &e)
// 	{
// 		std::cout << "Caught expected out-of-range exception: " << e.what() << "\n";
// 	}
// }

// void testComplexType()
// {
// 	std::cout << "---- TEST COMPLEX TYPE WITH EXCEPTION ----\n";
// 	Array<ComplexType> complexArray(2);

// 	try
// 	{
// 		complexArray[0] = {1, "First"};
// 		complexArray[1] = {2, "Second"};

// 		if (complexArray[0].id != 1 || complexArray[0].name != "First" ||
// 			complexArray[1].id != 2 || complexArray[1].name != "Second")
// 		{
// 			std::cout << "Complex type handling failed.\n";
// 			return;
// 		}

// 		std::cout << "Complex type handling verified.\n";
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << "Unexpected exception: " << e.what() << "\n";
// 	}
// }

// void testCopyIndependence()
// {
// 	std::cout << "---- TEST COPY INDEPENDENCE ----\n";

// 	try
// 	{
// 		Array<int> original(5);
// 		for (int i = 0; i < 5; ++i)
// 			original[i] = i;

// 		Array<int> copy = original;
// 		copy[2] = 100;

// 		if (original[2] != 2)
// 		{
// 			std::cout << "Original array was modified.\n";
// 			return;
// 		}

// 		std::cout << "Original and copy are independent.\n";
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << "Unexpected exception: " << e.what() << "\n";
// 	}

// 	std::cout << "---------------------------------\n";
// }

// int main()
// {
// 	testEmptyArray();
// 	testArraySize();
// 	testCopyConstructor();
// 	testAssignmentOperator();
// 	testSubscript();
// 	testConstArrayAccess();
// 	testReadWriteAccess();
// 	testComplexType();
// 	testCopyIndependence();
// 	return 0;
// }