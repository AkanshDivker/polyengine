#include <iostream>
#include <climits>

#include "AlphaBeta.h"
#include "TreeNodes.h"
#include "ConnectFourBoard.h"
using namespace std;

alphabeta::alphabeta(){
    moves_made = 0;
}
int alphabeta::alpha_beta(tree* tob, int depth, char player, int alpha, int beta, char aiplayer){

    if(tob->deep_enough(depth) && tob->use){
        tob->heuristic_value = tob->evaluation(aiplayer);
        return tob->evaluation(aiplayer);
    }

    

    
    
    if(tob->ob->player == player){
        int val = INT_MIN;
        for(int i = 0; i < 7; i++){
            if(tob->children[i] != NULL && tob->children[i]->use && tob->children[i]->ob->moves[i].row_index != -1){
                int temp = alpha_beta(tob->children[i], depth+1, player, alpha, beta, aiplayer);
                val = (temp > val)? temp: val;
                alpha = (val > alpha)?val:alpha;
                if(alpha >= beta)
                    break; 
            }
        }
        tob->heuristic_value = alpha;
        return alpha;
    }
    
    else{
        int val = INT_MAX;
        for(int i = 0; i < 7; i++){
            if(tob->children[i] != NULL && tob->children[i]->use && tob->children[i]->ob->moves[i].row_index != -1){
                int temp = alpha_beta(tob->children[i], depth+1, player, alpha, beta, aiplayer);
                val = (temp < val)? temp: val;
                beta = (val < beta)? val: beta;
                if(beta <= alpha)
                    break; 
            }
        }
        tob->heuristic_value = beta;
        return beta;
    }
    
}
