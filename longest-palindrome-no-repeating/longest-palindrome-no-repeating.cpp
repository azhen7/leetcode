#include <vector>
#include <string>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    if (s.length() <= 1) return s.length();
    std::string current_substr = "";
    std::vector<int> substr_lengths;
    for (int i = 0; i < s.length(); i++) {
        int index = current_substr.find(s[i]);
        /**
         * If the current character (s[i]) has already been added to @var current_substr,
         * the current length of current_substr is a valid length, and the entire part of 
         * the string up to the existing occurence of s[i] is erased.
        */
        if (index != std::string::npos) {
            substr_lengths.push_back(current_substr.length());
            current_substr.erase(0, index + 1);
        }
        current_substr += s[i];
    }
    //Add the latest substring length
    if (!current_substr.empty())
        substr_lengths.push_back(current_substr.length());
    
    return *std::max_element(substr_lengths.begin(), substr_lengths.end());
}

int main()
{
}