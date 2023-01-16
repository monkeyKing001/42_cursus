#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < IDEA_NUM; i++)
		ideas[i] = "I have no idea because I have no idea";
	std::cout
		<< "Brain "
		<< "Default Constructor Called\n";
}

Brain::Brain(const Brain& obj)
{
	for (int i = 0; i < IDEA_NUM; i++)
	{
		this -> ideas[i] = obj.getIdea(i);
	}
	std::cout
		<< "Brain "
		<< "Copy Constructor Called\n";
}
Brain& Brain::operator=(const Brain &obj)
{
	for (int i = 0; i < IDEA_NUM - 1; ++i)
	{
		this -> ideas[i] = obj.getIdea(i);
	}
	std::cout
		<< "Brain "
		<< "Copy Assignmnet Constructor Called\n";
	return (*this);
}

Brain::~Brain(void)
{
	std::cout
		<< "Brain "
		<< "Destructor Called\n";
	//delete this -> ideas;
}

std::string Brain::getIdea(const int pri_order) const
{
	return (this -> ideas[pri_order]);
}

void Brain:: setIdea(const int pri_order, std::string ideaInMind)
{
	this -> ideas[pri_order] = ideaInMind;
}

void Brain:: brain_scan()
{
	std::cout << "========= In the Brain ========\n";
	for (int i = 0; i < IDEA_NUM; i++)
	{
		std::cout
			<< "Idea["
			<< i
			<< "] : "
			<< this -> getIdea(i)
			<< "\n";
	}
	std::cout << "============================\n";
}
