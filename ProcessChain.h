#pragma once 
#include <string> 
#include <iostream> 
#include "Process.h" 
using namespace std;

class ProcessChain
{
	static const int MaxProcesses = 100;

	std::string name;
	Process * pChain[MaxProcesses];
	int processCounter;

	Duration CalcChainDuration();
public:
	explicit ProcessChain(const std::string& name);
	ProcessChain(const ProcessChain& copy);
	virtual ~ProcessChain();

	bool Insert(const Process& arg);
	friend std::ostream& operator<<(std::ostream& os, const ProcessChain& arg);
};