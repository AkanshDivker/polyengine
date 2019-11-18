#ifndef CONNECTFOURBOARD_H_INCLUDED
#define CONNECTFOURBOARD_H_INCLUDED

struct Move{
    int row_index;
    int col_index;
};

class tic{
    
public:
 
    char ** board;
    
    int row_size;
    
    int col_size;
    
    char player;
    
    Move *moves;
    
    
    tic();
    bool isBoardEmpty();
    int makeFirstMove();
    void checkPossibleMoves();
    bool checkPlayerWon();
    void operator=(tic);
    void display_board(tic *x);
};
#endif 
