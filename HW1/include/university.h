#include <../include/student.h>
#include <iostream>

class University
{
private:
    std::string name_ = "";
    double weights[3];
    double bias_ = 0;
    std::string country_ = "";

public:
    // Declaration of evaluate_student method
    void evaluate_student(const Student &student) const;
    // Constructer with name, weights, bias, and country parameters
    University(std::string name, double weights1, double weights2, double weights3, double bias, std::string country)
    {
        this->name_ = name;
        this->weights[0] = weights1;
        this->weights[1] = weights2;
        this->weights[2] = weights3;
        this->bias_ = bias;
        this->country_ = country;
    };
    // Constructer with name, weights,and bias parameters
    University(std::string name, double weights1, double weights2, double weights3, double bias)
    {
        this->name_ = name;
        this->weights[0] = weights1;
        this->weights[1] = weights2;
        this->weights[2] = weights3;
        this->bias_ = bias;
    };
};
