#include <iostream>
#include <iostream>
#include <time.h> 
#include <stdlib.h>   
#include <stdio.h> 
using namespace std;
char TTT_Board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
int playerAI();
void player_input(char[]);
void drawBoard(char[]);
void playAgain();
void callHelp();
void showBoard(char, char);
bool checkTTT_BoardX();
void checkTie();
int moveCheck(char);
int moveCheckAI(int);
int main()
{
	//Calls Help
	callHelp();

	//Draws the board with the values in arrayBoard
	drawBoard(TTT_Board);

	//call user input function -DV
	player_input(TTT_Board);

	return 0;
}
int playerAI()
{
	int randNum;
	srand(time(NULL));
	randNum = rand() % 8;// Returns random numer from 0-8
	randNum = randNum;
	return randNum;
}
//Player input function -DV
void player_input(char TTT_Board[])
{
	char playerinput;

	


	for (int i = 1; i <= 9; i++)
	{
		cout << "Player 1 pick a square by typing a number 1 - 9" << endl;
		cin >> playerinput;
		while (playerinput != '1' && playerinput != '2' && playerinput != '3' && playerinput != '4' && playerinput != '5' && playerinput != '6' && playerinput != '7' && playerinput != '8'
			&& playerinput != '9' && playerinput != 'h' && playerinput != 'H' && playerinput != 'r' && playerinput != 'R')
		{
			cout << "Invalid Input" << endl;
			cin >> playerinput;
		}

		//Move Check prevent double move
		while (moveCheck(playerinput) == 0)
		{
			cout << "Invalid move, please pick again" << endl; // input val for player 
			cin >> playerinput;
		}
		//char AIhold =static_cast<char>(playerAI());


		//call help input
		if (playerinput == 'H' || playerinput == 'h')
		{
			callHelp();
		}
		//call restart input
		else if (playerinput == 'R' || playerinput== 'r')
		{
			playAgain();
		}
		//Places Player input into array as X
		// tests all cases of player val 
		else if (playerinput == '1')
		{
			//playerinput = '0';
			TTT_Board[0] = 'X';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (playerinput == '2')
		{
			TTT_Board[1] = 'X';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (playerinput == '3')
		{
			TTT_Board[2] = 'X';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (playerinput == '4')
		{
			TTT_Board[3] = 'X';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (playerinput == '5')
		{
			TTT_Board[4] = 'X';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (playerinput == '6')
		{
			TTT_Board[5] = 'X';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (playerinput == '7')
		{
			TTT_Board[6] = 'X';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (playerinput == '8')
		{
			TTT_Board[7] = 'X';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (playerinput == '9')
		{
			TTT_Board[8] = 'X';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		
		int count = 0, count1 = 0;
		int AIhold = playerAI();
		while (moveCheckAI(AIhold) == 0) // Ai var validation 
		{
			AIhold = moveCheckAI(playerAI());
			if (count > 15)// fail safe for loop of randum num 
			{
				AIhold = count1++;
			}
			count++;
		}
		// Rests AI var cases 
		if (AIhold == 0)
		{
			TTT_Board[0] = 'O';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (AIhold == 1)
		{
			TTT_Board[1] = 'O';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (AIhold == 2)
		{
			TTT_Board[2] = 'O';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (AIhold == 3)
		{
			TTT_Board[3] = 'O';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (AIhold == 4)
		{
			TTT_Board[4] = 'O';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (AIhold == 5)
		{
			TTT_Board[5] = 'O';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (AIhold == 6)
		{
			TTT_Board[6] = 'O';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (AIhold == 7)
		{
			TTT_Board[7] = 'O';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
		else if (AIhold == 8)
		{
			TTT_Board[8] = 'O';
			drawBoard(TTT_Board);
			checkTTT_BoardX();
			checkTie();
		}
	}
}
//TieFunctions
void checkTie()
{
	int filledSquares = 0;
	for (int i = 0; i < 9; i++)
	{
		if (TTT_Board[i] != ' ')
		{
			filledSquares = filledSquares + 1;
		}
		else
		{
		}
	}
	while (checkTTT_BoardX() != true && filledSquares == 9)
	{
		cout << "It is a Tie!" << endl;
		playAgain();
	}
}
bool checkTTT_BoardX()
{
	//check row 1 for 3 x's
	if (TTT_Board[0] == TTT_Board[1] && TTT_Board[1] == TTT_Board[2] && TTT_Board[2] == 'X')
	{
		cout << "Congratulations Player 1 Wins!" << endl;
		playAgain();
		return true;
	}
	else
		//check row 2 for 3 x's
		if (TTT_Board[3] == TTT_Board[4] && TTT_Board[4] == TTT_Board[5] && TTT_Board[5] == 'X')
		{
			cout << "Congratulations Player 1 Wins!" << endl;
			playAgain();
			return true;
		}
		else
			//check row 3 for 3 x's
			if (TTT_Board[6] == TTT_Board[7] && TTT_Board[7] == TTT_Board[8] && TTT_Board[8] == 'X')
			{
				cout << "Congratulations Player 1 Wins!" << endl;
				playAgain();
				return true;
			}
			else
				//check column 1 for 3 x's
				if (TTT_Board[0] == TTT_Board[3] && TTT_Board[3] == TTT_Board[6] && TTT_Board[6] == 'X')
				{
					cout << "Congratulations Player 1 Wins!" << endl;
					playAgain();
					return true;
				}
				else
					//check column 2 for 3 x's
					if (TTT_Board[1] == TTT_Board[4] && TTT_Board[4] == TTT_Board[7] && TTT_Board[7] == 'X')
					{
						cout << "Congratulations Player 1 Wins!" << endl;
						playAgain();
						return true;
					}
					else
						//check column 3 for 3 x's
						if (TTT_Board[2] == TTT_Board[5] && TTT_Board[5] == TTT_Board[8] && TTT_Board[8] == 'X')
						{
							cout << "Congratulations Player 1 Wins!" << endl;
							playAgain();
							return true;
						}
						else
							//check top left diagnol for 3 x's
							if (TTT_Board[0] == TTT_Board[4] && TTT_Board[4] == TTT_Board[8] && TTT_Board[8] == 'X')
							{
								cout << "Congratulations Player 1 Wins!" << endl;
								playAgain();
								return true;
							}
							else
								//check top right diagnol for 3 x's
								if (TTT_Board[2] == TTT_Board[4] && TTT_Board[4] == TTT_Board[6] && TTT_Board[6] == 'X')
								{
									cout << "Congratulations Player 1 Wins!" << endl;
									playAgain();
									return true;
								}
								else
									//check row 1 for 3 o's
									if (TTT_Board[0] == TTT_Board[1] && TTT_Board[1] == TTT_Board[2] && TTT_Board[2] == 'O')
									{
										cout << "Congratulations Player 2 Wins!" << endl;
										playAgain();
										return true;
									}
									else
										//check row 2 for 3 o's
										if (TTT_Board[3] == TTT_Board[4] && TTT_Board[4] == TTT_Board[5] && TTT_Board[5] == 'O')
										{
											cout << "Congratulations Player 2 Wins!" << endl;
											playAgain();
											return true;
										}
										else
											//check row 3 for 3 o's
											if (TTT_Board[6] == TTT_Board[7] && TTT_Board[7] == TTT_Board[8] && TTT_Board[8] == 'O')
											{
												cout << "Congratulations Player 2 Wins!" << endl;
												playAgain();
												return true;
											}
											else
												//check column 1 for 3 o's
												if (TTT_Board[0] == TTT_Board[3] && TTT_Board[3] == TTT_Board[6] && TTT_Board[6] == 'O')
												{
													cout << "Congratulations Player 2 Wins!" << endl;
													playAgain();
													return true;
												}
												else
													//check column 2 for 3 o's
													if (TTT_Board[1] == TTT_Board[4] && TTT_Board[4] == TTT_Board[7] && TTT_Board[7] == 'O')
													{
														cout << "Congratulations Player 2 Wins!" << endl;
														playAgain();
														return true;
													}
													else
														//check column 3 for 3 o's
														if (TTT_Board[2] == TTT_Board[5] && TTT_Board[5] == TTT_Board[8] && TTT_Board[8] == 'O')
														{
															cout << "Congratulations Player 2 Wins!" << endl;
															playAgain();
															return true;
														}
														else
															//check top left diagnol for 3 o's
															if (TTT_Board[0] == TTT_Board[4] && TTT_Board[4] == TTT_Board[8] && TTT_Board[8] == 'O')
															{
																cout << "Congratulations Player 2 Wins!" << endl;
																playAgain();
																return true;
															}
															else
																//check top right diagnol for 3 o's
																if (TTT_Board[2] == TTT_Board[4] && TTT_Board[4] == TTT_Board[6] && TTT_Board[6] == 'O')
																{
																	cout << "Congratulations Player 2 Wins!" << endl;
																	playAgain();
																	return true;
																}
																else
																{
																	return false;
																}

}
//Displays Help
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
	cout << "Type 'R' to restart." << endl;
	cout << "Type 'H' for instructions on how to play." << endl;
	cout << "Get three in a row to win!" << endl;
}

//Draws a 3 x 3 grid and displays the corresponding input value in each square
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
void showBoard(char user, char  AI)
{
	TTT_Board[user] = 'X';
	TTT_Board[AI] = 'O';
}

// Asks User if they want to play again at the end of game
void restart()
{
	drawBoard(TTT_Board);
}

int moveCheckAI(int  AI)
{
	if (TTT_Board[AI] == 'X' || TTT_Board[AI] == 'O')
	{
		return 0;
	}
	else
		return 1;
}
int moveCheck(char playerInput)
{
	int I;

	I = (int)(playerInput);
	I = I - 49;
	if (TTT_Board[I] == 'X' || TTT_Board[I] == 'O')
	{
		return 0;
	}
	else
		return 1;
}
void playAgain()
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
		player_input(TTT_Board);
	}
	else if (input == 'N' || input == 'n')
	{
		exit(0);
	}
}
