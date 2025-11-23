#include <bits/stdc++.h>

using namespace std;

int main()
{
  // Requests in the disk queue
  vector<int> requests = {55, 58, 39, 18, 90, 160, 150, 38, 189};
  int head = 100; // Initial head position

  vector<bool> visited(requests.size(), false);
  int totalSeek = 0;
  vector<int> order;

  for (int i = 0; i < requests.size(); i++)
  {
    int idx = -1;
    int minDist = INT_MAX;

    // Find the request with minimum seek time from current head
    for (int j = 0; j < requests.size(); j++)
    {
      if (!visited[j])
      {
        int dist = abs(head - requests[j]);
        if (dist < minDist)
        {
          minDist = dist;
          idx = j;
        }
      }
    }

    // Move head to that request
    visited[idx] = true;
    totalSeek += minDist;
    head = requests[idx];
    order.push_back(head);
  }

  // Output
  cout << "Seek Sequence: ";
  for (int r : order)
    cout << r << " ";
  cout << "\nTotal Seek Time: " << totalSeek << endl;

  return 0;
}
