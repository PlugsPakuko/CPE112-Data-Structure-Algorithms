//Pakkawat Kaolim 66070503446
//Assignment 4.2 : Palindrome Checker

#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

int len(char *str){
    int count = 0;
    while(str[count])
        count++;
    return count;
}
bool isPalindrom(char *string, int top){
    int left = 0;
    int right = top - 1;
    while(left < right){
        if(string[left] != string[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main(void){
    char str[MAX];
    scanf("%s", str);
    if(isPalindrom(str, len(str))){
        printf("yes");
    }else{
        printf("no");
    }
    return 0;
}
