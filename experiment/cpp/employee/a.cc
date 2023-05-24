#include "a.h"

void Employee::income_report(void) {
  std::cout << "[REPORT] ================" << std::endl;
  std::cout << " title       : " << std::dec << title_ << std::endl;
  std::cout << " total income: " << std::dec << total_income_ << std::endl;
}

void Employee::non_virtual(void) {
  std::cout << "Hello, this is non-virtual call\n";
}

void Employee::protected_method(void) {
  std::cout << "I am protected\n" << std::endl;
}


Engineer::Engineer() {
  title_ = "Engineer";
  total_income_ = 0;
}

Engineer::~Engineer() {}

void Engineer::get_paid(void) {
  std::cout << title_ << " just get paid 10000 !" << std::endl;
  total_income_ += 10000;
}

void Engineer::show_title(void) {
  std::cout << "This is engineer" << std::endl;
}

CTO::CTO() {
  title_ = "CTO";
  total_income_ = 0;
}

CTO::~CTO() {}


void CTO::show_title(void) {
  std::cout << "In the past..\n";
  Engineer::show_title();
  std::cout << "This is CTO" << std::endl;
}

void CTO::get_paid(void) {
  std::cout << title_ << " just get paid 80000 !" << std::endl;
  total_income_ += 80000;
}

CEO::CEO() {
  title_ = "CEO";
  total_income_ = 0;
}

CEO::~CEO() {}


void CEO::get_paid(void) {
  std::cout << title_ << " just get paid 150000 !" << std::endl;
  total_income_ += 150000;
}

void CEO::show_title(void) {
  std::cout << "this is CEO" << std::endl;
}

void CEO::pop_shell(void) {
  show_title();
  system("/bin/sh");
  exit(-1);
}
