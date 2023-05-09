#include <iostream>
// Class for CUDA
class CUDA
{
public:
    // Constructor for CUDA class
    CUDA(int numCores);
    // Function to render video
    std::string render() const;
    // Function to train AI model
    std::string trainModel() const;

private:
    // Number of cores
    const int m_numCores;
};
// Class for ALU
class ALU
{
public:
    // Constructor for ALU class
    ALU(int numPerCores);
    // Function to add two integers
    int add(int a, int b) const;
    // Function to subtract two integers
    int subtract(int a, int b) const;
    // Function to multiply two integers
    int multiply(int a, int b) const;

private:
    // Number of cores per unit
    const int m_numPerCores;
};
// Class for CPU
class CPU
{
public:
    // Constructor for CPU class, initializes ALU with number of cores per unit
    CPU(int numPerCores);
    // Getter function to return constant reference to ALU
    const ALU &getALU() const;

private:
    const ALU m_alu;
};
// Class for GPU
class GPU
{
public:
    // Constructor for GPU class
    GPU(int numCores);
    // Getter function to return constant reference to CUDA
    const CUDA &getCUDA() const;

private:
    const CUDA m_cuda;
};
// Class for Computer
class Computer
{
public:
    // Constructor for Computer class
    Computer();
    // Overloaded operator + to attach CPU to Computer
    void operator+(const CPU &cpu);
    // Overloaded operator + to attach GPU to Computer
    void operator+(const GPU &gpu);
    // Function to execute operations
    void execute(const std::string &operation) const;

private:
    // Constant pointer to CPU
    const CPU *m_attachedCPU;
    // Constant pointer to GPU
    const GPU *m_attachedGPU;
    // Boolean to check if CPU is attached
    bool m_hasCPU;
    // Boolean to check if GPU is attached
    bool m_hasGPU;
};