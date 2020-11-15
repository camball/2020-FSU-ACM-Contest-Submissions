#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::cout;
using std::cin;
using std::string;

int calculate( std::vector<string> & );

int main()
{
    int p1Count = 0, p2Count = 0;
    int p1Size = 0, p2Size = 0;
    string input;
    char one;
    char two;
    std::vector <string> tokens1;
    std::vector <string> tokens2;
    
    cin >> p1Size;
    
    for (int i = 0; i < p1Size; i++) {
        cin >> one;
        cin >> two;
        
        input.push_back( one );
        input.push_back( two );
        tokens1.push_back( input );
        input.clear();
    }
    
    p1Count = calculate( tokens1 );
    
    
    
    cin >> p2Size;
    
    for (int i = 0; i < p2Size; i++) {
        cin >> one;
        cin >> two;
        
        input.push_back( one );
        input.push_back( two );
        tokens2.push_back( input );
        input.clear();
    }
    
    p2Count = calculate( tokens2 );
    
    
    if ( p1Count == p2Count )
        cout << "tie" << std::endl;
    else if ( p1Count > p2Count )
        cout << 1 << std::endl;
    else cout << 2 << std::endl;
    
    return 0;
}


int calculate( std::vector<string> & input) {
    int value = 0;
    for (int i = 0; i < input.size(); i++) {
        if ( input[i][0] == 'C' ) {
            if ( input[i][1] == 'L' )
                value += 16;
            else if ( input[i][1] == 'M' )
                value += 8;
            else value += 4;
        }
        
        if ( input[i][0] == 'G' ) {
            if ( input[i][1] == 'L' )
                value += 8;
            else if ( input[i][1] == 'M' )
                value += 4;
            else value += 2;
        }
        
        if ( input[i][0] == 'P' ) {
            if ( input[i][1] == 'L' )
                value += 4;
            else if ( input[i][1] == 'M' )
                value += 2;
            else value += 1;
        }
    }
    
    return value;
}

/*
 You both come to the agreement that
    2 Peanut candies are equal to a Gummy candy
    2 Gummy candy are equal to a Chocolate candy
 
 the size of the candy is important in determining who got the better selection.
 
 You both come to the agreement that
    2 Small candies are equal to 1 Medium candy
    2 Medium candies are equal to 1 Large candy
 
 Create a program that can calculate who got the better selection of candy, based on amount, type, and size of the candy.
 
 Hint: In order to calculate a ’value’ for each candy based on type and size, going up in size
 should double the value of the candy, and going up in rank for type of candy should double the value.
 */

/*
 LC = 16
 MC = 8
 SC = 4
 
 LG = 8
 MG = 4
 SG = 2
 
 LP = 4
 MP = 2
 SP = 1
 */
