#include <vector>

void swap_int(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void rotate(std::vector<std::vector<int>>& matrix)
{
    int size = matrix[0].size();

    int i = 0;
    int j = 0;
    while (size > j * 2)
    {
        for (i = j; i < size - 1 - j; i++)
        {
            swap_int(matrix[j][i], matrix[i][size - 1 - j]);
            swap_int(matrix[j][i], matrix[size - i - 1][j]);
            swap_int(matrix[size - i - 1][j], matrix[size - j - 1][size - i - 1]);
        }
        j++;
    }
}

int main()
{
}