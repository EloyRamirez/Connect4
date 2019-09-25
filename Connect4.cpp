//+++++++++++++++++++++++++++++++++++++++++++++++++
// Title: Connect4.cpp
// Course: Computational Problem Solving CPET-121
// Developer: Eloy Ramirez
// Date: Mar 28, 2019
// Description: Connect4 Basic Implementation
//+++++++++++++++++++++++++++++++++++++++++++++++++
#include<iostream>;
#include<string>;
#include<iomanip>;
#includ<cstdlib>;
#include<ctime>;
using namespace std;

int Random(char a, char b); // Placeholder for Random function
int Welcome(char a, char b); // Placeholder for Welcome function
void Display(char board[][7]); // Placeholder for Display function
bool Check(char board[][7], int a, int b); // Placeholder for Check function
int Drop(char board[][7], int b, char player); // Placeholder for Drop function

int main() // Main function
{
	char board[6][7]; //array for board
	for(int a =0;a <= 5; a++)
	{
		for(int b = 0; b<=6; b++) //fill array with whitespace
					board[a][b] = ' ';

	}
	char a=0, b=0, c; // Initializes a, b , and c characters
	c = Welcome(a,b); // Sets c as Welcome function
	Display(board); // Displays for first time so players can see the board
	int hold; // Will house user row choice
	int hold2 = 0; // will hold Drop value
	int charsPlaced = 0; // Number of pieces Dropped so can end game if a draw
	bool gamewon = false; // Will be changed to true when game is won and will exit while loop
	char player = c; // start as player 2 will change back 2 player 1
	while(!gamewon) // will stop when game is won
	{
		if(hold2 != -1) // Check if there was a error in the last Drop
		{
			if(player == 'O';) // if player 2 lasted Dropped a piece so its player 1s turn
			{
				cout<<"Player #1s Turn (X) : Enter Your Move : ";
				player = 'X'; // char of player 1 piece
			}
			else
			{
cout&lt;&lt;&quot;Player #2&#39;s Turn (O) : Enter Your Move : &quot;;
player = &#39;O&#39;; // char of player 2 piece
}
}
while(true) // will run until &#39;break;&#39;

{
if(charsPlaced == 42)
break; // if draw
cin&gt;&gt;hold; // get user input
hold--; // take off 1 to account for arrays starting at 0 not 1
if(hold &lt;=6 &amp;&amp; hold&gt;= 0)
break; // if within valid range stop loop
else cout&lt;&lt; &quot;\nPlease enter a value between 1 and 7 :&quot;; // ask

for input and loop again

if (cin.fail()) // catch a non number
{
cin.clear(); // Stops cin trying to put its value in

to hold

char c;
cin&gt;&gt;c;
}
}
if(charsPlaced == 42)
break; // if draw
hold2 = Drop(board,hold,player); // Drop the player store the row in

hold2

if(hold2 == -1) cout&lt;&lt;&quot;Column is full\nPlease enter another number

between 1 and 7:&quot;; // if error -1 row is full

else
{
gamewon = Check(board,hold2,hold); // Check if game is run
charsPlaced ++; // another character has been successfully placed
system(&quot;cls&quot;); // This clears the screen works with windows, not

necessary to run game

Display(board); // Displayed updated board
}
}
system(&quot;cls&quot;); // this clears the screen
if(charsPlaced == 42)
{ //if draw
cout&lt;&lt;&quot;No winner, Game was draw\n&quot;;
system(&quot;pause&quot;);
return 0;
}
if(player == &#39;O&#39;) // if won by player 2
cout&lt;&lt;&quot;gamewon by : player 2\n&quot;;
else cout&lt;&lt;&quot;gamewon by : player 1\n&quot;; // Else won by player 1
system(&quot;pause&quot;); // pauses before exit so players can see who won, works with
windows
return 0; // Exit application
}
int Random(char a, char b) // Randomizer function
{
srand(time(NULL)); // seed Randomizer
int r = rand()%2; // initializes r as Random number from 0 to 2
a = &#39;O&#39;; // sets a as &#39;O&#39; gamepiece
b = &#39;X&#39;; // sets b as &#39;X&#39; gamepiece

if(r==0) // returns &#39;O&#39; or &#39;X&#39;
return a;
else
return b;

}
int Welcome(char a, char b) // Welcome function
{
char piece = Random(a, b); // sets player first move
cout &lt;&lt; setw(30) &lt;&lt; &quot;Welcome to Connect4&quot; &lt;&lt; endl;
cout &lt;&lt; setw(42) &lt;&lt; &quot;The goal of Connect4 is to be the first&quot; &lt;&lt; endl;
cout &lt;&lt; &quot;player to place four Checkers sin a row, either&quot; &lt;&lt; endl;
cout &lt;&lt; setw(46) &lt;&lt; &quot;horizontally, vertically or diagonally. \n\n&quot; &lt;&lt; endl;
if (piece == &#39;X&#39;)
cout &lt;&lt; &quot;Player #1 was selected to go first\n&quot; &lt;&lt; endl;
if (piece == &#39;O&#39;)
cout &lt;&lt; &quot;Player #2 was selected to go first\n&quot; &lt;&lt; endl;
system(&quot;pause&quot;);
return piece;
}
void Display(char board[][7]) // Display function
{
for (int i=1; i&lt;=7; i++)
cout &lt;&lt; &quot; &quot; &lt;&lt; i;
cout &lt;&lt; &quot;\n\n&quot;;
cout &lt;&lt; &quot; | &quot; &lt;&lt; board[0][0] &lt;&lt; &quot; | &quot; &lt;&lt; board[0][1] &lt;&lt; &quot; | &quot; &lt;&lt; board[0][2]
&lt;&lt; &quot; | &quot; &lt;&lt; board[0][3] &lt;&lt; &quot; | &quot; &lt;&lt; board[0][4] &lt;&lt; &quot; | &quot; &lt;&lt; board[0][5] &lt;&lt; &quot; | &quot; &lt;&lt;
board[0][6] &lt;&lt; &quot; | &quot; &lt;&lt; endl;
cout &lt;&lt; &quot; +---+---+---+---+---+---+---+&quot; &lt;&lt; endl;
cout &lt;&lt; &quot; | &quot; &lt;&lt; board[1][0] &lt;&lt; &quot; | &quot; &lt;&lt; board[1][1] &lt;&lt; &quot; | &quot; &lt;&lt; board[1][2]
&lt;&lt; &quot; | &quot; &lt;&lt; board[1][3] &lt;&lt; &quot; | &quot; &lt;&lt; board[1][4] &lt;&lt; &quot; | &quot; &lt;&lt; board[1][5] &lt;&lt; &quot; | &quot; &lt;&lt;
board[1][6] &lt;&lt; &quot; | &quot; &lt;&lt; endl;
cout &lt;&lt; &quot; +---+---+---+---+---+---+---+&quot; &lt;&lt; endl;
cout &lt;&lt; &quot; | &quot; &lt;&lt; board[2][0] &lt;&lt; &quot; | &quot; &lt;&lt; board[2][1] &lt;&lt; &quot; | &quot; &lt;&lt; board[2][2]
&lt;&lt; &quot; | &quot; &lt;&lt; board[2][3] &lt;&lt; &quot; | &quot; &lt;&lt; board[2][4] &lt;&lt; &quot; | &quot; &lt;&lt; board[2][5] &lt;&lt; &quot; | &quot; &lt;&lt;
board[2][6] &lt;&lt; &quot; | &quot; &lt;&lt; endl;
cout &lt;&lt; &quot; +---+---+---+---+---+---+---+&quot; &lt;&lt; endl;
cout &lt;&lt; &quot; | &quot; &lt;&lt; board[3][0] &lt;&lt; &quot; | &quot; &lt;&lt; board[3][1] &lt;&lt; &quot; | &quot; &lt;&lt; board[3][2]
&lt;&lt; &quot; | &quot; &lt;&lt; board[3][3] &lt;&lt; &quot; | &quot; &lt;&lt; board[3][4] &lt;&lt; &quot; | &quot; &lt;&lt; board[3][5] &lt;&lt; &quot; | &quot; &lt;&lt;
board[3][6] &lt;&lt; &quot; | &quot; &lt;&lt; endl;
cout &lt;&lt; &quot; +---+---+---+---+---+---+---+&quot; &lt;&lt; endl;
cout &lt;&lt; &quot; | &quot; &lt;&lt; board[4][0] &lt;&lt; &quot; | &quot; &lt;&lt; board[4][1] &lt;&lt; &quot; | &quot; &lt;&lt; board[4][2]
&lt;&lt; &quot; | &quot; &lt;&lt; board[4][3] &lt;&lt; &quot; | &quot; &lt;&lt; board[4][4] &lt;&lt; &quot; | &quot; &lt;&lt; board[4][5] &lt;&lt; &quot; | &quot; &lt;&lt;
board[4][6] &lt;&lt; &quot; | &quot; &lt;&lt; endl;
cout &lt;&lt; &quot; +---+---+---+---+---+---+---+&quot; &lt;&lt; endl;
cout &lt;&lt; &quot; | &quot; &lt;&lt; board[5][0] &lt;&lt; &quot; | &quot; &lt;&lt; board[5][1] &lt;&lt; &quot; | &quot; &lt;&lt; board[5][2]
&lt;&lt; &quot; | &quot; &lt;&lt; board[5][3] &lt;&lt; &quot; | &quot; &lt;&lt; board[5][4] &lt;&lt; &quot; | &quot; &lt;&lt; board[5][5] &lt;&lt; &quot; | &quot; &lt;&lt;
board[5][6] &lt;&lt; &quot; | &quot; &lt;&lt; endl;
cout &lt;&lt; &quot; +---+---+---+---+---+---+---+&quot; &lt;&lt; endl;
}
bool Check(char board[][7], int a, int b) // Check function

{
int vertical = 1; // (|)
int horizontal = 1; // (-)
int diagonal1 = 1; // (\)
int diagonal2 = 1; // (/)
char player = board[a][b];
int i; // vertical
int ii; // horizontal
//Check for vertical(|)
for(i = a +1;board[i][b] == player &amp;&amp; i &lt;= 5;i++,vertical++); // Check down
for(i = a -1;board[i][b] == player &amp;&amp; i &gt;= 0;i--,vertical++); // Check up
if(vertical &gt;= 4)
return true;
//Check for horizontal(-)
for(ii = b -1;board[a][ii] == player &amp;&amp; ii &gt;= 0;ii--,horizontal++); // Check
left
for(ii = b +1;board[a][ii] == player &amp;&amp; ii &lt;= 6;ii++,horizontal++); // Check
right
if(horizontal &gt;= 4)
return true;
//Check for diagonal 1 (\)
for(i = a -1, ii= b -1;board[i][ii] == player &amp;&amp; i&gt;=0 &amp;&amp; ii &gt;=0; diagonal1 ++,
i --, ii --); // up and left
for(i = a +1, ii = b+1;board[i][ii] == player &amp;&amp; i&lt;=5 &amp;&amp; ii &lt;=6;diagonal1 ++,
i ++, ii ++); // down and right
if(diagonal1 &gt;= 4)
return true;
//Check for diagonal 2(/)
for(i = a -1, ii= b +1;board[i][ii] == player &amp;&amp; i&gt;=0 &amp;&amp; ii &lt;= 6; diagonal2
++, i --, ii ++); // up and right
for(i = a +1, ii= b -1;board[i][ii] == player &amp;&amp; i&lt;=5 &amp;&amp; ii &gt;=0; diagonal2 ++,
i ++, ii --); // up and left
if(diagonal2 &gt;= 4)
return true;
return false;
}
int Drop(char board[][7], int b, char player) // Drop function
{
if(b &gt;=0 &amp;&amp; b&lt;= 6)
{
if(board[0][b] == &#39; &#39;)
{
int i;
for(i = 0;board[i][b] == &#39; &#39;;i++)
if(i == 5)
{
board[i][b] = player;
return i;
}
i--;
board[i][b] =player;
return i;
}

else
{
return -1;
}
}
else
{
return -1;
}
}
