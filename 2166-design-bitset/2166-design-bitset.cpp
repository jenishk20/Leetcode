class Bitset {
public:
    vector<int>bit;
    bool flips;
    int cntOnes=0;
    Bitset(int size) {
        bit.resize(size);
        flips=false;
    }
    
    void fix(int idx) {
        
        if(!flips)
        {
            if(bit[idx]==0)
            {
                bit[idx]=1;
                cntOnes++;
            }
        }
        else
        {
            if(bit[idx]==1)
            {
                bit[idx]=0;
                cntOnes++;
            }
        }
        
    }
    
    void unfix(int idx) {
       
        if(!flips)
        {
            if(bit[idx]==1)
            {
                bit[idx]=0;
                cntOnes--;
            }
        }
        else
        {
            if(bit[idx]==0)
            {
                bit[idx]=1;
                cntOnes--;
            }
        }
        
    }
    
    void flip() {
        flips=!flips;
        cntOnes=bit.size()-cntOnes;
    }
    
    bool all() {
        
        return cntOnes==bit.size();
    }
    
    bool one() {
        return cntOnes>=1;
    }
    
    int count() {
       
        return cntOnes;
    }
    
    string toString() {
        
        string res="";
        if(!flips)
        {
            for(auto it:bit)
            {
                if(it==0)
                    res+="0";
                else
                    res+="1";
            }
        }
        else{
                
            for(auto it:bit)
            {
                if(it==0)
                    res+="1";
                else
                    res+="0";
            }
        }
        return res;
        
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */