#include "tkf.h"

void adminPanel(Menu menu[], int *menuCount)
{
    int choice;

    do
    {
        clearScreen();
        printHeader("ADMIN CONTROL PANEL");

        printf("\n");
        printf("  " COLOR_CYAN "┌──────────────────────────────────────┐" COLOR_RESET "\n");
        printf("  " COLOR_CYAN "│" COLOR_GREEN "  [1] " COLOR_RESET "➕ Add New Menu Item           " COLOR_CYAN "│" COLOR_RESET "\n");
        printf("  " COLOR_CYAN "│" COLOR_GREEN "  [2] " COLOR_RESET "✏️  Update Menu Pricing         " COLOR_CYAN "│" COLOR_RESET "\n");
        printf("  " COLOR_CYAN "│" COLOR_GREEN "  [3] " COLOR_RESET "🗑️  Delete Menu Item           " COLOR_CYAN "│" COLOR_RESET "\n");
        printf("  " COLOR_CYAN "│" COLOR_GREEN "  [4] " COLOR_RESET "📈 View Sales Performance Report " COLOR_CYAN "│" COLOR_RESET "\n");
        printf("  " COLOR_CYAN "│" COLOR_RED   "  [5] " COLOR_RESET "↩️  Return to Main Menu        " COLOR_CYAN "│" COLOR_RESET "\n");
        printf("  " COLOR_CYAN "└──────────────────────────────────────┘" COLOR_RESET "\n");

        printf("\n  " COLOR_BOLD COLOR_BLUE "➜ Admin Action [1-5]: " COLOR_RESET);
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice)
        {
            case 1:
                clearScreen();
                printHeader("ADD MENU ITEM");
                addMenuItem(menu, menuCount);
                printf("\n  " COLOR_GREEN "Press Enter to continue..." COLOR_RESET);
                getchar();
                break;

            case 2:
                clearScreen();
                printHeader("UPDATE MENU PRICING");
                updateMenuPrice(menu, *menuCount);
                printf("\n  " COLOR_GREEN "Press Enter to continue..." COLOR_RESET);
                getchar();
                break;

            case 3:
                clearScreen();
                printHeader("DELETE MENU ITEM");
                deleteMenuItem(menu, menuCount);
                printf("\n  " COLOR_GREEN "Press Enter to continue..." COLOR_RESET);
                getchar();
                break;

            case 4:
                clearScreen();
                printHeader("SALES PERFORMANCE REPORT");
                salesReport(menu, *menuCount);
                printf("\n  " COLOR_GREEN "Press Enter to return to Admin panel..." COLOR_RESET);
                getchar();
                break;

            case 5:
                printf("\n  " COLOR_DIM "Returning to main dashboard..." COLOR_RESET "\n");
                break;

            default:
                printf("\n  " COLOR_RED "[!] Invalid option. Please choose between 1 and 5." COLOR_RESET);
                printf("\n  " COLOR_DIM "Press Enter to continue..." COLOR_RESET);
                getchar();
        }

    } while(choice != 5);
}

void addMenuItem(Menu menu[], int *menuCount)
{
    if(*menuCount >= MAX_MENU)
    {
        printf("\n  " COLOR_RED "[!] Menu storage capacity is full." COLOR_RESET "\n");
        return;
    }

    Menu newItem;
    newItem.id = *menuCount + 1;

    printf("\n  " COLOR_BOLD COLOR_BLUE "➜ Enter food name: " COLOR_RESET);
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = '\0';

    printf("  " COLOR_BOLD COLOR_BLUE "➜ Enter category: " COLOR_RESET);
    fgets(newItem.category, sizeof(newItem.category), stdin);
    newItem.category[strcspn(newItem.category, "\n")] = '\0';

    printf("  " COLOR_BOLD COLOR_BLUE "➜ Enter regular price (RM): " COLOR_RESET);
    scanf("%f", &newItem.regularPrice);

    printf("  " COLOR_BOLD COLOR_BLUE "➜ Enter large price (RM): " COLOR_RESET);
    scanf("%f", &newItem.largePrice);
    clearInputBuffer();

    newItem.quantitySold = 0;
    menu[*menuCount] = newItem;
    (*menuCount)++;

    printf("\n  " COLOR_GREEN "✔ Menu item added successfully!" COLOR_RESET "\n");
}

void updateMenuPrice(Menu menu[], int menuCount)
{
    int id;

    displayMenu(menu, menuCount);

    printf("\n  " COLOR_BOLD COLOR_BLUE "➜ Enter menu ID to update pricing: " COLOR_RESET);
    scanf("%d", &id);

    if(id < 1 || id > menuCount)
    {
        printf("  " COLOR_RED "[!] Invalid menu ID selection." COLOR_RESET "\n");
        return;
    }

    printf("  " COLOR_BOLD COLOR_BLUE "➜ Enter new regular price (RM): " COLOR_RESET);
    scanf("%f", &menu[id-1].regularPrice);

    printf("  " COLOR_BOLD COLOR_BLUE "➜ Enter new large price (RM): " COLOR_RESET);
    scanf("%f", &menu[id-1].largePrice);
    clearInputBuffer();

    printf("\n  " COLOR_GREEN "✔ Menu item pricing updated successfully!" COLOR_RESET "\n");
}

void deleteMenuItem(Menu menu[], int *menuCount)
{
    int id;

    displayMenu(menu, *menuCount);

    printf("\n  " COLOR_BOLD COLOR_BLUE "➜ Enter menu ID to delete: " COLOR_RESET);
    scanf("%d", &id);

    if(id < 1 || id > *menuCount)
    {
        printf("  " COLOR_RED "[!] Invalid menu ID selection." COLOR_RESET "\n");
        return;
    }

    for(int i = id - 1; i < (*menuCount) - 1; i++)
    {
        menu[i] = menu[i+1];
        menu[i].id = i + 1; // Re-index remaining elements
    }

    (*menuCount)--;

    printf("\n  " COLOR_GREEN "✔ Menu item deleted successfully." COLOR_RESET "\n");
}

void salesReport(Menu menu[], int menuCount)
{
    printf("\n");
    printf(COLOR_CYAN "  ╭──────────────────────────────────────────────────╮\n");
    printf("  │               " COLOR_YELLOW COLOR_BOLD "SALES PERFORMANCE REPORT" COLOR_CYAN "           │\n");
    printf("  ├──────┬──────────────────────────────────┬────────┤\n");
    printf("  │ " COLOR_BOLD "%-4s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-32s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-6s" COLOR_RESET COLOR_CYAN " │\n", "ID", "Food Name", "Sold");
    printf("  ├──────┼──────────────────────────────────┼────────┤\n");

    for(int i = 0; i < menuCount; i++)
    {
        printf("  │ %-4d │ %-32s │ %-6d │\n",
               menu[i].id,
               menu[i].name,
               menu[i].quantitySold);
    }

    printf("  ╰──────┴──────────────────────────────────┴────────╯\n" COLOR_RESET);
}
