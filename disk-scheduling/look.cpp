#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int i,j,k,n,m,sum=0,x,y,h;
    cout<<"Enter the size of disk\n";
    cin>>m;
    cout<<"Enter number of requests\n";
    cin>>n;
    cout<<"Enter the requests\n";
    
    // creating an array of size n
    vector<int> a,b;        //a for input, b to display the final output seq
    
    int element;
    
    for(i=0;i<n;i++){
        cin>>element;
        a.push_back(element);       //accepting all the elements 
    }
    
    
    cout<<"Enter the head: \n";
    cin>>h;
    
    a.push_back(h);                 //head will also be added to the array
    
    int dir;
    cout<<"enter dir: ";
    cin>>dir;

   
    sort(a.begin(),a.end());
    
    
    int h_index;
    for(int i=0;i<a.size();i++)
    if(h == a[i]) {
    h_index = i;        //finding the index of the head after sorting
    break;
    }
    
    //right direction
    if(dir == 1) {
        for(int i=h_index;i<a.size();i++)       //first go till the right end 
            b.push_back(a[i]);
        for(int i=h_index-1;i>=0;i--)           //then the left end
            b.push_back(a[i]);    
    }
    
    //for left direction
    if(dir == 0) {
        for(int i=h_index;i>=0;i--)             //first go till the left end 
            b.push_back(a[i]);    
        for(int i=h_index+1;i<a.size();i++)     //then the right end 
            b.push_back(a[i]);
        
    }
    
    int head=b[0];
    cout<<head;
    for(i=1;i<b.size();i++){
        
        cout<<" -> "<<b[i]<<' ';
        // calculating the difference for the head movement
        sum+=abs(b[i]-head);
        // head is now at the next I/O request
        head=b[i];
    }
    
    cout<<'\n';
    cout<<"Total head movements = "<< sum<<'\n';
    return 0;
}

/*
I/P:
82
170
43
140
24
16
190
*/