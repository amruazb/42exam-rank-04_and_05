#pragma once 
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	private:
		std::string type;

	public:
		ATarget();
		ATarget(ATarget const &other);
		ATarget &operator=(ATarget const &other);
		ATarget(std::string const &type);
		virtual ~ATarget();

		std::string const &getType() const;

		void getHitBySpell(ASpell const &aspell_ref) const;
		virtual ATarget *clone() const = 0;
};
