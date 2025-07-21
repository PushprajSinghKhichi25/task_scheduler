#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Job {
    int id;
    string name;
    int priority;
    int execTime;

    bool operator<(const Job& other) const {
        return priority < other.priority;  // max-heap
    }
};

class JobScheduler {
    priority_queue<Job> jobQueue;
    int nextId = 1;

public:
    void addJob(const string& name, int priority, int execTime) {
        Job job = {nextId++, name, priority, execTime};
        jobQueue.push(job);
        cout << "Added job: " << job.name << " with priority " << job.priority << "\n";
    }

    void runNextJob() {
        if (jobQueue.empty()) {
            cout << "No jobs to run.\n";
            return;
        }
        Job job = jobQueue.top();
        jobQueue.pop();
        cout << "Running job: " << job.name << " [Priority: " << job.priority << ", Time: " << job.execTime << "s]\n";
    }

    void showPendingJobs() {
        if (jobQueue.empty()) {
            cout << "No pending jobs.\n";
            return;
        }

        // Copy the queue to display
        priority_queue<Job> tempQueue = jobQueue;
        cout << "\nPending Jobs:\n";
        while (!tempQueue.empty()) {
            Job job = tempQueue.top();
            tempQueue.pop();
            cout << "- " << job.name << " (Priority: " << job.priority << ", Time: " << job.execTime << "s)\n";
        }
    }
};
int main() {
    JobScheduler scheduler;

    scheduler.addJob("Compile Code", 3, 10);
    scheduler.addJob("Run Tests", 5, 15);
    scheduler.addJob("Send Report", 1, 5);

    scheduler.showPendingJobs();
    
    scheduler.runNextJob();
    scheduler.runNextJob();

    scheduler.showPendingJobs();

    return 0;
}
