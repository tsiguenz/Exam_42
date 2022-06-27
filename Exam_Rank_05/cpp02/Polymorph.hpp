/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:11:36 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/16 11:27:25 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include <iostream>
# include "ASpell.hpp"

class Polymorph: public ASpell {
	protected:
		std::string	type;

	public:
		Polymorph();
		Polymorph(std::string const& name, std::string const& effects);
		Polymorph(Polymorph const& polymorph);
		Polymorph&	operator=(Polymorph const& polymorph);
		virtual ~Polymorph();
		virtual ASpell*	clone();
};

#endif // POLYMORPH_HPP
