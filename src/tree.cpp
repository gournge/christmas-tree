#include <iostream>
#include <windows.h>
#include <vector>
#include "../include/fns.hpp"
using namespace std;

int main()
{
    int height, width;  // height is the amount of triangles
                        // width is their size
    bool if_mp3 = false;
    cout << "enter height and width (of trees) consecutively:\n";
    cin >> height >> width;
    cout << "enter whether to play mp3 music (1 or 0)\n";
    cin >> if_mp3;

    vector<vector<int>> data( height*width , vector<int> (height*width, 1));

    int song_length = 45;

    int count = 0;
    int dummy;
    if (if_mp3) play_song();
    while (if_mp3) {
      cout << "hello\n";
      count++; count %= song_length;
      christmas_tree(data, height, width, count%5-2);
      render(data);
      if (not if_mp3) play_buzzer_song(count);
      Sleep(10000);
      cin >> dummy;
    }
    cin >> dummy;
    return 0;
}
