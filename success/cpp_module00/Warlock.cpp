#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(Warlock const &other)
{
	*this = other;
}
Warlock &Warlock::operator=(Warlock const &other)
{
	this->name = other.name;
	this->title = other.title;
	return *this;
}


Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;
	std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!\n";
}

std::string const &Warlock::getName() const
{
	return this->name;
}
std::string const &Warlock::getTitle() const
{
	return this->title;
}

void Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
};
