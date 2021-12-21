#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//Variables ==> 
// char player1[30];
int column , row;
bool draw = false;
char turn = 'X';
// char player2[30];
char dice[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};


// Functions ==> 
void box_display();
void filling_element();
bool gameover();
// void checkwin_or_lose_or_over();


int main()
{
  cout << "\n\n\n\n\n\t\t\t T A C   T I C   T O E   G A M E " << endl;
  while (gameover())
  { 
    box_display();
    filling_element();
    gameover();
  }
  if (turn == 'X' && draw == false) {
        cout << "player 2[O] WINS!!!" << endl;
    }
    else if (turn == 'O'  && draw == false) {
        cout << "player 1[X] WINS!!!" << endl;
    }
    else {
        cout << "GAME DRAW!!" << endl;
    }

  return 0;
}


void box_display()
{
  system("cls");
  cout << "\t\t\t     |     |     " << endl;
  cout << "\t\t\t  " << dice[0][0] << "  |  " << dice[0][1] << "  |  " << dice[0][2] << "  " << endl;
  cout << "\t\t\t_____|_____|_____" << endl;
  cout << "\t\t\t     |     |     " << endl;
  cout << "\t\t\t  " << dice[1][0] << "  |  " << dice[1][1] << "  |  " << dice[1][2] << "  " << endl;
  cout << "\t\t\t_____|_____|_____" << endl;
  cout << "\t\t\t     |     |     " << endl;
  cout << "\t\t\t  " << dice[2][0] << "  |  " << dice[2][1] << "  |  " << dice[2][2] << "  " << endl;
  cout << "\t\t\t     |     |     " << endl;
}


void filling_element()
{
  int choise;
  if(turn== 'X')
  {
    cout<<"\n\n\t\tplayer1 [X] Is Turn : ";
    cin>>choise;
  }
  if(turn== 'O')
  {
    cout<<"\n\n\t\tplayer2 [O] Is Turn : ";
    cin>>choise;
  }
  switch (choise)
  {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;

  default:
    cout << "Invlid Value !!.." << endl;
    break;
  }
  if (turn == 'X' && dice[row][column] != 'X' && dice[row][column] != 'O') {
        dice[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && dice[row][column] != 'X' && dice[row][column] != 'O') {
        dice[row][column] = 'O';
        turn = 'X';
    }
    else {
        cout << "BOX ALREADYY FILLED...!!\n PLEASE TRYY AGAIN" << endl;
        filling_element();
    }
    box_display();
}

// void naming()
// {
  
//   cout << "\t\t\tEnter Player 1 Name : ";
//   gets(player1);
//   cout << "\n\t\t\tEnter Player 2 Name : ";
//   gets(player2);
//   cout << "\n\n\n";
// }
bool gameover() {
    // check win
    for (int i = 0; i < 3; i++) {
        if (dice[i][0] == dice[i][1] && dice[i][0] == dice[i][2] || dice[0][i] == dice[1][i] && dice[0][i] == dice[2][i])
        return false;
    }
    if (dice[0][0] == dice[1][1] && dice[0][0] == dice[2][2] || dice[0][2] == dice[1][1] && dice[0][2] == dice[2][0]) {
        return false;
    }

    //game playing
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
        if (dice[i][j] != 'X' && dice[i][j] != 'O') {
            return true;
        }
    //game draw
    draw = true;
    return false;
}