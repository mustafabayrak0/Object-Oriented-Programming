// Mustafa Bayrak 150210339
#include <Computer.h>
// Constructor for CUDA class, initializes number of cores
CUDA::CUDA(int numCores) : m_numCores(numCores)
{
    std::cout << "CUDA is ready\n";
}
// Constructor for ALU class, initializes number of cores per unit
ALU::ALU(int numPerCores) : m_numPerCores(numPerCores)
{
    std::cout << "ALU is ready\n";
}
// Constructor for CPU class, initializes ALU with number of cores per unit
CPU::CPU(int numPerCores) : m_alu(numPerCores)
{
    std::cout << "CPU is ready\n";
}
// Constructor for GPU class, initializes CUDA with number of cores
GPU::GPU(int numCores) : m_cuda(numCores)
{
    std::cout << "GPU is ready\n";
}
const CUDA &GPU::getCUDA() const
{
    return m_cuda;
}
const ALU &CPU::getALU() const
{
    return m_alu;
}
// Constructor for Computer class
Computer::Computer()
{
    std::cout << "Computer is ready\n";
    m_hasCPU = false;
    m_hasGPU = false;
}
// Overloaded operator + to attach CPU to Computer
void Computer::operator+(const CPU &cpu)
{
    // If CPU is already attached, print message
    if (m_hasCPU)
    {
        std::cout << "There is already a CPU\n";
    }
    // Else attach CPU
    else
    {
        m_attachedCPU = &cpu;
        m_hasCPU = true;
        std::cout << "CPU is attached\n";
    }
}
// Overloaded operator + to attach GPU to Computer
void Computer::operator+(const GPU &gpu)
{
    // If GPU is already attached, print message
    if (m_hasGPU)
    {
        std::cout << "There is already a GPU\n";
    }
    // Else attach GPU
    else
    {
        m_attachedGPU = &gpu;
        m_hasGPU = true;
        std::cout << "GPU is attached\n";
    }
}
// Executing the given operation on the attached components
void Computer::execute(const std::string &operation) const
{
    // Appropriate operation is executed based on the input
    if (operation == "add" || operation == "subtract" || operation == "multiply")
    {
        // integers to store the input
        int a, b;
        std::cout << "Enter two integers" << std::endl;
        // Taking input
        std::cin >> a >> b;
        // Execute add operation
        if (operation == "add")
        {
            std::cout << m_attachedCPU->getALU().add(a, b) << std::endl;
        }
        // Execute subtract operation
        else if (operation == "subtract")
        {
            std::cout << m_attachedCPU->getALU().subtract(a, b) << std::endl;
        }
        // Execute multiply operation
        else if (operation == "multiply")
        {
            std::cout << m_attachedCPU->getALU().multiply(a, b) << std::endl;
        }
    }
    // Execute render operation
    else if (operation == "render")
    {
        std::cout << m_attachedGPU->getCUDA().render() << std::endl;
    }
    // Execute trainModel operation
    else if (operation == "trainModel")
    {
        std::cout << m_attachedGPU->getCUDA().trainModel() << std::endl;
    }
}
// Function to render video
std::string CUDA::render() const
{
    return "Video is rendered";
}
// Function to train AI model
std::string CUDA::trainModel() const
{
    return "AI Model is trained";
}
// Function to add two integers
int ALU::add(int a, int b) const
{
    int result = a + b;
    return result;
}
// Function to subtract two integers
int ALU::subtract(int a, int b) const
{
    int result = a - b;
    return result;
}
// Function to multiply two integers
int ALU::multiply(int a, int b) const
{
    int result = a * b;
    return result;
}