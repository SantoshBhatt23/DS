#include <stdio.h>
//functions prototypes:
void display(int arr[], int n);
void insertEnd(int arr[], int *n, int value);
void insertBeginning(int arr[], int *n, int value);
void insertPosition(int arr[], int *n, int value, int pos);
void deleteEnd(int arr[], int *n);
void deleteBeginning(int arr[], int *n);
void deletePosition(int arr[], int *n, int pos);
void reverseTemp(int arr[], int n);
void reverseInPlace(int arr[], int n);
int sumIterative(int arr[], int n);
int sumRecursive(int arr[], int n);
int search(int arr[], int n, int key);
void separateOddEven(int arr[], int n);
void separatePosNeg(int arr[], int n);
void copySubArray(int *MainArray,int*subArray,int*n);

int main() {
    int SubArray1[10], SubArray2[10], MainArray[20];
    int n1 = 0, n2 = 0, n3 = 0;
    int choice, value, pos;

    while (1) {
        printf("\n-------------Array operations MENU:------------\n");
        printf("1. Insert at End \n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from Position\n");
        printf("7. Reverse using Temp Array\n");
        printf("8. Reverse In-place\n");
        printf("9. Sum of all elements:\n");
        printf("10. Search Element\n");
        printf("11. Separate Odd/Even\n");
        printf("12. Separate Positive/Negative\n");
        printf("13. Copy SubArray1 to main:\n");
        printf("14. Copy SubArray2 to main:\n");
        printf("15. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        int arrarChoice;

        switch (choice) {
        case 1:
            printf("Select Array:\n 1.Main \n2.Subarray1 \n3.SubArray2\n");
            scanf("%d",&arrayChoice);
            printf("Enter value: ");
            scanf("%d", &value);
            if(arrayChoice == 1){
                insertEnd(MainArray, &n3, value);
                display(MainArray, n3);
            }else if(arrayChoice==2){
                insertEnd(SubArray1,&n1,value);
                display(SubArray2,n1);
            }else{
                insertEnd(SubArray2,&n2,value);
                display(SubArray1,n1);
            }
            break;

        case 2:
            printf("Select Array:\n 1.Main \n2.Subarray1 \n3.SubArray2\n");
            scanf("%d",&arrayChoice);
            printf("Enter value: ");
            scanf("%d", &value);
            if(arrayChoice == 1){
                insertBeginning(MainArray, &n3, value);
                display(MainArray, n3);
            }else if(arrayChoice==2){
                insertBeginning(SubArray1,&n1,value);
                display(SubArray2,n1);
            }else{
                insertBeginning(SubArray2,&n2,value);
                display(SubArray1,n1);
            }
            break;

        case 3:
           printf("Select Array:\n 1.Main \n2.Subarray1 \n3.SubArray2\n");
            scanf("%d",&arrayChoice);
            printf("Enter value & position: ");
            scanf("%d %d", &value, &pos);
            if(arrayChoice==1){
                insertPosition(MainArray, &n3, value, pos);
                display(MainArray, n3);
            }else if(arrayChoice==2){
                insertPosition(SubArray1, &n1, value, pos);
                display(SubArray1,n1 );
            }else if(arrayChoice==3){
                insertPosition(SubArray2, &n2, value, pos);
                display(SubArray2, n2);
            }
            break;

        case 4:
            printf("Select Array:\n 1.Main \n2.Subarray1 \n3.SubArray2\n");
            scanf("%d",&arrayChoice);
            if(arrayChoice==1){
                deleteEnd(MainArray, &n3);
                display(MainArray, n3);
            }else if(arrayChoice==2){
                deleteEnd(SubArray1,&n1);
                display(SubArray1,n1);
            }else if(arrayChoice==3){
                deleteEnd(SubArray2,&n2);
                display(SubArray2,n2);
            }

            break;

        case 5:
            printf("Select Array:\n 1.Main \n2.Subarray1 \n3.SubArray2\n");
            scanf("%d",&arrayChoice);
            if(arrayChoice==1){
                deleteBeginning(MainArray, &n3);
                display(MainArray, n3);
            }else if(arrayChoice==2){
                deleteBeginning(SubArray1, &n1);
                display(SubArray1, n1);
            }else{
                deleteBeginning(SubArray2, &n2);
                display(SubArray2, n2);
            }
            break;

        case 6:
            printf("Select Array:\n 1.Main \n2.Subarray1 \n3.SubArray2\n");
            scanf("%d",&arrayChoice);
            printf("Enter position: ");
            scanf("%d", &pos);
            if(arrayChoice == 1){
                deletePosition(MainArray, &n3, pos);
                display(MainArray, n3);
            }else if(arrayChoice ==2){
                deletePosition(SubArray1, &n1, pos);
                display(SubArray1, n1);
            }else if(arrayChoice == 3){
                deletePosition(SubArray2, &n2, pos);
                display(SubArray2, n2);
            }
            break;

        case 7:
            reverseTemp(MainArray, n3);
            break;

        case 8:
            reverseInPlace(MainArray, n3);
            display(MainArray, n3);
            break;

        case 9:
            printf("Sum (Iterative): %d\n", sumIterative(MainArray, n3));
            printf("Sum (Recursive): %d\n", sumRecursive(MainArray, n3));
            break;

        case 10:
            printf("Enter value to search: ");
            scanf("%d", &value);
            pos = search(MainArray, n3, value);
            if (pos == -1)
                printf("Element not found\n");
            else
                printf("Element found at position %d\n", pos);
            break;

        case 11:
            separateOddEven(MainArray, n3);
            break;

        case 12:
            separatePosNeg(MainArray, n3);
            break;

        case 13:
            copySubArray(MainArray,SubArray1,&n3);
            break;
        case 14:
            copySubArray(MainArray,SubArray2,&n3);
            break;

        case 15:
            printf("Program completed successfully!");
            return 0;
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    printf("Program completed successfully!");
}

// Function Definitions

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertEnd(int arr[], int *n, int value) {
    arr[*n] = value;
    (*n)++;
}

void insertBeginning(int arr[], int *n, int value) {
    for (int i = *n; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = value;
    (*n)++;
}

void insertPosition(int arr[], int *n, int value, int pos) {
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    (*n)++;
}

void deleteEnd(int arr[], int *n) {
    (*n)--;
}

void deleteBeginning(int arr[], int *n) {
    for (int i = 0; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

void deletePosition(int arr[], int *n, int pos) {
    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

void reverseTemp(int arr[], int n) {
    int temp[20];
    for (int i = 0; i < n; i++)
        temp[i] = arr[n - i - 1];
    display(temp, n);
}

void reverseInPlace(int arr[], int n) {
    int t;
    for (int i = 0; i < n / 2; i++) {
        t = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = t;
    }
}

int sumIterative(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int sumRecursive(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + sumRecursive(arr, n - 1);
}

int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

void separateOddEven(int arr[], int n) {
    printf("Even: ");
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0)
            printf("%d ", arr[i]);

    printf("\nOdd: ");
    for (int i = 0; i < n; i++)
        if (arr[i] % 2 != 0)
            printf("%d ", arr[i]);
    printf("\n");
}

void separatePosNeg(int arr[], int n) {
    printf("Positive: ");
    for (int i = 0; i < n; i++)
        if (arr[i] >= 0)
            printf("%d ", arr[i]);

    printf("\nNegative: ");
    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
            printf("%d ", arr[i]);
    printf("\n");
}

void copySubArray(int *MainArray,int*subArray,int*n){
    for(int i =0 ; i<10 ; i++){
        MainArray[i] = subArray[i];
    }
    *n = 10;

}

