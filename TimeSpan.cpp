#include "stdafx.h"
#include "TimeSpan.h"
#include <cmath>
#include <stdexcept>

TimeSpan::TimeSpan()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}
TimeSpan::TimeSpan(float hour, float min, float sec)
{
	ConfigureTimeClock(hour, min, sec);
}
TimeSpan::TimeSpan(float min, float sec)
{
	ConfigureTimeClock(0, min, sec);
}
TimeSpan::TimeSpan(float sec)
{
	ConfigureTimeClock(0, 0, sec);
}
/*TimeSpan::TimeSpan(const TimeSpan &newTime)
{
hours = newTime.hours;
minutes = newTime.minutes;
seconds = newTime.seconds;
}
*/

void TimeSpan::ConfigureTimeClock(float floatingHours, float floatingMin, float floatingSec)
{
	hours = 0;
	minutes = 0;
	seconds = 0;
	float time = floatingHours * 60;
	time = time + floatingMin;
	time = time * 60;
	time = time + floatingSec;
	seconds = round(time);

	if (seconds >= 0)
	{
		while (seconds >= 60)
		{
			seconds = seconds - 60;
			minutes++;
		}
		while (minutes >= 60)
		{
			minutes = minutes - 60;
			hours++;
		}
	}
	else
	{
		while (seconds <= -60)
		{
			seconds = seconds + 60;
			minutes--;
		}
		while (minutes <= -60)
		{
			minutes = minutes + 60;
			hours--;
		}
	}
}

TimeSpan TimeSpan::operator=(const TimeSpan &time)
{
	hours = time.hours;
	minutes = time.minutes;
	seconds = time.seconds;
	return *this;
}

//just makes the time negative in all aspects (hours, min, secs)
TimeSpan TimeSpan::operator-()
{
	TimeSpan tempTime;
	tempTime.hours = -hours;
	tempTime.minutes = -minutes;
	tempTime.seconds = -seconds;
	return tempTime;
}

//multiplies time
TimeSpan TimeSpan:: operator*(const TimeSpan &time) const
{
	TimeSpan tempTime = *this;
	tempTime *= time;
	return tempTime;
}//done
TimeSpan TimeSpan:: operator+(const TimeSpan &time) const
{
	TimeSpan tempTime = *this;
	tempTime += time;
	return tempTime;
}//done
TimeSpan TimeSpan:: operator-(const TimeSpan &time) const
{
	TimeSpan tempTime = *this;
	tempTime -= time;
	return tempTime;
}//done

//allows time to be divided by time. and returns another
TimeSpan TimeSpan:: operator/(const TimeSpan &time) const	//add code for zero divide
{
	TimeSpan tempTime = *this;
	tempTime /= time;
	return tempTime;
}

bool TimeSpan:: operator==(const TimeSpan &time) const
{
	if (this->hours == time.hours)
	{
		if (this->minutes == time.minutes)
		{
			if (this->seconds == time.seconds)
			{
				return true;
			}
		}
	}
	return false;
}
bool TimeSpan:: operator!=(const TimeSpan &time) const
{
	return !(*this == time);
}
bool TimeSpan:: operator<=(const TimeSpan &time) const
{
	return !(*this > time);
}
bool TimeSpan:: operator>=(const TimeSpan &time) const
{
	return !(*this < time);
}
bool TimeSpan:: operator<(const TimeSpan &time) const
{
	if (this->hours == time.hours)
	{
		if (this->minutes == time.minutes)
		{
			if (this->seconds < time.seconds){
				return true;
			}
		}
		else if (minutes < time.minutes)
		{
			return true;
		}
	}
	else if (hours < time.hours)
	{
		return true;
	}
	return false;
}
bool TimeSpan:: operator>(const TimeSpan &time) const
{
	if (this->hours == time.hours)
	{
		if (this->minutes == time.minutes)
		{
			if (this->seconds > time.seconds){
				return true;
			}
		}
		else if (minutes > time.minutes)
		{
			return true;
		}
	}
	else if (hours > time.hours)
	{
		return true;
	}
	return false;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan &time)
{
	hours = hours + time.hours;
	minutes = minutes + time.minutes;
	seconds = seconds + time.seconds;
	ConfigureTimeClock(hours, minutes, seconds);
	return *this;
}//done
TimeSpan& TimeSpan::operator-=(const TimeSpan &time)
{
	hours = hours - time.hours;
	minutes = minutes - time.minutes;
	seconds = seconds - time.seconds;
	ConfigureTimeClock(hours, minutes, seconds);
	return *this;
}
TimeSpan& TimeSpan::operator*=(const TimeSpan &time)
{
	hours = hours * time.hours;
	minutes = minutes * time.minutes;
	seconds = seconds * time.seconds;
	ConfigureTimeClock(hours, minutes, seconds);
	return *this;
}
TimeSpan& TimeSpan::operator/=(const TimeSpan &time)
{
	if (time.hours != 0)
	{
		hours = hours / time.hours;
	}
	if (time.minutes != 0)
	{
		minutes = minutes / time.minutes;
	}
	if (time.seconds != 0)
	{
		seconds = seconds / time.seconds;
	}
	ConfigureTimeClock(hours, minutes, seconds);
	return *this;
}

ostream& operator<<(ostream &out, const TimeSpan &time)
{
	return out << "Hours: " << time.hours << " Minutes: " << time.minutes << " Seconds: " << time.seconds;
}
istream& operator>>(istream &in, TimeSpan &time)
{
	in >> time.hours >> time.minutes >> time.seconds;
	time.ConfigureTimeClock(time.hours, time.minutes, time.seconds);
	return in;
}

int TimeSpan::getHours() const
{
	return hours;
}
int TimeSpan::getMinutes() const
{
	return minutes;
}
int TimeSpan::getSeconds() const
{
	return seconds;
}

//checks sets time, allways true unless something other than ints are passed in.
bool TimeSpan::setTime(int newHours, int newMinutes, int newSeconds)
{
	ConfigureTimeClock(newHours, newMinutes, newSeconds);
	if (hours == NULL || minutes == NULL || seconds == NULL){
		return false;
	}
	return true;
}
TimeSpan::~TimeSpan()
{
}
