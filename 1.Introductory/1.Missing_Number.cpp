/*
Since the question doesn't ask about preserving the numbers sequel and they're just numbers between 1 and n
we didn't create an array to store them.

The existing_numbers array will register each given value as true and the missing one will be false. 
Thus we only need to cross the array once, giving the time complexity of O(n).

The relationship of the index i of existing_numbers with a given value n in the sequel can be reached
by the relation of:
i = n - 1.

Thus the missing value m can be seen as the only false value in the existing_numbers array registered with 
the j index. So we can reach the number with:
m = j + 1
*/


#include<bits/stdc++.h>


int main() {

    int n;

    std::cin >> n;

    int input_number;
    bool existing_numbers[n] = {false};
    int number_missing = 0;

    for(int i = 0; i < n - 1; i++ ) {
        std:: cin >> input_number;
        existing_numbers[input_number - 1] = true;
    }

    for(int j = 0; j < n; j++) {
        if(!existing_numbers[j]) number_missing = j + 1; 
    }

    std::cout << number_missing;
}