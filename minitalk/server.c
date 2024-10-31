/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:37:14 by npizzi            #+#    #+#             */
/*   Updated: 2024/09/11 08:43:58 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler_sigusr(int signum, siginfo_t *act, void *ucontext)
{
    static char c;
    static int calls;

    if (act->si_signo == SIGUSR2 && calls < 8)
        c |= 1 << calls;
    calls++;
    if (calls == 8)
    {
        if (c == 4)
        {
            write(1, "\n\n", 2);
            kill(act->si_pid, SIGUSR2);
            c = 0;
            calls = 0;
            return;
        }
        write(1, &c, 1);
        calls = 0;
        c = 0;
    }
    kill(act->si_pid, SIGUSR1);
    signum = signum;
    ucontext = ucontext;
}

int main(void)
{
    struct sigaction sa;
    
    sa.sa_sigaction = &handler_sigusr;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        printf(ANSI_COLOR_RED "Error handling SIGUSR1\n" ANSI_MODE_RESET);
        return (1);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        printf(ANSI_COLOR_RED "Error handling SIGUSR2\n" ANSI_MODE_RESET);
        return (1);
    }
    printf("\n\t");
    printf(ANSI_COLOR_CYAN MODE_BOLD WELCOME_MESSAGE ANSI_MODE_RESET);
    printf("\n\n\t\t\t\t");
    printf(MODE_BOLD ANSI_COLOR_CYAN "SERVER PID : %d\n\n" ANSI_MODE_RESET, getpid());
    fflush(stdout);
    while (1)
        pause();
    return (0);
}