#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 15;

void printMaze(vector<vector<char>> &maze) {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      if (maze[i][j] == '*') {
        cout << " ";
      } else {
        cout << maze[i][j];
      }
    }
    cout << endl;
  }
}

bool isValid(int x, int y) { return x >= 0 && x < SIZE && y >= 0 && y < SIZE; }

void generateMaze(vector<vector<char>> &maze) {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      maze[i][j] = '#';
    }
  }
  maze[0][1] = ' ';
  maze[SIZE - 1][SIZE - 2] = ' ';
  srand(time(NULL));
  for (int i = 1; i < SIZE - 1; ++i) {
    for (int j = 1; j < SIZE - 1; ++j) {
      if (rand() % 3 == 0) {
        maze[i][j] = '#';
      } else {
        maze[i][j] = ' ';
      }
    }
  }
}

bool findPath(vector<vector<char>> &maze, int x, int y) {
  if (!isValid(x, y) || maze[x][y] == '#' || maze[x][y] == '.' ||
      maze[x][y] == '*') {
    return false;
  }
  maze[x][y] = '.';
  if (x == SIZE - 1 && y == SIZE - 2) {
    return true;
  }
  if (findPath(maze, x, y + 1) || findPath(maze, x + 1, y) ||
      findPath(maze, x, y - 1) || findPath(maze, x - 1, y)) {
    return true;
  }
  maze[x][y] = '*';
  return false;
}

int main() {
  int i = 0;
  vector<vector<char>> maze(SIZE, vector<char>(SIZE));
  do {
    cout << ++i << endl;
    generateMaze(maze);
  } while (!findPath(maze, 0, 1));
  printMaze(maze);
  cout << "We generate " << i << " times.";
  return 0;
}