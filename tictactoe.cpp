// 4dtictactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <climits> 
#include<stdlib.h>

//function Declaration
void printboard(bool reset=false);
bool playGame(int playerOption, char sign);
bool checkWinner(int i, int j,char sign);
bool checkDiagonals(int i, int j,char sign);
void greetings(bool success,int player);



char **board;
int dimensions = 3;//default dimensions=3
int drawGame = 0;
int main()
{
    
    bool reset = false;
    int val = 1;
    int playerOption = -1;
    char firstPlayerSign = 'A';
    char secPlayerSign = 'B';
    char sign;
    int player = 1;

   

    do
    {
        
        cout << "How Many Dimensional Game you want to play? Please enter number: ";
        
        cin >> dimensions;
        
        if (dimensions < 3 || cin.fail())
        {
            cout << "Wrong Input dimensions starts from 3, Please Try again!" << endl;
            cin.clear(); 
            cin.ignore(INT_MAX, '\n');
        }
        
    }while (dimensions < 3 || cin.fail());
    drawGame = dimensions * dimensions;

    board = new char* [dimensions];

    for (int i = 0; i < dimensions; i++) {

        board[i] = new char[dimensions];

    }
   

    while (playerOption != 0)
    {
        printboard(reset);
        reset = false;
        do
        {
            cin.clear(); 
            cin.ignore(INT_MAX, '\n'); 
            std::cout << "Player " << player << ": Please choose your location Or Press 0 to exit ";
            std::cin >> playerOption;

            if ((playerOption < 1) || (playerOption > (dimensions * dimensions))||cin.fail())
            {
                cout << "Wrong Input!,Please Try again"<<endl;
            }
        } while ((playerOption<1)||(playerOption>(dimensions*dimensions))||cin.fail());
        switch (player)
        {
        case 1:
            sign = firstPlayerSign;
            break;
        case 2:
            sign = secPlayerSign;
            break;
        }
        bool reply = playGame(playerOption, sign);
        
        if (reply == true || drawGame == 0)
        {
            greetings(reply, player);
            do {
                if (cin.fail())
                {
                    cout << "Wrong Input! ";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
                cout << "Press 0 to Exit and any other number to continue!!";
                cin >> playerOption;


            } while (cin.fail());
            system("CLS");
            player = 0;
            reset = true;
        }
        
        player++;
        if (player >= 3)
        {
            player = 1;
        }
        
    }
   
   
}

void greetings(bool success,int player)
{
    if (success == true )
    {

        cout << "Hurrah!! Congratulations, Player " << player << " have won the game" << endl;
    }
    else if (success == false && drawGame == 0)
    {
        cout << "Oh Your Game is draw" << endl;
    }

 }


void printboard(bool reset)
{
    int val = 1;
    for (int i = 0; i < dimensions; i++)
    {
        for (int j = 0; j < dimensions; j++)
        {
            
           
            if ((board[i][j] == 'A' || board[i][j] == 'B')&& reset == false)
            {
                std::cout << "  " << board[i][j];
            }
        
            else 
            {
                if (reset == true)
                {
                    board[i][j] = ' ';
                }
                if (val < 10)
                {
                    std::cout << "  " <<val;
                }
                else
                {
                    std::cout << " " << val;
                }
                

            }
                
            if (j < dimensions - 1)
            {
                std::cout<< " | ";
            }
            val++;
            
            if (j == dimensions-1 && i<dimensions-1)
            {
                std::cout << endl;
               // cout << "dim" << i << j;
                for (int k = 0; k < dimensions * (dimensions)+6; k++)
                {
                    std::cout << "-";
                }
                std::cout << endl;
            }

        }
    }
    std::cout << endl;
}

bool playGame(int playerOption, char sign)
{
    int i=0, j=0;
    int k = 0;
    
    while (k <= dimensions)
    {
        if (playerOption > (dimensions * k) && playerOption <= (dimensions*(k+1)))
        {
            i = k; j = playerOption - ((dimensions * k) + 1);

        }
        k++;
    }

   
   board[i][j] = sign;    
   bool reply= checkWinner(i, j,sign);
   return reply;
}

bool checkWinner(int i,int j,char sign)
{
    
    bool result = false;
    int row=dimensions, column=dimensions;
    int counter = 0;
    drawGame--;
    if (i == j || ((i + j) / (dimensions - 1) == 1))
    {
        result = checkDiagonals(i, j, sign);
    }
    
        while ((board[i][counter] == sign) || (board[counter][j] == sign) )
        {
            

            if (sign == board[i][counter])
            {

                row = row - 1;
                
            }
            
            if (sign == board[counter][j])
            {
                column = column - 1;
            }
            
            if (counter < (dimensions-1))
            {
                counter++;
            }
            else
                break;
            
        }
    
    if (column == 0 || row == 0 || result==true)
    {
        
        return true;
    }
    else
        return false;
}
bool checkDiagonals(int i, int j,char sign)
{
    int diag = dimensions;
    int k = 0;
    while (board[k][k] == sign)
    {
        diag--;
        if (k < dimensions - 1)
        {
            k++;
        }
        else
        {
            break;
        }
        
    }
    
    if (((i + j) / (dimensions - 1) == 1)&& diag!=0)
    {
        diag = dimensions;
        for (int k = 0; k < dimensions; k++)
        {
            if (board[k][diag - 1] == sign)
            {
                diag--;
            }
            else
            {
                
                break;
            }
        }

    }
   
    if (diag == 0)
    {
        return true;

    }
    else
        return false;
    
}
