#include<stdio.h>
#include<stdlib.h>
int arr[50];
int insert_begin(int *arr,int size)
{
    int n,i;
    printf("\nEnter the element to insert: ");
    scanf("%d",&n);
    size++;
    for(i=size-1;i>=0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=n;
    printf("\nArray after insertion: ");
    for (i = 0; i < size; i++)
    {
        printf("\narr[%d]=%d",i,arr[i]);
    }    
    return 0; 
}
int insert(int *arr,int size)
{
        int n,loc,i,x;
        printf("Enter the element to insert: ");
        scanf("%d",&n);
        printf("\nEnter the location to insert: ");
        scanf("%d",&loc);
        if(loc<0 || loc>size+1)
        {
            printf("\nInvalid Location\n");
            insert(arr,size);
        }
        else
        {
        size++;
        for (i = size-1; i >= loc; i--)
        {
            arr[i]=arr[i-1];
        }
        arr[loc-1]=n;   
        }   
        return 0;
}
int insert_end(int *arr,int size)
{
    int n,i;
    printf("\nEnter the element to insert: ");
    scanf("%d",&n);
    arr[size]=n;
    size++;
    printf("\nArray after insertion: ");
    for (i = 0; i < size; i++)
    {
        printf("\narr[%d]=%d",i,arr[i]);
    }    
    return 0; 
}
int traverse(int *arr,int size)
{
    int i;
    printf("\nArray: ");
    for (i = 0; i < size; i++)
    {
        printf("\narr[%d]=%d",i,arr[i]);
    }    
    return 0; 
}
int delete(int *arr,int size)
{
    int loc,i;
    printf("Enter the position to delete: ");
    scanf("%d",&loc);
    if(loc>50 || loc<0)
        {
            printf("Deletion not possible");
        }
    else
        {
            for(i=loc-1;i<size-1;i++)
            {
                arr[i]=arr[i+1];
            }
            size--;
            printf("Array after deletion: ");
            for(i=0;i<size;i++)
            {
                printf("\narr[%d]=%d",i,arr[i]);
            }
        }
}
int delete_begin(int *arr,int size)
{
    int i;
    for(i=size-1;i<=0;i--)
    {
        arr[i-1]=arr[i];
    }
    size--;
    printf("Array after deletion: ");
    for(i=0;i<size;i++)
    {
        printf("\narr[%d]=%d",i,arr[i]);
    }
}
int main()
{
    int size,i,ch;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    if(size>50)
    {
        printf("\nArray Overflow");
    }
    if(size<0)
    {
        printf("\nInvalid Size");
    }
    else
    {
        printf("\nEnter the elements in the array: \n");
        for(i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }
    }
    while(1)
    {
        printf("\n1.Insert at beginning\n2.Insert at Specific Location\n3.Insert at last\n4.Display the array\n6.Delete at Specific location\n8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insert_begin(arr,size);
            size++;
            break;
        case 2:
            insert(arr,size);
            size++;
            printf("\nArray after insertion: ");
            traverse(arr,size);
            break;
        case 3:
            insert_end(arr,size);
            size++;
            break;
        case 4:
            traverse(arr,size);
            break;
        case 5:
            delete_begin(arr,size);
            break;
        case 6:
            delete(arr,size);
            break;
        case 8:
            printf("Program Ends!!");
            exit(0);
        default:
            printf("Invalid Choice");
            break;
        }
    }
    return 0;
}