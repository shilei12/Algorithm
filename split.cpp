#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> Split(const string&str, const char ch)
{
    stringstream ss(str);
    vector<string> res;
    while (!ss.fail()) {
        string innerStr = "";
        getline(ss, innerStr, ch);
        if (!innerStr.empty()) {
            res.emplace_back(innerStr);
        }
    }
    return res;
}

int main()
{
    string str = "726+923+2830";
    vector<string> res = Split(str, '+');
    for (const auto& str : res) {
        cout << str << endl;
    }
    return 0;
}