#include <iostream>
using namespace std;

void get_input(int[]);

int main()
{
	//1D array 0-8 (ensure user input - 1 to match array) -DV
	int arrayBoard[9];

	//call user input function -DV
	get_input(arrayBoard);

	return 0;
}

//Player input function -DV
void get_input(int[])
{
	int playerinput;

	for (int i = 1; i <= 9; i++)
	{

		cout << "Player 1 pick a square by typing a number 1 - 9";
		cin >> playerinput;

		//include AI function for player2 input -DV

		showBoard((playerinput - 1), playerAI);
	}

	return(playerinput, playerAI);
}