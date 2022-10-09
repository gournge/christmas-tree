#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "../include/fns.hpp"

using namespace std;

int main(int argc, char **argv)
{
    int n, s;  // n is the amount of triangles
                        // s is their size
    bool if_mp3 = false;
    cout << "enter n and s (of trees) consecutively:\n";
    cin >> n >> s;
    cout << "enter whether to play mp3 music (1 or 0)\n";
    cin >> if_mp3;

    vector<vector<int>> data( 4*s*s , vector<int> (n*n, 0));
    int count = 0;
    if (if_mp3) play_song();
    while (1) {
      christmas_tree(data, n+1, 2*s, abs(count%5-2)-2);
      lights(data);
      render(data);
      Sleep(1000);
      clearscreen(data);
      if (not if_mp3) play_buzzer_song(count);
      count++;
    }
    return 0;
}
