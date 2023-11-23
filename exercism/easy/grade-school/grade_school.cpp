#include "grade_school.h"
#include <algorithm>

namespace grade_school {

  const map<int, vector<string>> &school::roster() const { return roster_; }
  const vector<string> school::grade(int grade_number) const {
    return roster_.find(grade_number)->second;
  }
  void school::add(string name, int grade) {
    roster_[grade].push_back(name);
    std::sort(roster_[grade].begin(), roster_[grade].end());
  }

}// namespace grade_school
