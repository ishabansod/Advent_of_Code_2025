#include "utils.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int part1(vector<string> input)
{
    int zeroes = 0;
    int position = 50;

    for (auto &n : input)
    {
        char direction = n[0];
        int amount = stoi(n.substr(1));

        if (direction == 'L')
        {
            position = (position - amount) % 100;
        }
        else if (direction == 'R')
        {
            position = (position + amount) % 100;
        }

        if (position == 0)
        {
            zeroes++;
        }
    }
    return zeroes;
}

int part2(vector<string> input)
{
    int zeroes = 0;
    int position = 50;

    for (auto &n : input)
    {
        char direction = n[0];
        int amount = stoi(n.substr(1));

        zeroes += (amount/100);
        amount = amount%100;

        if (direction == 'R')
        {
            // position = (position + amount) % 100;
            // zeroes += (position + amount) / 100;

            // if (position == 0)
            // {
            //     zeroes++;
            // }
            position += amount;
            if (position == 0 || position == 100){
                zeroes++;
                position = 0;
            } else if (position>100)
            {
                zeroes++;
                position -= 100;
            }
        }
        else if (direction == 'L')
        {
            if (position == 0)
            {
                position = 100 - amount;
            }
            else
            {
                position -= amount;
                if (position == 0)
                {
                    zeroes++;
                }
                else if (position < 0)
                {
                    zeroes++;
                    position += 100;
                }
            }
        }
    }
    return zeroes;
}

int main()
{
    vector<string> lines = read_lines("inputs/day01.txt");

    int p1 = part1(lines);

    cout << "Part 1 - " << p1;

    cout << "\n";

    int p2 = part2(lines);
    cout << "Part 2 - " << p2;
}