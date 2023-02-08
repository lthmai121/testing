#include <iostream>
using namespace std;
int checkwinner(char tictac[3][3]);
int main()
{
	char tictac[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tictac[i][j] = '*';
		}	
	}
	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << tictac[i][j];
			}
			cout << endl;
		}
		cout << endl;
		// m is row location, n is column location
		int m, n;
		cout << "Player 1 turn: X " << endl;
		cout << "Insert your row location\n";
		cout << "Insert your column location\n";
		cin >> m >> n;
		// draw X on board
		tictac[m][n] = 'X';
		// player 2 turn
		cout << "Player 2 turn: X " << endl;
		cout << "Insert your row location\n";
		cout << "Insert your column location\n";
		cin >> m >> n;
		// draw O on board
		tictac[m][n] = 'O';
		int result = checkwinner(tictac);
		if (result == 0)
		{
			cout << "Player 1 wins\n";
			break;
		}
		else if (result == 1)
		{
			cout << "Player 2 wins\n";
			break;
		}
		else if (result == 2)
		{
			cout << "Tie\n";
			break;
		}
	}
}

int checkwinner(char tictac[3][3])
{
	bool firstRow = tictac[0][0] == tictac[0][1] && tictac[0][0] == tictac[0][2];
	bool secondRow = tictac[1][0] == tictac[1][1] && tictac[0][0] == tictac[1][2];
	bool thirdRow = tictac[2][0] == tictac[2][1] && tictac[2][0] == tictac[2][2];
	bool firstCol = tictac[0][0] == tictac[1][0] && tictac[0][0] == tictac[2][0];
	bool secondCol = tictac[0][1] == tictac[1][1] && tictac[0][1] == tictac[2][1];
	bool thirdCol = tictac[0][2] == tictac[1][2] && tictac[0][2] == tictac[2][2];
	bool diag1 = tictac[0][0] == tictac[1][1] && tictac[1][1] == tictac[2][2];
	bool diag2 = tictac[0][2] == tictac[1][1] && tictac[1][1] == tictac[2][0];

	if (firstRow || firstCol || diag1)
		if (tictac[0][0] == 'X')
			return 0;
		else if (tictac[0][0] == 'O')
			return 1;
	if (thirdCol || thirdRow)
		if (tictac[2][2] == 'X')
			return 0;
		else if (tictac[2][2] == 'O')
			return 1;
	if (secondCol || secondRow || diag2)
		if (tictac[1][1] == 'X')
			return 0;
		else if (tictac[1][1] == 'O')
			return 1;
	// if there exist *
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (tictac[i][j] == '*')
				return 3;
		}
	}
	return 2;
}