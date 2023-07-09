#include <stdio.h>

int win(char grid[3][3], int p);
int printgrid(char grid[3][3], int slot, int p);

int main()
{
    char grid[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = ' ';
        }
    }

    printf("Welcome to Tic-Tac-Toe Game! It will be fun, so let's begin.\n");
    printf("|%c|%c|%c|\n", grid[0][0], grid[0][1], grid[0][2]);
    printf("-------\n");
    printf("|%c|%c|%c|\n", grid[1][0], grid[1][1], grid[1][2]);
    printf("-------\n");
    printf("|%c|%c|%c|\n", grid[2][0], grid[2][1], grid[2][2]);
    int turns = 0, slot, player, i = 2, wi;
    while (turns != 9)
    {
        if (i % 2 == 0)
        {
            player = 1;
        }
        else
        {
            player = 2;
        }
        i++;
        turns++;
    g:
        printf("\nPlayer-%d please enter slot number (0-8) >> ", player);
        scanf("%d", &slot);
        int h = printgrid(grid, slot, player);
        if (h == 1)
        {
            goto g;
        }
        wi = win(grid, player);
        if (wi == 1)
        {
            break;
        }
    }

    return 0;
}

int printgrid(char grid[3][3], int slot, int p)
{
    char c = 'O';
    if (p == 1)
    {
        c = 'X';
    }

    if (slot == 0 && grid[0][0] == ' ')
    {
        grid[0][0] = c;
    }
    else if (slot == 1 && grid[0][1] == ' ')
    {
        grid[0][1] = c;
    }
    else if (slot == 2 && grid[0][2] == ' ')
    {
        grid[0][2] = c;
    }
    else if (slot == 3 && grid[1][0] == ' ')
    {
        grid[1][0] = c;
    }
    else if (slot == 4 && grid[1][1] == ' ')
    {
        grid[1][1] = c;
    }
    else if (slot == 5 && grid[1][2] == ' ')
    {
        grid[1][2] = c;
    }
    else if (slot == 6 && grid[2][0] == ' ')
    {
        grid[2][0] = c;
    }
    else if (slot == 7 && grid[2][1] == ' ')
    {
        grid[2][1] = c;
    }
    else if (slot == 8 && grid[2][2] == ' ')
    {
        grid[2][2] = c;
    }
    else
    {
        printf("You have entered an invalid move.\n");
        printf("Slot %d is already occupied! Please Try Again!\n", slot);
        return 1;
    }

    printf("|%c|%c|%c|\n", grid[0][0], grid[0][1], grid[0][2]);
    printf("-------\n");
    printf("|%c|%c|%c|\n", grid[1][0], grid[1][1], grid[1][2]);
    printf("-------\n");
    printf("|%c|%c|%c|\n", grid[2][0], grid[2][1], grid[2][2]);
    return 0;
}

int win(char grid[3][3], int p)
{
    int w = 0;
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && (grid[i][0] != ' ' && grid[i][1] != ' ' && grid[i][2] != ' '))
        {
            printf("Player-%d won the game!", p);
            w = 1;
        }
    }
    for (int j = 0; j < 3; j++)
    {
        if (grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j] && (grid[0][j] != ' ' && grid[1][j] != ' ' && grid[2][j] != ' '))
        {
            printf("Player-%d won the game!", p);
            w = 1;
        }
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && (grid[0][0] != ' ' && grid[1][1] != ' ' && grid[2][2] != ' '))
    {
        printf("Player-%d won the game!", p);
        w = 1;
    }
    if (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2] && (grid[2][0] != ' ' && grid[1][1] != ' ' && grid[0][2] != ' '))
    {
        printf("Player-%d won the game!", p);
        w = 1;
    }

    return w;
}