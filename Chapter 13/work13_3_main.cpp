
/*
 * work13_3_main.cpp
 *
 *  Created on: 2018Äê11ÔÂ29ÈÕ
 *      Author: Administrator
 */

// usedma.cpp -- inheritance, friends, and DMA
// compile with dma.cpp
#include <iostream>
#include "work13_3.h"
int main()
{
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8,1);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);
    shirt.Show();
    cout << endl;
    balloon.Show();
    cout << endl;
    map.Show();
    cout << endl;
    cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;
    cout << "Displaying lacksDMA object:\n";
    cout << balloon << endl;
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;
    lacksDMA balloon2(balloon);
    cout << "Result of lacksDMA copy:\n";
    cout << balloon2 << endl;
    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;
    std::cin.get();
    return 0;
}



