#include "tkf.h"

void clearInputBuffer()
{
    int c;

    while((c = getchar()) != '\n' && c != EOF);
}

void clearScreen() 
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

void printHeader(const char* title) 
{
    printf(COLOR_CYAN "  ╭────────────────────────────────────────╮\n");
    printf("  │          " COLOR_YELLOW COLOR_BOLD "%-22s" COLOR_CYAN "        │\n", title);
    printf("  │       " COLOR_RESET COLOR_DIM "Digital POS & Management System" COLOR_CYAN "  │\n");
    printf("  ╰────────────────────────────────────────╯\n" COLOR_RESET);
}
