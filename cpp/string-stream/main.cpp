/*
 * Starter code (main) by Hackerrank.com 
 * parseInts by Justin Cromer
 * date: 09-21-2022
 */
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    vector<int> rv;
    stringstream ss(str);
    char delim;
    int j;
    while (ss >> j) {
        ss >> delim;
        rv.push_back(j);
    }
    return rv;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
