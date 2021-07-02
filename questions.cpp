#include "questions.h"

int listElem::get(){return rightAnswer;}

string listElem::get(int& num){
	if (num < 0 || num >3) {
		return "bledna odpowiedz";
	}
	return options[num];
}

void listElem::printQ(){
	cout << question<<endl;
}

void listElem::printA(){
	for (int i = 0; i < 4; ++i) {
		cout << options[i] << endl;
	}
}

listElem::listElem() {
	nast = NULL;
	poprz = NULL;
	numOfQest++;
	question = "";
	for (int i = 0; i < 4; ++i)options[i] = " ";
	rightAnswer = 0;
	questionNum = 0;
}
listElem::listElem(string& _question, string* arr, int& _rightAnswer) {
	question = _question;
	for (int i = 0; i < 4; ++i)options[i] = arr[i];
	rightAnswer = _rightAnswer;
	questionNum = numOfQest;
	nast = NULL;
	poprz = NULL;
	numOfQest++;
}



int listElem::numOfQest = 0;


bool DynamicListMenager::inicjalizeList(string _fileName) {

	fstream fstr;
	fstr.open(_fileName, ios::in);
	//check if open
	if (fstr.is_open()) {

		string question = "";
		//get question

		while (getline(fstr, question)) {
			
			//temporarry variables 
			string qArr[4] = { " " };
			int rightAnswer = 0;

			//get anserws
			for (int i = 0; i < 4; ++i) {

				getline(fstr, qArr[i]);
				//look for answer with * (it's the right one)
				if (qArr[i].back() == '*') {
					rightAnswer = i;
					//delete * character
					qArr[i].back() = ' ';
				}
			}
			//add elem to list
			if (listHead == NULL) {
				listHead = wsk = new listElem(question, qArr, rightAnswer);
			}
			else {
				wsk->nast = new listElem(question, qArr, rightAnswer);
				wsk->nast->poprz = wsk;
				wsk = wsk->nast;
			}
		}
	}
	else {
		return false;
	}

	//wsk should point at head
	wsk = listHead;

	return true;
}

DynamicListMenager::DynamicListMenager() {
	listHead = NULL;
	wsk = NULL;
}

DynamicListMenager::~DynamicListMenager()
{
	//delete all elements of list
	while (listHead != NULL) {
		wsk = listHead->nast;
		delete listHead;
		listHead = wsk;
	}
}

listElem* DynamicListMenager::pickRandomElem(){
	//wsk is deleted after each lvl so it needs to point on listHead
	wsk = listHead;

	//random number from 1 to total number of Questions
	int questionNum = rand() % (wsk->numOfQest-1) + 2;
	

	while (wsk != NULL) {
			//check if number of this question is the right one
		if (wsk->questionNum == questionNum) {
			//if it's not head elem then change nast in previous one, else update listHead
			if (wsk->poprz != NULL) {
				wsk->poprz->nast = wsk->nast;
			}
			else {
				listHead = wsk->nast;
			}
			//if it's not last elem then change poprz in next one 
			if (wsk->nast != NULL) {	
				wsk->nast->poprz = wsk->poprz;
			}
			return wsk;
		}
		wsk = wsk->nast;
	}
	
	//if there is not a function with right number then call pickRandomElem again
	return pickRandomElem();
	
}
