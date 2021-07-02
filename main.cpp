// main.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include "person.h"
#include "ScoreBoard.h"
#include "questions.h"
#include "gameplayF.h"


#define FILENAME "questionsBase.txt"

int main(){
    srand(time(NULL));

    ////inicjalization of objects
    ScoreBoard* board = new ScoreBoard;
    ShowHost* sh1 = new ShowHost;
    DynamicListMenager* menager = new DynamicListMenager;
    

    ////inicjalization of questions list
    if (!menager->inicjalizeList(FILENAME)) {
        cout << "\nNie udalo sie zaladowac pliku z pytaniami" << endl;
        exit(1);
    }
   

    cout << string(40, ' ') << "Witam w grze MILIONERZY!" << endl;
    cout << "W trakcie gry napisz 'kola', aby skorzystac z kol ratunkowych" << endl;
    //get number of players from user
    getNumOfPlayers(*board);
    
  
    //get through number of players and play game
    switch (board->getPQ()) {
    case 1: {
        //create empty player object
        Player* p1 = NULL;

        //decide about making object a BOT or HUMANPLAYER
        switch (board->getBQ()) {
        case 0:  //1 gracz 0 botow
            p1 = new HumanPlayer();
            p1->set("Player");
            break;
        case 1: //1gracz w tym 1 bot
            p1 = new Bot();
            p1->set("Bot");
            break;
        default: cout << "Napotkano problem" << endl;
        }
        //start the game
        startGame(board, sh1, menager, p1);
        delete p1;
    } break;
    case 2: {
        Player* p1 = NULL;
        Player* p2 = NULL;

        switch (board->getBQ()) {
        case 0:  //2 graczy 0 botow
            p1 = new HumanPlayer();
            p1->set("Player1");
            p2 = new HumanPlayer();
            p2->set("Player2");
            break;
        case 1: //2gracz w tym 1 bot
            p1 = new HumanPlayer();
            p1->set("Player");
            p2 = new Bot();
            p2->set("Bot");
            break;
        case 2://2gracz w tym 2 boty
            p1 = new Bot();
            p1->set("Bot1");
            p2 = new Bot();
            p2->set("Bot2");
            break;
        default: 
            cout << "Napotkano problem" << endl;
            exit(1);
        }
        
        startGame(board, sh1, menager, p1,p2);
        delete p1, p2;
    } break;
    case 3: {
        Player* p1 = NULL;
        Player* p2 = NULL;
        Player* p3 = NULL;

        switch (board->getBQ()) {
        case 0:  //3 graczy 0 botow
            p1 = new HumanPlayer();
            p1->set("Player1");
            p2 = new HumanPlayer();
            p2->set("Player2");
            p3 = new HumanPlayer();
            p3->set("Player3");
            break;
        case 1: //3 graczy w tym 1 bot
            p1 = new HumanPlayer();
            p1->set("Player1");
            p2 = new HumanPlayer();
            p2->set("Player2");
            p3 = new Bot();
            p3->set("Bot");
            break;
        case 2: //3 graczy w tym 2 bot
            p1 = new HumanPlayer();
            p1->set("Player");
            p2 = new Bot();
            p2->set("Bot1");
            p3 = new Bot();
            p3->set("Bot2"); 
            break;
        case 3: //3graczy w tym 3 boty
            p1 = new Bot();
            p1->set("Bot1");
            p2 = new Bot();
            p2->set("Bot2");
            p3 = new Bot();
            p3->set("Bot3");
            break;
        default: cout << "Napotkano problem" << endl;
        }

        startGame(board, sh1, menager, p1, p2, p3);
        delete p1, p2, p3;
    } break;
    default:
        cout << "Napotkano problem1" << endl;
        exit(1);
    };

    cout <<endl<< string(40, ' ') << "Dziekuje za udzial w grze!" << endl;

    delete menager, sh1, board;
    return 0;
}

