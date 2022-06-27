/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:08:36 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/06/16 15:25:29 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include <map>
# include "ATarget.hpp"

class TargetGenerator {
	private:
		TargetGenerator(TargetGenerator const& targetGenerator);
		TargetGenerator&	operator=(TargetGenerator const& targetGenerator);
		std::map<std::string, ATarget*>	_targets;

	public:
		TargetGenerator();
		virtual ~TargetGenerator();
		void	learnTargetType(ATarget* target);
		void	forgetTarget(std::string const& target);
		ATarget*	createTarget(std::string const& target);
};

#endif // TARGETGENERATOR_HPP
