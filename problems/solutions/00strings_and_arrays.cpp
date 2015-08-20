// Given two strings, write a function that decides if one string is a perumation of the other

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool permutation(string first, string second)
{
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    
    if (first.compare(second) == 0){
        return true;
    }
    return false;
}

int main()
{
    string first = "something";
    string second = "ghinteosm";

    cout << permutation(first, second) << endl;

    return 0;
}
