#include "strings_and_arrays.h"

bool permutation(string first, string second)
{
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    if(first.compare(second) == 0){
        return true;
    }
    return false;
}
