#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int fromTower, toTower, disk, lastColumn = 0, currentColumn = 0, invalid = 0, disc_count = 6, color = 31, choice, move = 0;
int peg[3][6], disks[150];
int* positions = (int*)malloc(150 * sizeof(int));
bool continuegame = 0;

void Setup()
{
    FILE* fptr;
    FILE* diskptr;
    diskptr = fopen("disk.txt", "r");
    fptr = fopen("save.txt", "r");
    if (continuegame)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < disc_count; j++)
            {
                fscanf_s(fptr, "%d", &peg[i][j]);
            }
        }
        fscanf_s(fptr, "%d", &move);
        for (int i = 0; i < move+4; i++)
        {
            fscanf_s(fptr, "%d", &positions[i]);
        }
        for (int i = 0; i < move / 4; i++)
        {
            fscanf_s(diskptr, "%d", disks[i]);
        }
        continuegame = 0;
    }
    else {
        for (int i = 0; i < 4; i++)
        {
            positions[i] = 0;
        }
        for (int i = disc_count - 1; i >= 0; i--) {
            peg[0][disc_count - 1 - i] = i + 1;
        }
        for (int i = 1; i < 3; i++) {
            for (int j = disc_count - 1; j >= 0; j--) {
                peg[i][j] = 0;
            }
        }
    }   
}

void Draw()
{
    for (int i = 0; i < 3; i++) {
        printf("%c[%dm|\n|", 0x1B, 00);
        for (int j = 0; j < disc_count; j++) {
            if (peg[i][j] == 0)
            {
                printf("%c[%dm%d ", 0x1B, 00, peg[i][j]);
            }
            else {
                printf("%c[%dm%d ", 0x1B, color, peg[i][j]);
                color++;
            }
        }
        printf("%c[%dm\n|\n\n\n", 0x1B, 00);
    }
    color = 31;
    printf("\nChoose a number to make an action.\n1 - Make a move\n2 - Undo\n3 - Save\n4 - Restart\n5 - Quit\n");
}

void Save_Game()
{
    FILE* fptr; 
    FILE* diskptr;
    fptr = fopen("save.txt", "w");
    diskptr = fopen("disk.txt", "w");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < disc_count; j++)
        {
            fprintf(fptr, "%d ", peg[i][j]);
        }
        fprintf(fptr, "\n");
    }
    for (int i = 0; i < move+4; i++)
    {
        fprintf(fptr, "%d", positions[i]);
    }
    for (int i = 0; i < move/4; i++)
    {
        fprintf(diskptr, "%d", disks[i]);
    }
    fclose(fptr);
}

void Logic()
{
    while (invalid != -1 && invalid != -2) {
        invalid = 0;
        if (_kbhit()) {
            switch (_getch())
            {
            case '1':
            {
                printf("\n%c[%dmMove from peg: ", 0x1B, 00);
                scanf_s("%d", &fromTower);

                if (fromTower < 0 || fromTower > 2 || peg[fromTower][0] == 0) {
                    invalid = 1;
                }
                if (invalid == 0) {
                    printf("\n%c[%dmMove to peg: ", 0x1B, 00);
                    scanf_s("%d", &toTower);
                    printf("\n\n\n");
                    if (toTower < 0 || toTower > 2) {
                        invalid = 1;
                    }
                }
                if (invalid == 0) {
                    //Picking up a disk
                    for (int i = disc_count - 1; i >= 0; i--) {
                        if (peg[fromTower][i] != 0) {
                            disk = peg[fromTower][i];
                            disks[move] = disk;
                            peg[fromTower][i] = 0;
                            lastColumn = i;
                            positions[move] = fromTower;
                            positions[move + 1] = lastColumn;
                            break;
                        }
                    }
                    //Trying to place down a disk
                    if (peg[toTower][disc_count - 1] == 0) {
                        if (peg[toTower][0] != 0) {
                            for (int i = disc_count - 2; i >= 0; i--) {
                                if (peg[toTower][i] != 0) {
                                    if (peg[toTower][i] > disk) {
                                        peg[toTower][i + 1] = disk;
                                        currentColumn = i + 1;
                                        positions[move + 2] = toTower;
                                        positions[move + 3] = currentColumn;
                                        move+=4;
                                        break;
                                    }
                                    else {
                                        invalid = 1;
                                        peg[fromTower][lastColumn ] = disk;
                                        break;
                                    }
                                }
                            }
                        }
                        else {
                            peg[toTower][0] = disk;
                            currentColumn = 0;
                            positions[move + 2] = toTower;
                            positions[move + 3] = currentColumn;
                            move+=4;
                        }
                    }
                    else {
                        invalid = 1;
                    }
                }
                if (invalid == 1) {
                    printf("Invalid move! Please try again by choosing an action.\n");
                    continue;
                }
                else {
                    Draw();
                }
                //Win condition
                for (int i = 1; i < 3; i++) {
                    invalid = -1;
                    for (int j = 0; j < disc_count; j++) {
                        if (peg[i][j] == 0) {
                            invalid = 0;
                            break;
                        }
                    }
                    if (invalid == -1) {
                        break;
                    }
                }
            }
            break;
            case '2':
                if (positions[2] == 0 && positions[3] == 0)
                {
                    printf("\nNo moves left. Choose another action.\n");
                    break;
                }
                move-=4;
                peg[positions[move]][positions[move+1]] = disks[move];
                peg[positions[move+2]][positions[move+3]] = 0;
                for (int i = move; i < move + 4; i++)
                {
                    positions[i] = 0;
                }
                disks[move] = 0;
                Draw();
                break;
            case '3':
                Save_Game();
                printf("\nSave successful!\n");
                break;
            case '4':
                Setup();
                Draw();
                break;
            case '5':
                invalid = -2;
                printf("Thank you for playing my shitty game :D\nPress any key to exit.");
                break;
            }
        }
    }
}

int MainMenu()
{
    printf("\n\nHello, and welcome to Tower of Hanoi!\nPlease press the buttons corresponding to the menu options to access them.\n\n");
    printf("1. New Game\n2. Continue Game.\n3. Instructions\n4. Quit\n");
    scanf_s("%d", &choice);
    while (invalid != -1 && invalid !=-2)
    {
        switch (choice)
        {
            case 1:
            {
                Setup();
                Draw();
                Logic();
            }
            case 2:
            {
                continuegame = 1;
                Setup();
                Draw();
                Logic();
                break;
            }
            case 3:
            {
                printf("The Tower of Hanoi (also called The problem of Benares Temple or Tower of Brahma or Lucas' Tower and sometimes pluralized as Towers, or simply pyramid puzzle) is a mathematical game or puzzle consisting of three rods and a number of disks of various diameters, which can slide onto any rod. The puzzle begins with the disks stacked on one rod in order of decreasing size, the smallest at the top, thus approximating a conical shape. The objective of the puzzle is to move the entire stack to the last rod, obeying the following rules:\n\n1.Only one disk may be moved at a time.\n2.Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.\n3.No disk may be placed on top of a disk that is smaller than it.");
                MainMenu();
                break;
            }
            case 4:
            {
                printf("Thank you for playing my shitty game :D\nPress any key to exit.");
                return 0;
                break;
            }
        }
    }
}

int main()
{
    MainMenu();
    if (invalid == -1)
    {
        printf("\n%c[%dmCongratulations, you won!\n", 0x1B, 00);
    }
    free(positions);
    return 0;
}