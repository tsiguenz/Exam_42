/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:11:36 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/16 11:24:22 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include <iostream>
# include "ASpell.hpp"

class Fireball: public ASpell {
	protected:
		std::string	type;

	public:
		Fireball();
		Fireball(std::string const& name, std::string const& effects);
		Fireball(Fireball const& fireball);
		Fireball&	operator=(Fireball const& fireball);
		virtual ~Fireball();
		virtual ASpell*	clone();
};

#endif // FIREBALL_HPP
