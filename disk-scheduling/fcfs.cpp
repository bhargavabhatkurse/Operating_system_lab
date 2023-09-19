#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int i,j,k,n,m,head_movement=0,x,y,h;
    cout<<"Enter the size of disk\n";
    cin>>m;
    cout<<"Enter number of requests\n";
    cin>>n;
    cout<<"Enter the requests\n";
    
    // creating an array of size n
    int *a = new int[n];
    
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<"Enter the head position\n";
    cin>>h;
    
    // head will be at h at the starting
    int head=h;
    
    cout<<head;
    
    for(i=0;i<n;i++){
        cout<<" -> "<<a[i]<<' ';
        // calculating the difference for the head movement
        head_movement+=abs(a[i]-head);
        // head is now at the next I/O request
        head=a[i];
    }

    cout<<'\n';
    cout<<"Total head movements = "<< head_movement<<'\n';
    return 0;
}