#include <iostream>
#include <windows.h>
#include <vector>
#include "../include/fns.hpp"
using namespace std;

int main()
{
    int n, s;  // n is the amount of triangles
                        // s is their size
    bool if_mp3 = false;
    cout << "enter n and s (of trees) consecutively:\n";
    cin >> n >> s;
    cout << "enter whether to play mp3 music (1 or 0)\n";
    cin >> if_mp3;

    vector<vector<int>> data( n*s , vector<int> (n*s, 0));



    const int song_length = 45;

    int count = 0;
    if (if_mp3) play_song();
    while (1) {
      count++; count %= song_length;

      christmas_tree(data, n+1, 2*s, abs(count%11-5)-2);
      // for (auto &l : data) { for (auto &t : l) cout << t; }
      render(data);
      Sleep(1000);
      clearscreen(data);
      if (not if_mp3) play_buzzer_song(count);

    }
    return 0;
}
