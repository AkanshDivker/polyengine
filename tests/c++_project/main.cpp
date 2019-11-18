#include <iostream>
#include <ctime>
#include <climits>
#include "neweval.h"
#include "TreeNodes.h"
#include "ConnectFourBoard.h"
#include "AlphaBeta.h"

using namespace std;


int num_nodes_generated, num_nodes_expanded,game_path_length,start_time,stop_time;


char evalfn_choiceX,evalfn_choiceO;


int main(){
    
    int order;
    int choiceX,choiceO;
    
    cout<<"choose first or second turn?"<<endl;
    cout<<"  1 - first turn (X)"<<endl;
    cout<<"  2 - second turn (O)"<<endl;
    cout<<endl;
    cin>>order;
    cout<<endl;
    
    
    switch(order)
    {
    	case 1 : 
			choiceX = 0; 
			choiceO = 1;
			break;
		case 2 :
        	choiceX = 1;
        	choiceO = 0;
        	break;
	}

    
    int moves_made = 0;
    tic *board_ob = new tic;
    
    cout<<endl;
    cout<<"initial board state before starting game with(Initial Node config/Root Node) "<<moves_made<<" moves made"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    
    board_ob->display_board(board_ob);
    board_ob->player = 'X'; 
    
    alphabeta ab_ob;
   
    while(!board_ob->checkPlayerWon()){
        
        tree *head = new tree;
        *(head->ob) = *board_ob;
        
        if(head->ob->isBoardEmpty()){
            if(choiceX == 0 && moves_made == 0){
                int c;
                cout<<"User's turn!"<<endl;
                    cout<<"Fisrt move cannot be column 3!"<<endl;
                    cout<<"select column: ";
                    cin>>c;
                    cout<<endl;
                    while(c==3){
                        cout<<"Select again: ";
                        cin>>c;
                        cout<<endl;
                    }

                head->ob->board[0][c] = 'X';
                head->ob->player = 'X';
                
            }
            else if(choiceX == 1 && moves_made == 0){
                int random_col_index = head->ob->makeFirstMove();
                head->ob->board[0][random_col_index] = 'X';
                head->ob->player = 'X';
            }
           
            cout<<"Display board: "<<(moves_made+1)<<" moves made"<<endl;
            head->ob->display_board(head->ob);
         
            *(board_ob) = *(head->ob);
            
        }

        if(head->ob->player == 'O' &&  choiceX == 0 && moves_made >= 1){
            int c;
            int row, col;
            
            
            do{
                cout<<"User's turn!"<<endl;
                cout<<"Select Column: ";
                cin>>c;
                cout<<endl;
                head->ob->checkPossibleMoves();
                for(int i = 0; i < 7; i++){
                    if(head->ob->moves[i].col_index == c){
                        row = head->ob->moves[i].row_index;
                        col = head->ob->moves[i].col_index;
                    }
                }
            }while(row == -1);
            
            head->ob->board[row][col] = 'X';
            head->ob->player = 'X';
            
            cout<<"Display board: "<<(moves_made+1)<<" moves made"<<endl;
            head->ob->display_board(head->ob);
            
            if(head->ob->checkPlayerWon()){
                cout<<"You won!"<<endl;
                return 0;
            }
            *(board_ob) = *(head->ob);
        }

        if(head->ob->player == 'O' && choiceX == 1 && moves_made >= 1){
            int max = INT_MIN;
            int maxindex = -1;
            cout<<"AI turn"<<endl;
            clock_t begin = clock();
            
            int x = ab_ob.alpha_beta(head,0,head->ob->player,INT_MIN,INT_MAX, 'X');
            
            for(int i = 6; i >= 0; i--){
                int tempheur = head->children[i]->heuristic_value;
                cout<<i<<": "<<tempheur<<endl;
                if(tempheur >= max && head->children[i]->ob->moves[i].row_index != -1){
                    max = tempheur;
                    maxindex = i;
                }
            }
            clock_t  finish = clock();
      
            for(int i=0;i<7;i++)
            {
            	if(head->children[maxindex]->heuristic_value<neweval(head->children[i]))
            	{
            		
            		maxindex=i;
            		*(head->children[maxindex]->ob)=*(head->children[i]->ob);
            		max=head->children[maxindex]->heuristic_value=neweval(head->children[i]);
            		
				}
			}
            
            cout<<"----------------------------->>>"<<endl;
            double elapsed_secs = double(finish - begin) / CLOCKS_PER_SEC;
            cout<<"time: "<<elapsed_secs<<"second"<<endl;
            cout<<"row which AI choose is: ";
            cout<<head->children[maxindex]->ob->moves[maxindex].col_index<<endl;
            cout<<"evaluation values is as follows"<<endl;
            for(int k = 0; k < 7; k++){
                cout<<"row "<<k<<"'s evalution value is : "<<head->children[k]->heuristic_value<<endl;
            }
            cout<<maxindex<<"'s evaluation value is "<<head->children[maxindex]->heuristic_value<<" selected for hightest value."<<endl;
            cout<<"detail reason: "<<head->children[maxindex]->str<<endl;
            head->ob->display_board(head->children[maxindex]->ob);
            
            
            if(head->children[maxindex]->ob->checkPlayerWon()){
                cout<<"AI won!"<<endl;
                return 0;
            }
            
            
            cout<<"----------------------------->>>"<<endl;
            
            *(board_ob) = *(head->children[maxindex]->ob);
        }

        if(head->ob->player == 'X' && choiceO == 0 && moves_made >= 1){
            int c;
            int row, col;
            
             
            do{
                cout<<"User's turn!"<<endl;
                cout<<"Select Column: ";
                cin>>c;
                cout<<endl;
                head->ob->checkPossibleMoves();
                for(int i = 0; i < 7; i++){
                    if(head->ob->moves[i].col_index == c){
                        row = head->ob->moves[i].row_index;
                        col = head->ob->moves[i].col_index;
                    }
                }
            }while(row == -1);
            
        
            head->ob->board[row][col] = 'O';
            head->ob->player = 'O';
            
            
            cout<<"Display board: "<<(moves_made+1)<<" moves made"<<endl;
            head->ob->display_board(head->ob);
            
           
            if(head->ob->checkPlayerWon()){
                cout<<"You won!"<<endl;
                return 0;
            }
            
            *(board_ob) = *(head->ob);
            
        }

        if(head->ob->player == 'X' && choiceO == 1 && moves_made >= 1){
            int max = INT_MIN;
            int maxindex = -1;
            cout<<"AI turn"<<endl;
            clock_t begin = clock();
            
            
            int x = ab_ob.alpha_beta(head,0,head->ob->player,INT_MIN,INT_MAX, 'O');
            
            for(int i = 6; i >= 0; i--){
                int tempheur = head->children[i]->heuristic_value;
                cout<<i<<": "<<tempheur<<endl;
                if(tempheur >= max && head->children[i]->ob->moves[i].row_index != -1){
                    max = tempheur;
                    maxindex = i;
                }
            }
            clock_t  finish = clock();
         
            for(int i=0;i<7;i++)
            {
            	if(head->children[maxindex]->heuristic_value<neweval(head->children[i]))
            	{
            		
            		maxindex=i;
            		*(head->children[maxindex]->ob)=*(head->children[i]->ob);
            		max=head->children[maxindex]->heuristic_value=neweval(head->children[i]);
            		
				}
			}
            
            cout<<"----------------------------->>>"<<endl;
            double elapsed_secs = double(finish - begin) / CLOCKS_PER_SEC;
            cout<<"time: "<<elapsed_secs<<"second"<<endl;
            cout<<"row which AI choose is: ";
            cout<<head->children[maxindex]->ob->moves[maxindex].col_index<<endl;
            cout<<"evaluation values is as follows"<<endl;
            for(int k = 0; k < 7; k++){
                cout<<"row "<<k<<"'s evalution value is : "<<head->children[k]->heuristic_value<<endl;
            }
            cout<<maxindex<<"'s evaluation value is "<<head->children[maxindex]->heuristic_value<<" selected for hightest value."<<endl;
            cout<<"detail reason: "<<head->children[maxindex]->str<<endl;
            head->ob->display_board(head->children[maxindex]->ob);
            
          
            if(head->children[maxindex]->ob->checkPlayerWon()){
                cout<<"AI won!"<<endl;
                return 0;
            }
            
            
            cout<<"----------------------------->>>"<<endl;
            
            *(board_ob) = *(head->children[maxindex]->ob);
        }
       
   
        moves_made++;
        cout<<"moves made: "<<moves_made<<endl;
        game_path_length++;
    }
    
    return 0;
}
