#include <ctime>
#include <cstdlib>
#include "RandomComputer.h"

RandomComputer::RandomComputer() {}

char RandomComputer::makeMove() {
    srand (time(NULL));
    int random = rand() % 3 + 1;
    if ( random == 1){
        move = 'R';
    }
    else if ( random == 2){
        move = 'S';
    }
    else {
        move = 'P';
    }
    
    return move;
}

void RandomComputer::reset_count(){
}

void RandomComputer::declare_player(){
    std::cout << "This is RandomComputer Player" << std::endl;
}
