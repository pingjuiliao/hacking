#ifndef A_H
#define A_H

#include <iostream>
#include <string>

class Employee {
 public:
  virtual ~Employee() = default;
  virtual void get_paid(void) = 0;
  virtual void income_report(void);
  std::string title_;
  int total_income_;
};

class Engineer: public Employee {
 public:
  Engineer();
  virtual ~Engineer();
  virtual void get_paid(void);
 private:
  std::string fav_prog_language;
};

class CTO: public Engineer {
 public:
  CTO();
  virtual ~CTO();
  virtual void get_paid(void);
  
  // income report will use Engineer's
  // virtual void income_report(void);
};
/*
class HumanResource: public Employee {
 public:
  HumanResource();
  virtual ~HumanResource();
  virtual void get_paid(void);
};

class HRManager: public HumanResource {
 public:
  HRManager();
  virtual ~HRManager();
  // Manager did not get paid well
};*/

class CEO : public Engineer {
 public:
  CEO();
  virtual ~CEO();
  virtual void get_paid(void);
};

#endif  // A_H
