#pragma once


#ifndef iostream
#include <iostream>
#endif 


#include "ScoreBoard.h"
#include "questions.h"
#include "Lifebuoy.h"

using namespace std;
#include <ctype.h>
#include <assert.h>

class Person {
protected:
	//name for every person -> HumanPlayer, npc, Show host
	string name;	
public:
	//return name
	string get();
	//every subclass has to create a print method
	virtual void print() = 0;	
};

class Player : public Person {
protected:
	friend class ScoreBoard;
	string answer;
	bool hasPLost;
public:
	//get answer
	virtual string getAnswer() = 0;
	//set answer
	virtual void set(listElem*) = 0;
	//set name
	virtual void set(string) = 0;
	//prints nickname
	virtual void print() = 0;
	//check if player lost
	virtual bool hasLost() = 0;
	//make player loose
	virtual void makeLose() = 0;
	Player();
};


class HumanPlayer: public Player {
public:
	//get answer
	string getAnswer();
	//set answer
	void set(listElem*);
	//set name
	void set(string);
	//prints nickname
	void print();
	//check if player lost
	bool hasLost();
	//make player loose
	void makeLose();
};
class Bot : public Player {
protected:
	static int dificulty;
public:
	//get answer
	string getAnswer();
	//set answer
	void set(listElem*);
	//set name
	void set(string);
	//prints nickname
	void print();
	//check if player lost
	bool hasLost();
	//make player loose
	void makeLose();
	Bot();
};

class ShowHost :public Person {
private:
	friend class ScoreBoard;
	friend class listElem;
	friend class Lifebuoy;
	//update prize 
	void updatePrize(ScoreBoard&);
	Lifebuoy* lfB;
public:
	//print name
	void print();
	//prints status (informations about current lvl)
	void printStatus(ScoreBoard&);
	//update lvl and prize
	void updateStatus(ScoreBoard&);
	//set guaranteed prize
	void setGuaranteed(ScoreBoard&);
	//print question and answers
	void printQuestion(listElem*);
	//check if answer is correct
	void checkAnswer(Player*, listElem*);
	ShowHost();
};