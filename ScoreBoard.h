#pragma once

#include <iostream>
#include "person.h"
#include <assert.h>
#include "questions.h"
using namespace std;

class ScoreBoard {
private:
	friend class ShowHost;
	friend class Player;
	int currentPrize;
	int guaranteedPrize;
	int lvl;
	bool gameEnd;
	static int playerCount;
	int numOfPlayers;
	int numOfBots;
protected:
	//setters
		//set currentPrize
	void setCurrent(int);
		//set guaranteedPrize
	void setGuaranteed();
		//set lvl
	void setLvl(int);
public:
		//set number of players
	void setPQ();
		//set number of bots
	void setBQ();
	//getters
		//return number of players
	int getPQ();
		//return number of bots
	int getBQ();
		//return currentPrize
	int getCurrent();
		//return guaranteed
	int getGuaranteed();
		//return lvl
	int getLvl();
		//return game status (gameEnd)
	bool getStatus();
		//return number of Players that did not lose
	int getCount();

		//end game
	void endGame();
		//add 1 or decrement 1 from playerCount
	void updateCount(bool);
		//contructor
	ScoreBoard();
};

