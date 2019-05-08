/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:31:14 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/03 17:31:15 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>

template<typename T, typename U, typename V> void iter(T arr[], U len, V (*f)(T)) { for (size_t i = 0; i < len; ++i) { (*f)(arr[i]); } }

template<typename T> void print(T a) { std::cout << a << " "; }


int main(void)
{
    int quinte[5] = {18, 16, 13, 9, 12};

    char quarte[4] = {'H', 'U', 'I', 'T'};
    
    std::string tierce[5] = {"deux", "onze", "sept"};

    std::cout << "quinté : ";
    iter<int, size_t, void>(quinte, 5, print<int>);
    std::cout << std::endl;


    std::cout << "quarté : ";
    iter<char, size_t, void>(quarte, 4, print<char>);
    std::cout << std::endl;


    std::cout << "tiercé : ";
    iter<std::string, size_t, void>(tierce, 3, print<std::string>);
    std::cout << std::endl;


    return 0;
}
