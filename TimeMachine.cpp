// TimeMachine.cpp : Defines the entry point for the console application.
//Harman Dhunna 
//CSS342

#include "stdafx.h"
#include "TimeSpan.h"

int main()
{

	TimeSpan ts1(1, 24, 0);
	TimeSpan ts2(0, 84, 0);
	TimeSpan ts3 = ts1 + ts2;
	cout << "ts1: " << ts1 << endl;
	cout << "ts2: " << ts2 << endl;
	cout << "ts3: " << ts3 << endl;
	if (ts1 == ts2){
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}

	int waitVar;
	TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -53, 0), dur4(0, 0, 0);

	TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8, dur9;

	cout << "TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -53, 0), dur4(0, 0, 0);" << endl;

	cout << "TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8, dur9;" << endl;


	dur7 = dur1 + dur3;
	cout << dur1 << endl;
	cout << dur2 << endl;
	cout << dur3 << endl;
	cout << dur4 << endl;
	cout << dur5 << endl;
	cout << dur6 << endl;
	cout << dur7 << endl;
	dur6 = -dur6;
	cout << "negative of dur6 " << dur6 << endl;
	cout << dur9 << endl;
	dur7 += dur3;
	cout << dur3 << endl;
	cout << dur7 << endl;

	dur7 -= dur3;
	cout << dur3 << endl;
	cout << dur7 << endl;

	dur3 = dur4;

	if (dur3 == dur4)
	{
		cout << "equal and changed to 1:1:0" << endl;
		dur3.setTime(1, 1, 0);
		dur4.setTime(1.1, 2, 3);
		cout << dur3 << endl;
		cout << dur4 << endl;
	}
	else
	{
		cout << "not equal and false" << endl;
	}

	if (dur3 != dur4)
	{
		cout << "not equal and true" << endl;
	}
	else
	{
		cout << "equal and false" << endl;
	}

	if (dur3 > dur4)
	{
		cout << "dur3 is less and false" << endl;

	}
	else
	{
		cout << "dur3 is less and ture" << endl;
	}
	dur3.setTime(2, 3, 3);
	dur3 = dur4;
	if (dur3 >= dur4)
	{
		cout << "THIS dur3 is equal and true" << endl << "dur is changed and set to 000" << endl;
		dur3.setTime(0, 0, 0);
	}
	else
	{
		cout << "dur3 is equal and false" << endl;
	}
	if (dur3 < dur4)
	{
		cout << "this less and true" << endl; 
	}
	else
	{
		cout << "this less and false" << endl;
	}
	return 0;
}

