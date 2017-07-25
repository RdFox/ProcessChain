#include "Duration.h"
#include <iostream>
using namespace std;

Duration::Duration()
{
	this->h = 0;
	this->m = 0;
	this->s = 0;
}

Duration::Duration(unsigned int h, unsigned int m, unsigned int s)
{
	while (s >= 60) {
		s -= 60;
		m++;
	}
	while (m >= 60) {
		m -= 60;
		h++;
	}

	this->h = h;
	this->m = m;
	this->s = s;
}

Duration::Duration(const Duration & copy) : Duration(copy.h, copy.m, copy.s)
{
	this->isDirty = copy.isDirty;
}


void Duration::SetDirty()
{
	this->isDirty = true;
}

std::ostream& operator << (std::ostream& os, const Duration& duration)
{
	os << '[' << duration.h << '|' << duration.m << '|' << duration.s << ']';
	return os;
}

Duration Duration::operator + (const Duration& rhs)
{
	Duration addedDuration(this->h + rhs.h, this->m + rhs.m, this->s + rhs.s);
	return addedDuration;
}

Duration Duration::Add(const Duration & arg1, const Duration & arg2)
{
	Duration addedDuration = Duration(arg1) + Duration(arg2);
	return addedDuration;
}