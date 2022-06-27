/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:13:03 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/15 23:57:38 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() { }

ASpell::ASpell(std::string const& name, std::string const& effects)
: name(name), effects(effects) { }

ASpell::ASpell(ASpell const& spell) {
	*this = spell;
}

ASpell&	ASpell::operator=(ASpell const& spell) {
	this->name = spell.name;
	this->effects = spell.effects;
	return (*this);
}

ASpell::~ASpell() { }

std::string	ASpell::getName() const {
	return this->name;
}

std::string	ASpell::getEffects() const {
	return this->effects;
}

void	ASpell::launch(ATarget const& target) const {
	target.getHitBySpell(*this);
}
