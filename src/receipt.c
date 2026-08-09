#include "tkf.h"

void getCurrentDateTime(char buffer[])
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(buffer, 50, "%d/%m/%Y %H:%M:%S", t);
}

void generateReceipt(Customer customer)
{
    /* Reserved for future use if you want
       automatic receipt number generation */
}

void printReceipt(Customer customer)
{
    char dateTime[50];
    getCurrentDateTime(dateTime);

    printf("\n");
    printf(COLOR_CYAN "  ╭────────────────────────────────────────────────────────╮\n");
    printf("  │               " COLOR_YELLOW COLOR_BOLD "TKF KOREAN RESTAURANT RECEIPT" COLOR_CYAN "            │\n");
    printf("  ├────────────────────────────────────────────────────────┤\n");
    printf("  │ " COLOR_DIM "Date & Time    :" COLOR_RESET " %-37s " COLOR_CYAN "│\n", dateTime);
    printf("  │ " COLOR_DIM "Receipt No     :" COLOR_RESET " %-37s " COLOR_CYAN "│\n", customer.receiptNo);
    printf("  │ " COLOR_DIM "Member Status  :" COLOR_RESET " %-37s " COLOR_CYAN "│\n", customer.memberStatus);
    printf("  │ " COLOR_DIM "Order Method   :" COLOR_RESET " %-37s " COLOR_CYAN "│\n", customer.orderMethod);
    printf("  │ " COLOR_DIM "Payment Method :" COLOR_RESET " %-37s " COLOR_CYAN "│\n", customer.paymentMethod);
    printf("  ├──────┬──────────────────────────┬──────────┬───────┬─────────────┤\n");
    printf("  │ " COLOR_BOLD "%-4s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-24s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-8s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-5s" COLOR_RESET COLOR_CYAN " │ " COLOR_BOLD "%-11s" COLOR_RESET COLOR_CYAN " │\n", 
           "No", "Item", "Size", "Qty", "Total");
    printf("  ├──────┼──────────────────────────┼──────────┼───────┼─────────────┤\n");

    for (int i = 0; i < customer.cartCount; i++)
    {
        printf("  │ %-4d │ %-24s │ %-8s │ %-5d │ RM%-9.2f │\n",
               i + 1,
               customer.cart[i].foodName,
               customer.cart[i].size,
               customer.cart[i].quantity,
               customer.cart[i].totalPrice);
    }

    printf("  ├──────┴──────────────────────────┴──────────┴───────┴─────────────┤\n");
    printf("  │ Subtotal                        : RM %18.2f │\n", customer.subtotal);
    printf("  │ Member Discount                 : RM %18.2f │\n", customer.discount);
    printf("  │ Service Tax                     : RM %18.2f │\n", customer.serviceTax);
    printf("  │ Government Tax                  : RM %18.2f │\n", customer.governmentTax);
    printf("  ├────────────────────────────────────────────────────────┤\n");
    printf("  │ " COLOR_BOLD "TOTAL                           : RM %18.2f" COLOR_RESET COLOR_CYAN " │\n", customer.finalTotal);
    printf("  │ Amount Paid                     : RM %18.2f │\n", customer.payment);
    printf("  │ Change                          : RM %18.2f │\n", customer.change);
    printf("  ╰────────────────────────────────────────────────────────╯\n" COLOR_RESET);

    printf("\n  " COLOR_GREEN "✔ Thank you for dining with TKF Restaurant!" COLOR_RESET "\n");
}
