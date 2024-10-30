#include<stdio.h>

int main()
{
    int n;
    printf("How many elements do you want?\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements\n");
    for (int i=0;i<=n-1;i++)
        scanf("%d",&arr[i]);
    for (int i=0;i<=n-2;i++)
    {
        int min=i;
        for(int j=i;j<=n-1;j++)
        {
            if (arr[j]<arr[min])
                min=j;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    printf("The sorted array is \n");
        for (int i=0;i<=n-1;i++)
        printf("%d ",arr[i]);
    return 0;
}