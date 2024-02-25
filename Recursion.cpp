#include <iostream>
#include <vector>
using namespace std;
/*
Types of Recursion:
    1) Direct Recursion
    2) Indirect Recursion
    3) Tail Recursion
    4) Non-tail Recursion


1) Direct Recursion
- A function is called direct recursion if it calls the same function again.

2) Indirect Recursion
- A function (let say fun) is called indirect recursive if it calls another
function (let say fun2) and then fun2 calls fun directly or indirectly

3) Tail Recursion
- A recursive function is said to be tail recursive if the recursive call is the last thing
done by the function. there is no need to keep record of the previous state.

- Tail recursion is a special kind of recursion where the recursive call is the very last thing in the function. 
It’s a function that does not do anything at all after recursing.

4) Non-tail Recursion
- A recursive function is said to be non-tail recursive if the recursive call is not the last thing done by the function.
after returning back, there is some something left to evaluate.

*/

// Direct Recursion
void fun(){
    // some code
    fun();
    // some code
}

// Indirect Recursion
void fun2();
void fun1(){
    // some code
    fun2();
    // some code
}

void fun2(){
    // some code
    fun1();
    // some code
}

int N = 1;
void even();
void odd(){
    if(N <= 10){
        cout << N + 1 << " ";
        N++;
        even();
    }
    return;
}

void even(){
    if(N <= 10){
        cout << N - 1 << " ";
        N++;
        odd();
    }
    return;
}

// Tail Recursion
int fun3(int n){
    if(n == 0) // return the previos function 
        return 0;
    else
        cout << n << " ";
    return fun3(n - 1); // last thing is done by the fun
}
// Iterative 
int Raise(int base, int exp){
    // base ^ exp = base * base * .... (exp times)
    // 2 ^ 3 = 2 * 2 * 2

    int res = 1;
    for (int i = 1; i < exp; i++)
        res *= base;
    return res;
}

// Non-tail Recursion

// Recursive 
int Raise2(int base, int exp){
    // base ^ exp = base * base ^ exp - 1
    // 2 ^ 3 = 2 * 2 ^ 1

    if(exp == 0) // Base Case
        return 1;
    return base * Raise2(base, exp - 1); // Recursive Case
}

// More efficient recursion
int Raise3(int base, int exp){
    // base ^ exp = base ^ exp/2 * base ^ exp/2 (base if exp is odd)
    // 2 ^ 3 = 2 ^ 3/2 * 2 ^ 3/2
    // 2 ^ 2 = 2 ^ 2/2 * 2 ^ 2/2
    
    if(exp == 0)
        return 1;
    else{
        int half = Raise3(base, exp / 2);
        if(exp % 2 == 0)
            return half * half;
        else
            return base * half * half;
    }

    // if the exp is negative => base ^ exp = 1 / base ^ -exp
}

int power(int x, int n) {
    // Base case: if n is 0, return 1
    if (n == 0) {
        return 1;
    }
    
    // Recursive case: if n is positive and even
    if (n > 0 && n%2 == 0) {
        int y = power(x, n / 2);
        return y * y;
    } 
    
    // Recursive case: if n is positive and odd
    else if (n > 0 && n%2 != 0) {
        return x * power(x, n - 1);
    } 
    
    // Recursive case: if n is negative
    // elif n < 0
    return 1 / (x * power(x, -n - 1));
    
}

bool IsPalindrome(string s){
    // rotor
    // motor
    // rater

    // strip of for first and last char(rater)
    // ate => the first and last char not equal
    if(s.size() <= 1) // s.size() == 1 || s.size() == 0
        return true;
    return s[0] == s[s.size() - 1] && IsPalindrome(s.substr(1, s.size() - 2));
}

// Binary Search Using Recursive Way
const int NotFound = -1;
int BinarySearch(vector<string> &v, int start, int stop, string key){
    if(start > stop)
        return NotFound;

    int mid = (start + stop) / 2;
    if(v[mid] == key)
        return mid;
    else if(v[mid] > key)
        return BinarySearch(v,  start,  mid-1, key);
    else
        return BinarySearch(v,  mid+1,  stop, key);
}



int main(){
    odd();
    cout << endl << fun3(3) << endl;
    return 0;
}