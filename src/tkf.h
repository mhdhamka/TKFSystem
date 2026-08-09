#ifndef TKF_H
#define TKF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

// ANSI Color & Style Codes for Modern UI
#define COLOR_RESET     "\033[0m"
#define COLOR_BOLD      "\033[1m"
#define COLOR_DIM       "\033[2m"
#define COLOR_CYAN      "\033[36m"
#define COLOR_GREEN     "\033[32m"
#define COLOR_YELLOW    "\033[33m"
#define COLOR_RED       "\033[31m"
#define COLOR_MAGENTA   "\033[35m"
#define COLOR_BLUE      "\033[34m"

#define MAX_MENU 50
#define MAX_CART 20
#define MAX_CUSTOMER 100


/* ============================
        MENU STRUCTURE
   ============================ */

typedef struct
{
    int id;
    char name[50];
    char category[30];
    float regularPrice;
    float largePrice;
    int quantitySold;

} Menu;


/* ============================
        CART STRUCTURE
   ============================ */

typedef struct
{
    int menuID;
    char foodName[50];
    char size[10];
    int quantity;
    float price;
    float totalPrice;

} CartItem;


/* ============================
        CUSTOMER STRUCTURE
   ============================ */

typedef struct
{
    char receiptNo[20];
    char memberStatus[20];
    char orderMethod[20];
    char paymentMethod[20];

    CartItem cart[MAX_CART];

    int cartCount;
    float subtotal;
    float discount;
    float serviceTax;
    float governmentTax;
    float finalTotal;
    float payment;
    float change;
    char dateTime[50];

} Customer;


/* ============================
        MENU FUNCTIONS
   ============================ */

void initializeMenu(Menu menu[], int *menuCount);
void displayMenu(Menu menu[], int menuCount);
void searchMenu(Menu menu[], int menuCount);


/* ============================
        ORDER FUNCTIONS
   ============================ */

void addToCart(Customer *customer, Menu menu[], int menuCount);
void removeFromCart(Customer *customer);
void displayCart(Customer customer);



/* ============================
        PAYMENT FUNCTIONS
   ============================ */

void calculateBill(Customer *customer);
void paymentProcess(Customer *customer);


/* ============================
        RECEIPT FUNCTIONS
   ============================ */

void generateReceipt(Customer customer);
void printReceipt(Customer customer);


/* ============================
        ADMIN FUNCTIONS
   ============================ */

void adminPanel(Menu menu[], int *menuCount);
void addMenuItem(Menu menu[], int *menuCount);
void updateMenuPrice(Menu menu[], int menuCount);
void deleteMenuItem(Menu menu[], int *menuCount);
void salesReport(Menu menu[], int menuCount);


/* ============================
        FILE FUNCTIONS
   ============================ */

void saveTransaction(Customer customer);

void viewTransaction();


/* ============================
        UTILITY FUNCTIONS
   ============================ */

void getCurrentDateTime(char buffer[]);
void clearInputBuffer();
void clearScreen();
void printHeader(const char* title);

#endif
