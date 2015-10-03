#include <stdio.h>
#include <cs50.h>

// printf ANSI colors
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

// constants
#define MAX_LIMIT 200

// prototypes
bool is_input_valid(int argc, string argv[]);

int main(int argc, string argv[])
{
    // bad input
    if (!is_input_valid(argc, argv))
    {
        printf(COLOR_RED);
        printf("Usage: <optional min> <max>\n");
        printf("(Integers from 1 - %i) \n", MAX_LIMIT);
        printf(COLOR_RESET);

        // failure
        return 1;
    }

    // set min and max
    int min = 0;
    int max = 0;

    // only max provided
    if (argc == 2)
    {
        min = 0;
        max = atoi(argv[1]);
    }

    // min and max provided
    if (argc == 3)
    {
        min = atoi(argv[1]);
        max = atoi(argv[2]);

        // min is always the smaller number
        if (max < min)
        {
            // swap
            int temp = min;
            min = max;
            max = temp;
        }
    }

    // debug
    printf(COLOR_GREEN);
    printf("recursive sum! \n");
    printf("min: %i \n", min);
    printf("max: %i \n", max);
    printf(COLOR_RESET);

    // success
    return 0;
}

bool is_input_valid(int argc, string argv[])
{
    // require filename and max. allow optional min.
    if (argc < 2 || argc > 3)
    {
        return false;
    }
    // min and max
    if (argc == 3)
    {
        int min = atoi(argv[1]);
        int max = atoi(argv[2]);
        // values too small or not ints
        if (min < 1 || max < 1)
        {
            return false;
        }
        // values too high
        if (min > MAX_LIMIT || max > MAX_LIMIT)
        {
            return false;
        }
    }
    // max only
    else
    {
        int max = atoi(argv[1]);
        if (max < 1 || max > 100)
        {
            return false;
        }
    }
    // success
    return true;
}