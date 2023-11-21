#ifndef Brain_HPP
# define Brain_HPP

#include <iostream>
#include <sstream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain(void);
		Brain(const Brain &copy);
		~Brain(void);
		Brain &operator=(const Brain &assigned);
		std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);
		void displayIdeas(void) const;
};

#endif