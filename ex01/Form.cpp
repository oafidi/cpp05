#include "Form.hpp"

Form::Form()
        :name("default"),
        is_signed(false),
        grade_to_sign(150),
        grade_to_execute(150)
{
    std::cout << "default constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_execute)
        :name(name),
        is_signed(false),
        grade_to_sign(grade_to_sign),
        grade_to_execute(grade_to_execute)
{
    std::cout << "Parametrized Constructor called" << std::endl;

    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_execute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other) 
        :name(other.name),
        is_signed(other.is_signed),
        grade_to_sign(other.grade_to_sign),
        grade_to_execute(other.grade_to_execute)
{
    std::cout << "Copy Constructor called" << std::endl;
}

Form& Form::operator=(Form const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->is_signed = other.is_signed;
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::string	Form::getName() const
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->is_signed);
}

int	Form::getGradeToSign() const
{
	return (this->grade_to_sign);
}

int	Form::getGradeToExecute() const
{
	return (this->grade_to_execute);
}

void Form::beSigned(Bureaucrat const& bureaucrat)
{
    if (bureaucrat.getGrade() <= this->grade_to_sign)
        this->is_signed = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << f.getName()
       << ", signed: " << (f.getIsSigned() ? "true" : "false")
       << ", grade_to_sign: " << f.getGradeToSign()
       << ", grade_to_execute: " << f.getGradeToExecute();
    return os;
}
