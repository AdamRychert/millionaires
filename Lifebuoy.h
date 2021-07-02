#pragma once
#include "questions.h"
#include <iostream>
#include "person.h"

class Lifebuoy {
protected:
	bool call;
	bool half;
	bool audience;
	//left lifebuoyts
	int left;
	bool usedInRound;
public:

	//decrement left
	void useAny();
	//get left value
	int getLeft();
	//set false to used ones 
	void makeUsed(string);
	//check if available
	bool available(string);
	//check if used in round
	bool checkIfUsed();
	//set usedInRound
	void setUsed(bool);

	void useCall(listElem*);
	void useHalf(listElem*);
	void useAudeince(listElem*);
	Lifebuoy();
};