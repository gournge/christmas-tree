#include <iostream>
#include <windows.h>
#include <vector>
#include "../include/fns.hpp"
using namespace std;

void render(vector<vector<int>>& data) {
  // renders and zeros out
  
  char convert[3] = {' ', '#', '*'};
  for (int x = 0; x < data.size(); x++) {
    for (int y = 0; y < data[0].size(); y++) {
      cout << convert[data[x][y]];
      data[x][y] = 0;
    }
    cout << '\n';
  }
}

void row(vector<vector<int>>& data, int x, int y, int fill) {
  for (int i = 0; i < fill; i++) { data[x][y+i] = 1; }
}

void triangle(vector<vector<int>>& data, int x, int y, int size, int cut) {
  for (int i = cut; i<size; i++) {
    row(data, x+i, y, i);
  }
}

void christmas_tree(vector<vector<int>>& data, int height, int width, int shift) {
  int dx;
  int y = width/2;
  for (int x = 0; x < height; x++) {
    dx += x*(height-x);
    triangle(data, dx, y+(shift*(width-x)), width+x, (width+x)/3);
  }
}

void play_song() { }

void play_buzzer_song(int moment) {

}
