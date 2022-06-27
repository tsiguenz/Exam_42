/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:11:36 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/15 23:45:10 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <iostream>
# include "ASpell.hpp"

class Fwoosh: public ASpell {
	protected:
		std::string	type;

	public:
		Fwoosh();
		Fwoosh(std::string const& name, std::string const& effects);
		Fwoosh(Fwoosh const& fwoosh);
		Fwoosh&	operator=(Fwoosh const& fwoosh);
		virtual ~Fwoosh();
		virtual ASpell*	clone();
};

#endif // FWOOSH_HPP
