#include <bits/stdc++.h>
using namespace std;

const int N = 110;
string s[N] = {"                ********",
               "               ************",
               "               ####....#.",
               "             #..###.....##....",
               "             ###.......######              ###            ###",
               "                ...........               #...#          #...#",
               "               ##*#######                 #.#.#          #.#.#",
               "            ####*******######             #.#.#          #.#.#",
               "           ...#***.****.*###....          #...#          #...#",
               "           ....**********##.....           ###            ###",
               "           ....****    *****....",
               "             ####        ####",
               "           ######        ######",
               "##############################################################",
               "#...#......#.##...#......#.##...#......#.##------------------#",
               "###########################################------------------#",
               "#..#....#....##..#....#....##..#....#....#####################",
               "##########################################    #----------#",
               "#.....#......##.....#......##.....#......#    #----------#",
               "##########################################    #----------#",
               "#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#",
               "##########################################    ############"};

int main() {
    for (int i = 0; i < 22; i++) cout << s[i] << '\n';

    return 0;
}
