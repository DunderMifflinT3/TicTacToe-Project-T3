#include <iostream>
#include <time.h> 
#include <stdlib.h>   
#include <stdio.h>  
using namespace std;

int playerAI();
void player_input(int[]);
void drawBoard(int[]);

int main()
{
	//1D array 0-8 (ensure user input - 1 to match array) -DV
	char TTT_Board[9] = { '0', '1', '2', '3', '4', '5', '6', '7', '8'};

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
	return randNum;
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

void checkTTT_BoardX()
	{
		//check row 1 for 3 x's
		if (TTT_Board[0] == TTT_Board[1] && TTT_Board[1] == TTT_Board[2] && TTT_Board[2] == 'X')
		{
			cout << "Congratulations Player 1 Wins!" << endl;
		}
		else
			//check row 2 for 3 x's
			if (TTT_Board[3] == TTT_Board[4] && TTT_Board[4] == TTT_Board[5] && TTT_Board[5] == 'X')
			{
				cout << "Congratulations Player 1 Wins!" << endl;
			}
			else
				//check row 3 for 3 x's
				if (TTT_Board[6] == TTT_Board[7] && TTT_Board[7] == TTT_Board[8] && TTT_Board[8] == 'X')
				{
					cout << "Congratulations Player 1 Wins!" << endl;
				}
				else
					//check column 1 for 3 x's
					if (TTT_Board[0] == TTT_Board[3] && TTT_Board[3] == TTT_Board[6] && TTT_Board[6] == 'X')
					{
						cout << "Congratulations Player 1 Wins!" << endl;
					}
					else
						//check column 2 for 3 x's
						if (TTT_Board[1] == TTT_Board[4] && TTT_Board[4] == TTT_Board[7] && TTT_Board[7] == 'X')
						{
							cout << "Congratulations Player 1 Wins!" << endl;
						}
						else
							//check column 3 for 3 x's
							if (TTT_Board[2] == TTT_Board[5] && TTT_Board[5] == TTT_Board[8] && TTT_Board[8] == 'X')
							{
								cout << "Congratulations Player 1 Wins!" << endl;
							}
							else
								//check top left diagnol for 3 x's
								if (TTT_Board[0] == TTT_Board[4] && TTT_Board[4] == TTT_Board[8] && TTT_Board[8] == 'X')
								{
									cout << "Congratulations Player 1 Wins!" << endl;
								}
								else
									//check top right diagnol for 3 x's
									if (TTT_Board[2] == TTT_Board[4] && TTT_Board[4] == TTT_Board[6] && TTT_Board[6] == 'X')
									{
										cout << "Congratulations Player 1 Wins!" << endl;
									}
									else
										//check row 1 for 3 o's
										if (TTT_Board[0] == TTT_Board[1] && TTT_Board[1] == TTT_Board[2] && TTT_Board[2] == 'O')
										{
											cout << "Congratulations Player 2 Wins!" << endl;
										}
										else
											//check row 2 for 3 o's
											if (TTT_Board[3] == TTT_Board[4] && TTT_Board[4] == TTT_Board[5] && TTT_Board[5] == 'O')
											{
												cout << "Congratulations Player 2 Wins!" << endl;
											}
											else
												//check row 3 for 3 o's
												if (TTT_Board[6] == TTT_Board[7] && TTT_Board[7] == TTT_Board[8] && TTT_Board[8] == 'O')
												{
													cout << "Congratulations Player 2 Wins!" << endl;
												}
												else
													//check column 1 for 3 o's
													if (TTT_Board[0] == TTT_Board[3] && TTT_Board[3] == TTT_Board[6] && TTT_Board[6] == 'O')
													{
														cout << "Congratulations Player 2 Wins!" << endl;
													}
													else
														//check column 2 for 3 o's
														if (TTT_Board[1] == TTT_Board[4] && TTT_Board[4] == TTT_Board[7] && TTT_Board[7] == 'O')
														{
															cout << "Congratulations Player 2 Wins!" << endl;
														}
														else
															//check column 3 for 3 o's
															if (TTT_Board[2] == TTT_Board[5] && TTT_Board[5] == TTT_Board[8] && TTT_Board[8] == 'O')
															{
																cout << "Congratulations Player 2 Wins!" << endl;
															}
															else
																//check top left diagnol for 3 o's
																if (TTT_Board[0] == TTT_Board[4] && TTT_Board[4] == TTT_Board[8] && TTT_Board[8] == 'O')
																{
																	cout << "Congratulations Player 2 Wins!" << endl;
																}
																else
																	//check top right diagnol for 3 o's
																	if (TTT_Board[2] == TTT_Board[4] && TTT_Board[4] == TTT_Board[6] && TTT_Board[6] == 'O')
																	{
																		cout << "Congratulations Player 2 Wins!" << endl;
																	}
																	else
																		cout << "It is a Tie!" << endl;
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

void restart()
{
	drawBoard(TTT_Board);
}
