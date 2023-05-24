#include "a.h"

void Employee::income_report(void) const {
  std::cout << "[REPORT] ================" << std::endl;
  std::cout << " title       : " << std::dec << title_ << std::endl;
  std::cout << " total income: " << std::dec << total_income_ << std::endl;
}


Engineer::Engineer() {
  title_ = "Engineer";
  total_income_ = 0;
}

Engineer::~Engineer() {}

void Engineer::get_paid(void) const {
  std::cout << title_ << " just get paid 10000 !" << std::endl;
  total_income_ += 10000;
}

CTO::CTO() {
  title_ = "CTO";
  total_income_ = 0;
}

CTO::~CTO() {}

void CTO::get_paid(void) const {
  std::cout << title_ << " just get paid 80000 !" << std::endl;
  total_income_ += 80000;
}


CEO::CEO() {
  title_ = "CEO";
  total_income_ = 0;
}

CEO::~CEO() {}

void CEO::get_paid(void) const {
  std::cout << title_ << " just get paid 150000 !" << std::endl;
  total_income_ += 150000;
}
