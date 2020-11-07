#include<iostream>

using namespace std;

const int MAXN=100; 
int N=-1;

/*
m[][]ΪA[i:j]�����������˴��� 
s[][]Ϊ��Ӧm[][]�Ͽ�λ��k 
*/ 
void MatrixChain(int *p, int n, int m[MAXN][MAXN], int s[MAXN][MAXN])
{
	//i=jʱ��A[i:j]=AiΪ��һ����������� 
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int r=2;r<=n;r++)
	{
		for(int i=1;i<=n-r+1;i++)
		{
			int j = i+r-1;
			//��ʼ�� 
			m[i][j] = m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j] = i;
			for(int k=i+1;k<j;k++)
			{
				int t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				//ȡ����ֵ 
				if(t<m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
 				}
			}
		}
	}
	cout << m[1][N-1] << " ";
}
/* 
void Traceback(int i,int j,int s[MAXN][MAXN])
{
	if(i==j)
		return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"A"<<i<<","<<s[i][j];
	cout<<"B"<<(s[i][j]+1)<<","<<j<<endl;
	
}*/


void PrintAnswer(int s[MAXN][MAXN],int i,int j, int N)
{
    //cout << judge << " " << i << " " << j << endl;
	if(i==j)
    {
        cout<<"A"<<i;
    }
    else
    {
			cout << "(";
			PrintAnswer(s,i,s[i][j],N);
	     	PrintAnswer(s,s[i][j]+1,j,N);
	     	cout << ")";
    }
}

int main()
{
	int count = 1; 
	while(cin >> N)
	{
		if (N == 0)
	    	break;
		int m[MAXN][MAXN], s[MAXN][MAXN];
		int p[MAXN];
		int judge = 0;
		N++;
		for(int i=0; i<N; i++)
		{
			cin >> p[i];
		}
		cout << "Case " << count << ":" << endl;
		MatrixChain(p,N,m,s);
	    PrintAnswer(s,1,N-1,N-1);
	  //  Traceback(1,N-1,s);
	    cout << endl;
	    count++;
	   
	}
		
	return 0;
}
