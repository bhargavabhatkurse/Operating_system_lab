#include<iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int mutex=1, full=0, empty, in=0, out=0;
int buffer_size;
int buffer[100];

void signal(int *S)
{
    *S+=1;
    return;
}
int wait(int *S)
{
    if(*S<=0)
    {
       cout<<endl<<"Can't perform the operation at the moment"<<endl;
       return 0;
    }
   
    *S-=1;
    return 1;
}

void produce()
{
     int next_prod = rand()%100;
     
    int valid1 = wait(&empty);  //returns 1 if we empty was decremented
    int valid2 = wait(&mutex);  //acquire lock
  
    if(valid1 && valid2) {
   
        buffer[in] = next_prod;
        in = (in+1)%buffer_size;
        cout<<endl<<"Item produced: "<<next_prod<<" and added to the buffer"<<endl;
    }
    else {
    signal(&mutex);     //if we could decrement empty but acquired lock, then its pointless. so we release the lock
    return;
    }
    
    signal(&mutex);  //release the lock
    signal(&full);  //increment full 
}

void consume()
{
    int next_cons;
    
    int valid1 = wait(&full); 
    int valid2 = wait(&mutex);
    
    
     if(valid1 && valid2) {
   
        next_cons = buffer[out];
        out = (out+1)%buffer_size;
        cout<<endl<<"Item consumed: "<<next_cons<<" and removed from the buffer"<<endl;
     }
     else {
    signal(&mutex); //release the lock if we werent able to decrement full
    return;
    }
    
    //increment empty and release the lock
    signal(&mutex);
    signal(&empty);
}

int main()
{
    int choice;
    cout<<"Enter buffer size: ";
    cin>>buffer_size;
    empty = buffer_size;
    int iteration=0;
    do
    {
       
        choice = rand()%2;
        switch(choice)
        {
            case 0: cout<<"\n[Producer is trying to enter]";
                    produce();
                    iteration++;
                    break;
            case 1: cout<<"\n[Consumer is trying to enter]";
                    consume();
                    iteration++;
            case 3: break;
            default: cout<<"Select a valid option"<<endl;
        }
    }while(iteration != 100);
    return 0;
}



/*
void printbuffer() {
    for(int i = 0; i<buffer_size;i++)
        cout<<buffer[i];
}


*/
