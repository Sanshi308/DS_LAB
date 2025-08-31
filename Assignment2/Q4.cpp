4)) String Related Programs:
ans:-
a)Write a program to concatenate one string to another string.
#include <stdio.h>
int main() {
    char str[100];
    int length = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str);  

    while (str[length] != '\0') {  
        length++;
    }

    printf("Length = %d\n", length);
    return 0;
}

b)Write a program to reverse a string.
#include <stdio.h>
int main() {
    char str1[100], str2[100];
    int i = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str1);

    while (str1[i] != '\0') {  
        str2[i] = str1[i];  
        i++;
    }
    str2[i] = '\0'; 

    printf("Copied string = %s\n", str2);
    return 0;
}

c)Write a program to delete all the vowels from the string.
ans:-
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);   // take input string (with spaces)

    string result = "";
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        // check if character is NOT a vowel
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
              ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
            result += ch;  // keep non-vowels
        }
    }

    cout << "String after deleting vowels: " << result << endl;
    return 0;
}


4)Write a program to sort the strings in alphabetical order.
ans:-
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    string arr[100];   // array of strings
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Sorting using simple bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "\nStrings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}


5)Write a program to convert a character from uppercase to lowercase.
#include <stdio.h>
int main() {
    char ch;

    printf("Enter an uppercase character: ");
    scanf("%c", &ch);

  
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;   
        printf("Lowercase character = %c\n", ch);
    } else {
        printf("Entered character is not uppercase!\n");
    }

    return 0;
}






