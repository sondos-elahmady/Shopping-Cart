#include <iostream>
using namespace std;
#define SIZE 5
int menu()
{
    int choice; 
    cout << "Menu:\n";
    cout << "1: Add items to the cart.\n";
    cout << "2: View all items in the cart.\n";
    cout << "3: Calculate the total price of items in the cart.\n";
    cout << "4: Remove an item by its index.\n";
    cout << "5: Exit program.\n";
    cin >> choice;
    return choice;
}
void addItem(string item[], float price[])
{
    cout << "Please input items names and prices\n";
    cout << "Name: Price:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << "  ";
        cin >> item[i] >> price[i];
    }
}
void viewItems(string item[], float price[])
{
    cout << "Name: Price:\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << item[i] << "       " << price[i] << endl;
    }
}
float calculateTotalPrice(float price[])
{
    float sum = 0;
    for (int i = 0; i < SIZE; i++)
        sum += price[i];
    return sum;
}
void removeItem(string item[], float price[])
{
    int index;
    cout << "Which item do you want to remove?\n";
    cout << "I want to remove item number: ";
    cin >> index;
    item[index - 1] = "Blank";
    price[index - 1] = 0;
}
int main()
{
    int choice;
    string item[SIZE];
    float price[SIZE];
    do
    {
        switch (choice=menu())
        {
        case 1: addItem(item, price); break;
        case 2: viewItems(item, price); break;
        case 3:
        { 
            cout << "Total price equals " << calculateTotalPrice(price) << endl;
            if (calculateTotalPrice(price)>5000)
                cout << "Total price after disscount equals " << calculateTotalPrice(price)*0.9 << endl;
            break;
        }
        case 4: removeItem(item, price); break;
        case 5: continue;
        default: cout << "Invalid input, try again"; continue;
        }
    } while (choice != 5);
    cout << "Thank You!\n";
    return 0;
}
