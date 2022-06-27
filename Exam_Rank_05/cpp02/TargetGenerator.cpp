/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:08:38 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/16 15:39:50 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() { }

TargetGenerator::TargetGenerator(TargetGenerator const& targetGenerator) { (void) targetGenerator; }

TargetGenerator::~TargetGenerator() {
	std::map<std::string, ATarget*>::iterator	it = this->_targets.begin();
	std::map<std::string, ATarget*>::iterator	ite = this->_targets.end();

	for (; it != ite; it++)
		delete it->second;
}

TargetGenerator&	TargetGenerator::operator=(TargetGenerator const& targetGenerator) {
	(void) targetGenerator;
	return *this;
}

void	TargetGenerator::learnTargetType(ATarget* target) {
	std::map<std::string, ATarget*>::iterator	it = this->_targets.find(target->getType());
	if (it == this->_targets.end())
		this->_targets.insert(std::pair<std::string, ATarget*>(target->getType(), target->clone()));
}

void	TargetGenerator::forgetTarget(std::string const& target) {
	std::map<std::string, ATarget*>::iterator	it = this->_targets.find(target);
	
	if (it != this->_targets.end()) {
		delete it->second;
		this->_targets.erase(target);
	}
}

ATarget*	TargetGenerator::createTarget(std::string const& target) {
	std::map<std::string, ATarget*>::iterator	it = this->_targets.find(target);
	if (it != this->_targets.end())
		return it->second;
	return NULL;
}
