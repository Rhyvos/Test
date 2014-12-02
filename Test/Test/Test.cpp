// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RakPeerInterface.h"
using namespace std;
bool stop;

void foo(int x){
	int t;
	
	while(stop){
		
		t=rand()%1000+50;
		cout<<"Thread "<<x<<" break "<<t<<endl;
		this_thread::sleep_for(chrono::milliseconds(t));

	}
	cout<<"Ending Thread "<<x<<endl;

}
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	vector<thread*> v; 
	stop=true;
	for(int i=1;i<100;i++){

		v.push_back(new thread(foo,i));
		this_thread::sleep_for(chrono::milliseconds(rand()%1000+50));
	}
	this_thread::sleep_for(chrono::seconds(10));
	stop=false;
	this_thread::sleep_for(chrono::seconds(4));
	cout<<"Ending Process"<<endl;
	system("pause");

	return 0;
}

