#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<pair<long long, long long>> read_input(const string &path)
{
    vector<pair<long long, long long>> id_ranges;

    ifstream file(path);

    string content;
    getline(file, content);

    stringstream ss(content);
    string token;

    while (getline(ss, token, ','))
    {
        long long start, end;
        sscanf(token.c_str(), "%lld-%lld", &start, &end);
        id_ranges.emplace_back(start, end);
    }

    return id_ranges;
}

long long part1(vector<pair<long long, long long>> input)
{
    long long sum = 0;

    for (const auto &r : input)
    {
        long long start = r.first;
        long long end = r.second;

        for (auto n = start; n <= end; n++)
        {
            string s = to_string(n);

            if (s.size() % 2 != 0)
            {
                continue;
            }

            auto mid = s.size() / 2;

            string first = s.substr(0, mid);
            string second = s.substr(mid);

            if (first == second)
            {
                sum += n;
            }
        }
    }

    return sum;
}

// using period of a string to check substrings
// ex: 121212 has period 2 - we can make the whole string by repeating
// first two digits 3 times (6/2)

int findPeriod(string id)
{
    int period = -1;
    int i = 0;

    for (int j = 1; j < id.size(); j++)
    {
        int c1 = id[j];
        int c2 = id[i];
        if (c1 == c2)
        {
            period = (j - i);
            i++;
        }
        else
        {
            if (c1 == id[0])
            {
                i = 1;
                period = j;
            }
            else
            {
                i = 0;
                period = -1;
            }
        }
    }

    period = (id.size() % period != 0) ? -1 : period;
    return period;
}

long long part2(vector<pair<long long, long long>> input)
{
    long long sum = 0;

    for (const auto &r : input)
    {
        long long start = r.first;
        long long end = r.second;

        for (auto n = start; n <= end; n++)
        {
            string s = to_string(n);

            if (findPeriod(s) != -1)
                sum += n;
        }
    }
    return sum;
}

int main()
{
    auto id_range = read_input("inputs/day02.txt");

    // for (auto &r : id_range)
    // {
    //     cout << r.first << " - " << r.second << "\n";
    // }

    long long p1 = part1(id_range);

    cout << "Part 1 - " << p1;

    cout << "\n";

    long long p2 = part2(id_range);
    cout << "Part 2 - " << p2;
}