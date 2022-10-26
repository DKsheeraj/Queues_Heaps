#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define capacity 10
int size = 0;

int H[capacity+1];

int root()
{
    return 1;
}
int parent(int n)
{
    return n/2;
}
int leftchild(int n)
{
    return 2*n;
}
int rightchild(int n)
{
    return 2*n +1;
}
bool hasparent(int n)
{
    return n != root();
}
bool isnode(int n)
{
    return n <= size;
}

void swap(int *a, int *b)
{
    int emo = *a;
    *a = *b;
    *b = emo;
}


int getmax(int H[])
{
    if(size == 0)
    {
        printf("Empty priority queue\n");
        exit(0);
    }

    return H[root()];
}

void shiftup(int H[], int n)
{
    while(hasparent(n) && H[parent(n)] < H[n])
    {
        swap(&H[parent(n)], &H[n]);
        n = parent(n);
    }
}

void push(int H[], int key)
{
    if(size == capacity)
    {
        printf("Priority Queue full!\n");
        exit(0);
    }

    H[size+1] = key;
    size++;
    shiftup(H, size);
}

void shiftdown(int H[], int key)
{
    while(isnode(leftchild(key)))
    {
        int child = leftchild(key);

        if(isnode(rightchild(key)) && H[rightchild(key)] > H[leftchild(key)])
        {
            child = rightchild(key);
        }

        if(H[key] < H[child])
        {
            swap(&H[key], &H[child]);
        }
        else
        {
            break;
        }

        key = child;
        
    }
}

void pop(int H[])
{
    if(size == 0)
    {
        printf("Empty priority Queue\n");
        exit(0);
    }

    H[root()] = H[size];
    size--;
    shiftdown(H, root());
    
}

void build(int arr[], int H[], int n)
{
    for(int i = 0; i < n; i++)
    {
        H[i+1] = arr[i];
    }

    size = n;

    for(int i = size/2; i >= 1; i--)
    {
        shiftdown(H, i);
    }
}

int main()
{
    // push(H, 2);
    // push(H, 4);
    // push(H, 1);
    

    // for(int i = 1; i <= size; i++)
    // {
    //     printf("%d ", H[i]);
    // }

    int arr[] = {51, 43, 93, 18, 42, 99, 54, 2, 74};

    int n = sizeof(arr)/sizeof(arr[0]);

    build(arr, H, n);

    for(int i = 1; i <= size; i++) printf("%d ", H[i]);
}