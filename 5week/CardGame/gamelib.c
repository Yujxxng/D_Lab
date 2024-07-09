// TODO: Add file-level documentation.

#include <stdio.h>
#include "gamelib.h"

// TODO: Add function-level documentation.

void del_card(Card game[], CardIndex position)
{
	// TODO
	while (game[position].suit != '0')
	{
		game[position].suit = game[position + 1].suit;
		game[position].rank = game[position + 1].rank;
		position++;
	}
	game[position].suit = '0';
	game[position].rank = '0';
}

// TODO: Add function-level documentation.
void load_game(const char str[], Card game[])
{
	//printf("%d\n", (int)'\r'); 
	// TODO
	CardIndex idx = 0;
	while (*str != '0')
	{
		if (*str == ' ')
			idx++;
		else
		{
			game[idx].suit = *str;
			str++;
			game[idx].rank = *str;
		}
		++str;
	}
	game[idx].suit = *str;
	str++;
	game[idx].rank = *str;
}

// TODO: Add function-level documentation.
void play_game(Card game[])
{
	// TODO
	int e = 1;

	while (e)
	{
		CardIndex idx = 0;
		int flag = 0;
		CardIndex foundIdx = 0;
		while (game[idx + 3].suit != '0')
		{
			if (game[idx].rank == game[idx + 3].rank || game[idx].suit == game[idx + 3].suit)
			{
				flag = 1;
				foundIdx = idx + 3;
				break;
			}
			idx++;
		}

		if (flag)
		{
			game[foundIdx - 3].rank = game[foundIdx].rank;
			game[foundIdx - 3].suit = game[foundIdx].suit;
			del_card(game, foundIdx);
		}
		else
		{
			idx = 0;
			while (game[idx + 1].suit != '0')
			{
				if (game[idx].rank == game[idx + 1].rank || game[idx].suit == game[idx + 1].suit)
				{
					flag = 1;
					foundIdx = idx + 1;
					break;
				}
				idx++;
			}

			if (flag)
			{
				game[foundIdx - 1].rank = game[foundIdx].rank;
				game[foundIdx - 1].suit = game[foundIdx].suit;
				del_card(game, foundIdx);
			}
			else
				e = 0;
		}
	}
}

// TODO: Add function-level documentation.
void display_game(const Card game[])
{
	// TODO
	int i = 0;
	for (i = 0; game[i].suit != '0'; i++)
		printf("%c%c ", game[i].suit, game[i].rank);
	printf("%c%c \n", game[i].suit, game[i].rank);
}
