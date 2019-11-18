#include "neweval.h"


int neweval(tree * point)
{
	
	int value=-20000000;
	 char me=point->ob->player;
	 char opp=point->ReversePlayer(point->ob->player);
	 
	    for(int r=0;r<3;r++){
        for(int c=6;c>2;c--){
            
            char c1 = point->ob->board[r][c];
            char c2 = point->ob->board[r+1][c-1];
            char c3 = point->ob->board[r+2][c-2];
            char c4 = point->ob->board[r+3][c-3];
            
            if(c1==me&&c2==me&&c3==me&&c3==me&&c4==me)
            {
            	value+=1000000000; cout<<"***"<<endl;
			}
            if(c1==me&&c2==me&&c3==me&&c3==me&&c4==opp)
            {
            	value+=900000000;
			}			
			
            
        }
    }
    
    
    
    
    for(int r=0;r<3;r++){
        for(int c=0;c<4;c++){
            char c1 = point->ob->board[r][c];
            char c2 = point->ob->board[r+1][c+1];
            char c3 = point->ob->board[r+2][c+2];
            char c4 = point->ob->board[r+3][c+3];
            
            if(c1==me&&c2==me&&c3==me&&c3==me&&c4==me)
            {
            	value+=1000000000;
			}
            if(c1==me&&c2==me&&c3==me&&c3==me&&c4==opp)
            {
            	value+=900000000;
			}		
        }
        
    }
    
    
    
    for(int r=0;r<6;r++){
        for(int c=0;c<4;c++){
            char c1 = point->ob->board[r][c];
            char c2 = point->ob->board[r][c+1];
            char c3 = point->ob->board[r][c+2];
            char c4 = point->ob->board[r][c+3];
            
            if(c1==me&&c2==me&&c3==me&&c3==me&&c4==me)
            {
            	value+=1000000000;
			}
            if(c1==me&&c2==me&&c3==me&&c3==me&&c4==opp)
            {
            	value+=900000000;
			}					
            }
    }
    
    
    
   
    for(int r=0;r<3;r++){
        for(int c=0;c<7;c++){
            char c1 = point->ob->board[r][c];
            char c2 = point->ob->board[r+1][c];
            char c3 = point->ob->board[r+2][c];
            char c4 = point->ob->board[r+3][c];
            
             if(c1==me&&c2==me&&c3==me&&c3==me&&c4==me)
            {
            	value+=1000000000;
			}
            if(c1==me&&c2==me&&c3==me&&c3==me&&c4==opp)
            {
            	value+=900000000;
			}					
            
        }
    }
    
	return value;
	
}
