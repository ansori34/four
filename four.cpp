#include <iostream>

using namespace std;

void createMap();
void fill(int);
int getScore(char);

char status[4][4], player1 = '0', player2 = '#';
int count = 0;
bool turn = true;

int main()
{
  int angka;
  bool gameOver = false;

  createMap();

  while (count < 16) {

    if (turn) {
      cout << endl << "Player 1 = ";
    } else {
      cout << endl << "Player 2 = ";
    }

    cin >> angka;
    switch (angka) {
      case 1: fill(0); break;
      case 2: fill(1); break;
      case 3: fill(2); break;
      case 4: fill(3); break;
    }

    system("clear");
    createMap();
  }

  cout << endl << "Game Over !" << endl << endl;
  cout << "Player 1 Score = " << getScore(player1) << endl;
  cout << "Player 2 Score = " << getScore(player2) << endl;
}

void createMap()
{
  cout << "| 1 | 2 | 3 | 4 |" << endl;
  cout << "-----------------" << endl;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << "| ";

      switch (status[i][j]) {
        case '\0': cout << "  "; break;
        default : cout << status[i][j] << " "; break;
      }
    }
    cout << "|" << endl;
  }
}

void fill(int rowIndex)
{
  for (int i = 3; i >= 0; i--) {
    if (status[i][rowIndex] == '\0') {
      status[i][rowIndex] = (turn) ? player1 : player2;
      count++;
      break;
    }
  }

  turn = !turn;
}

int getScore(char player)
{
  int score = 0;

  for (int i = 0; i < 4; i++) {
    bool temp = true;

    for (int j = 0; j < 4; j++) {
      if (status[i][j] != player) {
        temp = false;
        break;
      }
    }

    if (temp) {
      score++;
    }
  }

  return score;
}
