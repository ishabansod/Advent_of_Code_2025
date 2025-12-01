#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

inline string read_file(const string& path) {
    ifstream f(path);
    return {istreambuf_iterator<char>(f), {}};
}

inline vector<string> read_lines(const string& path) {
    ifstream f(path);
    string s;
    vector<string> out;
    while (getline(f, s)) out.push_back(s);
    return out;
}