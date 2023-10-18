#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num, rem, i, fact, sum = 0, j;
    cout << "ENTER NUMBER YOU WANT TO CHECK IF IT IS STRONG OR NOT: ";
    cin >> num;
    j = num;
    for (num; num > 0; num = num / 10)
    {

        rem = num % 10;
        fact = 1;
        for (i = 1; i <= rem; i++)
        {
            fact = fact * i;
        }
        sum = sum + fact;
    }
    if (j == sum)
    {
        cout << j << " is a STRONG NUMBER";
    }
    else
    {
        cout << j << " IS NOT A STRONG NUMBER.";
    }
    return 0;
}
