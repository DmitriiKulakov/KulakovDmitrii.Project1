//Name: Kulakov Dmitrii
//Project#1: Memory Game

#include <iostream>
#include <ctime>
#include<Windows.h>
using namespace std;

const int rows = 3;
const int columns = 3;

void skip();
int countsStars(char[rows][columns]); //function to count '*' 
void changingStars(int[rows][columns], char[rows][columns], char[rows][columns], int, int);
void randomLettersInArray(char[]);
void displayMenu();
void displayStars(char[rows][columns]);
void displayPositions(int[rows][columns]);
void displayAnswers(char[rows][columns]);

int main()
{
    srand(time(0));
    int Positions[rows][columns];
    char Stars[rows][columns];
    char Answers[rows][columns];
    char answers[10];
    int i, j, counter;
    int position1, position2, move;
    char answ;

    displayMenu();

    do //loop to restart the game if user entered 'Y'
    {
        counter = 1;
        move = 1;

        for (i = 1;i < 10;i++)
        {
            answers[i] = ' ';
        }

        randomLettersInArray(answers);  //function for including letters in random places in the array

        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < columns; j++)
            {
                Stars[i][j] = '*';   //two-dimensial array includes '*'
                Positions[i][j] = counter;  //two-dimensial array with numbers from 1-9
                Answers[i][j] = answers[counter];  //two-dimensial array that includes letters from the array
                counter++;
            }
        }

        displayStars(Stars);  //function for displaying two-dimensional array 'Stars'

        displayPositions(Positions);  //function for displaying two-dimensional array 'Positions'

        do
        {
            do
            {
                cout << "Move #" << move << ": Enter two positions to match : ";
                cin >> position1 >> position2;
            } while ((position1 < 1 || position1>10 || position2 < 1 || position2>10 || position1==position2));  //loop to avoid errors if user entered wrong positions

            if (answers[position1] == answers[position2])  //if user found two same letters it will save it two-dimensional array 'Stars'
            {
                changingStars(Positions, Answers, Stars, position1, position2);  //function which changing stars on letters

                displayStars(Stars);
            }
            else
            {
                for (i = 0; i < rows; i++)
                {
                    for (j = 0; j < columns; j++)
                    {
                        if (Positions[i][j] == position1)
                        {
                            cout << Answers[i][j] << " ";
                        }
                        else if (Positions[i][j] == position2)
                        {
                            cout << Answers[i][j] << " ";
                        }
                        else
                        {
                            cout << Stars[i][j] << " ";
                        }
                    }
                    cout << endl;
                }

                Sleep(2000);
                skip();  //function which skips 50 lines
                displayStars(Stars);
            }

            move++;
        } while (countsStars(Stars) != 1);  //if stars will be 1, that means that user found all pairs of letters

        displayAnswers(Answers);   //function for displaying two-dimensional array 'Answers'

        do //loop for if user entered not symbol which he can(to not cause the error)
        {
            cout << "You did it in " << move << " moves!" << " Play again (Y or N)? ";
            cin >> answ;
        } while (answ != 'Y' && answ != 'N');
    } while (answ == 'Y');

    cout << "Bye.";

    return 0;
}

void randomLettersInArray(char answers[10])
{
    int r1, r2, counter2 = 0;
    do
    {
        do  //loop to put all letters in free spaces
        {
            r1 = rand() % 9 + 1;  //random numbers from 1-9
            r2 = rand() % 9 + 1;
        } while (r1 == r2);
        if (answers[r1] == ' ')
        {
            answers[r1] = 'a' + counter2;
        }
        if (answers[r2] == ' ')
        {
            answers[r2] = 'a' + counter2;
        }
        if ((answers[r2] == 'a' + counter2) && (answers[r1] == 'a' + counter2))
        {
            counter2++;
        }
        else if (answers[r1] == 'a' + counter2)
        {
            answers[r1] = ' ';
        }
        else if (answers[r2] == 'a' + counter2)
        {
            answers[r2] = ' ';
        }
    } while (counter2 != 4);
}

void skip()
{
    for (int i = 0;i < 50;i++)
    {
        cout << endl;
    }
}

int countsStars(char stars[rows][columns])
{
    int counter1 = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (stars[i][j] == '*')
            {
                counter1++;
            }
        }
    }
    return counter1;
}

void changingStars(int positions[rows][columns], char answers[rows][columns], char stars[rows][columns], int pos1, int pos2)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (positions[i][j] == pos1)
            {
                stars[i][j] = answers[i][j];
            }
            else if (positions[i][j] == pos2)
            {
                stars[i][j] = answers[i][j];
            }
        }
    }
}

void displayMenu()
{
    cout << "Welcome to the Matching Game. At each move, choose two positions that you think match." << endl;
}

void displayStars(char stars[rows][columns])
{
    cout << "Board is: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << stars[i][j] << " ";
        }
        cout << endl;
    }
}

void displayAnswers(char answers[rows][columns])
{
    cout << "Board is: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << answers[i][j] << " ";
        }
        cout << endl;
    }
}

void displayPositions(int positions[rows][columns])
{
    cout << "Board positions are: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << positions[i][j] << " ";
        }
        cout << endl;
    }
}