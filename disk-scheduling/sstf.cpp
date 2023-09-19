#include<bits/stdc++.h>
using namespace std;

int mindifference(int *a, int n, int head,int *completed) {
    int min=9999;
    int idx=9999; //not defined index
    
    for(int i=0;i<n;i++)
    if(abs(a[i] - head) <min && completed[i] == 0) { //if the difference between i/o and head is less than current minimum and the io request has not bee granted before
    min = a[i] - head; //set new minimum
    idx = i; //set the index
    }
   
    return idx; //return the index of that io
}
int main(){
    
    int i,j,k,n,m,sum=0,x,y,h;
    cout<<"Enter the size of disk\n";
    cin>>m;
    cout<<"Enter number of requests\n";
    cin>>n;
    cout<<"Enter the requests\n";
    
    // creating an array of size n
    int *a = new int[n];
    int *completed = new int[n];  //to keep track of the completed requests(not to repeat again while finding the mining difference)
    
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<"Enter the head position\n";
    cin>>h;
    
    // head will be at h at the starting
    int head=h;
    cout<<head;
    
    for(i=0;i<n;i++){
        
        int index = mindifference(a,n,head,completed);
        cout<<" -> "<<a[index]<<' ';
        // calculating the difference for the head movement
        sum+=abs(a[index]-head);
        // head is now at the next I/O request
        head=a[index];
        completed[index] = 1;
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    return 0;
}