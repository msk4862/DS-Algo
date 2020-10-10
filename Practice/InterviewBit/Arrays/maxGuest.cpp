/*Consider a big party where a log register for guest’s entry and exit times is maintained. 
Find the time at which there are maximum guests in the party. Note that entries in register 
are not in any order.
Example :

Input: entry[] = {1, 2, 9, 5, 5}
       exit[] = {4, 5, 12, 9, 12}
First guest in array arrives at 1 and leaves at 4, 
second guest arrives at 2 and leaves at 5, and so on.

Output: 5
There are maximum 3 guests at time 5.*/

#include <bits/stdc++.h>
using namespace std;

void maxGuest(int entry[], int exit[], int n){
    sort(entry,entry+n);
    sort(exit,exit+n);
    int i=1, j=0, ans=1, curr=1, time=entry[0];
    while(i<n && j<n){
        if(entry[i]<=exit[j]){
            curr++; 
            if(curr>ans){
                ans = curr;
                time = entry[i];
            }
            i++;
        }else{
            curr--; j++;
        }
    }
    cout<<"Max guest = "<<ans<<" at time "<<time;
}

int main(){
    int entry[] = {1, 2, 9, 5, 4};          
    int exit[]  = {4, 12, 5, 9, 12};
    maxGuest(entry,exit,5);
}