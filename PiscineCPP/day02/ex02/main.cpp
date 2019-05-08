#include <iostream>
#include "Fixed.hpp"

int	main(void){
	Fixed 	a;
	Fixed b(10);
	Fixed const c(42.42f);
	Fixed const	d(b);
	Fixed e(42);

	a = Fixed(1234.4321f);

	if (b < c)
		std::cout << b.toFloat() << " is smaller than " << c.toFloat() << std::endl;
	if (a > b)
		std::cout << a.toFloat() << " is bigger than " << b.toFloat() << std::endl;
	if (c >= e)
		std::cout << c.toFloat() << " is bigger than or equal to " << e.toFloat() << std::endl;
	if (e <= c)
		std::cout << e.toFloat() << " is smaller than or equal to " << c.toFloat() << std::endl;
	if (b == d)
		std::cout << b.toFloat() << " is equal to " << d.toFloat() << std::endl;
	if (a != c)
		std::cout << a.toFloat() << " is not equal to " << c.toFloat() << std::endl;

	b = a + c;

	std::cout << b.toFloat() << " is equals to " << a.toFloat() << " + " << c.toFloat() << std::endl;
	
	a = c - e;
	std::cout << a.toFloat() << " is equals to " << c.toFloat() << " - " << e.toFloat() << std::endl;

	b = Fixed(10);
	e = a * b;
	std::cout << e.toFloat() << " is equals to " << a.toFloat() << " * " << b.toFloat() << std::endl;
	e = a / b;
	std::cout << e.toFloat() << " is equals to " << a.toFloat() << " / " << b.toFloat() << std::endl;

	a = Fixed(0);
	b = Fixed(Fixed (5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << max(a, b) << std::endl; 

	return (0);
}