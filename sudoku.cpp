// This is a practice project written by Jafar Jafarzada 06/02/2026. Warnings may be results of scanf usage.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int displayMenu(int choice);
void iniArray(int board[9][9]);
void displayBoard(int board[9][9]);
int checkNum(int board[9][9], int vertiNum, int horiNum, int chosenNum);
int selectNum(int board[9][9], int vertiNum, int horiNum, int chosenNum);
int continueNum(int board[9][9], int vertiNum, int horiNum, int chosenNum, int tempNum);
int checkWin(int board[9][9]);

int main(void)
{
	int winCheck = 0;
	int menuChoice = 0;
	int board[9][9];
	int vertiNum = 0, horiNum = 0;
	int chosenNum = 0;
	menuChoice = displayMenu(menuChoice);
	if (menuChoice == 2)
	{
		return 0;
	}
	if (menuChoice == 1)
	{
		printf("\n\t\t\t    Enter a negative number to stop. Starting the game... \n");
	}
	iniArray(board);
	printf("\n\t\t\t\t\t     Current Board: \n\n");
	displayBoard(board);
	chosenNum = selectNum(board, vertiNum, horiNum, chosenNum);
	int tempNum = chosenNum;
	continueNum(board, vertiNum, horiNum, chosenNum, tempNum);
	return 0;
}

int displayMenu(int choice)
{
	printf("\t\t\t\t\t\t  SUDOKU\n\t\t\t\t     ================================\n\t\t\t\t\t         Main Menu\n\t\t\t\t\t    1. Start the Game\n\t\t\t\t\t    2. Exit the Game");
	do
	{
		printf("\n\t\t\t\t\t    Make your choice: ");
		scanf("%d", &choice);
		if (choice == 2)
		{
			printf("\n\t\t\t\t\t  Exiting the application...\n");
		}
	} while (choice > 2 || choice < 1);
	return(choice);
}
void iniArray(int board[9][9])
{
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			board[r][c] = 0;
		}
	}
}
void displayBoard(int board[9][9])
{
	for (int r = 0; r < 9; r++)
	{
		printf("\t\t\t\t\t  ");
		if (r == 3 || r == 6)
		{
			printf("---------------------\n\t\t\t\t\t  ");
		}
		for (int c = 0; c < 9; c++)
		{
			if (c == 3 || c == 6)
			{
				printf("| ");
			}
			printf("%d ", *(*(board + r) + c));
		}
		printf("\n");
	}
}
int checkWin(int board[9][9])
{
	int winChecker = 1;
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			if (board[r][c] == 0)
			{
				winChecker = 0;
			}
		}
	}
	return(winChecker);
}
int checkNum(int board[9][9], int vertiNum, int horiNum, int chosenNum)
{
	if (chosenNum < 0)
	{
		printf("\n\t\t\t           Exiting...");
		exit(0);
	}
	int checker = 1, temp = 0;
	while (chosenNum < 1 || chosenNum > 9)
	{
		printf("\n\t\t\t\t  Please select a number between 1 and 9!: ");
		scanf("%d", &chosenNum);
	}
	do
	{
		for (int i = 0; i < 9; i++)
		{
			if (board[i][vertiNum - 1] == chosenNum)
			{
				checker = 0;
				temp = chosenNum;
				printf("\n\t\t\t\tVertical line has number %d! Choose a different one: ", chosenNum);
				scanf("%d", &chosenNum);
				if (chosenNum != temp)
				{
					checker = 1;
				}
			}
			if (board[horiNum - 1][i] == chosenNum)
			{
				checker = 0;
				temp = chosenNum;
				printf("\n\t\t\t\tHorizontal line has number %d! Choose a different one: ", chosenNum);
				scanf("%d", &chosenNum);
				if (chosenNum != temp)
				{
					checker = 1;
				}
			}
		}
		int rowStart = ((horiNum - 1) / 3) * 3; // ADDED
		switch (vertiNum)
		{
		case 1:
			for (int r = rowStart; r < rowStart + 3; r++) { // CHANGED
				for (int c = 0; c < 3; c++) {
					if (board[r][c] == chosenNum) {
						checker = 0;
						temp = chosenNum;
						printf("\n\t\t\t\t3x3 Square has number %d! Choose a different one: ", chosenNum);
						scanf("%d", &chosenNum);
						if (chosenNum != temp)
						{
							checker = 1;
						}
					}
				}
			}
			break;
		case 2:
			for (int r = rowStart; r < rowStart + 3; r++) { // CHANGED
				for (int c = 0; c < 3; c++) {
					if (board[r][c] == chosenNum) {
						checker = 0;
						temp = chosenNum;
						printf("\n\t\t\t\t3x3 Square has number %d! Choose a different one: ", chosenNum);
						scanf("%d", &chosenNum);
						if (chosenNum != temp)
						{
							checker = 1;
						}
					}
				}
			}
			break;
		case 3:
			for (int r = rowStart; r < rowStart + 3; r++) { // CHANGED
				for (int c = 0; c < 3; c++) {
					if (board[r][c] == chosenNum) {
						checker = 0;
						temp = chosenNum;
						printf("\n\t\t\t\t3x3 Square has number %d! Choose a different one: ", chosenNum);
						scanf("%d", &chosenNum);
						if (chosenNum != temp)
						{
							checker = 1;
						}
					}
				}
			}
			break;
		case 4:
			for (int r = rowStart; r < rowStart + 3; r++) { // CHANGED
				for (int c = 3; c < 6; c++) {
					if (board[r][c] == chosenNum) {
						checker = 0;
						temp = chosenNum;
						printf("\n\t\t\t\t3x3 Square has number %d! Choose a different one: ", chosenNum);
						scanf("%d", &chosenNum);
						if (chosenNum != temp)
						{
							checker = 1;
						}
					}
				}
			}
			break;
		case 5:
			for (int r = rowStart; r < rowStart + 3; r++) { // CHANGED
				for (int c = 3; c < 6; c++) {
					if (board[r][c] == chosenNum) {
						checker = 0;
						temp = chosenNum;
						printf("\n\t\t\t\t3x3 Square has number %d! Choose a different one: ", chosenNum);
						scanf("%d", &chosenNum);
						if (chosenNum != temp)
						{
							checker = 1;
						}
					}
				}
			}
			break;
		case 6:
			for (int r = rowStart; r < rowStart + 3; r++) { // CHANGED
				for (int c = 3; c < 6; c++) {
					if (board[r][c] == chosenNum) {
						checker = 0;
						temp = chosenNum;
						printf("\n\t\t\t\t3x3 Square has number %d! Choose a different one: ", chosenNum);
						scanf("%d", &chosenNum);
						if (chosenNum != temp)
						{
							checker = 1;
						}
					}
				}
			}
			break;
		case 7:
			for (int r = rowStart; r < rowStart + 3; r++) { // CHANGED
				for (int c = 6; c < 9; c++) {
					if (board[r][c] == chosenNum) {
						checker = 0;
						temp = chosenNum;
						printf("\n\t\t\t\t3x3 Square has number %d! Choose a different one: ", chosenNum);
						scanf("%d", &chosenNum);
						if (chosenNum != temp)
						{
							checker = 1;
						}
					}
				}
			}
			break;
		case 8:
			for (int r = rowStart; r < rowStart + 3; r++) { // CHANGED
				for (int c = 6; c < 9; c++) {
					if (board[r][c] == chosenNum) {
						checker = 0;
						temp = chosenNum;
						printf("\n\t\t\t\t3x3 Square has number %d! Choose a different one: ", chosenNum);
						scanf("%d", &chosenNum);
						if (chosenNum != temp)
						{
							checker = 1;
						}
					}
				}
			}
			break;
		case 9:
			for (int r = rowStart; r < rowStart + 3; r++) { // CHANGED
				for (int c = 6; c < 9; c++) {
					if (board[r][c] == chosenNum) {
						checker = 0;
						temp = chosenNum;
						printf("\n\t\t\t\t3x3 Square has number %d! Choose a different one: ", chosenNum);
						scanf("%d", &chosenNum);
						if (chosenNum != temp)
						{
							checker = 1;
						}
					}
				}
			}
			break;
		default: printf("Huh...");
			break;
		}
	} while (checker == 0);
	return(chosenNum);
}
int selectNum(int board[9][9], int vertiNum, int horiNum, int chosenNum)
{
	do
	{
		printf("\n\t\t\t\t Select the slot (Vertical and Horizontal): ");
		scanf("%d %d", &vertiNum, &horiNum);
	} while (vertiNum < 0 || vertiNum > 9 || horiNum < 0 || horiNum > 9);
	printf("\n\t\t\t     Enter the number you wish to place (negative to stop): ");
	scanf("%d", &chosenNum);
	if (chosenNum < 0)
	{
		printf("\n\t\t\t                         Exiting...\n");
		exit(0);
	}
	while (chosenNum < 1 || chosenNum > 9)
	{
		printf("\n\t\t\t\t  Please select a number between 1 and 9!: ");
		scanf("%d", &chosenNum);
	}
	board[horiNum - 1][vertiNum - 1] = chosenNum;
	printf("\n\t\t\t\t\t       Current Board: \n\n");
	displayBoard(board);
	return(chosenNum);
}
int continueNum(int board[9][9], int vertiNum, int horiNum, int chosenNum, int tempNum)
{
	int winCheck = 0;
	do
	{
		do
		{
			printf("\n\t\t\t\t  Select the slot (Vertical and Horizontal): ");
			scanf("%d %d", &vertiNum, &horiNum);
		} while (vertiNum < 0 || vertiNum > 9 || horiNum < 0 || horiNum > 9);
		printf("\n\t\t\t     Enter the number you wish to place (Negative to stop): ");
		scanf("%d", &chosenNum);

		chosenNum = checkNum(board, vertiNum, horiNum, chosenNum);
		board[horiNum - 1][vertiNum - 1] = chosenNum;
		printf("\n\t\t\t\t\t      Current Board: \n\n");
		displayBoard(board);
	} while (chosenNum > 0);
	winCheck = checkWin(board);
	if (winCheck == 1)
	{
		printf("\nYOU WIN!!");
	}
	return(chosenNum);
}