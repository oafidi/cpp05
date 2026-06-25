#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", "defaultTarget", 25, 5)
{
	std::cout << "Presidential default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout << "Presidential parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
	: AForm(other)
{
	std::cout << "Presidential copy constructor called" << std::endl;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	std::cout << "Presidential copy assignment operator called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential destructor called" << std::endl;
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}