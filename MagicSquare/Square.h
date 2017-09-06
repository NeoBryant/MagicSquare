//
//  Square.h
//  MagicSquare
//
//  Created by 彭 on 2017/9/6.
//  Copyright © 2017年 彭. All rights reserved.
//

#ifndef Square_h
#define Square_h

#include <iostream>
using namespace std;
class Square {
public:
    Square();
    Square(int size);
    ~Square();
    bool isMagicSquare();
    void fillSquare();
    void getMagicSquare();
    void print();
private:
    int **square;
    int Size;
};

Square::Square() {
    square = NULL;
    Size = 0;
}
Square::Square(int size) {
    Size = size;
    square = new int*[Size];
    for (int i = 0; i < Size; ++i) {
        square[i] = new int[Size];
    }
}
Square::~Square() {
    for (int i = 0; i < Size; ++i) {
        delete []square[i];
    }
    delete []square;
}
bool Square::isMagicSquare() {
    int sum = 0;
    int rowSum = 0, colSum = 0, diaSum_a = 0, diaSum_b = 0;
    
    for (int i = 0; i < Size; ++i) {
        sum += square[0][i];
    }
    
    for (int i = 0; i < Size; ++i) {
        rowSum = 0;
        for (int k = 0; k < Size; ++k) {
            rowSum += square[i][k];
        }
        if (rowSum != sum) {
            return 0;
        }
    }
    for (int i = 0; i < Size; ++i) {
        colSum = 0;
        for (int k = 0; k < Size; ++k) {
            colSum += square[k][i];
        }
        if (colSum != sum) {
            return 0;
        }
    }
    
    if (Size % 2 != 0) {
        for (int i = 0, k = 0; i < Size; ++i, ++k) {
            diaSum_a += square[i][k];
            diaSum_b += square[Size-1-i][k];
        }
        if (diaSum_a != sum || diaSum_b != sum) {
            return 0;
        }
    }
    
    return 1;
}

void Square::fillSquare() {
    int num = 0;
    cout << "Please fill the square: \n";
    for (int i = 0; i < Size; ++i) {
        cout << "----";
    }
    cout << endl;
    
    for (int i = 0; i < Size; ++i) {
        for (int k = 0; k < Size; ++k) {
            cin >> num;
            square[i][k] = num;
        }
        cout << endl;
    }
    
    for (int i = 0; i < Size; ++i) {
        cout << "----";
    }
    cout << endl;
}

void Square::getMagicSquare() {
    int row = 0, col = Size/2;
    for (int i = 0; i < Size; ++i) {
        for (int k = 0; k < Size; ++k) {
            square[i][k] = 0;
        }
    }
    
    for (int i = 1; i <= Size*Size; ++i) {
        square[row][col] = i;
        
        int nextRow = row-1, nextCol = col+1;
        if (nextRow < 0) { nextRow = Size - 1; }
        if (nextCol > Size-1) { nextCol = 0; }
        
        if (square[nextRow][nextCol] == 0) {
            row = nextRow;
            col = nextCol;
        }
        else {
            ++row;
        }
        
    }
    print();
}

void Square::print() {
    cout << "The MAGIC SQUARE is : \n";
    for (int i = 0; i < Size; ++i) {
        cout << "--\t";
    }
    cout << endl;
    
    for (int i = 0; i < Size; ++i) {
        for (int k = 0; k < Size; ++k) {
            cout << square[i][k] << "\t";
        }
        cout << endl;
    }
    
    for (int i = 0; i < Size; ++i) {
        cout << "--\t";
    }
    cout << endl;
}

#endif /* Square_h */
