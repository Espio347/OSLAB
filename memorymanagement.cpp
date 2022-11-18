#include<bits/stdc++.h>

using namespace std;

void findBestFit(int block[],int b,int process[],int p)
{
  int allocation[p];  
  //Determining the best fit for processes
  for (int i=0; i<p; i++)
    {
        int index = -1;
        for (int j=0; j<b; j++)
        {
            if (block[j] >= process[i])
            {
                if (index == -1)
                  index = j;
                else if (block[index] > block[j])
                  index = j;
            }
        }

        if (index != -1)
        {
            allocation[i] = index;
            block[index] -= process[i];
        }
    }
   //Display the allocated blocks
    cout << "\nProcess\tProcess Size\tBlock Number\n";
    for (int i = 0; i < p; i++)
    {
        cout << "   " << i+1 << "\t\t" << process[i] << "\t\t";
        (allocation[i] != -1)? cout << allocation[i] + 1 : cout << "Not Allocated";
        cout << endl;
    }
}


void findFirstFit(int block[],int b,int process[],int p)
{
   int allocation[p];
   memset(allocation, -1, sizeof(allocation));
  //Determining the first fit for processes
  for (int i=0; i<p; i++)
    {
        for (int j=0; j<b; j++)
        {
         if (block[j] >= process[i])
            {
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }
   //Display the allocated blocks
    cout << "\nProcess\tProcess Size\tBlock Number\n";
    for (int i = 0; i < p; i++)
    {
        cout << "   " << i+1 << "\t\t" << process[i] << "\t\t";
        (allocation[i] != -1)? cout << allocation[i] + 1 : cout << "Not Allocated";
        cout << endl;
    }
}


int main()
{
 int blockSize[] = {100,500,200,300,400};
 int processSize[] = {212,417,112,326,89};
 int b = sizeof(blockSize) / sizeof(blockSize[0]) ;
 int p = sizeof(blockSize) / sizeof(blockSize[0]) ;
 int choice;
 cout<<"What Approach would you like to Use?"<<endl;
 cout<<"Press 1 For Best Fit"<<endl<<"Press 2 for First Fit"<<endl;
 cout<<"Enter the Approach:"<<endl;
 cin>>choice;
 switch(choice)
 {
    case 1: findBestFit(blockSize,b,processSize,p);
    case 2: findFirstFit(blockSize,b,processSize,p);
 }
 //cout<<"Worst Fit:"<<endl;
 //findWorstFit(blockSize,b,processSize,p);
 //cout<<"Next Fit:"<<endl;
 //findNextFit(blockSize,b,processSize,p);
 return 0;
}
