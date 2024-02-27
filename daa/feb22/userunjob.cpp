#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job
{
  int id;       // Job ID
  int deadline; // Deadline of job
  int profit;   // Profit of job
};

// Function to compare two jobs based on their profit
bool compare(Job a, Job b)
{
  return (a.profit > b.profit);
}

// Function to schedule jobs with maximum profit using greedy approach
void scheduleJobs(Job arr[], int n)
{
  // Sort jobs based on their profit in non-decreasing order
  sort(arr, arr + n, compare);

  int result[n]; // To store result (schedule)
  bool slot[n];  // To keep track of free time slots

  // Initialize all slots to be free
  for (int i = 0; i < n; i++)
    slot[i] = false;

  // Iterate through all given jobs
  for (int i = 0; i < n; i++)
  {
    // Find a free slot for this job (Note that we start from the last possible slot)
    for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
    {
      // If found a free slot, add this job to result and mark the slot as occupied
      if (slot[j] == false)
      {
        result[j] = i;  // Add this job to result
        slot[j] = true; // Mark the slot as occupied
        break;
      }
    }
  }

  // Print the scheduled jobs
  cout << "Scheduled Jobs: ";
  for (int i = 0; i < n; i++)
  {
    if (slot[i])
      cout << arr[result[i]].id << " ";
  }
  cout << endl;
}

int main()
{
  int n; // Number of jobs
  cout << "Enter the number of jobs: ";
  cin >> n;

  Job arr[n]; // Array to store jobs

  // Input jobs
  cout << "Enter job details (ID Deadline Profit) for " << n << " jobs:" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
  }

  // Schedule and print jobs
  scheduleJobs(arr, n);

  return 0;
}
