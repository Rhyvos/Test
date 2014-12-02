// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
bool stop;

void foo(int x){
	int t=0;
	cout<<"Thread "<<x<<" Starts "<<endl;
	while(stop){
		
		
		t++;

	}
	cout<<"Ending Thread "<<x<<endl;

}
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	vector<thread*> v; 
	stop=true;
	for(int i=1;i<10;i++){

		v.push_back(new thread(foo,i));
		this_thread::sleep_for(chrono::milliseconds(rand()%20+1));
	}
	this_thread::sleep_for(chrono::seconds(5));
	stop=false;
	this_thread::sleep_for(chrono::seconds(4));
	cout<<"Ending Process"<<endl;
	system("pause");

	return 0;
}

