#include<bits/stdc++.h>
using namespace std;


class queue {
  int size;
  int *arr;
  int pfront;
  int rear;

  public:
  queue() {

    size = 1000101;
    arr = new int[size];
    rear = 0;
    pfront = 0;
  }

  bool isEmpty() {
    if(pfront == rear) {
      return true;
    }else {
      return false;
    }
  }


  void enqueue(int data) {
    if(rear == pfront) {
      cout << "overflow condition!" << endl;
    }else {
      arr[rear] = data;
      rear++;
    }
  }

  int dequeue() {
    if(pfront == rear) {
      return -1;
    }else {
      int ans = arr[pfront];
      arr[pfront] = -1;
      pfront++;
      if(pfront == rear) {
        rear = 0;
        pfront = 0;
      }
      return ans;
    }
  }

  int front() {
    if(rear == pfront) {
      return -1;
    }else {
      return arr[pfront];
    }
  }
};