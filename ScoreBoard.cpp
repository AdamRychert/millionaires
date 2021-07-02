#include "ScoreBoard.h"

int ScoreBoard::playerCount = 0;

ScoreBoard::ScoreBoard(){
	lvl = 0;
	currentPrize = 0;
	guaranteedPrize = 0;
	gameEnd = false;
	numOfPlayers = 0;
	numOfBots = 0;
}

void ScoreBoard::setCurrent(int _prize){currentPrize = _prize;}

void ScoreBoard::setGuaranteed(){
	if (lvl == 5 || lvl == 10 || lvl == 15) {
		guaranteedPrize = currentPrize;
	}
}

void ScoreBoard::setLvl(int _lvl){
	assert(_lvl > 0);
	assert(_lvl < 16);
	lvl = _lvl;
}

void ScoreBoard::setPQ()
{
	int num = 0;
	cout << "Podaj liczbe graczy(maksymalnie 3): ";
	cin >> num;
	if (num == 0) {
		cout << "Nie podjeto sie rozgrywki. Koniec gry";
		exit(1);
	}
	if (num > 0 && num <= 3) {
		numOfPlayers = num;
		return;
	}
	cout << "Ilosc spoza zakresu. Gra rozpocznie sie z 1 graczem" << endl;
	numOfPlayers = 1;
}

void ScoreBoard::setBQ()
{
	int num = 0;
	cout << "Ile ma byc wsrod nich botow (zakres 0-3): ";
	if (!(cin >> num)) {
		cout << "To nie cyfra!";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	if (num == 0) {
		cout << "Gra rozpocznie sie bez botow" << endl;
		numOfBots = 0;
	}
	else if (num > 0 && num <= numOfPlayers) {
		numOfBots = num;
	}
	else {
		cout << "Ilosc spoza zakresu. Gra rozpocznie sie bez botow" << endl;
		numOfBots = 0;
	}
	
}

int ScoreBoard::getPQ()
{
	return numOfPlayers;
}

int ScoreBoard::getBQ()
{
	return numOfBots;
}

int ScoreBoard::getCurrent() { return currentPrize; }

int ScoreBoard::getGuaranteed(){return guaranteedPrize;}

int ScoreBoard::getLvl(){return lvl;}

bool ScoreBoard::getStatus()
{
	return gameEnd;
}

int ScoreBoard::getCount()
{
	return playerCount;
}

void ScoreBoard::endGame()
{
	if (lvl == 15) {
		cout << endl << string(10, ' ') << "<" << string(80, '-') << ">" << endl;
		cout << "\nFinalisci zabieraja za soba 1000000 zl!!!"<<endl;
	}
	gameEnd = true;
}

void ScoreBoard::updateCount(bool InOrDc) {
	InOrDc ? playerCount++ : playerCount--;
}

