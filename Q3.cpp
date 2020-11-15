#include <iostream>
#include <cctype>

using std::cout;
using std::cin;
using std::string;

void makeLower(string& str) {
    string temp;
    for ( int i = 0; i < str.size(); i++ ){ temp.push_back( tolower( str[i] ) ); }
    str = temp;
}

int main()
{
    string input, temp;
    
    getline( cin, input, '\n' );
    
    for (int i = 0; i < input.size(); i++) {
        if( isalpha(input[i]) ){
            temp.push_back( input[i] );
        }
    }
    
    string s1, s2;
    
    string::iterator start1 = temp.begin();
    string::iterator end1 = temp.begin();
    
    std::advance(end1, (temp.size() / 2 + 1));
    
    s1.insert( s1.begin(), start1, end1 );
    
    string::reverse_iterator start2 = temp.rbegin();
    string::reverse_iterator end2 = temp.rbegin();
    
    std::advance(end2, temp.size() / 2 + 1);
    
    s2.insert( s2.begin(), start2, end2 );
    
    makeLower(s1);
    makeLower(s2);
    
    bool flag = (s1 == s2) ? 1 : 0; // if it is already a perfect palindrome, just print out the input
    if ( flag == 0 ) {
        char bad;
        unsigned long pos = 0;
        unsigned long size = ( s2 > s1 ) ? s1.size() : s2.size();
        for (int i = 0; i < size; i++) {
            if ( s1[i] == s2[i] && s1[i+1] == s2[i+1] ) {
                // do nothing.
                // This lets input like "Borrqow or rob?" (supposed to be "Borrow or rob?") work, or more generally, words with repetitive letters like "Google" be processed.
            } else if ( s1[i+1] == s2[i] && s1[i] == s2[i+1] ) {
                pos++;
                // this is where I'm giving up (not worth my time to fix this edge case) - comment this line out to let "abaab" work, or leave it uncommented to let "baaba" work (where "baab" is the correct palindrome in both cases).
            } else if ( s1[i+1] == s2[i] ) {
                bad = s1[i];
                pos += i;
                break;
            } else if ( s1[i] == s2[i+1] ){
                bad = s2[i];
                pos += temp.size() - i - 1;
                break;
            }
        }
        /*
         Known weakness in the above algorithm: the ambiguous case of having the extra character as one of the very middle letters. Input like "Borrowq or rob?" is impossible to solve, because there is no way to choose which of the two middle letters is incorrect. A way to solve this may be to use a dictionary to decide that "Borrow" is the correct word, since "Borroq" is not a word in English, and then process accordingly.
         */
        
        unsigned long t = pos;
        int numNonAlpha = 0;
        for (int i = 0; i < t; i++) {
            if ( !isalpha(input[i]) ) { // this code not only deals with spaces, but also punctuation
                numNonAlpha++;
                t++;
            }
        }
        input.erase(pos + numNonAlpha, 1); // find the pos'th spot, ignoring spaces, and delete it.
    }
    cout << input << std::endl;
    
    return 0;
}
