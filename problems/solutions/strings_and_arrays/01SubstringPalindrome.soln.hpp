#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>

// Find all palindrome substrings in the given string 
// O(n^3)

bool isPalindrome(std::string& s)
{
    if ( s.length() == 1 )
        return false;

    std::stack<char> stack = std::stack<char>();
    int slow = 0;
    int fast = 0;
    int len = s.length();
    while ( fast != len && fast+1 != len )
    {
        stack.push(s[slow]);
        slow++;
        fast += 2;
    }
    if ( fast != len )
        slow++;

    while ( slow != len )
    {
        if ( stack.top() != s[slow] )
            return false;
        stack.pop();
        slow++;
    }
    return true;
}

void substringPalindrome(std::string& s)
{
    int len = s.length();
    int start;
    for ( start = 0; start < len; start++ )
    {
        int end = len - start;
        while ( end > 0 )
        {
            std::string substr = s.substr(start, end);
            if ( isPalindrome(substr) )
            {
                std::cout << substr << std::endl;
            }
            end--;
        }
    }
}

void checkPalindrome(int left, int right, std::string& s, std::unordered_set<std::string>& result)
{
    std::string builder = "";
    if ( s[left] == s[right-2] && left > 0 )
        builder.push_back(s[left+1]);

    while ( left >= 0 && right < s.length() )
    {
        if ( s[left] == s[right] )
        {
            builder.insert(0, 1, s[left]);
            builder.push_back(s[right]);
        }
        else
            break;
        result.insert(builder);
        left--;
        right++;
    }
}

// Find all substring palindromes O(n^2)
void substringPalindrome2(std::string& s)
{
    std::cout << "\nSubstring Palindrome 2\n";
    std::unordered_set<std::string> result = std::unordered_set<std::string>();
    for ( int i = 0; i < s.length(); i++ )
    {
        // even lengths
        checkPalindrome(i, i+1, s, result);
        // odd lengths
        checkPalindrome(i-1, i+1, s, result);
    }
    for ( std::unordered_set<std::string>::iterator str = result.begin() ; str != result.end(); str++ )
        std::cout << *str << std::endl;
}
