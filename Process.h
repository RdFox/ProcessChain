#pragma once 
#include <string> 
#include <iostream> 
#include "Duration.h"
using namespace std; 

class Process
{
	int id;
	std::string name;
	Duration* pDuration = nullptr;

public:
	Process(int id, std::string name);
	Process(const Process& copy);
	virtual ~Process();

	friend std::ostream& operator<<(std::ostream& os, const Process& arg);
	const Duration& TimeSpan();
	void TimeSpan(Duration& arg);
	int GetId() const;
};