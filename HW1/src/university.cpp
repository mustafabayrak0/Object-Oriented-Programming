#include <iostream>
#include <university.h>

// This method evaluates whether a student has been admitted.
void University::evaluate_student(const Student &student) const
{
    std::string name = student.get_name();
    double gpa = student.get_gpa();
    double gre = student.get_gre();
    double toefl = student.get_toefl();
    // Increase number of applications
    student.increment_num_of_applications();
    // Compute overall point by using weights and bias of university
    int overall_point = gpa * this->weights[0] + gre * this->weights[1] + toefl * this->weights[2] + this->bias_;
    // Student is admitted if overall point is greater than zero
    if (overall_point > 0)
    {
        std::cout << name << " is admitted to " << this->name_ << "." << std::endl;
    }
    else
    {
        std::cout << name << " is rejected from " << this->name_ << "." << std::endl;
    }
};