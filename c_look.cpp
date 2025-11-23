#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> requests = {18, 38, 39, 55, 58, 90, 150, 160, 189};
  int head = 100;

  sort(requests.begin(), requests.end());

  vector<int> seq;
  for (int x : requests)
  {
    if (x >= head)
      seq.push_back(x);
  }
  for (int x : requests)
  {
    if (x < head)
      seq.push_back(x);
  }

  int seek = 0, cur = head;
  for (int x : seq)
  {
    seek += abs(cur - x);
    cur = x;
  }

  cout << "Seek Sequence: ";
  for (int x : seq)
    cout << x << " ";
  cout << "\nTotal Seek: " << seek << endl;

  return 0;
}
