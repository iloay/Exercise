#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//小根堆    
class Heap{
    public:
        Heap(int capacity);
        Heap(int *tmp,int size,int capacity);
        ~Heap(){delete []array;}
        void insert(int data);
        void deleteNode(int pos);
        void decreaseValue(int pos,int diffvalue);
        void print();
    private:
        int *array;
        int size;
        int capacity;
        void doubleCapacity();
        void adjustHeapFromBottonToUp(int pos);
        void adjustHeapFromUpToBotton(int pos);
        void print(int pos);
};

Heap::Heap(int capacity):size(0),capacity(capacity)
{
    array = new int[capacity];
}

Heap::Heap(int *tmp,int size,int capacity):size(size),capacity(capacity)
{
    array = new int[capacity];
    array[0]=0;

    for(int i = 0 ; i < size; i ++)
        array[i + 1] = tmp[i];

    for(int i = 2; i <= size; i ++)
        adjustHeapFromBottonToUp(i);
}

void Heap::adjustHeapFromBottonToUp(int pos)
{
    int data = array[pos];

    int parent = pos / 2;
    int child = pos;

    if(parent >= 1 && array[parent] > data)
    {
        while(parent >= 1 && array[parent] > data)
        {
            array[child] = array[parent];
            child = parent;
            parent = parent / 2;
        }
    }

    array[child] = data;
}

void Heap::adjustHeapFromUpToBotton(int pos)
{
    int data = array[pos];
    int left = pos * 2;
    int right = left + 1;

    while(left <= size)
    {
        int minimum;
        if(left <= size && right <= size)
        {
            int small=array[left] > array[right] ? right:left;
            minimum= array[small] > array[pos] ? pos : small;
        }
        else
        {
            minimum = array[left] > array[pos] ? pos : left;
        }

        if(pos == minimum)
            break;

        array[pos] = array[minimum];
        pos = minimum;
        left = pos * 2;
        right = left + 1;
    }

    array[pos] = data;
}

void Heap::doubleCapacity()
{
    capacity = capacity * 2;
    int *tmp = new int[capacity];

    for(int i = 0 ; i < size; i ++)
        tmp[i] = array[i];
    delete []array;

    array = tmp;
}

void Heap::insert(int data)
{
    if(size == capacity)
        doubleCapacity();

    size++;

    array[size] = data;
    adjustHeapFromBottonToUp(size);
}

void Heap::deleteNode(int pos)
{
    if(pos <= 0)
        return;
    array[pos] = array[size];
    size --;
    adjustHeapFromUpToBotton(pos);
}

void Heap::decreaseValue(int pos,int diffvalue)
{
    array[pos] -= diffvalue;
    adjustHeapFromBottonToUp(pos);
}

void Heap::print(int pos)
{
    if(pos > size)
        return;
    print(pos * 2);
    cout<<array[pos]<<" ";
    print(pos * 2 + 1);
}

void Heap::print()
{
    cout<<"Size:"<<size<<"  Capacity:"<<capacity<<endl;
    print(1);
}

int main()
{
    srand((unsigned)time(NULL));

    int len = 10;
    int a[]={48,30,42,48,29,78,97,59,30,56};
//    Heap t(20);
    Heap t(a,10,20);

//    for(int i = 0 ; i < len; i ++)
//    {
//        int data = rand()% 100;
//        cout<<data<<" ";
//        t.insert(a[i]);
//    }
//    cout<<'\n';

    t.print();
    cout<<'\n';

//    t.deleteNode(4);
    t.decreaseValue(4,15);
    t.print();
    cout<<'\n';

    return 0;
}
