/*
i/p:
allocated
0 1 0
2 0 0 
3 0 2
2 1 1 
0 0 2

7 5 3
3 2 2 
9 0 2
2 2 2 
4 3 3 
*/


#include <iostream>
using namespace std;

int n,r;
int order = 0;              //order keeps track of the current selected process and keeps on rotating. after nth process it goes to the 1st process again
int allocated[10][10],Max[10][10],need[10][10],available[10];
int completed = 0;
int solution[10];
int work[10],finish[10];

int is_finish() {
    
//function checks if all processes are complete
    for(int i=0;i<n;i++)
        if(finish[i] != 1)
        return 0;
    return 1;
}

//function checks if the process's need is less than the current available
int is_possible(int process) {
  for(int j = 0;j<r;j++)
if(need[process][j] > work[j]) return 0;
    
  return 1;
}

int find_index() {
    int tried = 0;   //to keep track if we have tested all the processes n-1 times. Otherwise we might be in a loop
    while(!is_finish() && tried != n-1 )  //while all processes are not finished and we haven't tested n-1 processes
    if(finish[order] == 0 && is_possible(order))        //if the seleected process is not finished and its needs are less than current available
    return order;       //return that process
    else {tried++; order = (order+1)%n;     //otherwise, try another process. 
    }
    
    return -1;      //if no process is found
}

int bankers() {
      
    do { 
    int idx = find_index();         //find the index of the process which meets the requirement
   
    if(idx != -1) {        //if found
    
    for(int j=0;j<r;i++)
    work[j] += allocated[idx][j];    //complete the process and acquire its resources and add to available
    
    finish[idx] = 1;        //mark the process as finished
    solution[completed] = idx;      //add the process to the solution;
    completed++;        //one more process completed 
    }

    else break;  //if not found, break
    
    }while(completed != n);     //try till all processes are completed
    
     if(completed == n)             //if all are completed, return 1 so that we can print the sequence in main()
        return  1;
           
    else 
        return 0;
}

int check_request(int requester,int request[]) {
    
    for(int j = 0;j<r;j++)
   if(request[j] > need[requester][j]) {cout<<"more than the maximum claim"; return 0;} //more than its own request
 
   for(int j = 0;j<r;j++)
   if(request[j] > work[j]) {cout<<"system resources are less"; return 0;}          //more than the current available

    //modification
    for(int j = 0;j<r;j++) {
    work[j] -= request[j];                              //reduce the current available
    allocated[requester][j] += request[j];              //allocate the requester its requested resourcces
    need[requester][j] -= request[j];                   //reduce its needs
    }
    
    return 1;           // return and check if bankers() results in a sequence
    
}

int request() {
    int requester;
    int request[10];
    cout<<"Enter requester process : \n";
    cin>>requester;
    cout<<"Enter request: \n";
    
   for(int j=0;j<r;j++)
   cin>>request[j];
   

   if(check_request(requester,request)) {       //if the requester process passes all the conditions,apply bankers on it
        if(bankers()) return 1;             // sequence is found, return 1 and print the sequence in main()
        else {cout<<"can't be granted";return 0;}
   }
    return 0;       //if the requester fails to meet the conditions
}


int main()
{  
    cout<<"Enter no of processes and no of resources: \n";
    cin>>n;
    cin>>r;
   
   
   cout<<"\nenter allocated matrix: \n";
   for(int i=0;i<n;i++)
   for(int j=0;j<r;j++)
   cin>>allocated[i][j];
   
   cout<<"\nenter max need matrix: \n";
   for(int i=0;i<n;i++)
   for(int j=0;j<r;j++)
   cin>>Max[i][j];
   
   cout<<"\nenter availble: \n";
   for(int i=0;i<r;i++)
   cin>>available[i];
   
   for(int i=0;i<n;i++)
   for(int j=0;j<r;j++)
   need[i][j] = Max[i][j]-allocated[i][j];          //calculating the need matrix
   
   for(int i=0;i<r;i++)
   work[i]=available[i];            //work is same as available
   
   for(int i=0;i<n;i++)
    finish[i]=0;                    //to keep track of finished processes
   

    
    int choice;
    int result;
    
    do {
    cout<<"\n\nenter choice: ";
    cin>>choice;
    
    switch(choice) {
        case 1: result = bankers();break;                   //if result 1, solution exists and we cant print the sequence
        case 2: result = request();break;
    }
    
    
    if(result) {
        cout<<"\nsafe sequence: ";
       for(int i=0;i<n;i++)
           cout<<"P"<<solution[i]<<"->";
    }
           
    else 
        cout<<"\nno safe sequence\n";
        
    }while(choice);
        
   
   return 0;
   
}
