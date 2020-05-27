#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long int N,Q,p,q,k,i,j,max=0,sum=0;

    cin>>N>>Q;

    long int *a=new long int[N+1]();

    for(i=0;i<Q;i++)
    {
        cin>>p>>q>>k;
        a[p]+=k;

        /*
        adding in index+1 so that any next p's sum doesn't get substracted 
        by any last substraction (which will be done if we use a[q])
        */
        if((q+1)<=N) a[q+1]-=k;
    }

    for(i=1;i<=N;i++)
    {
       sum += a[i];
       if(max< sum) max=sum;

    }

    cout<<max;
    return 0;
}