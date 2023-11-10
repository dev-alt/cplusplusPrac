#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

    void showBalance(double balance);
    double deposit();
    double withdraw(double balance);

int main(){
    double balance = 134.50;
    int choice = 0;

    do{
        cout << "***********************\n";
        cout << "Enter your choice:\n";
        cout << "***********************\n";
        cout << "1. Show balance:\n";
        cout << "2. Deposit Money:\n";
        cout << "3. Withdraw Money:\n";
        cout << "4. Exit:\n";
        cin >> choice;

        std::cin.clear();
        fflush(stdin);

        switch (choice) {

            case 1:
                showBalance(balance);
                break;
            case 2:
                balance += deposit();
                showBalance(balance);
                break;
            case 3:
                balance -= withdraw(balance);
                showBalance(balance);
                break;
            case 4: cout << "Thanks for visiting";
                break;
            default: cout << "Invalid choice";
        }
    }while(choice != 4);



return 0;

};
void showBalance(double balance){
cout<<"Your balance is: $" << std::setprecision(2) <<  std::fixed << balance << endl;
}
double deposit(){
    double amount = 0;
    cout << "Enter amount to deposit: $";
    cin >> amount;

    if(amount > 0){
        return amount;
    }
    else {
        cout << "Invalid amount\n";
        return 0;
    }

}
double withdraw(double balance){
    double amount = 0;
    cout << "Enter amount to withdraw: $";
    cin >> amount;
    if(amount > balance){
        cout << "Invalid amount\n";
        return 0;
    }
    else if (amount< 0){
        cout << "Invalid amount\n";
        return 0;
    }
    else{
        return amount;
    }

}