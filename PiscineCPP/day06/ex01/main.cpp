/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:04:28 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/04/02 18:04:29 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include <string>

struct Data
{
    std::string    s1;
    int            n;
    std::string    s2;
};

void* serialize(void)
{
    Data*		data = new Data;
    static char	set[] = "abcdefghijklmnopqrstuvwxyz"
    					"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    					"1234567890";

    for (int i = 0; i < 8; i += 1)
    {
    	srand(time(NULL));
    	sleep(1);
        data->s1 += set[rand() % sizeof(set)];
        data->s2 += set[rand() % sizeof(set)];
    }
    data->n = rand() % 10;
    return (data);
}

Data *deserialize(void *raw) { return reinterpret_cast<Data*>(raw); }


int main()
{

	std::cout << "serializing... " << std::endl;
    void*	serie = serialize();
    Data*	data = deserialize(serie);

    std::cout<< data->s1 << " " << 
    			data->n << " " <<
    			data->s2 << std::endl;
    delete data;
    return (0);
}
