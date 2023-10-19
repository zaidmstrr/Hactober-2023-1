#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void log_exit(const char *msg, int err_no)
{
    fprintf(stderr, "%s\n", msg);
    exit(err_no);
}

typedef struct pair
{
    enum dir
    {
        left, above, diagonal, null
    } direction;
    int value;
} pair;

typedef struct twoD
{
    pair *arr;
    int rows, cols;
    pair *(*at)(struct twoD *, int, int);
    void (*print)(struct twoD *);
} twoD;

pair *get_2D_index(twoD *arr, int i, int j)
{
    return &arr->arr[(i * (arr->cols) + j)];
}

void print_2D(twoD *arr)
{
    for(int i = 0; i < arr->rows; ++i)
    {
        for(int j = 0; j < arr->cols; ++j)
        {
            char *direction = NULL;

            if(arr->at(arr, i, j)->direction == left)
                direction = "\u2190";
            else if(arr->at(arr, i, j)->direction == above)
                direction = "\u2191";
            else if(arr->at(arr, i, j)->direction == diagonal)
                direction = "\u2196";
            else
                direction = "-";

            printf("[%d, %s] ", arr->at(arr, i, j)->value, direction);
        }

        printf("\n");
    }
}

twoD *create_2D_array(int i, int j)
{
    twoD *arr = malloc(sizeof(*arr));

    if(!arr)
        log_exit("Failed to allocate 2D array.", 1);

    arr->arr = malloc(i * j * sizeof(*(arr->arr)));

    if(!arr->arr)
        log_exit("Failed to allocate 2D array.", 1);

    arr->rows = i;
    arr->cols = j;
    arr->at = get_2D_index;
    arr->print = print_2D;
    return arr;
}

void free_twoD(twoD *table)
{
    free(table->arr);
    free(table);
}

char *new_string(int len)
{
    char *str = malloc(len * sizeof(*str));

    if(!str)
        log_exit("Failed to allocate string.", 1);

    return str;
}

char *get_lcs_str(twoD *table, const char *str1)
{
    int len = table->at(table, table->rows - 1, table->cols - 1)->value;
    char *substr = new_string(len + 1);
    substr[len] = '\n';

    int i = table->rows - 1,
        j = table->cols - 1;

    while(i > 0 && j > 0)
    {
        if(table->at(table, i, j)->direction == left)
            --j;

        else if(table->at(table, i, j)->direction == above)
            --i;
        else
        {
            substr[--len] = str1[i - 1];
            --i;
            --j;
        }
    }

    return substr;
}

char *lcs(const char *str1, const char *str2)
{
    int len1 = strlen(str1),
        len2 = strlen(str2);

    twoD *table = create_2D_array(len1 + 1, len2 + 1);

    for(int i = 0; i <= len1; ++i)
    {
        table->at(table, i, 0)->value = 0;
        table->at(table, i, 0)->direction = null;
    }

    for(int j = 0; j <= len2; ++j)
    {
        table->at(table, 0, j)->value = 0;
        table->at(table, 0, j)->direction = null;
    }

    for(int i = 1; i <= len1; ++i)
    {
        for(int j = 1; j <= len2; ++j)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                table->at(table, i, j)->value = table->at(table, i - 1, j - 1)->value + 1;
                table->at(table, i, j)->direction = diagonal;
            }

            else
            {
                int above_val = table->at(table, i - 1, j)->value,
                    left_val = table->at(table, i, j - 1)->value;

                table->at(table, i, j)->value = above_val >= left_val ? above_val : left_val;
                table->at(table, i, j)->direction = above_val >= left_val ? above : left;
            }
        }
    }

    char *substr = get_lcs_str(table, str1);

#ifdef SHOW_TABLE
    printf("\nTable:\n");
    table->print(table);
    printf("\n");
#endif

    free_twoD(table);
    table = NULL;

    return substr;
}

int main(void)
{
    char str1[100],
        str2[100];

    printf("Enter string1: ");
    scanf("%99s", str1);

    printf("Enter string2: ");
    scanf("%99s", str2);

    char *longest_common_substring = lcs(str1, str2);
    printf("String: %s", longest_common_substring);

    free(longest_common_substring);
    return 0;
}
