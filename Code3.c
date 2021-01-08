// Alexander Rollison
//For the Pick New Number, Try copy pasting the code into it's seperate file and sort the numbers. It will give you randomized numbers 1-75 no repeats.

//BONUS: Works for Diagonals
// You can comment out the scanf and it will keep going until it hits a bingo. It will break out of the while loop if it runs more than 75 times, so if it looks like it runs more than 75 times, then
// it's just the compiler

#include <stdio.h>
#include <stdlib.h>
void FillCard(int B[][5], int check[5]);
int PickNextNumber(int B[][5], int check[75], int LetterNumber[2], int count);
void PrintCard(int B[][5]);
int CheckExisting(int B1[][5], int LetterNumber[2]);
void ReplaceNum(int B1[][5], int LetterNumber[2]);
int BINGO(int B1[][5]);
int BINGOColumn(int B1[][5]);
int BINGORow(int B1[][5]);

void ReplaceNum(int B1[][5], int LetterNumber[2])
{
	int i;
	int j;

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(B1[i][j] == LetterNumber[1])
			{
				B1[i][j] = 0;
			}
		}
	}
}

int BINGORow(int B1[][5])
{
	int counter = 0;
	int counter1 = 0;
	int i;
	int j;

	for(i = 0; i < 5; i++)
	{
		counter = 0;
		for(j = 0; j < 5; j++)
		{
			if(B1[i][j] == 0)
			{
				counter++;
			}

		}
		if(counter == 5)
		{
			return 1;
		}
	}

}

int BINGOColumn(int B1[][5])
{
	int counter = 0;
	int i;
	int j;

	for(i = 0; i < 5; i++)
	{
		counter = 0;
		for(j = 0; j < 5; j++)
		{
			if(B1[j][i] == 0)
			{
				counter++;
			}

		}
		if(counter == 5)
		{
			return 1;
		}
	}
}

int BINGO(int B1[][5])
{
	int counter = 0;
	int counter1 = 0;
	int i;
	int j;

	for(i = 0; i < 5; i++)
	{
		counter = 0;
		counter1 = 0;
		for(j = 0; j < 5; j++)
		{
			if(B1[i][j] == 0)
			{
				counter++;
			}

			if(B1[j][i] == 0)
			{
				counter1++;
			}
		}
		
		if(B1[0][0] == 0 && B1[1][1] == 0 && B1[3][3] == 0 && B1[4][4] == 0 )
		{
			return 5;
		}
		else if(B1[0][4] == 0 && B1[1][3] == 0 && B1[3][1] == 0 && B1[4][0] == 0)
		{
			return 4;
		}
		else if(counter == 5 && counter1 == 5)
		{
			return 3;
		}
		else if(counter == 5)
		{
			return 1;
		}
		else if(counter1 == 5)
		{
			return 0;
		}
	}

}


int CheckExisting(int B1[][5], int LetterNumber[2])
{
	int i;
	int j;
	int counter = 0;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(B1[i][j] == LetterNumber[1])
			{
				counter++;
			}
		}
	}

	if(counter > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void PrintCard(int B[][5])
{
	int i;
	int j;
	int k;

	printf("\n");

	printf("    B\t    I\t    N\t    G\t    O\n");

	for(i = 0; i < 41; i++)
	{
		printf("-");
	}
	printf("\n");

	for(j = 0; j < 5; j++)
	{
		for(k = 0; k < 5; k++)
		{
			if(B[j][k] == 0 || B[j][k] == 88)
			{
				printf("|   X\t");
			}
			else
			{
				printf("|  %2d\t", B[j][k]);
			}
		}
		printf("|\n");
	}

	for(i = 0; i < 41; i++)
	{
		printf("-");
	}

	printf("\n");

}
void FillCard(int B[][5], int check[5])
{
	int rand1;

	srand(time(0));
	int i;
	int j;
	int x = 1;

	for(i = 0; i < 5; i++)
	{
/////////	First Column
		if (i == 0)
		{
			for(j = 0; j < 5; j++)
			{
				rand1 = rand() % 15 + 1;
				if(rand1 != check[0]&&rand1 != check[1]&&rand1 != check[2]&&rand1 != check[3]&&rand1 != check[4])
				{
					B[j][0] = rand1;
					check[j] = rand1;
				}
				else
				{
					j--;
				}
			}
		}
/////////	Second Column
		else if(i == 1)
		{
			for(j = 0; j < 5; j++)
			{
				rand1 = rand() % 15 + 16;
				if(rand1 != check[0]&&rand1 != check[1]&&rand1 != check[2]&&rand1 != check[3]&&rand1 != check[4])
				{
					B[j][1] = rand1;
					check[j] = rand1;
				}
				else
				{
					j--;
				}
			}
		}
/////////	Third Column
		else if(i == 2)
		{
			for(j = 0; j < 5; j++)
			{
				rand1 = rand() % 15 + 31;
				if(rand1 != check[0]&&rand1 != check[1]&&rand1 != check[2]&&rand1 != check[3]&&rand1 != check[4])
				{
					B[j][2] = rand1;
					check[j] = rand1;
				}
				else
				{
					j--;
				}
			}
		}
/////////	Fourth Column
		else if(i == 3)
		{
			for(j = 0; j < 5; j++)
			{
				rand1 = rand() % 15 + 46;
				if(rand1 != check[0]&&rand1 != check[1]&&rand1 != check[2]&&rand1 != check[3]&&rand1 != check[4])
				{
					B[j][3] = rand1;
					check[j] = rand1;
				}
				else
				{
					j--;
				}
			}
		}
/////////	Fifth Column
		else if(i == 4)
		{
			for(j = 0; j < 5; j++)
			{
				rand1 = rand() % 15 + 61;
				if(rand1 != check[0]&&rand1 != check[1]&&rand1 != check[2]&&rand1 != check[3]&&rand1 != check[4])
				{
					B[j][4] = rand1;
					check[j] = rand1;
				}
				else
				{
					j--;
				}
			}
		}
	}
/////////	Hard Coded ascii X for [2][2]
	B[2][2] = 0;
}

int PickNextNumber(int B[5][5], int check[75], int LetterNumber[2], int count)
{
	int i;
	int x = 1;
	int rand1;
	char letter;
	int counter = 1;
	srand(time(0));

	while(counter != 0)
	{
		counter = 0;
		rand1 = rand() % 75 + 1;
		
		for(i = 0; i < 75; i++)
		{
			if(check[i] == rand1)
			{
				counter++;
			}
		}
	}
	
	check[count] = rand1;

	LetterNumber[1]= check[count];
	count++;
	
	if (LetterNumber[1] > 0 && LetterNumber[1] < 16) 
	{
		LetterNumber[0] = 66;
	}
	else if(LetterNumber[1] > 15 && LetterNumber[1] < 31)
	{
		LetterNumber[0] = 73;
	}

	else if(LetterNumber[1] > 30 && LetterNumber[1] < 46)
	{
		LetterNumber[0] = 78;
	}

	else if(LetterNumber[1] > 45 && LetterNumber[1] < 61)
	{
		LetterNumber[0] = 71;
	}

	else
	{
		LetterNumber[0] = 79;
	}
	
	return count;
}
int main(void)
{
	int Bingo1[5][5]; 	// Fillcard stuff
	int check[5];

	int check1[75];		//PickNextNumber stuff
	int LetterNumber[2];

	int y = 1;
	char Useryn = 'y';
	int ExistingNum;
	int BINGOCHECK;
	int count = 0;
	
	FillCard(Bingo1, check);
	PrintCard(Bingo1);

	while(y == 1)
	{

		PickNextNumber(Bingo1,check1,LetterNumber, count);

		printf("\nThe next number is %c%d\n\n",LetterNumber[0],LetterNumber[1]);

		printf("Do you have it?(Y/N)\n", LetterNumber[0],LetterNumber[1]);

		scanf(" %c", &Useryn);

		ExistingNum = CheckExisting(Bingo1, LetterNumber);

		if(ExistingNum == 1 && (Useryn == 'Y'|| Useryn == 'y'))
		{
			ReplaceNum(Bingo1, LetterNumber);
			PrintCard(Bingo1);
		}
		else if(ExistingNum == 0 && (Useryn == 'N'|| Useryn == 'n'))
		{
			PrintCard(Bingo1);
		}
		else
		{
			PrintCard(Bingo1);
			if(((Useryn != 'Y' || Useryn != 'N')||Useryn != 'y' || Useryn != 'n'))
			{
				printf("That value is not on your BINGO card -are you trying to cheat??\n\n");
			}
			
		}

		BINGOCHECK = BINGO(Bingo1);
		if(BINGOCHECK == 4 || BINGOCHECK == 5)
		{
			PrintCard(Bingo1);
			printf("You filled out a diagonal -BINGO!!!\n");
			y = 0;
		}
		else if(BINGOCHECK == 3)
		{
			PrintCard(Bingo1);
			printf("You filled out a row and a column -BINGO!!!\n");
			y = 0;
		}
		else if(BINGOCHECK == 1 && BINGORow(Bingo1) == 1)
		{
			PrintCard(Bingo1);
			printf("You filled out a row -BINGO!!!\n");
			y = 0;
		}
		else if(BINGOCHECK == 0 && BINGOColumn(Bingo1) == 1)
		{
			PrintCard(Bingo1);
			printf("You filled out a column -BINGO!!!\n");
			y = 0;
		}
		else if(count == 76)
		{
			printf("All 75 numbers have been called. You have lost BINGO...");
			y = 0;
		}
		else
		{
			y = 1;
		}

	}
	return 0;
}


