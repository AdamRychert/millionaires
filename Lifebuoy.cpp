#include "Lifebuoy.h"

void Lifebuoy::useCall(listElem* question) {
	cout << "~Wykonujesz telefon do znajomego~"<<endl;
	int chance = rand() % 10 + 1;
	int ceiling = rand() % 4 + 7;
	int numOfAnswer = question->get();
	cout << "Wydaje mi sie ze to: ";
	if (chance < ceiling) {
		cout << question->get(numOfAnswer)[0] << endl;
	}
	else {
		cout << "B" << endl;
	}
}

void Lifebuoy::useAny()
{
	left--;
}

int Lifebuoy::getLeft()
{
	return left;
}

void Lifebuoy::makeUsed(string opt)
{
	if (opt == "1")call = false;
	else if (opt == "2")audience = false;
	else if (opt == "3")half = false;
}

bool Lifebuoy::available(string opt)
{
	if (opt == "1") {
		if (call)return false;
	}
	else if (opt == "2") { 
		if (audience)return false;
	}
	else if (opt == "3") {
		if (half)return false;
	};
	return true;
}

bool Lifebuoy::checkIfUsed(){
	return usedInRound;
}

void Lifebuoy::setUsed(bool _b)
{
	usedInRound = _b;
}

void Lifebuoy::useHalf(listElem* question){
	int chance = rand() % 5;

	int numOfAnswer = question->get();
	char rightAnswer = question->get(numOfAnswer)[0];

	bool isFirst = rightAnswer == 'A' ? true : false;

	cout << "Pozostale odpowiedzi to: ";
	if (isFirst) {
		if (chance < 2) {
			cout << question->get(numOfAnswer)[0] << ", C"<<endl;
			return;
		}
		cout << "B, " << question->get(numOfAnswer)[0] << endl;		
	}
	else {
		if (chance < 2) {
			cout << question->get(numOfAnswer)[0] << ", A" << endl;
			return;
		}

		cout << "A, " << question->get(numOfAnswer)[0] << endl;
	}

}

void Lifebuoy::useAudeince(listElem* question){
	int chance = rand() % 100 + 1;
	int numOfAnswer = question->get();

	if (chance >= 75) {
		cout << chance << "% publicznosci wybiera " << question->get(numOfAnswer)[0] << endl;
	}
	else{
		chance = rand() % 20 + 55;
		int ceiling = rand() % 10 + 55;
		if (chance >= ceiling) {
			cout << chance << "% publicznosci wybiera " << question->get(numOfAnswer)[0] << endl;
		}
		else {
			cout << chance << "% publicznosci wybiera " << "C" << endl;
		}
	}

}

Lifebuoy::Lifebuoy() {
	call = true;
	half = true;
	audience = true;
	left = 3;
	usedInRound = false;
}
