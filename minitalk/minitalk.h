/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:59:49 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/11 08:44:12 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINITALK_H
#define _MINITALK_H

#include "./libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/random.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

#define SOH 1
#define STX 2
#define ETX 3
#define EOT 4

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_MODE_RESET "\x1b[0m"


#define WELCOME_MESSAGE "WELCOME TO MY SERVER... ENJOY THE TIME WHILE YOU ARE HERE MY FRIEND!" 

#define MODE_BOLD "\x1b[1m"
#define MODE_DIM "\x1b[2m"
#define MODE_ITALIC "\x1b[3m"
#define MODE_UNDERLINE "\x1b[4m"
#define MODE_BLINKING "\x1b[5m"
#define MODE_REVERSE "\x1b[7m"
#define MODE_STRIKETHROUGH "\x1b[9m"

#endif