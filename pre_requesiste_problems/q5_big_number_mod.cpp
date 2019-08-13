#include<iostream>
#include<cmath>
#include<assert.h>

using namespace std;

/***
__author__ = 'liang wang'
__date__  = '2019.Aug.11'

'''
Define function: f(x,y,z) = (x^(y!))%z
Request get a quick ouput, even for y or z is very big number.

'''
***/

long pow_mod(long x, long y, long z){
	long res(1);
	while( y!=0){
		if (y &1){
			res = res * x % z;
		}
		y >>=1;
		x = x %z;
		x = x* x;
	}
	return res;
}

long f(long x,long y,long z){
    x=x%z; // (x*x*x)%z == (x%z)*(x%z)*(x%z)%z
    if(!x) return x;
    if(x==1) return x;
    if(y==0) return x;

    long res(1);
    for(long i=1;i<=y;++i)
    {
        if( i==1){
	 	res = x % z;
	}else{
		res = pow_mod(res, i, z);
        }
    }
    return res;
}


int main()
{
    int x,y,z;
    assert(f(2,1,2)==0);
    assert(f(3,2,2)==1);
    assert(f(1,100000,1)==0);
    assert(f(1,100000,2)==1);
    assert(f(99036,92879,77028)==0);
    assert(f(57582,1465,57582)==0);
    assert(f(14916,63624,37968)==32544);
    assert(f(48778,6070,89146)==57188);

    cout<<" Congruatlation! you have pass all test cases!" <<endl;
    cout<<" Continue other test case for fun" <<endl;

    while(cin>>x>>y>>z)
    {
        cout<<"x= "<<x<<"\ty= "<<y<<"\tz= "<<z<<endl;
        cout<<f(x,y,z)<<endl;
    }
}
