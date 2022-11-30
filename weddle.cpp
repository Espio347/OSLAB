#include<iostream>
using namespace std;
#define f(x) 1/(1+x*x)

void findWeedle(float low,float up,int n,float h) {
     float s=0.0,k=0;
     for(int i=1;i<n;i++)
     {
      k = low + i*h;
      if(i%6==1)
       s+=5*f(k);
      else if(i%6==2 || i%6==4)
       s+=f(k);
      else if(i%6==3)
       s+=6*f(k);
      else if(i%6==5)
       s+= 5*f(k);
      else if(i%6==0)
       s+=2*f(k);
     }
     s+=f(up)+f(low);
     float ans=(3*h/10)*s;
     cout<<"The Integrated Value is: "<<ans<<endl;
}

int main()
{
 float low=0,up=6;
 int n=6;
 float h = (up - low)/n;
 findWeedle(low,up,n,h);
 return 0;
}
