//
// Created by thomas on 21/04/22.
//

struct MyStruct {
    int i;
    float f;
    void clear(){i=0; f=0;}
};
int main(){
    float* f2;
    {
        float* f= new float[1000000];
        f[999999]=0;
        MyStruct* s=new MyStruct;
        s->i = 10;
        f2=f;
        delete [] f;
    }
    f2[999999]=5;

    float f[5][5];
    float* f_ptr= (float*) f; // pointer cast;
    *(f_ptr+5*3+2)=9; // equivalent to f[3][2]=9

    return 0;
};