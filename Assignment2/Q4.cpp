4) String Related Programs:
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
#include <stdio.h>
int main() {
    char str1[100], str2[100];
    int i = 0, flag = 0;

    printf("Enter first string: ");
    scanf("%[^\n]", str1);
    getchar();   
    printf("Enter second string: ");
    scanf("%[^\n]", str2);

    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            flag = 1; 
            break;
        }
        i++;
    }

    if (flag == 0)
        printf("Strings are EQUAL\n");
    else
        printf("Strings are NOT equal\n");

    return 0;
}

4)Write a program to sort the strings in alphabetical order.
#include <stdio.h>
int main() {
    char str[100];
    int i = 0, j, length = 0;
    char temp;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

  
    while (str[length] != '\0') {
        length++;
    }

    j = length - 1;  

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }

    printf("Reversed string = %s\n", str);
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






