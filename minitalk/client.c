/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:49:00 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/23 12:27:59 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_char(char c, int server_pid)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if ((c & 1 << i) == 0)
        {
            if (kill(server_pid, SIGUSR1) == -1)
            {
                printf(ANSI_COLOR_RED "Error in sending SIGUSR1\n" ANSI_MODE_RESET);
                exit(1);
            }
        }
        else
        {
            if (kill(server_pid, SIGUSR2) == -1)
            {
                printf(ANSI_COLOR_RED "Error in sending SIGUSR1\n" ANSI_MODE_RESET);
                exit(1);
            }
        }
        i++;
        usleep(50000);
    }
}

void handler_sigusr(int signum)
{

    if (signum == SIGUSR1)
    {
        return;
    }
    if (signum == SIGUSR2)
    {
        printf(ANSI_COLOR_GREEN "Server got the message!\n" ANSI_MODE_RESET);
    }
}

void install_hanlder(void)
{
    struct sigaction sa;

    sa.sa_handler = &handler_sigusr;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        printf(ANSI_COLOR_RED "Error handling SIGUSR1\n" ANSI_MODE_RESET);
        exit(EXIT_FAILURE);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        printf(ANSI_COLOR_RED "Error handling SIGUS2\n" ANSI_MODE_RESET);
        exit(EXIT_FAILURE);
    }
}
int main(int argc, char *argv[])
{
    int server_pid;
    int i;
    
    install_hanlder();
    if (argc != 3)
    {
        printf("Insert only Server PID and String to send ppplease\n");
        return (1);
    }
    server_pid = ft_atoi(argv[1]);
    if (server_pid <= 0 || kill(server_pid, 0) == -1)
    {
        printf("Insert a valid PID\n");
        return (1);
    }
    i = 0;
    while (argv[2][i] != 0)
    {
        send_char(argv[2][i], server_pid);
        i++;
    }
    send_char(EOT, server_pid);
    return (0);
}
