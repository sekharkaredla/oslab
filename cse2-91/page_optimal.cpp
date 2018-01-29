#include<iostream>
using namespace std;
int main()
 {
          int nop,nof,page[20],i,count=0;
          cout<<"\n\tEnter the No. of Pages:";
          cin>>nop;          //Store the no of pages
          cout<<"\n\t Enter the Reference String:";
          for(i=0;i<nop;i++)
          {
          cout<<"\t";
          cin>>page[i]; //Array for Storing Reference String
          }
          
          cout<<"\n\t Enter the No of frames:-";
          cin>>nof;
          int frame[nof],fcount[nof];
          for(i=0;i<nof;i++)
          {
          frame[i]=-1;  //Frame Array
          fcount[i]=0;  // Track the next Availability of frames
          }
          i=0;
          while(i<nop)
          {
            int j=0,flag=0;
            while(j<nof)
            {
               if(page[i]==frame[j]){ // Checking Whether the Page is Already in frame or not
               flag=1;
               }
               j++;
            }    
            j=0;   
            cout<<"\n\t**************************************\n";
            cout<<"\t"<<page[i]<<"-->";    
            if(flag==0)
            {
              if(i>=nof)
              {
             int max=0,k=0;
             while(k<nof)
             {
                int dist=0,j1=i+1;
                while(j1<nop)
                {
                if(frame[k]!=page[j1])  //Calculating Distances of pages that are in the frame to their next occurence
                dist++;
                else
                { 
                break;
                }
                j1++;
                }
               fcount[k]=dist; //Storing Distances into array
              k++;   
             }            
             k=0;
              while(k<nof-1)
                {
                 
                  if(fcount[max]<fcount[k+1]) //Finding out the maxximum distance
                    max=k+1;
                  k++;
                }
               frame[max]=page[i];   
             } 
             else {
                  frame[i%nof]=page[i];
                  }
               count++;  // Increasing Page Fault.
            
           
            while(j<nof)
            {
               cout<<"\t|"<<frame[j]<<"|";
               j++;
            }
            
             }
           i++;  
            
          }
          cout<<"\n\t**************************************\n";
          cout<<"\n\tPage Fault is:"<<count;
//          getch();
	float hitratio=float(count)/nop;
	float missratio=1.0-hitratio;
	cout<<"\n\thit ratio:"<<hitratio;
	cout<<"\n\tmiss ratio:"<<missratio<<endl;
	return 0;
}        
