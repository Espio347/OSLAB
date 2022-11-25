//implementation of paging hardware for address translation
#include <bits/stdc++.h>

using namespace std;

 void calculatePhysicalAddress(int vm,int pgsize,int va)
 {
  int memPower=0,noOfPages=0,page=0,physicalAddress=206;
  int pageTable[4][2] = {{0,2},
                       {1,6},
                       {2,10},
                       {3,11}};
  //size of virtual memory
  while(vm)
  {
      vm/=2; 
      memPower++;
  }
  
  //no of pages to accomodate
  noOfPages = memPower - pgsize;  //1. How big is Page Table

  //determining frame no
  while(va>=4)
  { 
   va-=4;
   page++;
  }
  //frame
  int frameNo = pageTable[page][1]; // 2.this part is p
  int frameadd = frameNo * pgsize;

  //actual physical address?
  physicalAddress += frameadd + va;

  //Display Output
  cout<<"----------------------------------------"<<endl
      <<"Frame No.: "<<frameNo<<endl
      <<"[p|d]: "<<"["<<page<<"|"<<va<<"]"<<endl
      <<"No of Pages: "<<noOfPages<<endl
      <<"Page Size: "<<pgsize<<endl 
      <<"Physical Address Assigned to Process: "<<physicalAddress;
}
  
int main() {
  int virtualMemory = 16;
  int pageSize = 4;
  int virtualAddress = 11;
  calculatePhysicalAddress(virtualMemory,pageSize,virtualAddress);
  return 0;
}
