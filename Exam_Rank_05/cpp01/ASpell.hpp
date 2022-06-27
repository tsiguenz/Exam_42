/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:10:38 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/15 23:45:35 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell {
	protected:
		std::string	name;
		std::string	effects;

	public:
		ASpell();
		ASpell(std::string const& name, std::string const& effects);
		ASpell(ASpell const& spell);
		ASpell&	operator=(ASpell const& spell);
		virtual ~ASpell();
		std::string	getName() const;
		std::string	getEffects() const;
		void	launch(ATarget const& target) const;
		virtual ASpell*	clone() = 0;
};

#endif // ASPELL_HPP
