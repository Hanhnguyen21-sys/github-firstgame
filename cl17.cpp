#include <iostream>
#include <iomanip>
using namespace std;
// prototypes of functions
void getInput(string&, int&, int&);
void calcBill(int, int, int&, float&);
void displayBill(string,int ,float);
int main()
{
    char again;
    do // start do-while loop to take and display data many times
    {
    // declare variables
    string name=" ";
    int current=0, previous=0;
    float total;
    int gallon; 
    // call functions
    cout << setprecision(2) << fixed;
    getInput(name,current,previous);
    calcBill(current,previous,gallon,total);
    displayBill(name, gallon ,total);
    cout << "Another customer? Y to continue: ";
    cin >> again;
    again = toupper(again);
    cin.ignore(); // delete the enter key
    } while (again =='Y');
    cout << "Coded by Nguyen" << endl;
    cout << "New edition";
    return 0;
}
// defining functions
void getInput(string&cname, int&cur, int&pre)
{
    // prompt for name, current and previous readings
    cout << "Enter customer name: ";
    getline(cin,cname); // need to be getline instead of cin>>cname to read name with sapces
    cout << "Enter current reading: ";
    cin >> cur;
    cout << "Enter previous reading: ";
    cin >> pre;
    while (cur < pre) //validate number
    {
        cout << "Current value should be larger than previous value! Re-Enter" << endl;
        cout << "Enter current reading: ";
        cin >> cur;
        cout << "Enter previous reading: ";
        cin >> pre;
    }
}
void calcBill(int cur, int pre , int& gal, float& amount)
{
    // calculate total gallons used
    gal = cur-pre;
    // calcualte total charge
    amount = gal*.00175;
}
void displayBill(string cname,int gal ,float amount)
{
    // display name
    cout << "Water Bill for " << cname <<endl;
    // display total gallons
    cout << "Total gallons used: " << gal << endl;
    // display total charge
    cout << "Total Charge: $" << amount << endl;
}
