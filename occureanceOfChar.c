#include <stdio.h>

int main()
{
    int k;
    printf("Enter the length of string: ");
    scanf("%d", &k);
    char str[k];
    printf("Enter the string: ");
    scanf("%s",&str);
    char ch;
    printf("Enter the character: ");
    scanf("%s", &ch);
    int sum = 0;
    for (int i =0; str[i]!='\0'; i++)
    
    {
        if (str[i] == ch)
        {
            sum++;
        }
        
    }
    printf("Number of Occurence of given character in string is: %d", sum);
    return 0;
}