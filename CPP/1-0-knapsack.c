#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void log_exit(const char *msg, int err_no)
{
    fprintf(stdin, "%s\n", msg);
    exit(err_no);
}

typedef struct item
{
    int weight;
    int value;
} item;

void input_arr(item *arr, int length)
{
    for(int i = 0; i < length; ++i)
        scanf("%d %d", &arr[i].value, &arr[i].weight);
}

void print_arr(item *arr, int length)
{
    printf("[value:weight]\n");

    for(int i = 0; i < length; ++i)
        printf("[%d:%d] ", arr[i].value, arr[i].weight);

    printf("\n");
}

item *create_item_arr(int length)
{
    item *arr = malloc(length * sizeof(*arr));

    if(!arr)
        log_exit("Failed to create array.", 1);

    return arr;
}

typedef struct twoD
{
    int *arr;
    int rows, cols;
    int *(*at)(struct twoD *, int, int);
    void (*print)(struct twoD *);
} twoD;

int *get_2D_index(twoD *arr, int i, int j)
{
    return &arr->arr[(i * (arr->cols) + j)];
}

void print_2D(twoD *arr)
{
    for(int i = 0; i < arr->rows; ++i)
    {
        for(int j = 0; j < arr->cols; ++j)
            printf("%d ", *arr->at(arr, i, j));

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

void print_items_in_knapsack(twoD *table, item *items, int profit)
{
    int i = table->rows - 1,
        j = table->cols - 1;

    while(i > 0 && j > 0)
    {
        while(j > 0 && *table->at(table, i, j) != profit)
            --j;

        if(j <= 0)
            break;

        if(*table->at(table, i, j) != *table->at(table, i - 1, j))
        {
            printf("[%d %d] ", items[i - 1].value, items[i - 1].weight);
            profit -= items[i - 1].value;
        }

        --i;
    }

    printf("\n");
}

int max_profit(item *arr, int length, int capacity)
{
    twoD *table = create_2D_array(length + 1, capacity + 1);

    for(int i = 0; i < table->rows; ++i)
        *table->at(table, i, 0) = 0;

    for(int j = 0; j < table->cols; ++j)
        *table->at(table, 0, j) = 0;

    for(int i = 1; i < table->rows; ++i)
    {
        for(int j = 1; j < table->cols; ++j)
        {
            int weight = arr[i - 1].weight,
                value = arr[i - 1].value,
                col_above = *table->at(table, i - 1, j),
                other_val = j - weight >= 0 ? value + *table->at(table, i - 1, j - weight) : INT_MIN;

            *table->at(table, i, j) = col_above > other_val ? col_above : other_val;
        }
    }

    int stonks = *table->at(table, table->rows - 1, table->cols - 1);

#ifdef SHOW_TABLE
    printf("\nTable:\n");
    table->print(table);
    printf("\n");
#endif

    printf("Items chosen: [value:weight]\n");
    print_items_in_knapsack(table, arr, stonks);

    free_twoD(table);
    return stonks;
}

int main(void)
{
    int length;
    printf("Enter number of items: ");
    scanf("%d", &length);

    item *arr = create_item_arr(length);
    printf("Enter value followed by weight for %d items:\n", length);
    input_arr(arr, length);

    int knapsack_capacity;
    printf("Enter capacity of knapsack: ");
    scanf("%d", &knapsack_capacity);

    printf("Max profit: %d\n", max_profit(arr, length, knapsack_capacity));

    free(arr);
    return 0;
}
