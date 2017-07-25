#include "ProcessChain.h"
#include <iostream>
#include <algorithm>

using namespace std;

ProcessChain::ProcessChain(const std::string& name) : name(name) {
	for (int i = 0; i < MaxProcesses; i++) {
		this->pChain[i] = nullptr;
	}
	this->processCounter = 0;
}

ProcessChain::ProcessChain(const ProcessChain& copy) : name(copy.name) {
	this->processCounter = copy.processCounter;
	for (int i = 0; i < copy.MaxProcesses; i++) {
		if (copy.pChain[i] == nullptr) {
			this->pChain[i] = nullptr;
		} else {
			this->pChain[i] = new Process(*copy.pChain[i]);
		}
	}
}

ProcessChain::~ProcessChain() {
	for (int i = 0; i < MaxProcesses; i++) {
		delete this->pChain[i];
	}
}

Duration ProcessChain::CalcChainDuration() {
	Duration chainDuration = Duration();
	for (int i = 0; i < processCounter; i++) {
		chainDuration = chainDuration + pChain[i]->TimeSpan();
	}
	return chainDuration;
}


bool CompareProcessId(Process* firstProcess, Process* secondProcess) {
	return firstProcess->GetId() < secondProcess->GetId();
}

bool ProcessChain::Insert(const Process& arg) {
	if (processCounter >= MaxProcesses) {
		cout << "Overflowalert: ProcessChain already on 100 entrys";
		return false;
	}

	for (int i = 0; i < processCounter; i++) {
		if (pChain[i] != nullptr && pChain[i]->GetId() == arg.GetId()) {
			cout << "Process-id '" << arg.GetId() << "' duplicated";
			return false;
		}
	}

	if (pChain[processCounter] == nullptr) {
		pChain[processCounter] = new Process(arg); // add
		processCounter++;
		
		sort(pChain, pChain + processCounter, CompareProcessId); // resort
		return true;
	} else {
		cout << "pChain[processCounter] already filled";
	}

	return false;
}

std::ostream & operator<<(std::ostream & os, const ProcessChain & arg) {
	ProcessChain chain = arg;
	os << "Chain: '" << chain.name << "' has a complete duration of " << chain.CalcChainDuration()
		<< " with the following processes: " << endl;
	for (int i = 0; i < chain.MaxProcesses; i++) {
		Process* currentProcess = arg.pChain[i];
		if (currentProcess != nullptr) {
			Process p = *currentProcess;
			os << p << endl;
		}
	}
	return os;
}