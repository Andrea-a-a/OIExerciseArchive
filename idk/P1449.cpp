//P1739
#include <iostream>
#include <stack> 

using namespace std;

char c[256];
stack<char> a;

int main()
{
	for(int i = 0;; i ++)
	{
		cin >> c[i];
		if(c[i] == '@')
		{
			break;
		}
		if(c[i] == '(' )
		{
			a.push('(');
		}
		else if(c[i] == ')' && !a.empty())
		{
			a.pop();
		}
		else if(c[i] == ')' && a.empty())
		{
			printf("NO");
			return 0;
		}
		
	}
	
	if(!a.empty())
	{
		printf("NO");
		return 0;
	}
	else
	{
		printf("YES");
		return 0;
	}
}
