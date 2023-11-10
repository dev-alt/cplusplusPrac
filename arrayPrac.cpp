#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;


double getTotal(double prices[], int size);
int main(){

    double prices[] = {49.55, 2234.22, 434.211, 44.55, 43.11};

    //C++ ForLoop
    for(int price : prices){
        std::cout << price << std::endl;
    }

    int size = sizeof(prices)/sizeof(prices[0]);
    double total = getTotal(prices, size);
    cout << "$" << total;


    return 0;
};
double getTotal(double prices[], int size){
    double total = 0;

    for(int i = 0; i < size; i++){
        total += prices[i];
    }
    return total;
}