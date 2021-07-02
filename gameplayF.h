#pragma once

#include <iostream>
#include <ctime>
#include <string>
#include "person.h"
#include "ScoreBoard.h"
#include "questions.h"


//update lvl
void nextLvl(ShowHost& host, ScoreBoard&);
//input number of players
void getNumOfPlayers(ScoreBoard&);
//starts round for player
void playRound(Player*, ShowHost*, listElem*, ScoreBoard*);
//starts the game
template<typename T1, typename T2, typename T3, typename T4>
void startGame(T1* board, T2* host, T3* menager, T4* player1, T4* player2 = NULL, T4* player3 = NULL) {
    while (!board->getStatus()) {
        //15 rounds
        if (board->getLvl() < 15) {
            //load next level
            nextLvl(*host, *board);

            //choose question
            listElem* newQuestion = menager->pickRandomElem();

            //print question
            host->printQuestion(newQuestion);
            //get through players and their tours
            switch (board->getPQ()) {
            case 1:
                //check if player has lost before
                if (!player1->hasLost()) {
                    //if not then let him play
                    playRound(player1, host, newQuestion, board);
                }
                break;
            case 2:
                if (!player1->hasLost()) {
                    playRound(player1, host, newQuestion, board);
                }
                if (!player2->hasLost()) {
                    playRound(player2, host, newQuestion, board);
                }
                break;
            case 3:
                if (!player1->hasLost()) {
                    playRound(player1, host, newQuestion, board);
                }
                if (!player2->hasLost()) {
                    playRound(player2, host, newQuestion, board);
                }
                if (!player3->hasLost()) {
                    playRound(player3, host, newQuestion, board);
                }
            }
            //delete used question
            delete newQuestion;
        }
        //end game after 15 lvl-s
        if (board->getLvl() == 15) {
            board->endGame();
        }
    }
}