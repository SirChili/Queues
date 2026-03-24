#include <iostream>
#include <iomanip>
#include <queue>
#include "Job.h"

void printQueue(std::queue<Job> q) {

	std::queue<Job> tempQ = q;

	std::cout << std::setw(15) << std::left << "Job ID" << std::setw(30) << "Time Remaining(ms)" << std::endl;

	std::cout << "====================================" << std::endl;

	for (int i{}; i < q.size(); i++) {
		Job temp = tempQ.front();

		std::cout << std::setw(15) << std::left << temp.getJobID() << std::setw(30) << temp.getTime() << std::endl;

		tempQ.pop();
	}

}

Job createJob() {

	std::string id;
	int time;

	std::cout << "Enter Job ID: ";
	std::cin >> id;

	std::cout << "Enter Time Remaining: ";
	std::cin >> time; 

	Job newJob(id, time);

	return newJob;

}

int main() {

	int choice{};
	int runMax = 3;

	std::queue<Job> runnableQueue = {};
	std::queue<Job> sleepingQueue = {};

	while (choice != 6) {
		std::cout << " (^V^) Enter one of the following options:" << std::endl;
		std::cout << "1. Create job and add to \"Runnable\" queue" << std::endl;
		std::cout << "2. Display \"Runnable\" queue" << std::endl;
		std::cout << "3. Execute Job at front of queue" << std::endl;
		std::cout << "4. Display sleeping queue" << std::endl;
		std::cout << "5. Move job from Sleeping to \"Runnable\" queue " << std::endl;
		std::cout << "6. Exit " << std::endl;
		std::cin >> choice;


		switch (choice) {
		case 1:

			if (runnableQueue.size() < runMax) {
				runnableQueue.push(createJob());
				std::cout << "Job was successfully added to \"Runnable\" queue." << std::endl;
				std::cout << "There is now " << runnableQueue.size() << " jobs enqueued" << std::endl;
			}
			else {
				sleepingQueue.push(createJob());
				std::cout << "Max amount of jobs in \"Runnable\" queue is " << runMax << std::endl;
				std::cout << "Adding job to \"Sleeping\" queue" << std::endl;
			}

			break;
		case 2:
			if (runnableQueue.size() != 0) { printQueue(runnableQueue); }
			else { std::cout << "ERROR - \"Runnable\" queue is empty" << std::endl; }
			break;
		case 3:
			if (runnableQueue.size() != 0) {
				std::cout << "Executing Job ID " << runnableQueue.front().getJobID() << "..." << std::endl;
				runnableQueue.pop();
			}
			else { std::cout << "ERROR - \"Runnable\" queue is empty" << std::endl; 
			}			
			break;
		case 4:
			if (sleepingQueue.size() != 0) { printQueue(sleepingQueue); }
			else { std::cout << "ERROR - \"Sleeping\" queue is empty\n"; }
			break;
		case 5:
			if (runnableQueue.size() > runMax) {
				std::cout << "ERROR - insufficient memory in \"Runnable\" queue" << std::endl;
			
			}
			if (sleepingQueue.size() == 0) {
				std::cout << "ERROR - there are no jobs in \"Sleeping\" queue" << std::endl;
				
			}
			else {
				std::cout << "Moving job ID: " << sleepingQueue.front().getJobID() << " to \"Runnable\" queue..." << std::endl;
				runnableQueue.emplace(sleepingQueue.front());
				sleepingQueue.pop();
			}
			break;
		case 6:
			std::cout << "Closing Program..." << std::endl;
			break;
		default:
			std::cout << "Invalid Input" << std::endl;
			break;
		}
		

		system("Pause");
		system("cls");

	}
}

