#include <iostream>
class Student
{
private:
    std::string name_ = "";
    double gpa_ = 0;
    double gre_ = 0;
    double toefl_ = 0;
    mutable int num_of_applications_ = 0;

public:
    // Declaration of getter functions
    double get_gpa() const;
    double get_gre() const;
    double get_toefl() const;
    std::string get_name() const { return name_; }
    int get_num_of_applications() const { return num_of_applications_; }

    // Declaration of setter functions
    void set_name(const std::string &name);
    void increment_num_of_applications() const { ++num_of_applications_; }

    // constructer with name,gpa,gre, and toefl parameters
    Student(std::string name, double gpa, double gre, double toefl)
    {
        this->name_ = name;
        this->gpa_ = gpa;
        this->gre_ = gre;
        this->toefl_ = toefl;
        std::cout << name << " logged in to the system. " << std::endl;
    };
    // Copy constructer
    Student(const Student &other)
    {
        name_ = other.name_;
        gpa_ = other.gpa_;
        gre_ = other.gre_;
        toefl_ = other.toefl_;
        num_of_applications_ = other.num_of_applications_;
        std::cout << name_ << " logged in to the system. " << std::endl;
    };
    // Destructer
    ~Student()
    {
        std::cout << this->name_ << " logged out of the system with " << this->num_of_applications_ << " application(s)." << std::endl;
    };
};