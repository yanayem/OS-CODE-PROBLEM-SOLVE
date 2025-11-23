#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> ref = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
  int n = ref.size();
  int fm = 3; // Number of frames

  vector<int> frames;
  int pagehit = 0, pagefault = 0;

  cout << "LRU Page Replacement Simulation\n\n";

  for (int i = 0; i < n; i++)
  {
    int page = ref[i];
    bool found = false;

    // Check if page is already in frames
    for (int j = 0; j < frames.size(); j++)
    {
      if (frames[j] == page)
      {
        found = true;
        break;
      }
    }

    if (found)
    {
      pagehit++;
      // Move this page to the most recently used position
      frames.erase(remove(frames.begin(), frames.end(), page), frames.end());
      frames.push_back(page);
    }
    else
    {
      pagefault++;
      if (frames.size() == fm)
      {
        // Remove least recently used page (first element)
        frames.erase(frames.begin());
      }
      frames.push_back(page);
    }

    // Display current frames (traditional loop)
    cout << "Frames after accessing page " << page << ": ";
    for (int j = 0; j < frames.size(); j++)
    {
      cout << frames[j] << " ";
    }
    cout << endl;
  }

  // Output statistics
  cout << "\nTotal Pages: " << n << endl;
  cout << "Total Page Hits: " << pagehit << endl;
  cout << "Total Page Misses: " << pagefault << endl;
  cout << "Hit Ratio: " << double(pagehit) / n << endl;
  cout << "Miss Ratio: " << double(pagefault) / n << endl;

  return 0;
}
