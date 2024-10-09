#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <map>
#include <string>
#include <vector>


namespace grade_school {
  using std::map;
  using std::string;
  using std::vector;

  class school {
   public:
    school() = default;
    const map<int, vector<string>> &roster() const;
    const vector<string> grade(int grade_number) const;
    void add(string name, int grade);  
   private:
    map<int, vector<string>> roster_;
  };

}  // namespace grade_school

#endif // GRADE_SCHOOL_H
