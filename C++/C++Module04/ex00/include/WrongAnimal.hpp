#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal(); // default constructor
		WrongAnimal(std::string type); // constructor overload
		WrongAnimal(const WrongAnimal &copy); // copy constructor
		virtual ~WrongAnimal(); // destructor
		
		// Operator Overloads
		WrongAnimal &operator=(const WrongAnimal &rhs); // assignment operator overload
		
		// member function
		std::string getType() const;
		void makeSound() const;
};

#endif