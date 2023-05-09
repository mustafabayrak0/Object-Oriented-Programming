#include <../include/student.h>
#include <iostream>
// Implementation of setter functions
void Student::set_name(const std::string &name) { this->name_ = name; };

// Implementation of getter functions
double Student::get_gpa() const { return gpa_; }
double Student::get_gre() const { return gre_; }
double Student::get_toefl() const { return toefl_; }