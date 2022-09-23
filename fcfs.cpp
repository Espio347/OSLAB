#include<bits/stdc++.h>

using namespace std;
 
//waiting time
void WT(int process[],int n,int burst[],int waiting[])
{
    waiting[0] = 0;
    for (int  i = 1; i < n ; i++ )
        waiting[i] =  burst[i-1] + waiting[i-1] ;
}
 
//turn around time
void TAT( int processes[],int n,int burst[],int waiting[],int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = burst[i] + waiting[i];
}
 
//average time
void AT( int process[],int n,int burst[])
{
    int waiting[n],tat[n],total_wait= 0,total_tat= 0;
    WT(process,n,burst,waiting);
    TAT(process,n,burst,waiting,tat);
    cout << "Process  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";
    for (int  i=0; i<n; i++)
    {
        total_wait = total_wait + waiting[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << burst[i] <<"\t    "<< waiting[i] <<"\t\t  " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "<< (float)total_wait / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n << endl;
}
 

int main()
{
    int process[] = { 1, 2, 3};
    int n = sizeof process / sizeof process[0];
    int  burst[] = {4, 4, 8};
    AT(process,n,burst);
    return 0;
}
