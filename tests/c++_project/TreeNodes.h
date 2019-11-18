#ifndef TREENODES_H_INCLUDED
#define TREENODES_H_INCLUDED

#include <iostream>
#include "ConnectFourBoard.h"
using namespace std;

extern int num_nodes_generated,num_nodes_expanded,game_path_length,start_time,stop_time;

class tree{
    
public:
    
    int heuristic_value;
     
    int num_children;
    tree *children[7];
    bool use;
 
    tic *ob;
    string str;
    
    
    tree();
    char ReversePlayer(char player);
    void create_node(char);
    void set_heuristic_value(int);
    void add_all_children();
    bool deep_enough(int);
    int innerEval(char, char, char, char, char, char);
    int evaluation(char);
};
#endif 
