#include <string>

std::string convert(std::string s, int numRows) {
    if (numRows == 1) return s;

    int len = s.length();
    std::string converted;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = i; j < len; j += 2 * (numRows - 1))
        {
            converted += s[j];
            int newIndex = j + (numRows - 1 - i) * 2;
            if (i > 0 && newIndex < len && newIndex != j)
            {
                converted += s[newIndex];
            }
        }
    }
    return converted;
}

int main()
{
}