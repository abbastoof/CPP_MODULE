#include<algorithm>
#include<stack>
#include<iostream>
#include<deque>

void print(std::stack<int> stk)
{
	while(!stk.empty())
	{
		std::cout << stk.top() << std::endl;
		stk.pop();
	}
}

void showdq(std::deque<int> g)
{
    std::deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        std::cout << '\t' << *it;
    std::cout << '\n';
}

