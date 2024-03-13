#include <iostream>
using namespace std;

int func(int &a,int &b){
    cout<<"Address of a in func: "<<&a<<endl;
    cout<<"Address of b in func: "<<&b<<endl;
    return a+b;
}

int main(){
    int value = 2;
    try{
        printf("In the try block\n");
        throw value;
    }
    catch(...){
        printf("Something went wrong...\n");
    }
    puts("Continued the Program\n");
    int a = 2;
    int b = 3;
    cout<<"Address of a: "<<&a<<endl;
    cout<<"Address of b: "<<&b<<endl;
    
    int ans = func(a,b);
    printf("Value of ans: %d \n",ans);
    return 0;
}
