#include <iostream>
#include <vector>
#include <string>
#include "../include/fns.hpp"
#include <windows.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>
#pragma comment(lib, "winmm.lib")
using namespace std;

void render(vector<vector<int>>& data) {
  // renders and zeros out

  const string colors[] = {"",  "\033[32m", "\033[33m", "\033[31m", "\033[34m",  "\033[35m"};
  const string prints[] = {" ", "#",         "M",       "*",        "x",         "o"};
                       // green        brown      red         blue         magenta

  for (int i = 0; i < data[0].size()+2; i++) { cout << "#"; } cout << "\n";
  for (int x = 0; x < data.size(); x++) {
    cout << "#";
    for (int y = 0; y < data[0].size(); y++) {
      cout << colors[data[x][y]];
      cout << prints[data[x][y]];
      cout << "\033[0m";

      data[x][y] = 0;
    }
    cout << "# \n";
  }
  for (int i = 0; i < data[0].size()+2; i++) { cout << "#"; } cout << "\n";

}

void clearscreen(vector<vector<int>>& data) {
  cout << "\033[2J";
  for (int x = 0; x < data.size(); x++) {
    for (int y = 0; y < data[0].size(); y++) {
      cout << "\b \b";
    }
    cout << "\b \b";
  }
}


void row(vector<vector<int>>& data, int x, int y, int fill, int type) {
  for (int i = 0; i < fill; i++) { data[x][y+i] = type; }
}

void triangle(vector<vector<int>>& data, int x, int y, int size, int cut) {
  for (int i = cut; i<size+cut; i++) { row(data, x+i, y-i, 2*i+1, 1); }
}

void christmas_tree(vector<vector<int>>& data, const int size, const int width, int shift) {
  int y = data[0].size()/2; int x = 2;
  data[3][y+shift*(size-1)] = 1;
  for (int dx = 1; dx < size; dx++) {
    x += dx;
    triangle(data, x, y+shift*(size-dx), dx+2, dx);
  }
  x = data.size()-1; while (data[x][y]) x--;
  for (int j = 0; j < size*2/5; j++) row(data, x+j, y-(size*3/8), size*3/4, 2);
}

void lights(vector<vector<int>>& data) {

  for (int x = 0; x < data.size(); x++) {
    for (int y = 0; y < data[0].size(); y++) {
      srand(time(NULL)+x*y);
      int c = rand()%5, color = rand()%3;
      if (c == 0) data[x][y] = color+3;
    }
  }
}


void play_song() {
  // to uncomment this line add copper.wav to src and uncomment the second next
  // PlaySound("copper.wav", NULL, SND_FILENAME | SND_RESOURCE );
  PlaySound( R"(C:\Users\filip\OneDrive\Dokumenty\Pulpit\"Filip - Laptop"\Liceum\IB\"Comp sci"\choinka\resource\copper.wav)", NULL, SND_FILENAME | SND_RESOURCE );

 }

void play_buzzer_song(int moment) {
  const bool song[] = { 1, 1, 1, 0, 0, 0, // 40 units long
                        1, 1, 1, 0, 0, 0,
                        1, 1, 1, 1, 1, 0,
                        0, 0, 1, 1, 1, 0,
                        1, 1, 1, 0, 1, 1,
                        0, 1, 1, 1, 0, 0,
                        0, 0, 0, 0}
  const int len = 40;
  if (song[moment%len]) cout << "\a";
}
