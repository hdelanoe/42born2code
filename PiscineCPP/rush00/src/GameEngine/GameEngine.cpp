/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:26:06 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 18:40:04 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"
#include "../Enemy/AEnemy.hpp"
#include "../Player/Player.hpp"
#include "../Player/AProjectile.hpp"
#include "../Player/Laser.hpp"

GameEngine::GameEngine(void):
_running(true), _paused(false), _death(false), _time(clock()), _time2(clock()), _time3(clock()), _player(new Player()), 
_entities(NULL), _nbG(0), _projectiles(NULL), _nbP(0), _enemies(NULL), _nbE(0), _score(0) {}

GameEngine::GameEngine(GameEngine const &src) { *this = src; }

GameEngine::~GameEngine(void)
{
	for (int i = 0; i < _nbP; i++)
	{
		delete _projectiles[i];
	}
	for (int i = 0; i < _nbE; i++)
	{
		delete _enemies[i];
	}
	delete _player;
	return;
}

GameEngine &GameEngine::operator=(GameEngine const &rhs)
{
	if (this != &rhs)
	{
		_player = rhs.getPlayer();
		_projectiles = rhs.getProjectiles();
		_enemies = rhs.getEnemies();
		_nbP = rhs.getNbP();
		_nbE = rhs.getNbE();
	}
	return *this;
}

void GameEngine::control(int const &iInput)
{

	dynamic_cast<Player*>(_player)->Input(iInput);

	if (iInput == 119 && _player->getY() - _player->getSpeed() * 3 > 0 && !this->_paused)
		_player->setPos(_player->getX(), _player->getY() - _player->getSpeed()* 3);

	if (iInput == 115 && _player->getY() + _player->getSpeed() *  3 + _player->getH() < LINES - 4 && !this->_paused)
		_player->setPos(_player->getX(), _player->getY() + _player->getSpeed()* 3);

	if (iInput == 100 && _player->getX() + _player->getW() + 1 * _player->getSpeed() * 3< COLS && !this->_paused)
		_player->setPos(_player->getX() + 1 * _player->getSpeed()* 3, _player->getY());

	if (iInput == 97 && _player->getX() - 1 * (_player->getSpeed()* 3) > 0 && !this->_paused)
		_player->setPos(_player->getX() - 1 * _player->getSpeed()* 3, _player->getY());

	if (iInput == 32 && !this->_paused)
		addProjectile(dynamic_cast<Player *>(_player)->shoot());

	if (iInput == 'p')
		this->_paused = !this->_paused;

	if (iInput == 27)
		this->_running = false;
}

void	GameEngine::display(void)
{	
	displayEntity(_player);
	for (int i = 0 ; i < _nbP ; i++)
		displayEntity(_projectiles[i]);
	for (int i = 0 ; i < _nbE ; i++)
		displayEntity(_enemies[i]);
	for (int i = 0 ; i < _nbG ; i++)
		displayEntity(_entities[i]);


}

void GameEngine::displayEntity(AGameEntity const *gE) const
{
	for (int i = 0 ; i < gE->getH() ; i++) {
		move(gE->getY() + i, gE->getX());
		attron(COLOR_PAIR(gE->getColor()));
		printw("%s", gE->getSprite().substr(i * gE->getW(), gE->getW()).c_str());
		attroff(COLOR_PAIR(gE->getColor()));
	}
}

bool GameEngine::isRunning(void) const 		{ return this->_running; }
bool GameEngine::isPaused(void) const 		{ return this->_paused; }
void GameEngine::setPause(bool const &iVal) { this->_paused = iVal; }
void GameEngine::resetDeath(void) 			{ this->_death = false; }
bool GameEngine::isAfterDeath(void) const 	{ return this->_death; }

void GameEngine::displayHud(void) const
{
	std::string bar(COLS, '=');
	move(0, 0);
	printw("%s", bar.c_str());
	move(LINES - 4, 0);
	printw("%s", bar.c_str());
	for (int i = 1; i < LINES - 4; i++)
	{
		move(i, 0);
		printw("%c", '|');
		move(i, COLS - 1);
		printw("%c", '|');
	}

	if (this->_paused)
	{
		move(0, (COLS / 2) - 6);
		printw("%s", " GAME PAUSED ");
		move(LINES - 4, (COLS / 2) - 6);
		printw("%s", " GAME PAUSED ");
	}

	move(LINES - 2, 3);
	printw("%s", "PLAYER LIVES:");
	for (int i = 0, j = 0; i < _player->getHP(); i++)
	{
		j += 1;
		move(LINES - 2, 18 + i + j);
		printw("%s", "A");
	}
	if (dynamic_cast<Player*>(_player)->getShield())
	{
		move(LINES - 2, 25);
		attron(COLOR_PAIR(COLOR_BLUE));
		printw("%s", " SHIELD UP! ");
		attroff(COLOR_PAIR(COLOR_BLUE));

	}

	move(LINES - 2, COLS - 20);
	printw("SCORE: %010d", this->_score);
}

//void			GameEngine::setNbP(int n)			{ _nbP += n; }

AGameEntity*	GameEngine::getPlayer() const 		{ return _player; }
AGameEntity**	GameEngine::getEntities() const 	{ return _entities; }
AGameEntity**	GameEngine::getProjectiles() const 	{ return _projectiles; }
AEnemy**		GameEngine::getEnemies() const 		{ return _enemies; }
int				GameEngine::getNbG() const 			{ return _nbG; }
int				GameEngine::getNbE() const 			{ return _nbE; }
int				GameEngine::getNbP() const 			{ return _nbP; }
int 			GameEngine::getTime() const			{ return _time; }
int 			GameEngine::getTime2() const		{ return _time2; }
int 			GameEngine::getTime3() const		{ return _time3; }


int 			GameEngine::getScore(void) const { return _score; }
