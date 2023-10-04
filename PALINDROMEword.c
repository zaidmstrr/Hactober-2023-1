#include <stdio.h>
#include <string.h>
int main()
{
    char word[10];
    printf("ENTER A WORD TO FIND WHETHER IT IS A PALINDROME OR NOT\n");
    gets(word);
    printf("THE REVERSED WORD IS %s\n", strrev(word));

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == word[strlen(word) - i - 1])
        {
            if (i == strlen(word) - 1)
            {
                printf("YES");
                break;
            }
            else
            {
                continue;
            }
        }
        else
        {
            printf("NO");
            break;
        }
    }
    return 0;
}