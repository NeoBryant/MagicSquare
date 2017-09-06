//
//  main.cpp
//  MagicSquare
//
//  Created by 彭 on 2017/9/6.
//  Copyright © 2017年 彭. All rights reserved.
//

#include <iostream>
#include "Square.h"
using namespace std;


int main() {
    
    int size = 0;
    cout << "If you want to set a square, input the size of it please: ";
    cin >> size;
    Square square(size);
    square.fillSquare();
    if (square.isMagicSquare()) {
        cout << "Woo~~ it's a MAGIC SQUARE!" << endl;
    }
    else {
        cout << "Ehh~~ it's not a MAGIC SQUARE, it's just a normal square!" << endl;
    }
    
    cout << "If you want to set a MAGIC square, input the size of it please(odd number required): ";
    cin >> size;
    while (size % 2 == 0) {
        cout << "please input an odd number: ";
        cin >> size;
    }
    
    Square magicSquare(size);
    magicSquare.getMagicSquare();
    
    return 0;
}
