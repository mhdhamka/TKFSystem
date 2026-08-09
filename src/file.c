#include "tkf.h"

void saveTransaction(Customer customer)
{
    FILE *file;

    file = fopen("TransactionRecord.txt", "a");

    if(file == NULL)
    {
        printf("\n  " COLOR_RED "[!] Unable to open transaction file for saving." COLOR_RESET "\n");
        return;
    }

    fprintf(file, "\n");
    fprintf(file, "  ╭────────────────────────────────────────────────────────╮\n");
    fprintf(file, "  │               TKF KOREAN RESTAURANT ARCHIVE            │\n");
    fprintf(file, "  ├────────────────────────────────────────────────────────┤\n");
    fprintf(file, "  │ Receipt No     : %-37s │\n", customer.receiptNo);
    fprintf(file, "  │ Member Status  : %-37s │\n", customer.memberStatus);
    fprintf(file, "  │ Order Method   : %-37s │\n", customer.orderMethod);
    fprintf(file, "  │ Payment Method : %-37s │\n", customer.paymentMethod);
    fprintf(file, "  ├──────┬──────────────────────────┬──────────┬───────┬─────────────┤\n");
    fprintf(file, "  │ %-4s │ %-24s │ %-8s │ %-5s │ %-11s │\n", "No", "Item", "Size", "Qty", "Total");
    fprintf(file, "  ├──────┼──────────────────────────┼──────────┼───────┼─────────────┤\n");

    for(int i = 0; i < customer.cartCount; i++)
    {
        fprintf(file, "  │ %-4d │ %-24s │ %-8s │ %-5d │ RM%-9.2f │\n",
                i + 1,
                customer.cart[i].foodName,
                customer.cart[i].size,
                customer.cart[i].quantity,
                customer.cart[i].totalPrice);
    }

    fprintf(file, "  ├──────┴──────────────────────────┴──────────┴───────┴─────────────┤\n");
    fprintf(file, "  │ Subtotal                        : RM %18.2f │\n", customer.subtotal);
    fprintf(file, "  │ Member Discount                 : RM %18.2f │\n", customer.discount);
    fprintf(file, "  │ Service Tax                     : RM %18.2f │\n", customer.serviceTax);
    fprintf(file, "  │ Government Tax                  : RM %18.2f │\n", customer.governmentTax);
    fprintf(file, "  ├────────────────────────────────────────────────────────┤\n");
    fprintf(file, "  │ FINAL TOTAL                     : RM %18.2f │\n", customer.finalTotal);
    fprintf(file, "  │ Amount Paid                     : RM %18.2f │\n", customer.payment);
    fprintf(file, "  │ Change                          : RM %18.2f │\n", customer.change);
    fprintf(file, "  ╰────────────────────────────────────────────────────────╯\n");

    fclose(file);

    printf("\n  " COLOR_GREEN "✔ Transaction recorded and saved successfully." COLOR_RESET "\n");
}

void viewTransaction()
{
    FILE *file;
    char line[300];

    file = fopen("TransactionRecord.txt", "r");

    if(file == NULL)
    {
        printf("\n  " COLOR_RED "[!] No transaction history archive found." COLOR_RESET "\n");
        return;
    }

    printf("\n");
    printf(COLOR_CYAN "  ╭────────────────────────────────────────────────────────╮\n");
    printf("  │               " COLOR_YELLOW COLOR_BOLD "TRANSACTION HISTORY ARCHIVE" COLOR_CYAN "              │\n");
    printf("  ╰────────────────────────────────────────────────────────╯\n" COLOR_RESET);

    while(fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);
}
