#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    std::cout << "----- SHRUBBERY TEST -----" << std::endl << std::endl;
    {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm form("home");

        boss.executeForm(form);

        boss.signForm(form);
        boss.executeForm(form);
    }

    std::cout << "\n----- ROBOTOMY TEST -----" << std::endl;
    {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm form("home");

        boss.signForm(form);

        boss.executeForm(form);
    }

    std::cout << "\n----- PRESIDENTIAL TEST -----" << std::endl;
    {
        Bureaucrat president("Boss", 1);
        PresidentialPardonForm form("home");

        president.signForm(form);
        president.executeForm(form);
    }

    std::cout << "\n----- LOW GRADE TEST -----" << std::endl;
    {
        Bureaucrat low("Slave", 150);
        ShrubberyCreationForm form("home");

        low.signForm(form);
        low.executeForm(form);
    }

    return 0;
}