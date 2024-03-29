
#include <iostream>
using namespace std;

#define MAXSIZE 50
typedef int KeyType;

typedef  struct                     
{ KeyType  key;                                             
} ElemType;  

typedef  struct
{ ElemType  *R; 
  int  length;
} SSTable;                      

void  Create(SSTable &T)
{ int i;
  T.R=new ElemType[MAXSIZE+1];
  cin>>T.length;
  for(i=1;i<=T.length;i++)
     cin>>T.R[i].key;   
}

int  Search_Bin(SSTable T, KeyType k);

int main () 
{  SSTable T;  KeyType k;
   Create(T);
   cin>>k;
   int pos=Search_Bin(T,k);
   if(pos==0) cout<<"NOT FOUND"<<endl;
   else cout<<pos<<endl;
   return 0;
}

/* ����������д�� */
int  Search_Bin(SSTable T, KeyType k){
    int high, low, mid;
	low = 1;
	high = T.length;
	while (low <= high) {
		mid = (high + low) / 2;
		if (k == T.R[mid].key) return mid;
		else if (k > T.R[mid].key) low = mid + 1;
		else high = mid - 1;
	}
	return 0;
}