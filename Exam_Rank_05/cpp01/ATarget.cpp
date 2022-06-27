/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:49:26 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/15 23:18:13 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget() { }

ATarget::ATarget(std::string const& type)
: type(type) { }

ATarget::ATarget(ATarget const& target) {
	*this = target;
}

ATarget&	ATarget::operator=(ATarget const& target) {
	this->type = target.type;
	return (*this);
}

ATarget::~ATarget() { }

std::string	const ATarget::getType() const {
	return this->type;
}

void	ATarget::getHitBySpell(ASpell const& spell) const {
	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}
