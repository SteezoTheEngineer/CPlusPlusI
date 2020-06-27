#include <iostream>
#include "bitset.h"

void useBitSet(BitSet bSet){}

int main(){
    BitSet bSet(10);
    useBitSet(bSet);
    BitSet bset2 = std::move(bSet);
    return 0;
}