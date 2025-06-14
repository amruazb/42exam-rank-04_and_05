#pragma once 
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>


class SpellBook
{
	private:;
		SpellBook(SpellBook const &other);
		SpellBook &operator=(SpellBook const &other);
		std::map<std::string, ASpell *> arr;
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *aspell_ptr);
		void forgetSpell(std::string const &name);
		ASpell* createSpell(std::string const &name);
};
