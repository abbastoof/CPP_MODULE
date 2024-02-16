/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:43:03 by atoof             #+#    #+#             */
/*   Updated: 2024/02/16 18:02:25 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	std::cout << s.size() << std::endl;
// 	return 0;
// }
void test_iterator(MutantStack<int> &mstack)
{
	
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Testing iterator" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "Size of stack s is: ";
	std::cout << s.size() << std::endl;
}

void test_reverse_iterator(MutantStack<int> &mstack)
{
	std::cout << "Testing reverse iterator" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}
	std::cout << "Size of stack mstack is: ";
	std::cout << mstack.size() << std::endl;
}

void test_const_iterator(MutantStack<int> &mstack)
{
	std::cout << "Testing const iterator" << std::endl;
	MutantStack<int>::const_iterator cit = mstack.begin();
	MutantStack<int>::const_iterator cite = mstack.end();
	++cit;
	--cit;
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	std::cout << "Size of stack mstack is: ";
	std::cout << mstack.size() << std::endl;
}

void test_const_reverse_iterator(MutantStack<int> &mstack)
{
	std::cout << "Testing const reverse iterator" << std::endl;
	MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = mstack.rend();
	++crit;
	--crit;
	while (crit != crite)
	{
		std::cout << *crit << std::endl;
		++crit;
	}
	std::cout << "Size of stack mstack is: ";
	std::cout << mstack.size() << std::endl;
}

void test_exceptions(MutantStack<int> &mstack)
{
	std::cout << "Testing exceptions" << std::endl;
	try
	{
		mstack.pop();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		mstack.pop();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		mstack.pop();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		mstack.pop();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	MutantStack<int> mstack;
	test_iterator(mstack);
	test_reverse_iterator(mstack);
	test_const_iterator(mstack);
	test_const_reverse_iterator(mstack);
	test_exceptions(mstack);
	return 0;
}