#include "Referee.h"
#include "Player.h"

Referee::Referee(){
    result = ' ';
}


char Referee::refGame(Player* player1, Player* player2){
    char p1 = player1->makeMove();
    char p2 = player2->makeMove();
    if ( p1 == p2){
        result = 'T';
    }
    else if ((p1 == 'R' && p2 == 'P') || (p1 == 'P' && p2== 'S')  ||  (p1 == 'S' && p2 == 'R') ) {
        result = 'L';
    }
    else{
        result = 'W';
    }
    return result;
}

Player* Referee::match(Player* p1, Player* p2){
     Player* advanced;
     int win = 0;
     int tide = 0;
     int lose = 0;
     Referee referee;
     for (int i = 0; i < 5; i++){
         char result = referee.refGame(p1, p2);
         if ( result == 'W'){
             win++;
         }
         else if ( result == 'L'){
             lose++;
         }
         else if (result == 'T'){
             tide++;
         }
     }
     p1->reset_count();
     p2->reset_count();
     if ( win >= 3 || tide == 5 ){
        advanced = p1;
     }
     else if (win > lose){
         advanced = p1;
     }
     else if ( win == lose && tide == 1 ){
         advanced = p1;
     }
     else if ( win == lose && tide == 3){
         advanced = p1;
     }
     else{
         advanced = p2;
     }
     return advanced;
}
