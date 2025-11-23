#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> ref = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
  int n = ref.size();
  int fm = 3; // number of frames

  vector<int> frames;
  int pagefault = 0;
  int pagehit = 0;

  for (int i = 0; i < n; i++)
  {
    int page = ref[i];
    bool found = false;

    // check if page is already in frame
    // for (int i = 0; i < frames.size(); i++) { int f = frames[i]; }
    for (int f : frames)
    {
      if (f == page)
      {
        found = true;
        break;
      }
    }

    if (!found)
    {
      pagefault++;
      if (frames.size() == fm)
      {
        frames.erase(frames.begin()); // FIFO remove first
      }
      frames.push_back(page);
    }
    else
    {
      pagehit++;
    }

    // Print current frame status
    cout << "Frames after accessing " << page << ": ";
    for (int f : frames)
      cout << f << " ";
    cout << endl;
  }

  cout << "\nTotal Pages: " << n << endl;
  cout << "Total Page Hits: " << pagehit << endl;
  cout << "Total Page Misses: " << pagefault << endl;

  cout << "Hit Ratio: " << double(pagehit) / n << endl;
  cout << "Miss Ratio: " << double(pagefault) / n << endl;

  return 0;
}
