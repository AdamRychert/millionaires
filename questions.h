#pragma once

#include <iostream>
#include <assert.h>
#include <random>
#include <fstream>  
#include <string>
#include <time.h>
using namespace std;

//element of the list
class listElem {
private:
	friend class DynamicListMenager;
	//address to next elem
	listElem* nast;
	//address to element before
	listElem* poprz;
	//total number of question
	static int numOfQest;
	//contains question
	string question;
	//contains answers
	string options[4];
	//number of right answer
	int rightAnswer;
	//number of current question
	int questionNum;
public:
	//geters
	//get right answer
	int get();
	//get specyfic option
	string get(int&);
	//print question
	void printQ();
	//print answer
	void printA();
	//constructors
	listElem();
	listElem(string&, string*, int&);
	//destructor
};

//class for list menagment
class DynamicListMenager {
private:
	friend class listElem;
	//pointer to head of the list
	listElem* listHead;
	//additional pointer should always be reseted to point on head
	listElem* wsk;
public:
	//create a dynamic list
	bool inicjalizeList(string);
	//pick a random question and return it's address
	listElem* pickRandomElem();
	//constructor
	DynamicListMenager();
	~DynamicListMenager();
};


