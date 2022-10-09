#include <vector>
using namespace std;

void render(vector<vector<int>>& data);
void clearscreen(vector<vector<int>>& data);

void row(vector<vector<int>>& data, int x, int y, int fill, int type);
void triangle(vector<vector<int>>& data, int x, int y, int size, int cut);
void christmas_tree(vector<vector<int>>& data, int height, int width, int shift);
void lights(vector<vector<int>>& data);

void play_song();
void play_buzzer_song(int moment);
