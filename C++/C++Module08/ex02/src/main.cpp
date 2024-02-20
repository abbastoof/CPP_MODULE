/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:43:03 by atoof             #+#    #+#             */
/*   Updated: 2024/02/20 16:27:52 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#include <list>

// int main()
// {
	// MutantStack<int> mstack;
	// mstack.push(5);
	// mstack.push(17);
	// std::cout << mstack.top() << std::endl;
	// mstack.pop();
	// std::cout << mstack.size() << std::endl;
	// mstack.push(3);
	// mstack.push(5);
	// mstack.push(737);
	// //[...]
	// mstack.push(0);
	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// std::cout << *it << std::endl;
	// ++it;
	// }
	// std::stack<int> s(mstack);
	// std::cout << s.size() << std::endl;

	//================================================================================================

// 	std::list<int> mstack;
// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	// std::cout << mstack.top() << std::endl;
// 	// mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	mstack.push_back(0);
// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	// std::stack<int> s(mstack);
// 	// std::cout << s.size() << std::endl;
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

int main()
{
	MutantStack<int> mstack;
	test_iterator(mstack);
	test_reverse_iterator(mstack);
	test_const_iterator(mstack);
	test_const_reverse_iterator(mstack);
	return 0;
}