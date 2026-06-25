#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n--- Test valid grade ---" << std::endl;
    try
    {
        Bureaucrat b("Omar", 75);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test high grade ---" << std::endl;
    try
    {
        Bureaucrat b("Yassine", 0);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test low grade ---" << std::endl;
    try
    {
        Bureaucrat b("Nouredine", 151);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test increment ---" << std::endl;
    try
    {
        Bureaucrat b("Ahmed", 2);
        std::cout << b << std::endl;
        b.increment();
        std::cout << b << std::endl;
        b.increment();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test decrement ---" << std::endl;
    try
    {
        Bureaucrat b("Aya", 149);
        std::cout << b << std::endl;
        b.decrement();
        std::cout << b << std::endl;
        b.decrement();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}