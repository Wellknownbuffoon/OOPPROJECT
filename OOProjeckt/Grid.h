#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>

template<typename T>
class Grid {
private:
    int width;
    int height;
    T** entries;

public:
    
    Grid(int w, int h) : width(w), height(h) {
        entries = new T*[height];
        for (int i = 0; i < height; ++i) {
            entries[i] = new T[width];
        }
    }

    
    ~Grid() {
        if (entries) {
            for (int i = 0; i < height; ++i) {
                delete[] entries[i];
            }
            delete[] entries;
        }
    }

   
    T& operator()(int x, int y) {
        if(x >= 0 && x < width && y >= 0 && y < height) {
            return entries[y][x];
        }
        static T dummy; 
        return dummy;
    }

    
    const T& operator()(int x, int y) const {
        if(x >= 0 && x < width && y >= 0 && y < height) {
            return entries[y][x];
        }
        static T dummy; 
        return dummy;
    }

    
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    
    void print() const {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                std::cout << entries[y][x] << " ";
            }
            std::cout << "\n";
        }
    }
};

#endif