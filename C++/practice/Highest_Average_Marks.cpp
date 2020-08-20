/**Student with Highest Average Marks**/

#include <iostream>
#include <unordered_map>
#define COLUMNS 2
using namespace std;

string* getBestStudent (string students[][COLUMNS], int size) {
  static string result[COLUMNS];
  unordered_map<string, pair<int, int>> mp;
  int i, total = 0, count = 0;

  result[1] = "0";

  for (i = 0; i < size; i++) {
    if (mp.find(students[i][0]) == mp.end()) {
      total = stoi(students[i][1]);
      count = 1;
    } else {
      total = mp[students[i][0]].first + stoi(students[i][1]);
      count = mp[students[i][0]].second + 1;
    }

    mp[students[i][0]] = make_pair(total, count);

    if (stoi(result[1]) <= total/count) {
      result[0] = students[i][0];
      result[1] = to_string(total/count);
    }
  }

  return result;
}

int main() {
  string students[][COLUMNS] = {{"jerry","65"}, {"bob","1"}, {"jerry","23"},{"jerry","23"}, {"jerry","100"},{"Eric","83"}};
  int size = sizeof(students)/sizeof(students[0]);
  string *bestStudent = getBestStudent(students, size);
  cout << bestStudent[0] << " - " <<  bestStudent[1] << endl;
  return 0;
}
