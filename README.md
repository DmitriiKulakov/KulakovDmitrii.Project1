# KulakovDmitrii.Project1
Project #1 : Memory Game
a) Write a C++ program that plays the memory game. A description of the game is as follows:
You have a 3x3 board in which you hide 4 pairs of letters which are directly coded into the
program (one board position is blank). Each time, the player is asked to pick a pair of board
positions. The contents of the board positions are then revealed and if the same letter
appears in these positions, the player has successfully matched one of the 4 pairs. The
process continues until the player has matched all 4 pairs. The program should allow a
player to play again (if they wish), at the end of each game.
A sample run should give the following (user’s response shown here in bold):
Welcome to the Matching Game. At each move, choose two positions
that you think match.
Board is:
* * *
* * *
* * *
Board positions are:
1 2 3
4 5 6
7 8 9
Move #1: Enter two positions to match: 1 5
Board is:
[Screen is cleared after 2 seconds]
Board is:
* * *
* * *
* * *
Move #2: Enter two positions to match: 1 3
Board is:

Move #3: Enter two positions to match: 4 5
b * *
* c *
* * *
b * b
* * *
* * *
3
Board is:
[Screen is cleared after 2 seconds]
Board is:
b * b
* * *
* * *
Move #4: Enter two positions to match: ….
…..
….
Board is:
b d b
c d
a c a
You did it in 7 moves! Play again (Y or N)? N
Bye.
(b) Modify your program in (a) above so that the letters are allocated randomly within the 3x3
array. You will need a random number generator that randomly chooses the positions of the
pairs. There are 4 pairs of letters (a, b, c, and d) and one board position will be left blank.
You will call the random number generator at least twice for each pair to get the two
positions. (You may need to call it more than twice if it gives you a position which is
already taken). The random number generator should generate numbers from 1 to 9
(inclusive), indicating the board positions. The following C++ statement issues an integer
form 1 to 9 and assigns it to an integer r: r=rand()%9 +1; .
