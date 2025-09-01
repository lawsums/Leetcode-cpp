//
// Created by Hello on 2025/8/27.
//

#ifndef LEETCODE_STRINGOPERATIONS_H
#define LEETCODE_STRINGOPERATIONS_H

#include <string>
typedef long long ll;
using namespace std;

class StringOperations {
private:
    ll base = 499;
    string mulStringsLessTenTimes(string num1, int times) ;
    int mapping(char c) ;

public:
    string addStrings(string num1, string num2) ;
    string mulStrings(string num1, string num2) ;
    ll string_hash(const string& s) ;
};


#endif//LEETCODE_STRINGOPERATIONS_H
