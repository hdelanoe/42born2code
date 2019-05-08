/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:24:06 by hdelanoe          #+#    #+#             */
/*   Updated: 2019/03/31 18:46:28 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <typeinfo>
#include <ncurses.h>

#include "../AGameEntity.hpp"
#include "../Enemy/AEnemy.hpp"

class GameEngine
{
  public:
	GameEngine(void);
	GameEngine(GameEngine const &src);
	~GameEngine(void);

	GameEngine &operator=(GameEngine const &rhs);

	void control(int const &iInput);

	void update(void);
	void updatePlayer(void);
	void updateProjectiles(void);
	void updateEnemies(void);
	void updateEntities(void);

	void display(void);
	void displayEntity(AGameEntity const *iPtr) const;

	void addProjectile(AGameEntity *iPtr);
	void removeProjectile(int const &iIndex);

	void addEnemy(AEnemy *iPtr);
	void removeEnemy(int const &iIndex);
	AEnemy *spawn_enemy(void);

	void addEntityToArray(AGameEntity *iPtr);
	void addEntityToArray(AGameEntity **iArray, AGameEntity *iEntity, int *iAmount);
	void removeEntityToArray(int const &iIndex);

	AGameEntity*	getPlayer(void) const;
	AGameEntity**	getProjectiles(void) const;
	int 			getNbP(void) const;
	AEnemy**		getEnemies(void) const;
	int 			getNbE(void) const;
	AGameEntity**	getEntities(void) const;
	int 			getNbG(void) const;
	int 			getTime(void) const;
	int 			getTime2(void) const;
	int 			getTime3(void) const;
	int 			getScore(void) const;

	bool isRunning(void) const;
	bool isPaused(void) const;
	void setPause(bool const &iVal);
	void resetDeath(void);
	bool isAfterDeath(void) const;

	bool check_oow(AGameEntity *iPtr);

	void displayHud(void) const;

  private:
	bool _running;
	bool _paused;
	bool _death;

	int _time;
	int _time2;
	int _time3;

	AGameEntity *_player;

	AGameEntity **_entities;
	int _nbG;

	AGameEntity **_projectiles;
	int _nbP;

	AEnemy **_enemies;
	int _nbE;

	int _score;
};

#endif
