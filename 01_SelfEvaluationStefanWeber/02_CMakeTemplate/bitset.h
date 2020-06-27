#ifndef BITSET_H
#define BITSET_H

class BitSet{
    private:
    bool* m_bitSet = nullptr;
    int m_nbrValues;

    public:
    BitSet(int nbrValues):m_nbrValues(nbrValues), m_bitSet(new bool[m_nbrValues]){

    };

    ~BitSet(){
        delete [] m_bitSet;
    }


    
    BitSet(const BitSet &copy){
        if(copy.m_bitSet != nullptr)
        m_nbrValues = copy.m_nbrValues;
        m_bitSet = new bool[m_nbrValues];
        for (int i = 0; i<m_nbrValues;i++){
            m_bitSet[i]=copy.m_bitSet[i];
        }
    }
    BitSet(BitSet &&move){
         if(move.m_bitSet != nullptr){
            m_nbrValues = move.m_nbrValues;
            m_bitSet = move.m_bitSet;
            move.m_bitSet = nullptr;
            move.m_nbrValues = 0;
        }
    }
};

#endif 