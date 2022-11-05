#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  string customer = "";
  string orderList = "";
  float total = 0;
  float cash = 0;
  float change = 0;
  
  cout << "Enter Customer Name: ";
  cin >> customer;

  cout << endl << "Welcome, " << customer << "!";
  cout << endl << "MENU" << endl;
  cout << "1 - Spaghetti (60.00)" << endl;
  cout << "2 - Burger (50.00)" << endl;
  cout << "3 - Fries (35.00)" << endl;
  cout << "4 - Drinks (25.00)" << endl;
  
  char addOrder = 'N';
  do {
      int order = 0;
      float price = 0;
      string item = "";
      
      int qty = 0;
      
      string orderTxt = "";
      float itemTotal = 0;
      
      bool validOrder = true;
      
      cout << endl << "Please choose your order: ";
      cin >> order;
      cout << endl << "Qty: ";
      cin >> qty;
      
      switch (order){
          case 1:
            price = 60.00;
            item = "Spaghetti";
            break;
          case 2:
            price = 50.00;
            item = "Burger";
            break;
          case 3:
            price = 35.00;
            item = "Fries";
            break;
          case 4:
            price = 25.00;
            item = "Drinks";
            break;
          default:
            validOrder = false;
      }
      
      if (validOrder){
          itemTotal = price * qty;
          orderTxt = item + " - " + to_string(price) + " x " + to_string(qty) + " = " + to_string(itemTotal) + "\n";
      
          orderList = orderList + orderTxt;
          total = total + itemTotal;
      }
      else {
          cout << endl << "Invalid Order!";
      }
      
      cout << endl << "Do you want to add more orders? [Y/N] ";
      cin >> addOrder;
      cout << endl;
  } while (addOrder == 'Y');
  
  
  cout << endl << "YOUR ORDERS: "<< endl << orderList;
  cout << endl << "Total: " << total;
  cout << endl << "Cash: ";
  cin >> cash;
  
  change = cash - total;
  cout << endl << "Change: " << change;

  return 0;
}