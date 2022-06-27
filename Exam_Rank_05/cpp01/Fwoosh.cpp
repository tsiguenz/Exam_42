/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:11:24 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/15 23:41:13 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed") { }

Fwoosh::Fwoosh(std::string const& name, std::string const& effects)
: ASpell(name, effects) { }

Fwoosh::Fwoosh(Fwoosh const& fwoosh) {
	*this = fwoosh;
}

Fwoosh&	Fwoosh::operator=(Fwoosh const& fwoosh) {
	this->name = fwoosh.name;
	this->effects = fwoosh.effects;
	return (*this);
}

Fwoosh::~Fwoosh() { }

ASpell*	Fwoosh::clone() {
	return new Fwoosh;
}
