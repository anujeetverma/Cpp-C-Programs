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
    for (int i=0;i<=n-1;i++)
    {
        int j=i;
            while(j>0&&arr[j-1]>arr[j])
            {
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                j--;
            }
        }
    printf("The sorted array is \n");
    for (int i=0;i<=n-1;i++)
        printf("%d ",arr[i]);
    return 0;
}