//T292786
#include<iostream>
#include<stack>

using namespace std;
int a, a0;
int b[1001], b0=0;
stack<int> c;
 
int main()
{
	cin >> a;
//cout<<" a: "<<a;
	//a0 = a;
	for(int i = 0;i<a; i++)
	{
		cin>>b[i];
//cout << " b: "<<b[i]<<endl ;
	}
	for(a0 = 1; a0 <= a; a0++)
	{
		
		c.push(a0);
		//cout<< a0 <<"b0:"<<b0<<endl<<c.top()<<endl;
		if(c.top() ==b[b0])
		{         
			
			c.pop();
			b0++;
		}
	}

	while(c.top()==b[b0]&&!c.empty())
		{
			c.pop();
			b0++;
		}
		
	if(c.empty())
	{
	printf("YES");
	return 0;
	}
	else
	{
		printf("NO");
		return 0;
	}
	


}
