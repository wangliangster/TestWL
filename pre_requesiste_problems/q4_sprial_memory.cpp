#include<iostream>
#include<assert.h>
#include<cmath>
using namespace std;
int get(int num){
    int x,y,r;
    r=sqrt(num-1)+1;
    if(!(r%2)) ++r;
    x=r/2;
    y=-x;
    num=r*r-num;
    if(!num) return abs(x)+abs(y);
    --r;
    if(num>0){
        x-=num>r?r:num;
        num-=r;
        if(num>0){
            y+=num>r?r:num;
            num-=r;
            if(num>0){
                x+=num>r?r:num;
                num-=r;
                if(num>0){
                    y-=num;
                }
            }
        }
    }
    return abs(x)+abs(y);
}
int main()
{
    int num;
    assert(get(1)==0);
    assert(get(1024)==31);
    assert(get(100000)==173);
    assert(get(2345678)==1347);
    cout<<" Congratulation, you have pass all test cases, pls continue for new input!"<<endl;
    while(cin>>num)
    {
        cout<<get(num)<<endl;
    }
}
