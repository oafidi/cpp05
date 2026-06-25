#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", "defaultTarget", 72, 45)
{
	std::cout << "Robotomy default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", target, 72, 45)
{
	std::cout << "Robotomy parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: AForm(other)
{
	std::cout << "Robotomy copy constructor called" << std::endl;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	std::cout << "Robotomy copy assignment operator called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destructor called" << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "Traq Traq Traq ....." << std::endl;

    if (rand() % 2)
        std::cout << this->getTarget() << " has been robotomized successfully 50% of the time." << std::endl;
    else
		std::cout << "the robotomy failed!" << std::endl;
}