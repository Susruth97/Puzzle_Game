int goLeft(Board *board);
int goUp(Board *board);
int goDown(Board *board);
int goRight(Board *board);
void swap(Board *board, int x1, int y1, int x2, int y2);
int isValidInput(char letter);



/*
Take Only Valid Input W,A,S,D,w,a,s,d . If Invalid input is entered ,Take input again . Keep Taking input until its valid
Hint : Use While Loop and isValidInput function
*/
char takeInput()
{
	/*
	Take input and return it ,Use fflush if scanf is being used .
	Does this function need fflush ? Whats fflush ? Post your observations in the forum ,if fflush is present/not present.
	*/
	char c;
	scanf("%c", &c);

	while (isValidInput(c) == 1)
		scanf("%c", &c);
	fflush;

	return c;
}
/*
Return 1 for Valid Input ie if w,a,s,d,W,A,S,D are entered .
Return 0 for all other inputs
*/
int isValidInput(char letter){
	if (letter >= 'A' && letter <= 'Z')
		letter = letter + 32;
	if (letter == 'w' || letter == 's' || letter == 'a' || letter == 'd')
		return 1;
	else
		return 0;
}
/*
Process the Given Input .Ie Decide whether to move Left , Right , Up ,or Down based on W,A,S,D,w,a,s,d.
Call goLeft Function if A or a are entered.,similarly do for all valid inputs .
Output :
Returns 1 : If Input is Valid and Move is also Valid .
Returns 0 : If Input if Valid and Move is Invalid .
Returns 0: If Input is invalid ,like other letters are entered or sent through takeInput.
*/
int processInput(Board *board, char inputChar)
{
	/*
	Handle the input char inputChar ,which is either w,a,s,d,W,A,S,D for up,left,down and right
	*/
	if (inputChar >= 65 && inputChar <= 90)
		inputChar = inputChar + 32;

	if (inputChar == 'w')
	{
		if (goUp(board) == 1)
			return 1;
		else
			return 0;
	}
	else if (inputChar == 'a')
	{
		if (goLeft(board) == 1)
			return 1;
		else
			return 0;
	}
	else if (inputChar == 's')
	{
		if (goDown(board) == 1)
			return 1;
		else
			return 0;
	}
	else if (inputChar == 'd')
	{
		if (goRight(board) == 1)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

/*
This Method is invoked when a character is taken as input ie User has played his ValidMove ,and you need to proccess that Move .
Steps to be Done :
1)Call ProcessInput
2)Call modifyMoveCountBasedOnProccessInput and also pass Step 1s output
3)Call clearAndRedrawScreen
4)Call printUser
*/
void playMove(Board *board, User *user, char choice){
	int a = processInput(board, choice);
	modifyMoveCountBasedOnProccessInput(user, a);
	clearAndRedrawScreen(board);
	printUser(user);

}

/*
Move the 0 Tile one position to the left .
Return 1 if the move is possible, 0 other wise .
*/
int goRight(Board *board)
{
	for (int i = 0; i < board->rows; i++)
	{
		for (int j = 0; j < board->cols; j++)
		{
			if (board->table[i][j] == 0)
			{
				if (j != 0)
				{
					int temp;
					temp = board->table[i][j];
					board->table[i][j] = board->table[i][j - 1];
					board->table[i][j - 1] = temp;
					board->emptyTileCol = j - 1;
					board->emptyTileRow = i;
					return 1;
				}
				else
					return 0;
			}
		}
	}
}

/*
Move the 0 Tile one position to the Right.
Return 1 if the move is possible, 0 other wise .
*/
int goLeft(Board *board)
{
	for (int i = 0; i < board->rows; i++)
	{
		for (int j = 0; j < board->cols; j++)
		{
			if (board->table[i][j] == 0)
			{
				if (j != board->cols - 1)
				{
					int temp;
					temp = board->table[i][j];
					board->table[i][j] = board->table[i][j + 1];
					board->table[i][j + 1] = temp;
					board->emptyTileCol = j + 1;
					board->emptyTileRow = i;
					return 1;
				}
				else
					return 0;
			}
		}
	}
}

/*
Move the 0 Tile one position to the UP .
Return 1 if the move is possible, 0 other wise .
*/
int goDown(Board *board){
	for (int i = 0; i < board->rows; i++)
	{
		for (int j = 0; j < board->cols; j++)
		{
			if (board->table[i][j] == 0)
			{
				if (i != 0)
				{
					int temp;
					temp = board->table[i][j];
					board->table[i][j] = board->table[i - 1][j];
					board->table[i - 1][j] = temp;
					board->emptyTileCol = j;
					board->emptyTileRow = i - 1;
					return 1;
				}
				else
					return 0;
			}
		}
	}
}

/*
Move the 0 Tile one position to the Down .
Return 1 if the move is possible, 0 other wise .
*/
int goUp(Board *board){
	for (int i = 0; i < board->rows; i++)
	{
		for (int j = 0; j < board->cols; j++)
		{
			if (board->table[i][j] == 0)
			{
				if (i != board->rows - 1)
				{
					int temp;
					temp = board->table[i][j];
					board->table[i][j] = board->table[i + 1][j];
					board->table[i + 1][j] = temp;
					board->emptyTileCol = j;
					board->emptyTileRow = i + 1;
					return 1;
				}
				else
					return 0;
			}
		}
	}
}


/*
You can use this Helper SWAP Function which can remove lots of extra Code from above functions .
*/
void swap(Board *board, int x1, int y1, int x2, int y2)
{

}