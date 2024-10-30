#include<stdio.h>


int modified_binary_search(int arr[], int n, int target) {
    int low = 0, high = n - 1,count=0;

    while (low <= high) {
        int mid = low + (high - low) / 3; //midpoint

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            low = mid + 1; //right part
        } else {
            high = mid - 1; //left part
        }
        count++;
    } 
    printf("%d",count);
    return -1; //not found
}

// int binary_search(int arr[], int n, int target) {
//     int low = 0, high = n - 1, count = 0;

//     while (low <= high) {
//         int mid = low + (high - low) / 2;

//         if (arr[mid] == target) {
//             printf("Left moves: %d\n", count);
//             return mid;
//         } else if (arr[mid] < target) {
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//             count++;
//         }
//     }

//     printf("Left moves: %d\n", count); // Print count even if not found
//     return -1;
// }


int main(){
    int arr[15]={2,3,4,5,6,7,8,9,12,2,3,4,5,3,2};
    int n = sizeof(arr);
    printf("Enter the number you want to find: ");
    int s;
    scanf("%d",&s);
    if(modified_binary_search(arr, n,s)==-1){
        printf("Not Found");
    }
    else{
        printf("Found");
    }

}    



