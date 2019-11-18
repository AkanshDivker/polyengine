#ifndef ALPHABETA_H_INCLUDED
#define ALPHABETA_H_INCLUDED

#include <iostream>
#include "TreeNodes.h"
using namespace std;

class alphabeta{
    int moves_made;
public:
    
    alphabeta();
    
    int alpha_beta(tree*, int, char, int, int, char);

};
#endif 
