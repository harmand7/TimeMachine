#pragma once
#include <iostream>
using namespace std;	
class VendingBank
{
public:
	VendingBank();
	VendingBank(int id);
	VendingBank(int id, double startMoney);
	~VendingBank();

	bool AddMoney(double value);
	bool SubMoney(double value);
	double makeChange(Item soldItem, double recievedAmount);

	double getMoney();
	int getId();

	bool OpenForSale();
	bool isEmpty();
	string toString();

private:
	double money;
	int id;
	bool setId(int id);
	bool setMoney(double money);
};

