#include <iostream>
#include "RingBuffer.h"

int main(){
    RingBuffer<char, 5> Ring; // declare type and size
    char first = 'a';
    char scnd = 'b';
    char thrd = 'd';
    Ring.push(first);
    Ring.push(scnd);
    Ring.push(thrd);
    std::cout << *Ring.getNewest()<< std::endl;


}
