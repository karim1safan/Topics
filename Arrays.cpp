/*

Array: An object consisting of a numbered list of variables, each
is a primitive type or reference

char[] c; => reference to array(any length of character)

▢ →  ▢▢▢▢▢▢
↳ c reference

c = new char[4];
c[0] = 'b';
c[3] = 'e';
c[4] = 's'; => Run-time ERROR

""  => string
''  => (abostroph) char
String[] s = new String[8];
Object o = new Object[8]; (string, double, int, ...)

Field: c.length => length of array
c.length = 7;   => compile-time ERROR
    ↳ Field

Primes Revisted:
Sieve Of Eratosthenes => Sieve Algorithm

- That's the most efficient ways to find all primes smaller or equal N
- Given a number N print all primes smaller or equal to N

N = 10
prims[2, 3, 5, 7]






















--------------------------
Array: Contigous area of memory (check of memory) consisting equal
size elements each element indexed by contigous integer

- Tha main advantage in the array is indexed in constant time O(1)
1  2  3 4  5
⬛⬛⬛⬛⬛ → size: 5

- If you want to know the address of a specific element in the arr
arr_address + element_size * (i - first_index)
                              ↳ the index of the element

If you wanna know the address of the index 4
arr_address + 5 * (4 - 1) => arr_address + 15

- All this operations the compilar made it automatic for you

 ↱ (1,1)
⬛⬛⬛⬛⬛⬛
⬛⬛⬛⬛⬛⬛
⬛⬛⬛⬛⬛⬛
        ↳(3,4)

row = 3, col = 6 in the arr

- If you wanna know how many cell befor specific cell in the arr

(row-1)*col + (col-1)
(3-1)*6 + (4-1) = 15 element befor this cell

- if you take this equation and multiply by element_size and add to
  the arr_address gives you the address of this element

arr_address + element_size * ((row-1)*col + (col-1)) => give you the address of this element

Row-major
⬛ → (1,1)
⬛ → (1,2)
⬛ → (1,3)
⬛ → (1,4)
⬛ → (1,5)
⬛ → (1,6)
⬛ → (2,1)
⬛ → (2,2)
...

Col-major
⬛ → (1,1)
⬛ → (2,1)
⬛ → (3,1)
⬛ → (1,2)
⬛ → (2,2)
⬛ → (3,2)
⬛ → (1,3)
⬛ → (2,3)
...

• Time for common operations:

            Add     Remove
Beginning   O(n)    O(n)
Middle      O(1)    O(1)
End         O(n)    O(n)

O(1) → For reading and writing from array, access too -> this is feature in the arr

-------------
Dynamic Array:
-------------
Problem: Static array are stric!
int my_array[100]; // Fixed Size

Semi-Solution: Dynamically-allocated array
int *my_array = new int[size]

Problem: Might not know max size when allocating an array

- All Problems In Computer Science can be solved by another level of
indirection

Solution: dynamic array(also as known resizable arrays)
Idea: store a pointer to dynamically allocated array and replace it
with a newly-allocated array as needed.

Dynamic array: abstract data type with the following operations (at a minimum)
• Get(i):       return element at location i*
• Set(i, val)   Sets element i to val*

this two operation must be O(1) -> const-time

PushBack(val)   Adds val to the end
Remove(i)       Remove element at location i
size()          number of element

Store:
• arr: dynamically-allocated array
• capacity: size of all the dynamically-allocated array
• size: number of element currently in the arr

- Get(i)        O(1)
if i < 0 or i >= size:
    ERROR: index out of range
return arr[i]

- Set(i, val)    O(1)
if i < 0 or i >= size:
    ERROR: index out of range
arr[i] = val

- PushBack(val)  O(N)
if size == capacity:
    allocate new_arr[2*capacity]
    for i from 0 to sz - 1:
        new_arr[i] = arr[i]
    free arr
    arr = new_arr;
    capacity = 2*capacity
arr[size] = val
size += 1

- Remove(i)     O(N)
if i < 0 or i >= sz:
    ERROR: index out of range
for j from i to sz - 2:
    arr[j] = arr[i+1]
size -= 1


-------------
Jagged Array:   AKA Array of Arrays 
-------------
                     ↱ ROW
int[][] ml = new int[4][]
↳ this line equal to those lines 

int[0] ml = new int[6]
int[1] ml = new int[4]
int[2] ml = new int[4]
int[3] ml = new int[5]

such 2D array
▢▢▢▢▢▢
▢▢▢▢
▢▢▢▢
▢▢▢▢▢▢

Different ROW and COl
*/

#include <iostream>
using namespace std;

bool isPrime(int n){

    for (int i = 2; i < n; i++){
        if(n%i == 0)
            return false;
    }

    return true;
}

int main(){

    // print all prime numbers from 2 to n
    // int n = 10;
    // for (int i = 2; i <= n; i++){
    //     if(isPrime(i)){
    //         cout << i << "\n";
    //     }
    // }


    // Sieve Algorithm

    return 0;
}

