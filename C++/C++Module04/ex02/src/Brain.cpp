#include "../include/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "empty";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &assigned)
{
	std::cout << "Brain assignment operator called" << std::endl;
	for (int i= 0; i < 100; i++)
		this->_ideas[i] = assigned.getIdea(i);
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}


std::string Brain::getIdea(int i) const
{
	if (i < 0 || i > 99)
		return ("index out of range");
	return (this->_ideas[i]);
}

void Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i > 99)
		std::cout << "index out of range" << std::endl;
	else
		this->_ideas[i] = idea;
}

void Brain::displayIdeas(void) const
{
	for (int i = 0; i < 100; i++)
	{
		if (this->getIdea(i).empty())
			break;
		else
			std::cout << getIdea(i) << std::endl;
	}
}