/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine_Update.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:19:49 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 18:55:08 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>

#include "GameEngine.hpp"
#include "../Player/Player.hpp"
#include "../AGameEntity.hpp"
#include "../Enemy/AEnemy.hpp"
#include "../Enemy/Drone.hpp"
#include "../Enemy/Sentinel.hpp"
#include "../Enemy/Satelite.hpp"

#include "../Light.hpp"
#include "../Shield.hpp"


void	GameEngine::update(void)
{
	dynamic_cast<Player*>(_player)->checkShield();
	int t = clock();
	updatePlayer();
	updateProjectiles();
	if (t - _time > 500000) {
		if (t - _time > 1000000) {
			addEnemy(spawn_enemy());
			_time = clock();
		}
		addEntityToArray(new Light());
	}
	if(t - _time3 > 10000000) {
		addEntityToArray(new Shield());
		_time3 = clock();
	}
	updateEnemies();
	updateEntities();
	_running = _player->isAlive();

}

void	GameEngine::updatePlayer(void)
{
	if (dynamic_cast<Player*>(_player)->getUp() && _player->getY() - _player->getSpeed() > 0 && !this->_paused)
		_player->setPos(_player->getX(), _player->getY() - _player->getSpeed());

	if (dynamic_cast<Player*>(_player)->getDown() && _player->getY() + _player->getSpeed() + _player->getH() < LINES - 4 && !this->_paused)
		_player->setPos(_player->getX(), _player->getY() + _player->getSpeed());

	if (dynamic_cast<Player*>(_player)->getRight() && _player->getX() + _player->getW() + 1 * _player->getSpeed() < COLS && !this->_paused)
		_player->setPos(_player->getX() + 1 * _player->getSpeed(), _player->getY());

	if (dynamic_cast<Player*>(_player)->getLeft() && _player->getX() - 1 * (_player->getSpeed()) > 0 && !this->_paused)
		_player->setPos(_player->getX() - 1 * _player->getSpeed(), _player->getY());
}

void GameEngine::updateProjectiles()
{
	int j = -1;
	for (int i = 0 ; i < _nbP ; i++) {
		_projectiles[i]->setPos(_projectiles[i]->getX() + _projectiles[i]->getSpeed() * _projectiles[i]->getVX(), _projectiles[i]->getY());
		j = _projectiles[i]->checkEntities(_enemies, _nbE);
		if (j >= 0) {
			_score = _score < 999999999 ? _score + _enemies[j]->getScoreValue() : 999999999;
			removeEnemy(j);
			removeProjectile(i);
			i--;
			continue ;
		}
		if (check_oow(_projectiles[i])) {
			removeProjectile(i);
			i--;
		}
	}
}

void	GameEngine::addProjectile(AGameEntity* projectile)
{
	if (projectile == nullptr)
		return ;
	_nbP++;
	AGameEntity **tmp = new AGameEntity*[_nbP];
	for (int i = 0; i < _nbP - 1; i++) {
        tmp[i] = _projectiles[i];
    }
    delete _projectiles;
	tmp[_nbP -1] = projectile;
    _projectiles = tmp;
}

void	GameEngine::removeProjectile(int const &i)
{
	_nbP--;
	delete _projectiles[i];
	_projectiles[i] = _projectiles[_nbP];
	AGameEntity **tmp = new AGameEntity*[_nbP];
	for (int j = 0; j < _nbP; j++) {
        tmp[j] = _projectiles[j];
    }
    delete _projectiles;
    _projectiles = tmp;

}

void GameEngine::updateEnemies()
{
	for (int i = 0 ; i < _nbE ; i++) {
		if (_enemies[i]->getType() == "sentinel")
			addEnemy(dynamic_cast<Sentinel*>(_enemies[i])->shoot());
		_enemies[i]->pattern();
		_enemies[i]->setPos(_enemies[i]->getX() + _enemies[i]->getSpeed() * _enemies[i]->getVX(), _enemies[i]->getY() + _enemies[i]->getSpeed() * _enemies[i]->getVY());
		if (_enemies[i]->checkHitBox(dynamic_cast<Player*>(_player)) == true)
		{
			removeEnemy(i);
			if (dynamic_cast<Player*>(_player)->isHit())
			{
				this->_death = true;
				this->_paused = true;
			}
			i--;
			continue ; 
		}
		if (check_oow(_enemies[i])) {
			removeEnemy(i);
			i--;
		}
	}
}

void	GameEngine::addEnemy(AEnemy* enemy)
{
	if (enemy == nullptr)
		return ;
	_nbE++;
	AEnemy **tmp = new AEnemy*[_nbE];
	for (int i = 0; i < _nbE - 1; i++) {
        tmp[i] = _enemies[i];
    }
    delete _enemies;
	tmp[_nbE -1] = enemy;
    _enemies = tmp;
}

AEnemy*	GameEngine::spawn_enemy(void)
{
	int rd = 5 + (rand() % static_cast<int>(LINES - 15 + 1));
	float type = round(rand() % 10);
	if (type < 1)
		return new Satelite(COLS -15, rd);
	else if (type < 3)
		return new Sentinel(COLS -8, rd);

	return new Drone(COLS -6, rd);
}

void	GameEngine::removeEnemy(int const &i)
{
	_nbE--;
	delete _enemies[i];
	_enemies[i] = _enemies[_nbE];
	AEnemy **tmp = new AEnemy*[_nbE];
	for (int j = 0; j < _nbE; j++) {
        tmp[j] = _enemies[j];
    }
    delete _enemies;
    _enemies = tmp;

}

void	GameEngine::addEntityToArray(AGameEntity* entity)
{
	_nbG++;
	AGameEntity **tmp = new AGameEntity*[_nbG];
	for (int i = 0; i < _nbG - 1; i++) {
        tmp[i] = _entities[i];
    }
    delete _entities;
	tmp[_nbG -1] = entity;
    _entities = tmp;
}

void	GameEngine::addEntityToArray(AGameEntity** arr, AGameEntity *entity, int *nb)
{
	*nb += 1;
	AGameEntity **tmp = new AGameEntity*[*nb];
	for (int i = 0; i < *nb - 1; i++) {
        tmp[i] = arr[i];
    }
    delete arr;
	tmp[*nb -1] = entity;
    arr = tmp;
}

void	GameEngine::removeEntityToArray(int const &i)
{
	_nbG--;
	delete _entities[i];
	_entities[i] = _entities[_nbG];
	AGameEntity **tmp = new AGameEntity*[_nbG];
	for (int j = 0; j < _nbG; j++) {
        tmp[j] = _entities[j];
    }
    delete _entities;
    _entities = tmp;
}

void GameEngine::updateEntities()
{
	for (int i = 0 ; i < _nbG ; i++) {
		_entities[i]->setPos(_entities[i]->getX() + _entities[i]->getSpeed() * _entities[i]->getVX(), _entities[i]->getY());
		if (_entities[i]->getType() == "shield") {
			if (_entities[i]->checkHitBox(dynamic_cast<Player*>(_player)) == true) {
				dynamic_cast<Player*>(_player)->setShield(true);
				removeEntityToArray(i);
				i--;
				continue ;
			}
		}
		if (check_oow(_entities[i])) {
			removeEntityToArray(i);
			i--;
		}
	}
}

bool			GameEngine::check_oow(AGameEntity* e)
{
	if (e->getY() + e->getH() >= LINES - 5 || e->getY() - e->getH() <= 2)
	{
		e->setVY(e->getVY() * -1);
	}
	if (e->getX() + e->getW() >= COLS || e->getX()  - e->getW() <= 2)
		return true;
	return false;
}

