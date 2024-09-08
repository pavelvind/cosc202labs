// Lab 0:  finding gold!!

#include <iostream>

using namespace std;

int totalGolds = 0;


int main(){
    char letter;
    while(cin.get(letter)) {
        if(letter == '\n') continue;
        if((letter >= 'A') && (letter <= 'Z')){
            totalGolds  += letter - 'A' +1;
        }

    }

    cout << totalGolds <<endl;
	return 0;
}
