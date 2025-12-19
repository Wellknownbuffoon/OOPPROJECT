#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>
#include <stdexcept>

template <typename T>
class List {
private:
    T* data;
    int currentsize;
    int capacity;
    void resize() {
        int newCapacity = (capacity == 0) ? 2 : capacity * 2;
        T* newData = new T[newCapacity];
        
        for (int i = 0; i < currentsize; ++i) {
            newData[i] = data[i];
        }
        if (data) delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    
    List() {
        data = nullptr;     
        currentsize = 0;    
        capacity = 0;       
    }
    List(const List& other) {
        currentsize = other.currentsize;
        capacity = other.capacity;
        if (capacity > 0) {
            data = new T[capacity];
            for (int i = 0; i < currentsize; ++i) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }
    }
    ~List() {
        if (data) delete[] data;
        data = nullptr;
    }
    List& operator=(const List& other) {
        if (this != &other) {
            if (data) delete[] data;
            currentsize = other.currentsize;
            capacity = other.capacity;
            if (capacity > 0) {
                data = new T[capacity];
                for (int i = 0; i < currentsize; ++i) {
                    data[i] = other.data[i];
                }
            } else {
                data = nullptr;
            }
        }
        return *this;
    } 
    T& operator[](int index) {
        assert(index >= 0 && index < currentsize);
        return data[index];
    }
    const T& operator[](int index) const {
        assert(index >= 0 && index < currentsize);
        return data[index];
    }
    int size() const {
        return currentsize; 
    }
    void clear() {
        currentsize = 0;
    }
    void pushback(const T& item) {
        if (currentsize == capacity) {
            resize();
        }
        data[currentsize++] = item;
    }
};

#endif