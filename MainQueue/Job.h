#pragma once
#include <string>

class Job
{
protected:
	std::string jobID;
	int timeR;

public:
	void setJobID(std::string id);
	void setTimeRemaining(int time);

	std::string getJobID();
	int getTime();

	Job() = default;
	Job(std::string id, int time);
};

