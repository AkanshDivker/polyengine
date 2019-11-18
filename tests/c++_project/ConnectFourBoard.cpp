#include <iostream>
#include <ctime>
#include <cstdlib>

#include "ConnectFourBoard.h"
using namespace std;

tic::tic(){
   
    row_size = 6;
    col_size = 7;
   
    board = new char* [row_size];
    for(int i=0;i<row_size;i++)
        board[i] = new char [col_size];
  
    for(int i=0;i<row_size;i++){
        for(int j=0;j<col_size;j++)
            board[i][j]=' ';
    }
    
    moves = new Move[7];
    for(int i=0;i<7;i++){
        moves[i].col_index = -1;
        moves[i].row_index = -1;
    }
    
    player = 'n';
}

bool tic::isBoardEmpty(){
    
    for(int i=0;i<row_size;i++){
        for(int j=0;j<col_size;j++){
            if(board[i][j]!=' ')
                return false;
        }
    }
    return true;
}

int tic::makeFirstMove(){
    
    int random_col;
    srand((unsigned int)time(NULL));
    do{
        random_col = rand()%7;
    }while(random_col == 3); 
    return random_col;
}

void tic::checkPossibleMoves(){
    
        for(int col = 0; col < 7; col++){
            for(int row = 0; row < 6; row++){
               
                if(board[row][col] == ' '){
                    this->moves[col].col_index = col;
                    this->moves[col].row_index = row;
                    break;
                }
                else if(row == 5 && board[row][col] != ' '){
                    this->moves[col].col_index = col;
                    this->moves[col].row_index = -1;
            }
        }
    }

}


bool tic::checkPlayerWon(){
    
    bool win=false;
    char c1,c2,c3,c4;
    
   
    for(int r=0;r<row_size;r++){
        for(int c=0;c<4;c++){
            if(!win){
                c1 = board[r][c];
                c2 = board[r][c+1];
                c3 = board[r][c+2];
                c4 = board[r][c+3];
                
                if(c1!=' '||c2!=' '||c3!=' '||c4!=' '){ 
                    if((c1 == c2)&& (c2 == c3) && (c3 == c4)){
                        win = true;
                        break;
                    }
                }
            }
        }
    }
    
    if(!win){
        for(int r=0;r<3;r++){
            for(int c=0;c<col_size;c++){
                c1 = board[r][c];
                c2 = board[r+1][c];
                c3 = board[r+2][c];
                c4 = board[r+3][c];
                
                if(c1!=' '||c2!=' '||c3!=' '||c4!=' '){
                    if((c1 == c2)&& (c2 == c3) && (c3 == c4)){
                        win = true;
                        break;
                    }
                }
            }
        }
    }
    
 
    if(!win){
        for(int r=0;r<3;r++){
            for(int c=6;c>2;c--){
                c1 = board[r][c];
                c2 = board[r+1][c-1];
                c3 = board[r+2][c-2];
                c4 = board[r+3][c-3];
               
                if(c1!=' '||c2!=' '||c3!=' '||c4!=' '){
                    if((c1 == c2)&& (c2== c3) && (c3== c4)){
                   
                        win=true;
                        break;
                    }
                }
            }
        }
    }
 
    if(!win){
        for(int r=0;r<3;r++){
            for(int c=0;c<4;c++){
                c1 = board[r][c];
                c2 = board[r+1][c+1];
                c3 = board[r+2][c+2];
                c4 = board[r+3][c+3];
                
                if(c1!=' '||c2!=' '||c3!=' '||c4!=' '){
                    if((c1 == c2)&& (c2== c3) && (c3== c4)){
                      
                        win=true;
                        break;
                    }
                }
            }
        }
    }
    return win;
}

void tic::operator=(tic rhs){
    
    for(int i=0;i<row_size;i++){
        for(int j=0;j<col_size;j++){
            this->board[i][j] = rhs.board[i][j];
        }
    }
    
    for(int i=0;i<7;i++){
        this->moves[i].row_index = rhs.moves[i].row_index;
        this->moves[i].col_index = rhs.moves[i].col_index;
    }
    this->player = rhs.player;
}

void tic::display_board(tic *x){
    cout<<endl;
    cout<<"C0 "<<" C1 "<<" C2 "<<" C3 "<<" C4 "<<" C5 "<<" C6"<<endl;
    for(int i=5;i>=0;i--){
        for(int j=0;j<7;j++){
            cout<<x->board[i][j]<<" | ";
        }
        cout<<endl;
        for(int k=0;k<7;k++)
            cout<<"----";
        cout<<endl;
    }
    cout<<endl;
}
