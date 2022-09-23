/*
 * Box-it starter code: Hackerrank.com
 * Class Box: Justin Cromer
 * Date: 09/23/2022
 */

//#include<bits/stdc++.h>  /* because clang */
#include <iostream>
using namespace std;

using namespace std;
//Implement the class Box  
class Box {
private:
    int l, b, h;
public:
    Box() : l(0), b(0), h(0) {};
    Box(int x, int y, int z) : l(x), b(y), h(z) {};
    Box(Box &p_b) : l(p_b.l), b(p_b.b), h(p_b.h) {};
    
    int getLength() { return this->l; };
    int getBreadth() { return this->b; };
    int getHeight() { return this->h; };
    long long CalculateVolume() { 
        return (long)this->l * (long)this->b * (long)this->h;
    }

    bool operator<(Box &b) {
        bool rv = false;
        if (this->l < b.getLength()) {
            rv =  true;
        } else if (this->b < b.getBreadth() && this->l == b.getLength()) {
            rv = true;
        } else if (this->h < b.getHeight() && 
                   this->b == b.getBreadth() &&
                   this->l == b.getLength()) {
            rv = true;               
        }
        return rv;
    }
    
    friend ostream& operator<<(ostream& out, Box& B) {
        if (dynamic_cast<Box*>(&B) == nullptr) {
            return out;
        }
        out << B.l << " " << B.b << " " << B.h;
        return out;
    }
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
