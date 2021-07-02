#include "gameplayF.h"

void nextLvl(ShowHost& host, ScoreBoard& board) {
    //update lvl, and currentPrize
    host.updateStatus(board);
    //print host name
    cout << endl <<string(10, ' ') << "<" << string(80, '-') << ">" << endl;
    host.print();
    //print all the info about current lvl
    host.printStatus(board);
}
void getNumOfPlayers(ScoreBoard& board) {
    //players
    board.setPQ();
    //bots
    board.setBQ();
}
void playRound(Player* player, ShowHost* host, listElem* question, ScoreBoard* board) {
 
    player->print();
        //get player answer
    player->set(question);
       //check if answer was correct if not make player loose
    host->checkAnswer(player, question);
        //check if player has lost
    if (!player->hasLost()) {
            //if not inform about correct answer
        host->print();
        cout << "Gratuluje poprawnej odpowiedzi" << endl;
            //set guaranteed prize
        host->setGuaranteed(*board);
    }
    else {
        //inform
        host->print();
        cout << player->get() << " odpada z gry i zabiera ze soba: " << board->getGuaranteed() << "zl"<<endl;
        //change player count to one less
        board->updateCount(false);
    }

    //if all players loose then end game
    if (board->getCount() == 0) {
        cout << endl << string(10, ' ') << "<" << string(80, '-') << ">" << endl;
        board->endGame();
    };
}