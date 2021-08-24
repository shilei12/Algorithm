/**
 * @file matchTest.cpp
 * @author shilei (qwepoi1248@163.com)
 * @brief learning match function of regex
 * @version 1
 * @date 2021-07-30
 * https://www.cnblogs.com/coolcpp/p/cpp-regex.html
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool CheckValid(const string& str)
{
    regex qq_reg("[1-9]\\d{4,11}");
    return regex_match(str, qq_reg);
}


int main()
{
    string str = "8729616641231";
    bool ret = CheckValid(str);
    cout << boolalpha << ret << endl;
}