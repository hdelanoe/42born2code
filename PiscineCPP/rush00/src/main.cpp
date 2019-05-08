/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:48:56 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 18:52:24 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <time.h>
#include "GameEngine/GameEngine.hpp"
#include "AGameEntity.hpp"
#include "Player/AProjectile.hpp"
#include "Player/Player.hpp"

#include "ft_retro.hpp"

int main()
{
	initscr();
	raw();
	curs_set(0);
	noecho();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_GREEN, COLOR_BLUE);


	attron(COLOR_PAIR(2));
	move(LINES / 2 - 1, COLS / 2 - 11);
	printw("%s", "WELCOME TO FT_RETRO!");
	move(LINES / 2, COLS / 2 - 41);
	printw("%s", "Use WASD to move, SPACE to shoot, avoid ennemies and stay alive as long as you can!");
	move(LINES / 2 + 1, COLS / 2 - 14);
	printw("%s", "Press ENTER key when ready!");
	
	while(getch() != 10);
		
	int start, t;
	start = clock();

	keypad(stdscr, true);

	GameEngine *engine = new GameEngine();
	engine->displayEntity(engine->getPlayer());
	nodelay(stdscr, true);

	while (engine->isRunning() && engine->getPlayer()->isAlive())
	{
		t = clock();
		engine->control(getch());

		if (t - start > 50000 && !engine->isPaused())
		{
			engine->update();
			start = t;
		}
		if (engine->isAfterDeath())
		{
			erase();
			engine->display();
			nodelay(stdscr, false);
			move(LINES / 2, COLS / 2 - 21);
			attron(COLOR_PAIR(8));
			printw("%s", " YOU DIED! Press ENTER key to continue... ");
			refresh();
			while (getch() != 10);
			engine->getPlayer()->setPos(8, LINES / 2);
			dynamic_cast<Player*>(engine->getPlayer())->setTimer(clock());
			dynamic_cast<Player*>(engine->getPlayer())->setShield(true);
			start = clock();
			engine->resetDeath();
			engine->setPause(false);
			nodelay(stdscr, true);
		}
		erase();
		engine->display();
		engine->displayHud();
		refresh();
	}

	erase();
	nodelay(stdscr, false);
	if (!engine->getPlayer()->isAlive())
	{
		attron(COLOR_PAIR(COLOR_RED));
		move(LINES / 2, COLS / 2 - 5);
		printw("%s", "GAME OVER!");
	}
	else
	{
		attron(COLOR_PAIR(COLOR_GREEN));
		move(LINES / 2, COLS / 2 - 10);
		printw("%s", "SEE YOU SPACE COWBOY!");
	}
	move(LINES / 2 + 2, COLS / 2 - 13 );
	printw("%s %010d", "Your score was:", engine->getScore());
	move(LINES / 2 + 3, COLS / 2 - 14);
	printw("%s", " (press any key to exit...) ");
	refresh();
	getch();

	endwin();
	delete engine;

	return 0;
}
