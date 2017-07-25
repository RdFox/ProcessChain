#include "Process.h"

Process::Process(int id, const std::string name) : name(name){
	this->id = id;
	this->pDuration = new Duration();
}

Process::Process(const Process& copy) : name(copy.name){
	delete this->pDuration;
	this->id = copy.id;
	this->pDuration = new Duration(*copy.pDuration);
}

Process::~Process(){
	delete this->pDuration;
}

const Duration& Process::TimeSpan(){
	return *pDuration;
}

void Process::TimeSpan(Duration & arg){
	delete this->pDuration;
	this->pDuration = new Duration(arg);
}

int Process::GetId() const{
	return this->id;
}



std::ostream & operator<<(std::ostream & os, const Process & process){
	os << process.id << ' ' << process.name << ' ' << *process.pDuration;
	return os;
}

bool operator<(Process const & firstProcess, Process const & secondProcess){
	return firstProcess.GetId() < secondProcess.GetId();
}
