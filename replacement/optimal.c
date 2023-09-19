#include<stdio.h>
    
int main()
{
    int m, n, position, k, l;
    int a = 0, b = 0, page_fault = 0;
    
    int total_frames = 4;
    int frames[total_frames];
    int temp[total_frames];
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    
    //int pages[] = {0,1,7,3,0,2,0,4,2,3,0,2,3,1,2,0,1,7,0,1}; //exam question
    
    int total_pages = sizeof(pages)/sizeof(pages[0]);  //20 pages

    for(m = 0; m < total_frames; m++){
            frames[m] = -1;                 //initialise all frames to -1
    }
    
    for(n = 0; n < total_pages; n++)  //for each page
    {
        printf("%d: ", pages[n]);
            
            a = 0, b = 0;  //a keeps track of initial faults when some frames are still -1
                            //b keeps track of replacement
            
            for(m = 0; m < total_frames; m++)
            {
                if(frames[m] == pages[n])  //if the page is already there, its a hit
                {      
                        a = 1;
                        b = 1;
                        
                        //a and b are set because there's no need to find further
                        break;
                }
            }
            if(a == 0)  //if page is not found, its a miss
            {
                //initial miss case
                for(m = 0; m < total_frames; m++)
                {
                    if(frames[m] == -1)   //if any frame is -1 ie empty
                    {
                        frames[m] = pages[n];   //put the page in that empty frame
                        b = 1;  //no need to replace any page
                        page_fault++;  //initial page fault
                        break;
                    }
                }
            }
            if(b == 0)
            {   //replacement is needed
            
                for(m = 0; m < total_frames; m++)
                {
                    temp[m] = 0;        //array taken to see if the pages is the frame occur or not
                }
                for(k = n + 1, l = 1; l <= total_frames-1 && k<total_pages; k++) 
            //k = n - 1 : from the last page.   l <= total_frames-1 : one less then the frame because we want to replace the one which is still no filled
            //k<total_pages : k can go till the last page
                {
                    for(m = 0; m < total_frames; m++)
                    {
                        if(frames[m] == pages[k]) //if that page occurs
                        {   
                            if(!temp[m]) {    //if it is already set that means we can check for one more frame
                            temp[m] = 1; //set the location in temp array
                            l++;
                            }
                           
                                   
                        }
                    }
                }
                for(m = 0; m < total_frames; m++)
                {   
                    
                    if(temp[m] == 0)  {  //WE NEED THE POSITION WHERE TEMP IS STILL 0. THAT IS THE POSITION WE NEED TO REPLACE
                        position = m;  //after we find the first 0 location, break
                        break;
                       
                    }
                }
                
                frames[position] = pages[n];
                page_fault++;
            }
            
            for(m = 0; m < total_frames; m++)
            {
                printf("%d\t", frames[m]);
            }
            printf("\n");
    }
    printf("\nTotal Number of Page Faults:\t%d\n", page_fault);
    
    return 0;
}