#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool pallindrome(char str[])
{

    int left=0;
    int right=strlen(str)-1;

    while(left<right)
    {

        if(str[left]!=str[right])
            return false;
        left++;
        right--;
    }
    return true;
}


int main()
{

    char str[100];
    printf("take a string:");
    gets(str);

    if(pallindrome(str))
        printf("string is a pallindorme");
    else
    printf("string is not a pallindrome");

    return 0;

}
