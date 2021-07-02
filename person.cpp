#include "person.h"

//GET NAME
string Person::get(){
    return name;
}

string HumanPlayer::getAnswer()
{
    return answer;
}

//PRINTS NAME
void HumanPlayer::print(){
    cout << endl << " > " << name << ":";
}

bool HumanPlayer::hasLost()
{
    return hasPLost;
}

void HumanPlayer::makeLose()
{
    hasPLost = true;
}

void HumanPlayer::set(string _defaultName){
    while (true) {
      
        string _name;
        cout << "Podaj nazwe gracza ('d' dla domyslnej): ";
        cin >> _name;

        if (_name == "d") {
            name = _defaultName;
            break;
        }
        if (!isupper(_name[0])) {
            cout << "\nBledna nazwa gracza. Powinna ona zaczynac sie z duzej litery\n" << endl;
            while (getchar() != '\n')
                ;
            continue;
        }
        bool isNotValid = false;

        for (int i = 1; i < _name.length(); ++i) {
            if (!islower(_name[i])) {
                cout << "\nBledna nazwa gracza. Po pierwszej literze wszystkie pozostale znaki powinny byc malymi literami\n" << endl;
                while (getchar() != '\n')
                    ;
                isNotValid = true;
                break;
            }
        }
        if (isNotValid)continue;
        name = _name;
        break;
    }
}


void HumanPlayer::set(listElem*){
    cin >> answer;
}


void ShowHost::print(){
    cout << endl << " * " << name << ": ";
}

//PRINTS STATUS OF HumanPlayer
void ShowHost::printStatus(ScoreBoard& board){ 
    //check if lvl =1
    if (board.getLvl() == 1) {
        cout << "Zaczynamy gre! Walczysz o " << board.getCurrent() <<" zlotych."<< endl;
    }
    else {

        cout << " Pora na pytanie numer:  " << board.getLvl()
             << ". Zawalczysz o " << board.getCurrent() << " zlotych."<<endl;
        if (board.getLvl() == 5 || board.getLvl() == 10 || board.getLvl() == 15) {
            cout << endl << string(40, ' ') << "JEST TO SUMA GWARANTOWANA" << endl;
        }
    }
}

//UPDATE PRIZE 

void ShowHost::updatePrize(ScoreBoard& board){
    int prize = 0;
    //if lvl is less then 4 
    if (board.getLvl() < 4) { prize = board.getLvl() * 100; }
    //if lvl == 4 or lvl == 12 then choose one of the two 
    else if (board.getLvl() == 4 || board.getLvl() == 12) { board.getLvl() == 4 ? prize = 500 : prize = 125000; }
    //else double the prize
    else { prize = board.getCurrent() * 2; }
    //and set current prize
    board.setCurrent(prize);
}


//UPDATE HumanPlayer LVL AND RUN UPDATEPRIZE()
void ShowHost::updateStatus(ScoreBoard& board){
    //update current lvl   || lvl needs to be updates as first
    board.setLvl(board.getLvl() + 1);   
    //update prize 
    updatePrize(board); 
}

//SET GUARANTEED PRIZE  
void ShowHost::setGuaranteed(ScoreBoard& board){
    board.setGuaranteed();
}

void ShowHost::printQuestion(listElem* wsk){
    print();
    cout << "Pytanie brzmi: ";
    //print question
    wsk->printQ();
    //print answer
    wsk->printA();
}

void ShowHost::checkAnswer(Player* player, listElem* wsk)
{

    string answer = player->getAnswer();
    if (answer == "kola" && !lfB->checkIfUsed()) {
        if (lfB->getLeft() == 0) {
            cout << "Nie masz juz kol ratunkowych" << endl;
            lfB->setUsed(true);
            player->print();
            player->set(wsk);
            return checkAnswer(player, wsk);
        }
        while (true) {
            string option = " ";
            cout << " > 1 Telefon do przyjaciela" << endl
                << " > 2 Widownia" << endl
                << " > 3 50/50" << endl
                << "Podaj numer kola, lub 'q' aby wyjsc: ";
            cin >> option;
            if (lfB->available(option)) {
                cout << "Juz uzyles tego kola!" << endl;
                continue;
            }
            if (option == "1") {
                lfB->useCall(wsk);
                
            }
            else if (option == "2") {
                lfB->useAudeince(wsk);
            }
            else if (option == "3") {
                lfB->useHalf(wsk);
            }
            else if (option == "q") {
                lfB->setUsed(true);
                return checkAnswer(player, wsk);
            }
            else {
                cout << "Blednie podana opcja. Ponawiam." << endl;
                continue;
            }
            player->print();
            player->set(wsk);
            lfB->useAny();
            lfB->makeUsed(option);
            lfB->setUsed(true);
            return checkAnswer(player, wsk);
        }
        
        
    }
    lfB->setUsed(false);
    //get right answer
    switch (wsk->get()) {
    //case optionber of right answer
        //if player answer = letter that represents right answer
        //player hasLost change to false || else player lost -> hasLost = true
    case 0:
        if (!(answer == "a" || answer == "A")) {
            player->makeLose();
        }
        if (answer == "q") {
            cout << " Postanowiles zakonczyc gre. Zegnaj"<<endl;
            exit(0);
        }
        break;
    case 1:
        if (!(answer == "b" || answer == "B")){
            player->makeLose(); 
        }
        if (answer == "q") {
            cout << " Postanowiles zakonczyc gre. Zegnaj" << endl;
            exit(0);
        }
        break;
    case 2:
        if (!(answer == "c" || answer == "C")){ 
            player->makeLose();
        }
        if (answer == "q") {
            cout << " Postanowiles zakonczyc gre. Zegnaj" << endl;
            exit(0);
        }
        break;
    case 3:
        if (!(answer == "d" || answer == "D")){ 
            player->makeLose(); 
        }
        if (answer == "q") {
            cout << " Postanowiles zakonczyc gre. Zegnaj" << endl;
            exit(0);
        }
        break;
    default:
        player->makeLose();
    }
  
}

ShowHost::ShowHost(){
    name = "Prowadzacy";
    lfB = new Lifebuoy;
}

string Bot::getAnswer(){
    return answer;
}

void Bot::set(listElem* wsk){
    int chance = rand() % 10+1;
    int numOfAnswer = wsk->get();
    if (chance <= dificulty) {
        answer = wsk->get(numOfAnswer)[0];
    }
    else {
        answer = "A";
    }
    cout << answer << endl;
}

void Bot::set(string _defBotName){
    name = _defBotName;
}

void Bot::print(){
    cout << "\n < " << name << ":";
}

bool Bot::hasLost()
{
    return hasPLost;
}

void Bot::makeLose()
{
    hasPLost = true;
}

Bot::Bot()
{
    if (dificulty == 11) {
        int num = 0;
        cout << "Podaj poziom trudnosci botow (0-10): ";
        cin >> num;
        if (num < 0 || num >10) {
            dificulty = 5;
            cout << "Podano bledna wartosc, ustawiam na 5" << endl;
            return;
        }
        dificulty = num;
    }
}



Player::Player(){
    answer = "";
    hasPLost = false;
    ScoreBoard wsk;
    wsk.updateCount(true);
}
int Bot::dificulty = 11;