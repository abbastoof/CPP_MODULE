/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:53:13 by atoof             #+#    #+#             */
/*   Updated: 2024/03/04 12:16:17 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

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
    delete [] mirror;
    return 0;
}

/* My own test */

// int main()
// {	
// 	std::cout << "---- TEST EMPTY ----" << std::endl;
// 	std::cout << "Initializing empty int array..." << std::endl;
// 	Array<int> empty;
// 	std::cout << "--------------------" << std::endl;
// 	if (empty.getSize() != 0)
// 		std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
// 	else
// 		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
// 	std::cout << "--------------------" << std::endl;
// 	std::cout << "Initializing empty string array..." << std::endl;
// 	Array<std::string> emptyStr;
// 	std::cout << "--------------------" << std::endl;
// 	if (emptyStr.getSize() != 0)
// 		std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
// 	else
// 		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
// 	std::cout << "--------------------" << std::endl;
// 	std::cout << "---- TEST SIZE ----" << std::endl;
// 	std::cout << "Initializing int array with size 5..." << std::endl;
// 	Array<int> size(5);
// 	std::cout << "--------------------" << std::endl;
// 	if (size.getSize() != 5)
// 		std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
// 	else
// 		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
// 	std::cout << "--------------------" << std::endl;
// 	std::cout << "Initializing string array with size 5..." << std::endl;
// 	Array<std::string> sizeStr(5);
// 	std::cout << "--------------------" << std::endl;
// 	if (sizeStr.getSize() != 5)
// 		std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
// 	else
// 		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
// 	std::cout << "--------------------" << std::endl;
// 	std::cout << "---- TEST COPY ----" << std::endl;
// 	std::cout << "Initializing int array with size 5..." << std::endl;
// 	Array<int> copy(size);
// 	std::cout << "--------------------" << std::endl;
// 	if (copy.getSize() != 5)
// 		std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
// 	else
// 		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
// 	std::cout << "--------------------" << std::endl;
// 	std::cout << "Initializing string array with size 5..." << std::endl;
// 	Array<std::string> copyStr(sizeStr);
// 	std::cout << "--------------------" << std::endl;
// 	if (copyStr.getSize() != 5)
// 		std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
// 	else
// 		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
// 	std::cout << "--------------------" << std::endl;
// 	std::cout << "---- TEST ASSIGN ----" << std::endl;
// 	std::cout << "Initializing int array with size 5..." << std::endl;
// 	Array<int> assign;
// 	assign = size;
// 	std::cout << "--------------------" << std::endl;
// 	if (assign.getSize() != 5)
// 		std::cout << "\033[33mTEST FAIL\033[0m" << std::endl;
// 	else
// 		std::cout << "\033[32mTEST OKAY\033[0m" << std::endl;
// 	std::cout << "--------------------" << std::endl;
// 	std::cout << "---- TEST SUBSCRIPT and it should throw an exception ----" << std::endl;
// 	{
// 		Array<int> number(700);
// 		int* copy = new int[700];
// 		srand(time(NULL));
// 		for (int i = 0; i < 700; i++)
// 		{
// 			const int value = rand();
// 			number[i] = value;
// 			copy[i] = value;
// 		}
// 		try
// 		{
// 			number[-2] = 0;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 		try
// 		{
// 			number[700] = 0;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << '\n';
// 		}
// 		delete [] copy;
// 	}
// 	return 0;
// }