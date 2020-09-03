#include <iostream>
#include <iostream>
#include <time.h> 
#include <stdlib.h>   
#include <stdio.h>  
using namespace std;

void player_input(char[]);
void drawBoard(char[]);
int playerAI();
int main()
{
	//1D array 0-8 (ensure user input - 1 to match array) -DV
	char arrayBoard[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8'};

	//Draws the board with the values in arrayBoard
	drawBoard(arrayBoard);

	//call user input function -DV
	player_input(arrayBoard);

	return 0;
}

//Player input function -DV
void player_input(int[])
{
	int playerinput;

	for (int i = 1; i <= 9; i++)
	{

		cout << "Player 1 pick a square by typing a number 1 - 9" << endl;
		cin >> playerinput;
		
		//input validation -DV
		//need to include double selection error -DV
		if (playerinput > 9 || playerinput < 1)
		{
			cout << "Invaild Number" << endl;
		}
		//include AI function for player2 input -DV
		//rename showBoard and playerAI to appropriate function and variable -DV
		else
		{
			showBoard((playerinput - 1), playerAI);
		}
	}

	return(playerinput, playerAI);
}

//Draws a 3 x 3 grid and displays the corresponding input value in each square
void drawBoard(int input[])
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
int playerAI()
{
	int randNum;
	srand(time(NULL));
	randNum = rand() % 8;// Returns random numer from 0-8
	return randNum;
}