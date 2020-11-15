#include <iostream>

using std::cout;
using std::cin;

int main() {
    
    int guests = 0;
    int SpookyCake = 0, PumpkinPie = 0, CaramelApple = 0, CandyCorn = 0;
    
    cin >> guests;
    
    for (int i = guests; i >= 0; i--) {
        if ( guests >= 9 ) {
            SpookyCake++;
            guests -= 9;
        }
    }
    cout << "Cake: " << SpookyCake << '\n';
    
    for (int i = guests; i >= 0; i--) {
        if ( guests >= 5 ) {
            PumpkinPie++;
            guests -= 5;
        }
    }
    cout << "Pie: " << PumpkinPie << '\n';
    
    for (int i = guests; i >= 0; i--) {
        if ( guests >= 2 ) {
            CaramelApple++;
            guests -= 2;
        }
    }
    cout << "Apple: " << CaramelApple << '\n';
    
    for (int i = guests; i >= 0; i--) {
        if ( guests >= 1 ) {
            CandyCorn++;
            guests -= 1;
        }
    }
    cout << "Corn: " << CandyCorn << '\n';
    
    return 0;
}
