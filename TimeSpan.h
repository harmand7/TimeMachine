#pragma once
#include <iostream>
using namespace std;

class TimeSpan
{
	friend ostream& operator<<(std::ostream &out, const TimeSpan &time);
	friend istream& operator>>(std::istream &in, TimeSpan &time);

public:

	TimeSpan();
	TimeSpan(float hour, float min, float sec);
	TimeSpan(float min, float sec);
	TimeSpan(float sec);
	//TimeSpan(const TimeSpan &newTime);

	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

	TimeSpan operator=(const TimeSpan &time);
	TimeSpan TimeSpan::operator-();

	TimeSpan operator*(const TimeSpan &time) const;
	TimeSpan operator+(const TimeSpan &time) const;
	TimeSpan operator-(const TimeSpan &time) const;
	TimeSpan operator/(const TimeSpan &time) const;

	TimeSpan& operator+=(const TimeSpan &time);
	TimeSpan& operator-=(const TimeSpan &time);
	TimeSpan& operator*=(const TimeSpan &time);
	TimeSpan& operator/=(const TimeSpan &time);

	bool operator==(const TimeSpan &time) const;
	bool operator!=(const TimeSpan &time) const;

	bool operator<=(const TimeSpan &time) const;
	bool operator>=(const TimeSpan &time) const;

	bool operator<(const TimeSpan &time) const;
	bool operator>(const TimeSpan &time) const;

	bool setTime(int hours, int minutes, int seconds);

	//	void operator++(); not  clear
	//	void operator--();

	~TimeSpan();
private:
	int hours = NULL;
	int	minutes = NULL;
	int seconds = NULL;

	void ConfigureTimeClock(float hours, float min, float sec);
};
