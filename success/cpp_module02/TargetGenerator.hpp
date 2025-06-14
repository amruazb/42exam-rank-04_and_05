#pragma once 
#include <iostream>
#include "ATarget.hpp"
#include "ATarget.hpp"
#include <map>


class TargetGenerator
{
	private:;
		TargetGenerator(TargetGenerator const &other);
		TargetGenerator &operator=(TargetGenerator const &other);
		std::map<std::string, ATarget *> arr;
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *atarget_ptr);
		void forgetTargetType(std::string const &name);
		ATarget* createTarget(std::string const &name);
};
