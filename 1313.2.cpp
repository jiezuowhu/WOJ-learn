#include <iostream>
#include <memory>
#include<cstring>
     
using namespace std;

int Nmin[1000];      // ���Լ�¼��һά����
     
int KTail( int K )
{
     memset( Nmin, 0, sizeof(Nmin) );    

     long long int num = 1;                         
     bool flag = false;                 // ��Ҫһ����ǣ������ж��Ƿ�>=1000

     /*if ( K>=1000 )
     {
        flag = true;
        K=K%1000;                 
     } */                            
     
     for ( int i = 1; ; ++ i)
     {
         num *= K;               // num = (K^i-1)%1000 * K
         if ( flag || num>=1000 )     // ���������Ŀ������ K^i>=1000
         {
              flag = true;               // ���ǵ��п���֮ǰ��false���ٸ�ֵ
              num = num%1000;

              if ( Nmin[num]==0 )       
                    Nmin[num] = i;
                 else
                       return i + Nmin[num];   
             }
         }
    }
     
    int main()
    {
         int k;
         while(1)
         {
             cin>>k;
			 if(k==0) break;
             cout<<KTail(k)<<endl;
		 }
         return 0;
    }

     