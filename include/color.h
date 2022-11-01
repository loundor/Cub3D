/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stissera <stissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:53:46 by stissera          #+#    #+#             */
/*   Updated: 2022/11/01 17:55:57 by stissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
#define COLOR_H

// Foreground color
#define	RST				"\001\e[0;0m\002"
#define	BLACK			"\001\e[0;30m\002"
#define	DARKRED			"\001\e[0;31m\002"
#define	DARKGREEN		"\001\e[0;32m\002"
#define	DARKYELLOW		"\001\e[0;33m\002"
#define	DARKBLUE		"\001\e[0;34m\002"
#define	DARKAMGENTA		"\001\e[0;35m\002"
#define	DARKCYAN		"\001\e[0;36m\002"
#define	GRAY			"\001\e[0;37m\002"
#define	DARKGRAY		"\001\e[1;90m\002"
#define	RED				"\001\e[1;91m\002"
#define	GREEN			"\001\e[1;92m\002"
#define	YELLOW			"\001\e[1;93m\002"
#define	BLUE			"\001\e[1;94m\002"
#define	MAGENTA			"\001\e[1;95m\002"
#define	CYAN			"\001\e[1;96m\002"
#define	WHITE			"\001\e[1;97m\002"
// Background color
#define BK_RST			"\001\e[49m\002"
#define BK_BLACK		"\001\e[40m\002"
#define BK_DARKRED		"\001\e[41m\002"
#define BK_DARKGREEN	"\001\e[42m\002"
#define BK_DARKYELLOW	"\001\e[43m\002"
#define BK_DARKBLUE		"\001\e[44m\002"
#define BK_DARKMAGENTA	"\001\e[45m\002"
#define BK_DARKCYAN		"\001\e[46m\002"
#define BK_GRAY			"\001\e[47m\002"
#define BK_DARKGRAY		"\001\e[100m\002"
#define BK_RED			"\001\e[101m\002"
#define BK_GREEN		"\001\e[102m\002"
#define BK_YELLOW		"\001\e[103m\002"
#define BK_BLUE			"\001\e[104m\002"
#define BK_MAGENTA		"\001\e[105m\002"
#define BK_CYAN			"\001\e[106m\002"
#define BK_WHITE		"\001\e[107m\002"

#endif