#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string customerArray[5] = {"Christian", "Chris", "Xtian", "Chan", "Xian"};
string menuArray[4][2] = {
  { "Spaghetti", "60.00" },
  { "Burger", "50.00" },
  { "Fries", "35.00" },
  { "Drinks", "25.00" }
};

bool validCustomer(string customer) {
  bool validCustomer = false;
  for (int i = 0; i < 5; i++) {
    if (customerArray[i] == customer) {
      validCustomer = true;
    }
  }

  return validCustomer;
}

void printMenu() {
  for (int i = 0; i < 4; i++) {
    cout << to_string(i) << " - " << menuArray[i][0] << " (" << menuArray[i][1] << ")" << endl;
  }
}

string getItem(int order){
  return menuArray[order][0];
}

float getPrice(int order){
  return stof(menuArray[order][1]);
}


int main() {
  string customer = "";
  string orderList = "";
  float total = 0;
  float cash = 0;
  float change = 0;
  
  cout << "Enter Customer Name: ";
  cin >> customer;

  if (!validCustomer(customer)) {
    cout << endl << "Invalid Customer!";
    return 0;
  }

  cout << endl << "Welcome, " << customer << "!";
  cout << endl << "MENU" << endl;
  printMenu();
  
  char addOrder = 'N';
  do {
      int order = 0;      
      int qty = 0;
      
      string orderTxt = "";
      float itemTotal = 0;
      
      bool validOrder = true;
      
      cout << endl << "Please choose your order: ";
      cin >> order;
      cout << endl << "Qty: ";
      cin >> qty;

      if (order < 4 && order >= 0){
          string item = getItem(order);
          float price = getPrice(order);

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