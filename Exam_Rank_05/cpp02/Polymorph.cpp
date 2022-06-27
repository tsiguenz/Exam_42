/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:11:24 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/16 11:28:16 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph(): ASpell("Polymorph", "turned into a critter") { }

Polymorph::Polymorph(std::string const& name, std::string const& effects)
: ASpell(name, effects) { }

Polymorph::Polymorph(Polymorph const& polymorph) {
	*this = polymorph;
}

Polymorph&	Polymorph::operator=(Polymorph const& polymorph) {
	this->name = polymorph.name;
	this->effects = polymorph.effects;
	return (*this);
}

Polymorph::~Polymorph() { }

ASpell*	Polymorph::clone() {
	return new Polymorph;
}
