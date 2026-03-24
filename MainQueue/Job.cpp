#include "Job.h"

void Job::setJobID(std::string id)
{
	jobID = id;
}

void Job::setTimeRemaining(int time)
{
	timeR = time;
}

std::string Job::getJobID()
{
	return jobID;
}

int Job::getTime()
{
	return timeR;
}


Job::Job(std::string id, int time)
{
	jobID = id;
	timeR = time;

}