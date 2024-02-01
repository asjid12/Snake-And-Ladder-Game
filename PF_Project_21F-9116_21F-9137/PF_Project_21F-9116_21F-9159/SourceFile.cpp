#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<string>
using namespace std;
//global variables.
int num[10][10];
int player1_row = 9, player2_row = 9, player3_row = 9, player4_row = 9; // Row position for players 
int player1_col = 0, player2_col = 0, player3_col = 0, player4_col = 0; // Col Position for Players 
int s1, s2, s3, s4;
int i, j, k, l;
int M;
//functions.
void playGame();            
void board(int num[][10]); 
void intro();             
void userchoice();       
void credits();         
void instructions();   
void instructions1();
//snakes and ladder functions
bool snakes1();
bool snakes2();
bool snakes3();
bool snakes4();
bool ladders1();
bool ladders2();
bool ladders3();
bool ladders4();
//main function
int main()            //main function which operates rest of the functions.
{
	intro();
	userchoice();
	if (M == 1)
	{
		system("cls");
		playGame();
	}
	else if (M == 2)
	{
		system("cls");
		credits();
	}
	else if (M == 3)
	{
		system("cls");
		instructions1();
	}
	else if (M == 4)
	{

	}
	else if (M == 5)
	{
		system("cls");
	}
	return 0;
}
//other game functions
void playGame()//board function called in it when user wants to play game.
{
	//srand((unsigned int)time(NULL));
	s1 = 0, s2 = 0, s3 = 0, s4 = 0;
	bool player1_forward = true, player2_forward = true, player3_forward = true, player4_forward = true;
	int playerturn = 0;
	int winOperate = 0;  //to see if 3 users have won.
	bool firstTurn = true;
	while (winOperate <= 2)// will run until game is over.
	{
		system("cls");
		instructions();
		board(num);
		cout << "\n\nGenerating the Dice Number for player ";
		cout << playerturn + 1;
		cout << ": ";
		int dice;
		//dice = (rand() % 6) + 1;
		cin >> dice;
		cout << dice << endl;
		cin.get();
		if (firstTurn == true && dice != 6)
		{
			continue;
		}
		else if (firstTurn == true && dice == 6)
		{
			firstTurn = false;
		}
		if (playerturn == 0)   //for the first player.
		{
			if (player1_forward == true)
			{
				if ((player1_col + dice) > 9)
				{
					player1_row--;
					dice = dice - (9 - player1_col);
					player1_col = 10 - dice;
					player1_forward = false;
				}
				else
				{
					player1_col = player1_col + dice;
				}
			}
			else // Forward_movement is false.
			{
				if ((player1_col - dice) < 0)
				{
					player1_row--;
					player1_col = dice - player1_col;
					player1_forward = true;
				}
				else
				{
					player1_col = player1_col - dice;
				}
			}
			if (snakes1() == true)
			{
				s1 -= 4;
				player1_forward = !player1_forward;
				cout << "Bit by a snake!!!" << endl;
			}
			else if (ladders1() == true)
			{
				s1 += 5;
				player1_forward = !player1_forward;
				cout << "Ladder reached!!!" << endl;
			}
			else
			{
				s1 += 2;
			}
			if (player1_row <= 0 && player1_col <= 0)
			{
				winOperate++;
			}
		}
		else if (playerturn == 1) //for the second player.
		{
			if (player2_forward == true)
			{
				if ((player2_col + dice) > 9)
				{
					player2_row--;
					dice = dice - (9 - player2_col);
					player2_col = 10 - dice;
					player2_forward = false;
				}
				else
				{
					player2_col = player2_col + dice;
				}
			}
			else // Forward_movement is false 
			{
				if ((player2_col - dice) < 0)
				{
					player2_row--;
					player2_col = dice - player2_col;
					player2_forward = true;
				}
				else
				{
					player2_col = player2_col - dice;
				}
			}
			if (snakes2() == true)
			{
				s2 -= 4;
				player2_forward = !player2_forward;
				cout << "Bit by a snake!!!" << endl;
			}
			else if (ladders2() == true)
			{
				s2 += 5;
				player2_forward = !player2_forward;
				cout << "Ladder reached!!!" << endl;
			}
			else
			{
				s2 += 2;
			}
			if (player2_row <= 0 && player2_col <= 0)
			{
				winOperate++;
			}
		}
		else if (playerturn == 2)    //for the third player.
		{
			if (player3_forward == true)
			{
				if ((player3_col + dice) > 9)
				{
					player3_row--;
					dice = dice - (9 - player3_col);
					player3_col = 10 - dice;
					player3_forward = false;
				}
				else
				{
					player3_col = player3_col + dice;
				}
			}
			else // Forward_movement is false 
			{
				if ((player3_col - dice) < 0)
				{
					player3_row--;
					player3_col = dice - player3_col;
					player3_forward = true;
				}
				else
				{
					player3_col = player3_col - dice;
				}
			}
			if (snakes3() == true)
			{
				s3 -= 4;
				player3_forward = !player3_forward;
				cout << "Bit by a snake!!!" << endl;
			}
			else if (ladders3() == true)
			{
				s3 += 5;
				player3_forward = !player3_forward;
				cout << "Ladder reached!!!" << endl;
			}
			else
			{
				s3 += 2;
			}
			if (player3_row <= 0 && player3_col <= 0)
			{
				winOperate++;
			}
		}
		else if (playerturn == 3)   //for the fourth player.
		{
			if (player4_forward == true)
			{
				if ((player4_col + dice) > 9)
				{
					player4_row--;
					dice = dice - (9 - player4_col);
					player4_col = 10 - dice;
					player4_forward = false;
				}
				else
				{
					player4_col = player4_col + dice;
				}
			}
			else // Forward_movement is false 
			{
				if ((player4_col - dice) < 0)
				{
					player4_row--;
					player4_col = dice - player4_col;
					player4_forward = true;
				}
				else
				{
					player4_col = player4_col - dice;
				}
			}
			if (snakes4() == true)
			{
				s4 -= 4;
				player4_forward = !player4_forward;
				cout << "Bit by a snake!!!" << endl;
			}
			else if (ladders4() == true)
			{
				s4 += 5;
				player4_forward = !player4_forward;
				cout << "Ladder reached!!!" << endl;
			}
			else
			{
				s4 += 2;
			}
			if (player4_row <= 0 && player4_col <= 0)
			{
				winOperate++;
			}
		}
		playerturn++;
		if (playerturn == 4)
		{
			playerturn = 0;
		}
	}
	system("cls");
	if (s1 > s2 && s1 > s3 && s1 > s4)
	{
		cout << "Winner is Player 1 (@) and score is: " << s1 << endl;
	}
	else if (s2 > s1 && s2 > s3 && s2 > s4)
	{
		cout << "Winner is Player 2 (#) and score is: " << s2 << endl;
	}
	else if (s3 > s2 && s2 > s3 && s2 > s4)
	{
		cout << "Winner is Player 3 ($) and score is: " << s3 << endl;
	}
	else if (s4 > s2 && s4 > s3 && s4 > s1)
	{
		cout << "Winner is Player 4 (&) and score is: " << s4 << endl;
	}
}
void board(int num[][10])//game board with array and colors, prints the board.
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   //This function is also used to give the board it's colors.
	int n = 100;
	int m = 81;
	bool check = false;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (i % 2 == 0)
			{
				num[i][j] = n;
				n--;
				check = true;
			}
			else
			{
				num[i][j] = m;
				m++;
				check = false;
			}
		}
		if (check)
		{
			for (k = 0; k < 10; k++)
			{
				n--;
			}
		}
		else
		{
			for (l = 0; l < 30; l++)
			{
				m--;
			}
		}
	}
	SetConsoleTextAttribute(hConsole, 14);
	for (i = 0; i < 56; i++)
	{
		cout << "*";
	}
	cout << endl << endl;
	for (i = 0; i < 10; i++)
	{
		SetConsoleTextAttribute(hConsole, 13);
		cout << "|";
		for (j = 0; j < 10; j++)
		{
			for (j = 0; j < 10; j++)
			{
				bool c = true;
				SetConsoleTextAttribute(hConsole, 11);
				if (player1_row == i && player1_col == j)
				{
					SetConsoleTextAttribute(hConsole, 10);
					cout << setw(5) << "@" << setw(5);
					c = false;
				}
				if (player2_row == i && player2_col == j)
				{
					SetConsoleTextAttribute(hConsole, 10);
					cout << setw(5) << "#" << setw(5);
					c = false;
				}
				if (player3_row == i && player3_col == j)
				{
					SetConsoleTextAttribute(hConsole, 10);
					cout << setw(5) << "$" << setw(5);
					c = false;
				}
				if (player4_row == i && player4_col == j)
				{
					SetConsoleTextAttribute(hConsole, 10);
					cout << setw(5) << "&" << setw(5);
					c = false;
				}
				if (c == true)
				{ // Otherwise Print the Board Number 
					SetConsoleTextAttribute(hConsole, 11);
					cout << setw(5) << num[i][j] << setw(5);
				}
			}
			SetConsoleTextAttribute(hConsole, 13);
			cout << "|" << endl << endl;
		}
	}
	SetConsoleTextAttribute(hConsole, 14);
	for (i = 0; i < 56; i++)
	{
		cout << "*";
	}
	cout << endl;
}
void intro()//displays game name and #'s with Sleep.
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (i = 0;i < 3;i++)
	{
		cout << setw(35);
		for (j = 0;j < 56;j++)
		{
			Sleep(20);
			SetConsoleTextAttribute(hConsole, 12);
			cout << "#";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, 10);
	cout << setw(73) << "|SNAKE AND LADDER GAME|" << endl;
	for (i = 0;i < 3;i++)
	{
		cout << setw(35);
		for (j = 0;j < 56;j++)
		{
			Sleep(20);
			SetConsoleTextAttribute(hConsole, 12);
			cout << "#";
		}
		cout << endl;
	}
}
void userchoice()//presents user with choice after introduction.
{
	HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colors, 13);
	cout << "\t\t\t\t\t __________________________________" << endl;
	cout << "\t\t\t\t\t| ";
	SetConsoleTextAttribute(colors, 7);
	Sleep(500);
	cout << "Press '1' to Play game.";
	SetConsoleTextAttribute(colors, 13);
	cout << "\t   | " << endl;
	cout << "\t\t\t\t\t|__________________________________|" << endl;
	cout << "\t\t\t\t\t| ";
	SetConsoleTextAttribute(colors, 7);
	Sleep(500);
	cout << "Press '2' to Credits.";
	SetConsoleTextAttribute(colors, 13);
	cout << "\t\t   | " << endl;
	cout << "\t\t\t\t\t|__________________________________|" << endl;
	cout << "\t\t\t\t\t| ";
	SetConsoleTextAttribute(colors, 7);
	Sleep(500);
	cout << "Press '3' to Instructions/Rules.";
	SetConsoleTextAttribute(colors, 13);
	cout << " | " << endl;
	cout << "\t\t\t\t\t|__________________________________|" << endl;
	cout << "\t\t\t\t\t| ";
	SetConsoleTextAttribute(colors, 7);
	Sleep(500);
	cout << "Press '4' to Record.";
	SetConsoleTextAttribute(colors, 13);
	cout << "\t\t   | " << endl;
	cout << "\t\t\t\t\t|__________________________________|" << endl;
	cout << "\t\t\t\t\t| ";
	SetConsoleTextAttribute(colors, 7);
	Sleep(500);
	cout << "Press '5' to Exit.";
	SetConsoleTextAttribute(colors, 13);
	cout << "\t\t   | " << endl;
	cout << "\t\t\t\t\t|__________________________________|" << endl;
	cout << endl;
	SetConsoleTextAttribute(colors, 10);
	Sleep(500);
	cout << "\t\t\t\t\t __________________________________" << endl;
	SetConsoleTextAttribute(colors, 7);
	Sleep(500);
	cout << "\t\t\t\t\t Your choice is : ";
	cin >> M;
	cout << endl;
}
void credits()//who created this game.
{
	HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colors, 14);
	cout << "This game has been created by AMASH RIZWAN (21F-9116)!!!" << endl;
	cout << "This game has been created by SHAYAN AHMAD (21F-9159)!!!" << endl;
}
void instructions()//calls snake and ladder positions during gameplay.
{
	HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colors, 13);
	cout << "-------------" << setw(20) << "-------------" << endl;
	cout << "Snake is at:" << setw(20) << " Ladder is at:" << endl;
	cout << "-------------" << setw(20) << "-------------" << endl;
	cout << "17 --> 6" << setw(20) << "9 --> 14" << endl;
	cout << "28 --> 25" << setw(20) << "30 --> 32" << endl;
	cout << "42 --> 40" << setw(20) << "38 --> 44" << endl;
	cout << "52 --> 48" << setw(20) << "47 --> 56" << endl;
	cout << "65 --> 59" << setw(20) << "62 --> 74" << endl;
	SetConsoleTextAttribute(colors, 10);
	cout << "72 --> 70" << setw(20) << "64 --> 74" << endl;
	cout << "83 --> 80" << setw(20) << "71 --> 90" << endl;
	cout << "94 --> 90" << setw(20) << "89 --> 93" << endl;
	cout << "-------------" << setw(20) << "-------------" << endl;
	cout << endl;
}
void instructions1()
{
	HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colors, 6);
	cout << "Welcome to SNAKE AND LADDEER gamee!!!!!" << endl;
	cout << "Following are the INSTRUCTIONS for game:" << endl;
	SetConsoleTextAttribute(colors, 13);
	cout << "-------------" << setw(20) << "-------------" << endl;
	cout << "Snake is at:" << setw(20) << " Ladder is at:" << endl;
	cout << "-------------" << setw(20) << "-------------" << endl;
	cout << "17 --> 6" << setw(20) << "9 --> 14" << endl;
	cout << "28 --> 25" << setw(20) << "30 --> 32" << endl;
	cout << "42 --> 40" << setw(20) << "38 --> 44" << endl;
	cout << "52 --> 48" << setw(20) << "47 --> 56" << endl;
	cout << "65 --> 59" << setw(20) << "62 --> 74" << endl;
	SetConsoleTextAttribute(colors, 10);
	cout << "72 --> 70" << setw(20) << "64 --> 74" << endl;
	cout << "83 --> 80" << setw(20) << "71 --> 90" << endl;
	cout << "94 --> 90" << setw(20) << "89 --> 93" << endl;
	cout << "-------------" << setw(20) << "-------------" << endl;
	cout << endl;
	SetConsoleTextAttribute(colors, 10);
	cout << "There are four players: @, #, $, &." << endl;
	SetConsoleTextAttribute(colors, 11);
	cout << "Game starts when any player gets a 6." << endl;
	SetConsoleTextAttribute(colors, 12);
	cout << "If any player gets 3 consecutive 6's, he loses the turn." << endl;
	SetConsoleTextAttribute(colors, 13);
	cout << "First winner gives 3 moves to second player." << endl;
	SetConsoleTextAttribute(colors, 14);
	cout << "Game ends when 3/4 users win the game." << endl;
}
bool snakes1()
{
	if (player1_row == 8 && player1_col == 3)
	{
		player1_row = 9;
		player1_col = 5;
		return true;
	}
	else if (player1_row == 7 && player1_col == 7)
	{
		player1_row = 7;
		player1_col = 4;
		return true;
	}
	else if (player1_row == 5 && player1_col == 1)
	{
		player1_row = 6;
		player1_col = 0;
		return true;
	}
	else if (player1_row == 4 && player1_col == 8)
	{
		player1_row = 5;
		player1_col = 7;
		return true;
	}
	else if (player1_row == 3 && player1_col == 4)
	{
		player1_row = 4;
		player1_col = 1;
		return true;
	}
	else if (player1_row == 2 && player1_col == 8)
	{
		player1_row = 3;
		player1_col = 9;
		return true;
	}
	else if (player1_row == 1 && player1_col == 2)
	{
		player1_row = 2;
		player1_col = 0;
		return true;
	}
	else if (player1_row == 0 && player1_col == 6)
	{
		player1_row = 1;
		player1_col = 9;
		return true;
	}
	else
	{
		return false;
	}
}
bool snakes2()
{
	if (player2_row == 8 && player2_col == 3)
	{
		player2_row = 9;
		player2_col = 5;
		return true;
	}
	else if (player2_row == 7 && player2_col == 7)
	{
		player2_row = 7;
		player2_col = 4;
		return true;
	}
	else if (player2_row == 5 && player2_col == 1)
	{
		player2_row = 6;
		player2_col = 0;
		return true;
	}
	else if (player2_row == 4 && player2_col == 8)
	{
		player2_row = 5;
		player2_col = 7;
		return true;
	}
	else if (player2_row == 3 && player2_col == 4)
	{
		player2_row = 4;
		player2_col = 1;
		return true;
	}
	else if (player2_row == 2 && player2_col == 8)
	{
		player2_row = 3;
		player2_col = 9;
		return true;
	}
	else if (player2_row == 1 && player2_col == 2)
	{
		player2_row = 2;
		player2_col = 0;
		return true;
	}
	else if (player2_row == 0 && player2_col == 6)
	{
		player2_row = 1;
		player2_col = 9;
		return true;
	}
	else
	{
		return false;
	}
}
bool snakes3()
{
	if (player3_row == 8 && player3_col == 3)
	{
		player3_row = 9;
		player3_col = 5;
		return true;
	}
	else if (player3_row == 7 && player3_col == 7)
	{
		player3_row = 7;
		player3_col = 4;
		return true;
	}
	else if (player3_row == 5 && player3_col == 1)
	{
		player3_row = 6;
		player3_col = 0;
		return true;
	}
	else if (player3_row == 4 && player3_col == 8)
	{
		player3_row = 5;
		player3_col = 7;
		return true;
	}
	else if (player3_row == 3 && player3_col == 4)
	{
		player3_row = 4;
		player3_col = 1;
		return true;
	}
	else if (player3_row == 2 && player3_col == 8)
	{
		player3_row = 3;
		player3_col = 9;
		return true;
	}
	else if (player3_row == 1 && player3_col == 2)
	{
		player3_row = 2;
		player3_col = 0;
		return true;
	}
	else if (player3_row == 0 && player3_col == 6)
	{
		player3_row = 1;
		player3_col = 9;
		return true;
	}
	else
	{
		return false;
	}
}
bool snakes4()
{
	if (player4_row == 8 && player4_col == 3)
	{
		player4_row = 9;
		player4_col = 5;
		return true;
	}
	else if (player4_row == 7 && player4_col == 7)
	{
		player4_row = 7;
		player4_col = 4;
		return true;
	}
	else if (player4_row == 5 && player4_col == 1)
	{
		player4_row = 6;
		player4_col = 0;
		return true;
	}
	else if (player4_row == 4 && player4_col == 8)
	{
		player4_row = 5;
		player4_col = 7;
		return true;
	}
	else if (player4_row == 3 && player4_col == 4)
	{
		player4_row = 4;
		player4_col = 1;
		return true;
	}
	else if (player4_row == 2 && player4_col == 8)
	{
		player4_row = 3;
		player4_col = 9;
		return true;
	}
	else if (player4_row == 1 && player4_col == 2)
	{
		player4_row = 2;
		player4_col = 0;
		return true;
	}
	else if (player4_row == 0 && player4_col == 6)
	{
		player4_row = 1;
		player4_col = 9;
		return true;
	}
	else
	{
		return false;
	}
}
bool ladders1()
{
	if (player1_row == 9 && player1_col == 8)
	{
		player1_row = 8;
		player1_col = 6;
		return true;
	}
	else if (player1_row == 7 && player1_col == 9)
	{
		player1_row = 6;
		player1_col = 8;
		return true;
	}
	else if (player1_row == 6 && player1_col == 2)
	{
		player1_row = 5;
		player1_col = 3;
		return true;
	}
	else if (player1_row == 5 && player1_col == 6)
	{
		player1_row = 4;
		player1_col = 4;
		return true;
	}
	else if (player1_row == 3 && player1_col == 1)
	{
		player1_row = 2;
		player1_col = 3;
		return true;
	}
	else if (player1_row == 3 && player1_col == 3)
	{
		player1_row = 2;
		player1_col = 3;
		return true;
	}
	else if (player1_row == 2 && player1_col == 9)
	{
		player1_row = 1;
		player1_col = 9;
		return true;
	}
	else if (player1_row == 1 && player1_col == 8)
	{
		player1_row = 0;
		player1_col = 7;
		return true;
	}
	else
	{
		return false;
	}
}
bool ladders2()
{
	if (player2_row == 9 && player2_col == 8)
	{
		player2_row = 8;
		player2_col = 6;
		return true;
	}
	else if (player2_row == 7 && player2_col == 9)
	{
		player2_row = 6;
		player2_col = 8;
		return true;
	}
	else if (player2_row == 6 && player2_col == 2)
	{
		player2_row = 5;
		player2_col = 3;
		return true;
	}
	else if (player2_row == 5 && player2_col == 6)
	{
		player2_row = 4;
		player2_col = 4;
		return true;
	}
	else if (player2_row == 3 && player2_col == 1)
	{
		player2_row = 2;
		player2_col = 3;
		return true;
	}
	else if (player2_row == 3 && player2_col == 3)
	{
		player2_row = 2;
		player2_col = 3;
		return true;
	}
	else if (player2_row == 2 && player2_col == 9)
	{
		player2_row = 1;
		player2_col = 9;
		return true;
	}
	else if (player2_row == 1 && player2_col == 8)
	{
		player2_row = 0;
		player2_col = 7;
		return true;
	}
	else
	{
		return false;
	}
}
bool ladders3()
{
	if (player3_row == 9 && player3_col == 8)
	{
		player3_row = 8;
		player3_col = 6;
		return true;
	}
	else if (player3_row == 7 && player3_col == 9)
	{
		player3_row = 6;
		player3_col = 8;
		return true;
	}
	else if (player3_row == 6 && player3_col == 2)
	{
		player3_row = 5;
		player3_col = 3;
		return true;
	}
	else if (player3_row == 5 && player3_col == 6)
	{
		player3_row = 4;
		player3_col = 4;
		return true;
	}
	else if (player3_row == 3 && player3_col == 1)
	{
		player3_row = 2;
		player3_col = 3;
		return true;
	}
	else if (player3_row == 3 && player3_col == 3)
	{
		player3_row = 2;
		player3_col = 3;
		return true;
	}
	else if (player3_row == 2 && player3_col == 9)
	{
		player3_row = 1;
		player3_col = 9;
		return true;
	}
	else if (player3_row == 1 && player3_col == 8)
	{
		player3_row = 0;
		player3_col = 7;
		return true;
	}
	else
	{
		return false;
	}
}
bool ladders4()
{
	if (player4_row == 9 && player4_col == 8)
	{
		player4_row = 8;
		player4_col = 6;
		return true;
	}
	else if (player4_row == 7 && player4_col == 9)
	{
		player4_row = 6;
		player4_col = 8;
		return true;
	}
	else if (player4_row == 6 && player4_col == 2)
	{
		player4_row = 5;
		player4_col = 3;
		return true;
	}
	else if (player4_row == 5 && player4_col == 6)
	{
		player4_row = 4;
		player4_col = 4;
		return true;
	}
	else if (player4_row == 3 && player4_col == 1)
	{
		player4_row = 2;
		player4_col = 3;
		return true;
	}
	else if (player4_row == 3 && player4_col == 3)
	{
		player4_row = 2;
		player4_col = 3;
		return true;
	}
	else if (player4_row == 2 && player4_col == 9)
	{
		player4_row = 1;
		player4_col = 9;
		return true;
	}
	else if (player4_row == 1 && player4_col == 8)
	{
		player4_row = 0;
		player4_col = 7;
		return true;
	}
	else
	{
		return false;
	}
}