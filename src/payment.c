#include "tkf.h"

void calculateBill(Customer *customer)
{
    customer->subtotal = 0.0f;

    /* Calculate subtotal */
    for (int i = 0; i < customer->cartCount; i++)
    {
        customer->subtotal += customer->cart[i].totalPrice;
    }

    /* Member discount */
    if (strcmp(customer->memberStatus, "Member") == 0)
    {
        customer->discount = customer->subtotal * 0.10f;
    }
    else
    {
        customer->discount = 0.0f;
    }

    /* Service tax (Dine-In only) */
    if (strcmp(customer->orderMethod, "Dine-In") == 0)
    {
        customer->serviceTax = (customer->subtotal - customer->discount) * 0.10f;
    }
    else
    {
        customer->serviceTax = 0.0f;
    }

    /* Government tax */
    customer->governmentTax =
        (customer->subtotal - customer->discount) * 0.06f;

    /* Final total */
    customer->finalTotal =
        customer->subtotal
        - customer->discount
        + customer->serviceTax
        + customer->governmentTax;
}

void paymentProcess(Customer *customer)
{
    int choice;

    printf("\n");
    printf(COLOR_CYAN "  ╭────────────────────────────────────╮\n");
    printf("  │          " COLOR_YELLOW COLOR_BOLD "PAYMENT PROCESSING" COLOR_CYAN "        │\n");
    printf("  ├────────────────────────────────────┤\n");
    printf("  │ " COLOR_GREEN "[1]" COLOR_RESET " 💵 Cash Payment                    " COLOR_CYAN "│\n");
    printf("  │ " COLOR_GREEN "[2]" COLOR_RESET " 💳 Debit / Credit Card             " COLOR_CYAN "│\n");
    printf("  │ " COLOR_GREEN "[3]" COLOR_RESET " 📱 E-Wallet                        " COLOR_CYAN "│\n");
    printf("  ╰────────────────────────────────────╯\n" COLOR_RESET);

    printf("\n  " COLOR_BOLD COLOR_BLUE "➜ Choose payment method [1-3]: " COLOR_RESET);
    scanf("%d", &choice);
    clearInputBuffer();

    switch (choice)
    {
        case 1:
            strcpy(customer->paymentMethod, "Cash");

            do
            {
                printf("  " COLOR_BOLD COLOR_BLUE "➜ Enter Cash Received (RM): " COLOR_RESET);
                scanf("%f", &customer->payment);
                clearInputBuffer();

                if (customer->payment < customer->finalTotal)
                {
                    printf("  " COLOR_RED "[!] Insufficient payment. Amount required is RM%.2f\n" COLOR_RESET, customer->finalTotal);
                }

            } while (customer->payment < customer->finalTotal);

            customer->change =
                customer->payment - customer->finalTotal;

            break;

        case 2:
            strcpy(customer->paymentMethod, "Card");
            customer->payment = customer->finalTotal;
            customer->change = 0.0f;
            printf("  " COLOR_GREEN "✔ Card payment processed successfully.\n" COLOR_RESET);
            break;

        case 3:
            strcpy(customer->paymentMethod, "E-Wallet");
            customer->payment = customer->finalTotal;
            customer->change = 0.0f;
            printf("  " COLOR_GREEN "✔ E-Wallet payment processed successfully.\n" COLOR_RESET);
            break;

        default:
            printf("  " COLOR_RED "[!] Invalid option. Please try again.\n" COLOR_RESET);
            paymentProcess(customer);
            return;
    }
}
