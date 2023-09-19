#include<stdio.h>
int main()
{
int i,j,n,a[50],frame[10],no,k,flag,fault=0;

printf("\n ENTER THE NUMBER OF PAGES:\n");
scanf("%d",&n);

printf("\n ENTER THE PAGES :\n");   //reference string
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
            
printf("\n ENTER THE NUMBER OF FRAMES :");
scanf("%d",&no);


for(i=0;i<no;i++)
  frame[i]= -1;         //intialising all frames to -1


j=0; //keeping track of which frame to replace;


printf("ref string\t page frames\n");

for(i=1;i<=n;i++) {

printf("%d\t\t",a[i]);


flag=0; //assuming page wont be there

for(k=0;k<no;k++)  //checks the all frames to see if the reference page is there or not
if(frame[k]==a[i]) //if found
flag=1;  //set flag


if(flag==0)  //if not in the frames, replace 
{

frame[j]=a[i];  //replacing frame j
j=(j+1)%no;    //next time this frame will be replaced. going circular

fault++; //increase the faults

for(k=0;k<no;k++)  //display the frame
printf("%d\t",frame[k]);

}
printf("\n");
}

printf("Page Fault Is %d",fault);
return 0;
}
