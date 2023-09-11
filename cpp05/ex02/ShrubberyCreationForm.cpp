#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(/* args */)
{
	std::cout << "Shrubbery creation form constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() throw()
{
	std::cout << "Shrubbery creation form destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : target_(target)
{
	this->setIsSigned(false);
	this->setGradeForSigned(145);
	this->setGradeForExecute(137);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
{
	*this = rhs;
	std::cout << "Shrubbery creation form conversion constructor called" << std::endl;
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this == &rhs) return *this;
	this->setIsSigned(rhs.getIsSigned());
	this->setGradeForSigned(rhs.getGradeForSigned());
	this->setGradeForExecute(rhs.getGradeForExecute());
	return *this;
}

//코드 중복 줄이는 방법...?

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const 
{
	if (this->getIsSigned() == false) throw AForm::FormNotSigned();
    if (this->getGradeForExecute() < executor.getGrade()) throw Bureaucrat::GradeTooLowException();
	std::ofstream file(this->target_ + "_shrubbery");
	for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            file << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            file << "*";
        }
        file << std::endl;
    }
    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - 1; j++) {
            file << " ";
        }
        file << "|" << std::endl;
    }
    file.close();
    std::cout << "Execution of Shrubbery form success!" << std::endl;
}
