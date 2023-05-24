#include <stdio.h>

#include <iostream>

#include "a.h"

const int kNumEmployee = 11;
void hire(Employee**);
void ceo_privilege(CEO*);
void JITROP(Employee**);
int arbit_write_prompt(void);
int arbit_read_prompt(void);
void upcast_demo(CTO* cto);
void downcast_demo(Engineer* eng);

int main(int argc, char** argv) {
  Employee* employees[kNumEmployee];

  // hire employees
  hire(employees);

  // CEO privilege
  ceo_privilege((CEO *) employees[0]);

  // ARBITRARY READ/WRITE VULNERABILITY
  JITROP(employees);

  // get paid for two month
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < kNumEmployee; ++j) {
      employees[j]->get_paid();
    } 
  }

  // income report
  for (int i = 0; i < kNumEmployee; ++i) {
    employees[i]->income_report();
  }

  
  upcast_demo((CTO *) employees[1]);
  downcast_demo((Engineer *)employees[1]);
  downcast_demo((Engineer *)employees[2]);
  
  for (int i = 0; i < kNumEmployee; ++i) {
    employees[i]->non_virtual();
  }

  return 0;
}

void hire(Employee** employees) {
  for (int i = 0; i < kNumEmployee; ++i) {
    switch(i) {
      case 0:
        employees[i] = new CEO();
        break;
      case 1:
        employees[i] = new CTO();
        break;
      default:
        employees[i] = new Engineer();
        break;
    } 
  }
}

void ceo_privilege(CEO* ceo) {
  printf("Initially, income is %u\n", ceo->total_income_);
  ceo->get_paid();
  ceo->income_report();
}

// 
void upcast_demo(CTO* cto) {
  Engineer* eng = dynamic_cast<Engineer*>(cto);
  std::cout << "Upcasting CTO to engineer\n"; 
  eng->show_title();
}

void downcast_demo(Engineer* eng) {
  CTO* cto = dynamic_cast<CTO*>(eng);
  if (!cto) {
    std::cout << "Cannot downcast Engineer to CTO\n";
    return;
  }
  std::cout << "Downcasting engineer to CTO\n";
  cto->show_title();
}

void JITROP(Employee** employees) {
  std::string cmd;
  for (int i = 0; i < kNumEmployee; ++i) {
    std::cout << "employee[" << std::dec << i << "]: " 
      << std::hex << employees[i] << std::endl;
  }

  while (true) {
    int r = arbit_read_prompt();
    if (r == -1)
      break;
  }

  while (true) {
    int r = arbit_write_prompt();
    if (r == -1)
      break;
  }
}

int arbit_read_prompt(void) {
  uint64_t addr;
  std::cout << "R addr : ";
  std::cin >> addr;
  if (!addr) {
    return -1;
  }
  uint64_t* ptr = reinterpret_cast<uint64_t*>(addr);
  std::cout << "R value : 0x" << std::hex << *ptr << std::endl;
  return 0;
}

int arbit_write_prompt(void) {
  uint64_t addr;
  uint64_t value;
  std::cout << "W addr : ";
  std::cin >> addr;
  if (!addr) {
    return -1;
  }
  std::cout << "W value: ";
  std::cin >> value;
  uint64_t* ptr = reinterpret_cast<uint64_t*>(addr);
  std::cout << "Mem[" << std::hex << addr << "] = " << std::hex << value << std::endl; 
  *ptr = value;
  return 0;
}
