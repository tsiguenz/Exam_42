/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:49:22 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/15 23:51:58 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
# include "ASpell.hpp"

class ASpell;

class ATarget {
	protected:
		std::string	type;

	public:
		ATarget();
		ATarget(std::string const& type);
		ATarget(ATarget const& target);
		ATarget&	operator=(ATarget const& target);
		virtual ~ATarget();
		std::string const	getType() const;
		void	getHitBySpell(ASpell const& spell) const;
		virtual ATarget*	clone() = 0;
};

#endif // ATARGET_HPP
