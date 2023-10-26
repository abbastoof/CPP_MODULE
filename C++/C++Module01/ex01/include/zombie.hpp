#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void	announce(void);
		void	setName(std::string name);
	private:
		std::string	_name;
};

#endif