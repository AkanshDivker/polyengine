#include <cstdlib>
#include <ctime>
#include <climits>

#include "TreeNodes.h"

using namespace std;


tree::tree(){
    
    heuristic_value = INT_MIN;
    num_children = 0;
    for(int i=0;i<7;i++){
        children[i] = NULL;
    }
    str="";
    use = false;
    

    ob = new tic();
    
    
}


char tree::ReversePlayer(char player){
    if(player == 'X')
        return 'O';
    else
        return 'X';
}

void tree::create_node(char p){
    
    children[num_children++] = new tree();
}


void tree::set_heuristic_value(int value){
    
    heuristic_value = value;
}


void tree::add_all_children(){
    
    char p;
    int row,col;
    
    for(int i=0;i<7;i++){
        
        create_node('n');
        
     
        
        *(children[i]->ob) = *(this->ob);
        
        
        if(this->ob->player == 'X'){
            p = 'O';
            this->children[i]->ob->player = p;
        }
        
        else if(ob->player == 'O'){
            p = 'X';
            this->children[i]->ob->player = p;
        }
        
        else{
            p = 'X';
            this->children[i]->ob->player = p;
        }

        
        num_nodes_generated++;
        children[i]->ob->checkPossibleMoves();
        
        if(children[i]->ob->moves[i].row_index != -1){
            row = children[i]->ob->moves[i].row_index;
            col = children[i]->ob->moves[i].col_index;
            children[i]->ob->board[row][col] = p;
            children[i]->use = true;
        }
        else{
            children[i]->use = false;
            continue;
        }
    }
}

bool tree::deep_enough(int depth){
    
    if(heuristic_value!= INT_MIN) 
        return heuristic_value;
    
    if(depth == 7|| ob->checkPlayerWon()){
        if(ob->checkPlayerWon()){
           
            this->add_all_children();
        }
        return true;
    }
    
    else{
        num_nodes_expanded++;
        this->add_all_children();
        return false;
    }
}


int tree::innerEval(char c1, char c2, char c3, char c4, char me, char opp){
    char blank = ' ';
    int goodvalue = 0;
    int value = 0;

    
    if((c1 == me && c2== me && c3== me && c4 == blank)||(c1 == me && c2== me && c3== blank && c4 == me)|(c1 == me && c2== blank && c3 == me && c4 == me)|(c1 == blank && c2== me && c3== me && c4 == me)){
        value += 50 ;
         string s="mine is 3 -> +50 ";
        this->str.append(s);
        this->str.push_back(' ');
     
    }
    if((c1 == me && c2== me && c3== blank && c4 == blank)||(c1 == me && c2== blank && c3== me && c4 == blank)|(c1 == me && c2== blank && c3 == blank && c4 == me)|(c1 == blank && c2== me && c3== me && c4 == blank)|(c1 == blank && c2== me && c3== blank && c4 == me)|(c1 == blank && c2== blank && c3== me && c4 == me)){
        value += 15 ;
        string s="mine is 2 -> +15 ";
        this->str.append(s);
        this->str.push_back(' ');
    }
    if((c1 == me && c2== blank && c3== blank && c4 == blank)||(c1 == blank && c2== me && c3== blank && c4 == blank)|(c1 == blank && c2== blank && c3 == me && c4 == blank)|(c1 == blank && c2== blank && c3== blank && c4 == me)){
        value += 3 ;
        string s="mine is 1 -> +3 ";
        this->str.append(s);
        this->str.push_back(' ');
    }
    if((c1 == opp && c2== opp && c3== opp && c4 == blank)||(c1 == opp && c2== opp && c3== blank && c4 == opp)|(c1 == opp && c2== blank && c3 == opp && c4 == opp)|(c1 == blank && c2== opp && c3== opp && c4 == opp)){
        value -= 50 ;
        string s="counterpart is 3 -> -50 ";
        this->str.append(s);
        this->str.push_back(' ');
    }
    if((c1 == opp && c2== opp && c3== blank && c4 == blank)||(c1 == opp && c2== blank && c3== opp && c4 == blank)|(c1 == opp && c2== blank && c3 == blank && c4 == opp)|(c1 == blank && c2== opp && c3== opp && c4 == blank)|(c1 == blank && c2== opp && c3== blank && c4 == opp)|(c1 == blank && c2== blank && c3== opp && c4 == opp)){
        value -= 15 ;
         string s="counterpart is 2 -> -15 ";
        this->str.append(s);
        this->str.push_back(' ');
    }
    if((c1 == opp && c2== blank && c3== blank && c4 == blank)||(c1 == blank && c2== opp && c3== blank && c4 == blank)|(c1 == blank && c2== blank && c3 == opp && c4 == blank)|(c1 == blank && c2== blank && c3== blank && c4 == opp)){
        value -= 3 ;
         string s="counterpart is 1 -> -10 ";
        this->str.append(s);
        this->str.push_back(' ');
    }
    if(c1 == me && c2== me && c3== me && c4== me){
        value += 1000000;
         string s="mine is 4 -> +1000000 ";
        this->str.append(s);
        this->str.push_back(' ');
    }
    
    if(c1 == opp && c2== opp && c3== opp && c4== opp){
        value -= 1000000;
        string s="counterpart is 4 -> -1000000 ";
        this->str.append(s);
        this->str.push_back(' ');
    }
    
    return value;
}


int tree::evaluation(char aiplayer){
    int eval = 0;
    int temp = 0;
    int linecount = 0;
    char me = aiplayer;
    char opp = ReversePlayer(aiplayer);
    char blank = ' ';
    
    for(int r=0;r<3;r++){
        for(int c=6;c>2;c--){
            
            char c1 = this->ob->board[r][c];
            char c2 = this->ob->board[r+1][c-1];
            char c3 = this->ob->board[r+2][c-2];
            char c4 = this->ob->board[r+3][c-3];
            
            temp = innerEval(c1, c2, c3, c4, me, opp);
            eval += temp;
            
        }
    }
    
    
    
    for(int r=0;r<3;r++){
        for(int c=0;c<4;c++){
            char c1 = this->ob->board[r][c];
            char c2 = this->ob->board[r+1][c+1];
            char c3 = this->ob->board[r+2][c+2];
            char c4 = this->ob->board[r+3][c+3];
            
            temp = innerEval(c1, c2, c3, c4, me, opp);
            eval += temp;
            
        }
        
    }
    
    
    for(int r=0;r<6;r++){
        for(int c=0;c<4;c++){
            char c1 = this->ob->board[r][c];
            char c2 = this->ob->board[r][c+1];
            char c3 = this->ob->board[r][c+2];
            char c4 = this->ob->board[r][c+3];
            
            temp = innerEval(c1, c2, c3, c4, me, opp);
            eval += temp;
            }
    }
    
    
    for(int r=0;r<3;r++){
        for(int c=0;c<7;c++){
            char c1 = this->ob->board[r][c];
            char c2 = this->ob->board[r+1][c];
            char c3 = this->ob->board[r+2][c];
            char c4 = this->ob->board[r+3][c];
            
            temp = innerEval(c1, c2, c3, c4, me, opp);
            eval += temp;
            
        }
    }
    
    return eval;
}

