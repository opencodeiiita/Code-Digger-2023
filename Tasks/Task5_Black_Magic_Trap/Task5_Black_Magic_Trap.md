**PROBLEM STATEMENT:**

Arya resides in a small town where he hasn't had the opportunity to explore a wide range of games. However,
there's one game he's exceptionally skilled at: Snake and Ladder. Arya possesses a unique talent that sets 
him apart—he can draw any side of dice needed in a single attempt, making him an almost unbeatable player.

A twist in the story arises when one of Arya's friends(gf), who happens to have knowledge of black magic, 
decides to challenge Arya's prowess in Snake and Ladder, board where the cells are labeled from 1 to n*m in
a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating
direction each row) She intends to make the game more challenging for Arya by invoking her magical abilities.
Specifically, she can block a certain number of sides of the die, denoted by k, where 0 <= k <= 6. These 
blocked sides, represented as a0, a1, ... ak, will be off-limits for Arya during the game.

Faced with this magical challenge, Arya seeks to find a strategy that will allow him to win the game in the
fewest moves possible. He turns to you for assistance, hoping that you can provide him with a sequence of
moves that will enable him to emerge victorious while navigating the obstacles created by the blocked sides.

if not possible print -1

**INPUT FORMAT:**

first line n , m . dimension of board (1<= n,m <= 20)

next n line contain m spaced integer . board if cell[i][j] != -1 then there is snake or ladder at that point 
and you have to jump to that cell .

next line contain k - number of side blocked (1<=k<=6)

next line contain k spaced integer 

**OUTPUT FORMAT:**

sequence of move to reach end point in minimum move

**NOTE:**

1 and n*m position dont have snake or ladder


**INPUT**


4 4

-1 -1 -1 -1

-1 -1 -1 -1

-1 -1 -1 -1 

-1 15 -1 -1

5

2 3 4 5 6

**OUTPUT**

1 1

