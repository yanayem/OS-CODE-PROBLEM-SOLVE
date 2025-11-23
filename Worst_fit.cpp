#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> memory = {150, 350, 200, 400, 100, 300};
  vector<int> process = {115, 500, 210, 100, 375};
  vector<int> alloc(process.size(), -1);
  vector<int> memCopy = memory;

  // Worst Fit Allocation
  for (int i = 0; i < process.size(); i++)
  {
    int worst = -1;
    for (int j = 0; j < memCopy.size(); j++)
    {
      if (memCopy[j] >= process[i])
      {
        if (worst == -1 || memCopy[j] > memCopy[worst])
        {
          worst = j;
        }
      }
    }
    if (worst != -1)
    {
      alloc[i] = worst;
      memCopy[worst] -= process[i];
    }
  }

  // Internal Fragmentation Calculation
  int internalFrag = 0;
  for (int i = 0; i < process.size(); i++)
  {
    if (alloc[i] != -1)
      internalFrag += memCopy[alloc[i]];
  }

  // Total Free Space
  int totalFree = 0;
  for (int j = 0; j < memCopy.size(); j++)
    totalFree += memCopy[j];

  // Unused Free Space Calculation (never used blocks)
  int unusedFree = 0;
  for (int j = 0; j < memCopy.size(); j++)
  {
    if (memCopy[j] == memory[j])
      unusedFree += memCopy[j];
  }

  // Not Allocated Processes
  vector<int> notAllocatedList;
  for (int i = 0; i < process.size(); i++)
  {
    if (alloc[i] == -1)
      notAllocatedList.push_back(process[i]);
  }

  // Smallest Not Allocated Process
  int minNotAllocated = 0;
  if (!notAllocatedList.empty())
    minNotAllocated = *min_element(notAllocatedList.begin(), notAllocatedList.end());

  // External Fragmentation = min(smallest not allocated, total free)
  int externalFrag = 0;
  if (!notAllocatedList.empty())
    externalFrag = min(minNotAllocated, totalFree);

  // Output
  cout << "Total Internal Fragmentation: " << internalFrag << " KB\n";
  cout << "Unused Free Space (never used blocks): " << unusedFree << " KB\n";
  if (!notAllocatedList.empty())
    cout << "External Fragmentation: " << externalFrag << " KB\n";

  // Display process allocation
  for (int i = 0; i < process.size(); i++)
  {
    if (alloc[i] != -1)
      cout << "Process " << i + 1 << " (" << process[i] << " KB) -> Block " << alloc[i] + 1 << "\n";
    else
      cout << "Process " << i + 1 << " (" << process[i] << " KB) -> Not Allocated\n";
  }

  return 0;
}
