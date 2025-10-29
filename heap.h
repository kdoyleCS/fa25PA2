//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        if (size==0) {
             return -1;
        }
        int minIdx = data[0];
        data[0] = data[size-1];
        size--;

        downheap(0,weightArr);
        return minIdx;
    }

    void upheap(int pos, int weightArr[]) {
        int child = pos;
        int parent = (child - 1) / 2;
        while (child > 0 && weightArr[data[child]] < weightArr[data[parent]]) {
            swap(data[child], data[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
    }

    void downheap(int pos, int weightArr[]) {
        int parent = pos;
        while (true) {
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int smallest = parent;

            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }
            if (smallest == parent) {
                break;
            }
            swap(data[parent], data[smallest]);
            parent = smallest;
        }
    }
};

#endif