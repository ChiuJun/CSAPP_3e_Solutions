long decode2(long x,long y,long z){
    y-=z;
    x*=y;
    y<<=63;
    y>>=63;
    y^=x;
    
    return y;
}

int main(void){
    decode2(1,1,1);

    return 0;
}