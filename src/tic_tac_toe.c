#include "../includes/tic_tac_toe.h"

void print_board(char *brd)
{
	printf("\e[1;1H\e[2J");
	printf("The TIC TAC TOE Tournament\n\n");
	printf("  %c | %c | %c\n -----------\n  %c | %c | %c\n -----------\n  %c | %c | %c\n", brd[0], brd[1], brd[2], brd[3], brd[4], brd[5], brd[6], brd[7], brd[8]);
}

int check_horizontal(char plr, char *brd)
{
	if (brd[0] == plr && brd[1] == plr && brd[2] == plr)
		return (1);
	if (brd[3] == plr && brd[4] == plr && brd[5] == plr)
		return (1);
	if (brd[6] == plr && brd[7] == plr && brd[8] == plr)
		return (1);
	return (0);
}

int check_vertical(char plr, char *brd)
{
	if (brd[0] == plr && brd[3] == plr && brd[6] == plr)
		return (1);
	if (brd[1] == plr && brd[4] == plr && brd[7] == plr)
		return (1);
	if (brd[3] == plr && brd[6] == plr && brd[8] == plr)
		return (1);
	return (0);
}

int check_diagonal(char plr, char *brd)
{
	if (brd[0] == plr && brd[4] == plr && brd[8] == plr)
		return (1);
	if (brd[2] == plr && brd[4] == plr && brd[6] == plr)
		return (1);
	return (0);
}

int checks(char plr, char *brd)
{
	if (check_horizontal(plr, brd) == 1)
		return (0);
	if (check_vertical(plr, brd) == 1)
		return (0);
	if (check_diagonal(plr, brd) == 1)
		return (0);
	return (1);
}

int main(void)
{
	char board[9] = "---------";
	int input;
	char player = 'X';
	int i = 1;

	while (i)
	{
		print_board(board);
		printf("\nEnter a number %c (1 - 9): ", player);
		scanf("%d", &input);
		printf("\n");
		input--;
		if (board[input] == '-')
			board[input] = player;
		else
			continue;
		i = checks(player, board);
		if (i == 0)
		{
			print_board(board);
			printf("\n%c is the winner. Well done!!!\n", player);
			break;
		}
		player = (player == 'X') ? 'O' : 'X';
	}
}
