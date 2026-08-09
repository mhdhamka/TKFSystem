#include "tkf.h"

int main()
{
    #if defined(_WIN32) || defined(_WIN64)
        SetConsoleOutputCP(65001);
    #endif

    Menu menu[MAX_MENU];
    int menuCount = 0;
    Customer customers[MAX_CUSTOMER];
    int customerCount = 0;
    int choice;

    initializeMenu(menu, &menuCount);

    do
    {
        clearScreen();
        printf("\n");
        printHeader("TKF KOREAN RESTAURANT");
        
        printf("\n");
        printf("  " COLOR_CYAN "┌──────────────────────────────────────┐" COLOR_RESET "\n");
        printf("  " COLOR_CYAN "│" COLOR_GREEN "  [1] " COLOR_RESET "⚡ New Customer Order         " COLOR_CYAN "│" COLOR_RESET "\n");
        printf("  " COLOR_CYAN "│" COLOR_GREEN "  [2] " COLOR_RESET "📋 Browse Full Menu           " COLOR_CYAN "│" COLOR_RESET "\n");
        printf("  " COLOR_CYAN "│" COLOR_GREEN "  [3] " COLOR_RESET "🔍 Search Food Item           " COLOR_CYAN "│" COLOR_RESET "\n");
        printf("  " COLOR_CYAN "│" COLOR_GREEN "  [4] " COLOR_RESET "📊 Transaction History        " COLOR_CYAN "│" COLOR_RESET "\n");
        printf("  " COLOR_CYAN "│" COLOR_GREEN "  [5] " COLOR_RESET "⚙️  Admin Control Panel       " COLOR_CYAN "│" COLOR_RESET "\n");
        printf("  " COLOR_CYAN "│" COLOR_RED   "  [6] " COLOR_RESET "🚪 Exit System                " COLOR_CYAN "│" COLOR_RESET "\n");
        printf("  " COLOR_CYAN "└──────────────────────────────────────┘" COLOR_RESET "\n");
        
        printf("\n  " COLOR_BOLD COLOR_BLUE "➜ Select Action [1-6]: " COLOR_RESET);
        
        scanf("%d", &choice);
        clearInputBuffer();

        switch(choice)
        {
            case 1:
            {
                clearScreen();
                printHeader("NEW ORDER CHECKOUT");
                Customer customer;
                customer.cartCount = 0;

                generateReceipt(customer);
                
                printf("\n  " COLOR_CYAN "┌─ Step 1: Customer Verification ──────┐" COLOR_RESET "\n");
                printf("  " COLOR_CYAN "│" COLOR_YELLOW " Are you a registered member? (Y/N): " COLOR_CYAN "│" COLOR_RESET "\n");
                printf("  " COLOR_CYAN "└──────────────────────────────────────┘" COLOR_RESET "\n");
                printf("  " COLOR_BOLD COLOR_BLUE "➜ Choice: " COLOR_RESET);

                char member;
                scanf("%c", &member);
                clearInputBuffer();

                if(member == 'Y' || member == 'y')
                {
                    strcpy(customer.memberStatus, "Member");
                    printf("  " COLOR_GREEN "✔ Member status applied successfully (Discounts enabled).\n" COLOR_RESET);
                }
                else
                {
                    strcpy(customer.memberStatus, "Non Member");
                    printf("  " COLOR_DIM "ℹ Standard guest checkout selected.\n" COLOR_RESET);
                }

                printf("\n  " COLOR_CYAN "┌─ Step 2: Dining Preference ──────────┐\n");
                printf("  " COLOR_CYAN "│" COLOR_RESET "  1. Dine-In                          " COLOR_CYAN "│" COLOR_RESET "\n");
                printf("  " COLOR_CYAN "│" COLOR_RESET "  2. Takeaway                         " COLOR_CYAN "│" COLOR_RESET "\n");
                printf("  " COLOR_CYAN "└──────────────────────────────────────┘" COLOR_RESET "\n");
                printf("  " COLOR_BOLD COLOR_BLUE "➜ Method: " COLOR_RESET);

                int method;
                scanf("%d", &method);
                clearInputBuffer();

                if(method == 1)
                {
                    strcpy(customer.orderMethod, "Dine-In");
                }
                else
                {
                    strcpy(customer.orderMethod, "Takeaway");
                }

                int orderChoice;
                do
                {
                    clearScreen();
                    printHeader("MENU & CART SELECTION");
                    displayMenu(menu, menuCount);
                    addToCart(&customer, menu, menuCount);

                    printf("\n  " COLOR_CYAN "┌──────────────────────────────────────┐" COLOR_RESET "\n");
                    printf("  " COLOR_CYAN "│" COLOR_YELLOW " Add another item to cart?           " COLOR_CYAN "│" COLOR_RESET "\n");
                    printf("  " COLOR_CYAN "│" COLOR_RESET "  1. Yes                              " COLOR_CYAN "│" COLOR_RESET "\n");
                    printf("  " COLOR_CYAN "│" COLOR_RESET "  2. Proceed to Checkout              " COLOR_CYAN "│" COLOR_RESET "\n");
                    printf("  " COLOR_CYAN "└──────────────────────────────────────┘" COLOR_RESET "\n");
                    printf("  " COLOR_BOLD COLOR_BLUE "➜ Action: " COLOR_RESET);
                    scanf("%d", &orderChoice);
                    clearInputBuffer();

                } while(orderChoice == 1);

                clearScreen();
                printHeader("BILLING & PAYMENT");
                displayCart(customer);
                calculateBill(&customer);
                paymentProcess(&customer);
                printReceipt(customer);
                saveTransaction(customer);

                customers[customerCount] = customer;
                customerCount++;
                
                printf("\n  " COLOR_GREEN "✔ Order completed successfully!" COLOR_RESET);
                printf("\n  " COLOR_DIM "Press Enter to return to the main dashboard..." COLOR_RESET);
                getchar();
                break;
            }

            case 2:
                clearScreen();
                printHeader("RESTAURANT MENU");
                displayMenu(menu, menuCount);
                printf("\n  " COLOR_GREEN "Press Enter to return to main menu..." COLOR_RESET);
                getchar();
                break;

            case 3:
                clearScreen();
                printHeader("MENU SEARCH ENGINE");
                searchMenu(menu, menuCount);
                printf("\n  " COLOR_GREEN "Press Enter to return to main menu..." COLOR_RESET);
                getchar();
                break;

            case 4:
                clearScreen();
                printHeader("TRANSACTION LOGS");
                viewTransaction();
                printf("\n  " COLOR_GREEN "Press Enter to return to main menu..." COLOR_RESET);
                getchar();
                break;

            case 5:
                clearScreen();
                printHeader("ADMIN CONTROL PANEL");
                adminPanel(menu, &menuCount);
                printf("\n  " COLOR_GREEN "Press Enter to return to main menu..." COLOR_RESET);
                getchar();
                break;

            case 6:
                clearScreen();
                printf("\n");
                printf(COLOR_MAGENTA "  ╭────────────────────────────────────────╮\n");
                printf("  │     Thank you for using TKF System!    │\n");
                printf("  │           Have a great day!            │\n");
                printf("  ╰────────────────────────────────────────╯\n\n" COLOR_RESET);
                break;

            default:
                printf("\n  " COLOR_RED "[!] Invalid choice. Please pick between 1 and 6." COLOR_RESET);
                printf("\n  " COLOR_DIM "Press Enter to continue..." COLOR_RESET);
                getchar();
        }
    } while(choice != 6);

    return 0;
}
