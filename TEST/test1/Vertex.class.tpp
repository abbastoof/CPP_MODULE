/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vertex.class.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:16:42 by atoof             #+#    #+#             */
/*   Updated: 2024/02/12 13:36:04 by atoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

template< typename T = float>
class Vertex {

public:
	Vertex(T const & x, T const & y, T const & z): _x(x), _y(y), _z(z) {}
	~Vertex(void){}

	T const & getX(void) const {return this->_x;}
	T const & getY(void) const {return this->_y;}
	T const & getZ(void) const {return this->_z;}
private:
	T const _x;
	T const _y;
	T const _z;
	
	Vertex(void);
};

template <typename T>
std::ostream & operator<<(std::ostream & o, Vertex<T> const & v) {
	std::cout.precision(1);
	o << std::setiosflags(std::ios::fixed);
	o << "Vertex( ";
	o << v.getX() << ", ";
	o << v.getY() << ", ";
	o << v.getZ();
	o << " )";
	return o;
}