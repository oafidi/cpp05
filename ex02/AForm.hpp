#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class AForm
{
    private:
        const std::string name;
        const std::string target;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;

    public:
        class GradeTooHighException : public std::exception 
        {
            public:
                const char * what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
            public:
                const char * what() const throw();
        };

        class FormNotSignedException : public std::exception 
        {
            public:
                const char * what() const throw();
        };

        AForm();
        virtual ~AForm();
        AForm(const std::string name, const std::string target, const int grade_to_sign, const int grade_to_execute);
        AForm(const AForm &other);
	    AForm& operator=(const AForm &other);

        std::string getName() const;
        std::string getTarget() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(Bureaucrat const& bureaucrat);
        void execute(Bureaucrat const & executor) const;

    protected:
        virtual void executeForm() const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
