#include "tkf.h"

void initializeMenu(Menu menu[], int *menuCount)
{
    Menu defaultMenu[] =
    {
        {1, "Bibimbap", "Rice", 10.00, 15.00, 0},
        {2, "Korean Fried Chicken", "Chicken", 9.00, 14.00, 0},
        {3, "Bulgogi", "Meat", 8.50, 13.50, 0},
        {4, "Japchae", "Noodles", 8.50, 13.50, 0},
        {5, "Hameul Pajeon", "Pancake", 7.00, 12.00, 0}
    };

    int size = sizeof(defaultMenu) / sizeof(defaultMenu[0]);

    for(int i = 0; i < size; i++)
    {
        menu[i] = defaultMenu[i];
    }

    *menuCount = size;
}

void displayMenu(Menu menu[], int menuCount)
{
    printf("\n");
    printf(COLOR_CYAN "  ╭────────────────────────────────────────────────────────────╮\n");
    printf("  │                    " COLOR_YELLOW COLOR_BOLD "TKF FOOD MENU" COLOR_CYAN "                           │\n");
    printf("  ├──────┬──────────────────────────────┬──────────────┬─────────┬─────────┤\n");
    printf("  │ " COLOR_BOLD "%-4s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-28s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-12s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-7s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-7s" COLOR_RESET COLOR_CYAN " │\n", 
           "ID", "Food Name", "Category", "Regular", "Large");
    printf("  ├──────┼──────────────────────────────┼──────────────┼─────────┼─────────┤\n");

    for(int i = 0; i < menuCount; i++)
    {
        printf("  │ %-4d │ %-28s │ %-12s │ RM%-5.2f │ RM%-5.2f │\n",
               menu[i].id,
               menu[i].name,
               menu[i].category,
               menu[i].regularPrice,
               menu[i].largePrice);
    }

    printf("  ╰──────┴──────────────────────────────┴──────────────┴─────────┴─────────╯\n" COLOR_RESET);
}

void searchMenu(Menu menu[], int menuCount)
{
    char keyword[50];

    printf("\n  " COLOR_BOLD COLOR_BLUE "➜ Enter food name to search: " COLOR_RESET);
    fgets(keyword, sizeof(keyword), stdin);

    keyword[strcspn(keyword, "\n")] = '\0';

    int found = 0;

    printf("\n");
    printf(COLOR_CYAN "  ╭────────────────────────────────────────╮\n");
    printf("  │            " COLOR_YELLOW COLOR_BOLD "SEARCH RESULTS" COLOR_CYAN "              │\n");
    printf("  ╰────────────────────────────────────────╯\n" COLOR_RESET);

    for(int i = 0; i < menuCount; i++)
    {
        if(strstr(menu[i].name, keyword) != NULL)
        {
            printf("  " COLOR_GREEN "[ID: %d]" COLOR_RESET " " COLOR_BOLD "%s" COLOR_RESET " " COLOR_DIM "(Category: %s)" COLOR_RESET "\n",
                   menu[i].id,
                   menu[i].name,
                   menu[i].category);
            printf("          Regular Price : " COLOR_YELLOW "RM%.2f" COLOR_RESET "\n", menu[i].regularPrice);
            printf("          Large Price   : " COLOR_YELLOW "RM%.2f" COLOR_RESET "\n", menu[i].largePrice);
            printf("  " COLOR_CYAN "  ──────────────────────────────────────" COLOR_RESET "\n");

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("  " COLOR_RED "[!] No matching food items found for \"%s\".\n" COLOR_RESET, keyword);
    }
}
