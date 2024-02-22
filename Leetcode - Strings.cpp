int main()
{
    /*
        - A string is actually an array of unicode characters.  
        - In C++ == and compare() both are used to compare strings and find if the 
          given strings are equal or not but they differ in working.
            • return 1      => strings are equal.
            • return 0      => strings not equal.
    
        - Compare() returns an integer unlike == operator to tell how the string 
          are related lexicographically.
             • return 0     => strings are equal.
             • return < 0   => First string is lexicographically less than the second string.
             • return > 0   => First string is lexicographically greater than the second string.
    
        - Immutable means that you can't change the content of the string once it's initialized.


    */

    // defining strings to be compared 
    string st1 = "GfG";
    string st2 = "GeeksforGeeks";

    // comparing string using == operator 
    if (st1 == st2) {
        cout << "Strings are Equal\n";
    }
    else {
        cout << "Strings are not Equal\n";
    }
    cout << "===================================\n";
    string ss1 = "GfG";
    string ss2 = "GeeksforGeeks";
    int value = ss1.compare(ss2);
    if (value == 0) {
        cout << "The strings are Equal\n";
    }
    // value > 0 (s1 is greater than s2) 
    else if (value > 0) {
        cout << "The string1 is greater than string 2\n";
    }
    // Now the only left value < 0 (s1 is smaller than s2) 
    else {
        cout << "The string1 is smaller than string 2\n";
    }
    cout << "===================================\n";
    string s1 = "Hello World";
    cout << "s1 is \"Hello World\"" << endl;
    string s2 = s1;
    cout << "s2 is initialized by s1" << endl;
    string s3(s1);
    cout << "s3 is initialized by s1" << endl;
    // compare by '=='
    cout << "Compared by '==':" << endl;
    cout << "s1 and \"Hello World\": " << (s1 == "Hello World") << endl;
    cout << "s1 and s2: " << (s1 == s2) << endl;
    cout << "s1 and s3: " << (s1 == s3) << endl;
    cout << "s2 and s3: " << (s2 == s3) << endl;
    // compare by 'compare'
    cout << "Compared by 'compare':" << endl;
    cout << "s1 and \"Hello World\": " << !s1.compare("Hello World") << endl; // 1 => false
    cout << "s1 and \"Hello World\": " << s1.compare("Hello World") << endl; //  0 => true
    cout << "s1 and s2: " << !s1.compare(s2) << endl;
    cout << "s1 and s3: " << !s1.compare(s3) << endl;
    cout << "s2 and s3: " << !s2.compare(s3) << endl;
    cout << "===================================\n";
    // The string is mutable in c++, in java and other languages it's immutable.
    string str = "Hello World";
    str[5] = ',';
    cout << str << endl;
    cout << "===================================\n";
    string str1 = "Hello World";
    // 1. concatenate
    str1 += "!";
    cout << str1 << endl;
    // 2. find
    cout << "The position of first 'o' is: " << str1.find('o') << endl;
    cout << "The position of last 'o' is: " << str1.rfind('o') << endl;
    // 3. get substr
    cout << str1.substr(6, 5) << endl;

    return 0;
}