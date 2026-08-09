#include "tkf.h"

void addToCart(Customer *customer, Menu menu[], int menuCount)
{
    int choice;
    int quantity;
    char size[10];

    if(customer->cartCount >= MAX_CART)
    {
        printf("\n  " COLOR_RED "[!] Cart is full. Cannot add more items." COLOR_RESET "\n");
        return;
    }

    printf("\n  " COLOR_BOLD COLOR_BLUE "➜ Enter menu ID to add: " COLOR_RESET);
    scanf("%d", &choice);
    clearInputBuffer();

    if(choice < 1 || choice > menuCount)
    {
        printf("  " COLOR_RED "[!] Invalid menu selection. Please try again." COLOR_RESET "\n");
        return;
    }

    printf("  " COLOR_BOLD COLOR_BLUE "➜ Choose size (R - Regular / L - Large): " COLOR_RESET);
    scanf("%s", size);
    clearInputBuffer();

    printf("  " COLOR_BOLD COLOR_BLUE "➜ Enter quantity: " COLOR_RESET);
    scanf("%d", &quantity);
    clearInputBuffer();

    float price;

    if(size[0]=='R' || size[0]=='r')
    {
        strcpy(size, "Regular");
        price = menu[choice-1].regularPrice;
    }
    else if(size[0]=='L' || size[0]=='l')
    {
        strcpy(size, "Large");
        price = menu[choice-1].largePrice;
    }
    else
    {
        printf("  " COLOR_RED "[!] Invalid size choice." COLOR_RESET "\n");
        return;
    }

    CartItem *item = &customer->cart[customer->cartCount];

    item->menuID = menu[choice-1].id;
    strcpy(item->foodName, menu[choice-1].name);
    strcpy(item->size, size);
    item->quantity = quantity;
    item->price = price;
    item->totalPrice = price * quantity;

    customer->cartCount++;

    printf("\n  " COLOR_GREEN "✔ Successfully added %dx %s (%s) to your cart!" COLOR_RESET "\n", 
           item->quantity, item->foodName, item->size);
}

void removeFromCart(Customer *customer)
{
    int remove;

    if(customer->cartCount == 0)
    {
        printf("\n  " COLOR_RED "[!] Cart is already empty." COLOR_RESET "\n");
        return;
    }

    displayCart(*customer);

    printf("\n  " COLOR_BOLD COLOR_BLUE "➜ Enter item number to remove: " COLOR_RESET);
    scanf("%d", &remove);
    clearInputBuffer();

    if(remove < 1 || remove > customer->cartCount)
    {
        printf("  " COLOR_RED "[!] Invalid selection number." COLOR_RESET "\n");
        return;
    }

    for(int i = remove - 1; i < customer->cartCount - 1; i++)
    {
        customer->cart[i] = customer->cart[i+1];
    }

    customer->cartCount--;

    printf("\n  " COLOR_GREEN "✔ Item removed successfully from cart." COLOR_RESET "\n");
}

void displayCart(Customer customer)
{
    printf("\n");
    printf(COLOR_CYAN "  ╭────────────────────────────────────────────────────╮\n");
    printf("  │                    " COLOR_YELLOW COLOR_BOLD "SHOPPING CART" COLOR_CYAN "                   │\n");
    printf("  ├──────┬──────────────────────────┬──────────┬───────┬─────────────┤\n");
    printf("  │ " COLOR_BOLD "%-4s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-24s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-8s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-5s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-11s" COLOR_RESET COLOR_CYAN " │\n", 
           "No", "Food Name", "Size", "Qty", "Price");
    printf("  ├──────┼──────────────────────────┼──────────┼───────┼─────────────┤\n");

    if(customer.cartCount == 0)
    {
        printf("  │                   " COLOR_DIM "Your cart is empty" COLOR_RESET COLOR_CYAN "              │\n");
        printf("  ╰──────┴──────────────────────────┴──────────┴───────┴─────────────╯\n" COLOR_RESET);
        return;
    }

    for(int i = 0; i < customer.cartCount; i++)
    {
        printf("  │ %-4d │ %-24s │ %-8s │ %-5d │ RM%-9.2f │\n",
               i + 1,
               customer.cart[i].foodName,
               customer.cart[i].size,
               customer.cart[i].quantity,
               customer.cart[i].totalPrice);
    }

    printf("  ╰──────┴──────────────────────────┴──────────┴───────┴─────────────╯\n" COLOR_RESET);
}
