#include <iostream>
#include <iostream>
#include <time.h> 
#include <iostream>
#include <iostream>
#include <time.h> 
#include <stdlib.h>   
#include <stdio.h>
#include<windows.h>
using namespace std;
char TTT_Board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
void callHelp();
void drawBoard(char[]);// function headers
void player_input();
void playAgain();
bool checkTTT_BoardX();
int moveCheck(int);
int main()
{
	void callHelp();
	drawBoard(TTT_Board);
	player_input();
}
void callHelp()
{
	cout << "Input a number between 1 and 9, as shown below, to place an X (Player 1) or an O (Player 2) in that spot." << endl;
	cout << "     |     |     " << endl;
	cout << "  1  |  2  |  3  " << endl;		//First row inputs
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  4  |  5  |  6  " << endl;		//Second row inputs
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  7  |  8  |  9  " << endl;		//Third row inputs
	cout << "     |     |     " << endl;
	cout << "Type '0' to restart." << endl;
	cout << "Type '-999' for instructions on how to play." << endl;
	cout << "Get three in a row to win!" << endl;
	drawBoard(TTT_Board);
}
void drawBoard(char input[])
{
	cout << "     |     |     " << endl;
	cout << "  " << input[0] << "  |  " << input[1] << "  |  " << input[2] << "  " << endl;		//First row inputs
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << input[3] << "  |  " << input[4] << "  |  " << input[5] << "  " << endl;		//Second row inputs
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << input[6] << "  |  " << input[7] << "  |  " << input[8] << "  " << endl;		//Third row inputs
	cout << "     |     |     " << endl;
}


void playAgain()// function is called when 0 is hit and restarts game
{
	char input;
	cout << "Play again?\n Y for Yes, N for No" << endl;
	cin >> input;
	//loop checks if user entered correct input
	while (input != 'Y' && input != 'y' && 'y' && input != 'N' && input != 'n')
	{
		cout << "invalid input enter again" << endl;
		cin >> input;
	}
	if (input == 'Y' || input == 'y')
	{
		for (int i = 0; i < 9; i++)
		{
			TTT_Board[i] = ' ';
		}
		drawBoard(TTT_Board);
		player_input();
	}
	else if (input == 'N' || input == 'n')
	{
		exit(0);
	}
}
void player_input()// checks player input 
{
	int playerinput;
	for (int j = 1; 1 < 9; j++)
	{
		cout << "Player 1 pick a square by typing a number 1 - 9" << endl;
		cin >> playerinput;
		
			/*while (isdigit(playerinput)==false)
			{

			}*/
			//cin.ignore(10, '\n');
			bool test = false;
			while (test == false)
			{
				for (int x = 1; x <= 9; x++)// tests for all numbers 1-9
				{
					if (playerinput == x && test == false)
					{
						test = true;

					}
					else if(playerinput== -999 || playerinput== 0)// speical case numbers 
					{
						test = true;
					}
				}
				if (test == false)
				{
					cout << "Invalid Input" << endl;
					cin >> playerinput;
				}
				//cin.ignore(10, '\n');
			}
			while (moveCheck(playerinput) == 0)// need to be fixed 
			{
				cout << "Invalid move, please pick again" << endl; // input val for player 
				cin >> playerinput;
				cin.ignore(10, '\n');
			}
			for (int i = 1; i <= 9; i++)
			{
				if (playerinput == i)// replaced all if staments 
				{
					TTT_Board[i - 1] = 'X';
					drawBoard(TTT_Board);
					checkTTT_BoardX();
					//checkTie();
					
				}
			}
			 if (playerinput == -999)// call help
			{
				callHelp();
			}
			//call restart input
			else if (playerinput == 0)
			{
				playAgain();
			}



		
	}
}
bool checkTTT_BoardX()// improved check function 
{
	for (int i=0; i<8; i++)
	{
		if ( TTT_Board[i] == 'X' && TTT_Board[i+1] == 'X' && TTT_Board[i+2] == 'X'&& (i==0 || i==3 || i==6))
		{
			cout << "Congratulations Player 1 Wins!" << endl;
			playAgain();
			return true;
		}
		else if(TTT_Board[i] == 'X' && TTT_Board[i + 3] == 'X' && TTT_Board[i + 6] == 'X')
		{
			cout << "Congratulations Player 1 Wins!" << endl;
			playAgain();
			return true;
		}
		else if (TTT_Board[i] == 'X' && TTT_Board[i + 4] == 'X' && TTT_Board[i + 8] == 'X')
		{
			cout << "Congratulations Player 1 Wins!" << endl;
			playAgain();
			return true;
		}
		else if (TTT_Board[i+2] == 'X' && TTT_Board[i + 4] == 'X' && TTT_Board[i + 6] == 'X' && i+2==2)
		{
			cout << "Congratulations Player 1 Wins!" << endl;
			playAgain();
			return true;
		}
	
	}
}
int moveCheck(int playerInput )// needs to be finished
{
	int takenspots[9] = { 0,0,0,0,0,0,0,0,0 };
	
	for (int x = 0; x < 8; x++)
	{
		if (takenspots[x]==0)
		{
			takenspots[playerInput-1] = 1;
			if (x==8)
			{
				return 1;
			}
			
		}
		else
			if (x == 8)
			return 0;
	
	}
}

/* Tyler Notes
Requirements 
Code bugs out when char is in
Ai needs to be added
place checking needs to be implemented 
*/
