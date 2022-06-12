// Programming Assignment 3
// Justin Smith

#include <iostream> // This program uses I/O streams
#include <string> // Using string objects
#include <fstream> // Need to output data to external txt file
#include <iomanip> // Needed to use format manipulators
#include <algorithm> // For changing case in strings 

using namespace std;

const double FRAGILE_FEE = 2.00; // Constants

// Program resides entirely within main function
int main()
{
    // Variable declarations
    string itemName;
    string destinationName;
    double orderTotal;
    double shippingCost;
    double totalWithShipping;
    string fragile;

    cout << "*******************************************************************************" << endl;
    cout << "******************** ITCS 2530 -- Programming Assignment 3 ********************" << endl;
    cout << "*******************************************************************************" << endl << endl;

    // Need to gather input from the user to find the name, fragility of the item, order total, and destination
    cout << setw(78) << left << setfill('.') << "Please enter the item name to be shipped (no spaces)" << ":";
    cin >> itemName;
    // Promt the user to ask if the item is fragile
    cout << setw(78) << left << setfill('.') << "Is the item fragile? (y=yes/n=no)" << ":";
    cin >> fragile;
    transform(fragile.begin(), fragile.end(), fragile.begin(), ::tolower); // Changes the string to lowercase to accept all cases
    if (!(fragile == "y" || fragile == "n")) // If incorrect value entered, exit program
    {
        cout << "Invalid entry, exiting" << endl;
        return 1;
    }
    // Prompt the user for their order total
    cout << setw(78) << left << setfill('.') << "Please enter your order total" << ":";
    cin >> orderTotal;
    // Prompt the user to enter the destination of the order
    cout << setw(78) << left << setfill('.') << "Please enter destination (usa/can/aus)" << ":";
    cin >> destinationName;
    transform(destinationName.begin(), destinationName.end(), destinationName.begin(), ::tolower); // Changes the string to lowercase to accept all cases
    if (!(destinationName == "usa" || destinationName == "can" || destinationName == "aus")) // If incorrect value entered, exit program
    {
        cout << "Invalid entry, exiting" << endl;
        return 1;
    }
    cout << endl;

    /*
    We need to find the shipping cost accounting for the destination. There are 4 tiers of shipping costs and 
    each tier is a different amount for each destinationThe following code uses selection structures (if/else) 
    to resolve the shipping cost and new total. I explored using a switch structure here instead but due to either 
    the expression being logical or not numerical like in the instance of looking at the usa/can/aus strings, I 
    that this was my best course for a selection structure.
    */
    if (orderTotal < 50.00)
        if (destinationName == "usa")
        {
            shippingCost = 6.00;
            totalWithShipping = shippingCost + orderTotal;
        }
        else if (destinationName == "can")
        {
            shippingCost = 8.00;
            totalWithShipping = shippingCost + orderTotal;
        }
        else
        {
            shippingCost = 10.00;
            totalWithShipping = shippingCost + orderTotal;
        }
    // Check for shipping cost if price between 50.01 and 100.00
    else if (orderTotal >= 50.01 && orderTotal <= 100.00)
        if (destinationName == "usa")
        {
            shippingCost = 9.00;
            totalWithShipping = shippingCost + orderTotal;
        }
        else if (destinationName == "can")
        {
            shippingCost = 12.00;
            totalWithShipping = shippingCost + orderTotal;
        }
        else
        {
            shippingCost = 14.00;
            totalWithShipping = shippingCost + orderTotal;
        }
    // check for shipping cost if order total between 100.01 and 150.0        
    else if (orderTotal >= 100.01 && orderTotal < 150.00)
        if (destinationName == "usa")
        {
            shippingCost = 12.00;
            totalWithShipping = shippingCost + orderTotal;
        }
        else if (destinationName == "can")
        {
            shippingCost = 15.00;
            totalWithShipping = shippingCost + orderTotal;
        }
        else
        {
            shippingCost = 17.00;
            totalWithShipping = shippingCost + orderTotal;
        }
    // There is no shipping cost for larger than 150.00 orders. Order total then equals order total
    else
    {
        shippingCost = 0;
        totalWithShipping = orderTotal;
    }
        

    // Need to finally add the fragile fee to our new total if applicable
    if (fragile == "y")
        totalWithShipping += FRAGILE_FEE;

                    
    cout << totalWithShipping << endl;

    system("pause");

    return 0;
}

