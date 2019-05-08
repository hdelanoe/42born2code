/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelanoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:11:32 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/28 22:11:33 by hdelanoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IAsteroid.hpp"
#include "IMiningLaser.hpp"
#include "AsteroKreog.hpp"
#include "KoalaSteroid.hpp"
#include "StripMiner.hpp"
#include "MiningBarge.hpp"

int main()
{
	IMiningLaser *b = new StripMiner();
	IMiningLaser *a = new DeepCoreMiner();


	MiningBarge *barge = new MiningBarge();

	barge->equip(a);
	barge->equip(b);

	IAsteroid *c = new AsteroBocal();
	IAsteroid *d = new BocalSteroid();

	barge->mine(c);
	barge->mine(d);

	delete a;
	delete b;
	delete c;
	delete d;
	delete barge;
	
	return 0;


}
