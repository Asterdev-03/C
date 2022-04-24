#include <stdio.h>

int main()
{
    // Initialzation
    int status = 1, quantity;
    float billAmount = 0.0;
    char itemNo;

    // Continue untill the purchase is over
    while (status == 1)
    {
        // Displaying the items that can be purchased
        printf("\n");
        printf("1. Pen  10/-\n");
        printf("2. Book  45.5/-\n");
        printf("3. A4 Sheets  1.5/-\n");
        printf("4. Graph Paper  2/-\n");
        printf("5. Water Bottle  50/-\n");
        printf("6. Watch  99.99/-\n");
        printf("Enter 'N' to end the purchase\n");

        // Input the item no
        printf("Enter the Item No. : ");
        scanf("%s", &itemNo);

        // Checks for the item no
        switch (itemNo)
        {
        case '1':
            printf("Enter Quantity : ");
            scanf("%d", &quantity);
            billAmount += 10 * quantity; // adds the (the price of the item * to its quantity) to the amount
            break;

        case '2':
            printf("Enter Quantity : ");
            scanf("%d", &quantity);
            billAmount += 40.5 * quantity;
            break;

        case '3':
            printf("Enter Quantity : ");
            scanf("%d", &quantity);
            billAmount += 1.5 * quantity;
            break;

        case '4':
            printf("Enter Quantity : ");
            scanf("%d", &quantity);
            billAmount += 2 * quantity;
            break;

        case '5':
            printf("Enter Quantity : ");
            scanf("%d", &quantity);
            billAmount += 50 * quantity;
            break;

        case '6':
            printf("Enter Quantity : ");
            scanf("%d", &quantity);
            billAmount += 99.9 * quantity;
            break;

        case 'N':
            status = 0; // changing status to 0 (or false) to stop the purchasing loop
            break;

        default:
            printf("Invalid Item No. !!!\tPlease enter the correct itemNo\n");
            break;
        }
    }

    // Displaying the total amount
    printf("\nBill : %f", billAmount);
    return 0;
}