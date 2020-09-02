#include <iostream>
using namespace std;

void get_input(int[]);

int main()
{
	//1D array 0-8 (ensure user input - 1 to match array) -DV
	int arrayBoard[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8};

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
