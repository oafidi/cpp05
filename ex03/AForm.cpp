#include "AForm.hpp"

AForm::AForm()
        :name("default"),
        target("defaultTarget"),
        is_signed(false),
        grade_to_sign(150),
        grade_to_execute(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const std::string name, const std::string target, const int grade_to_sign, const int grade_to_execute)
        :name(name),
        target(target),
        is_signed(false),
        grade_to_sign(grade_to_sign),
        grade_to_execute(grade_to_execute)
{
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_execute > 150)
        throw GradeTooLowException();
    std::cout << "AForm parametrized constructor called" << std::endl;
}

AForm::AForm(const AForm &other) 
        :name(other.name),
        target(other.target),
        is_signed(other.is_signed),
        grade_to_sign(other.grade_to_sign),
        grade_to_execute(other.grade_to_execute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(AForm const &other)
{
    if (this != &other)
        this->is_signed = other.is_signed;
    std::cout << "AForm copy assignment operator called" << std::endl;
	return (*this);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::string	AForm::getName() const
{
	return (this->name);
}

std::string AForm::getTarget() const
{
    return (this->target);
}

bool AForm::getIsSigned() const
{
	return (this->is_signed);
}

int	AForm::getGradeToSign() const
{
	return (this->grade_to_sign);
}

int	AForm::getGradeToExecute() const
{
	return (this->grade_to_execute);
}

void AForm::beSigned(Bureaucrat const& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->grade_to_sign)
        this->is_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << f.getName()
       << ", target: " << f.getTarget()
       << ", signed: " << (f.getIsSigned() ? "true" : "false")
       << ", grade_to_sign: " << f.getGradeToSign()
       << ", grade_to_execute: " << f.getGradeToExecute();
    return os;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->is_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > this->grade_to_execute)
        throw GradeTooLowException();
    executeAction();
}
