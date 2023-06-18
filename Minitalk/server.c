#include "../../include/minitalk.h"

int receiving = 0;

void  handle_signal(int signal, siginfo_t * info, void * context)
{
    static unsigned char    c = 0;
    static int              bit = 7;
    
    (void)context;
    if (signal == SIGUSR2)
        c |= (1 << bit);
    bit--;
    if (bit < 0)
    {   
        if (c == '\0')
            write(STDOUT_FILENO, "\n", 1);
        else    
            write(STDOUT_FILENO, &c, 1);
        bit = 7;
        c = 0;
    }
    send_signal(info->si_pid, SIGUSR1); 
}

int main()
{   
    struct sigaction sig_action;
    char *process_ID;

    process_ID = ft_itoa(getpid());
    if(*process_ID == -1)
    {
        ft_putstr_fd("Error: Process ID retrieval failed.\n", STDERR_FILENO);
        exit(EXIT_FAILURE);
    }        
    ft_putstr_fd("Server Process ID:", STDOUT_FILENO);
    ft_putstr_fd(process_ID, STDOUT_FILENO);
    ft_putstr_fd("\n", STDOUT_FILENO);

    ft_memset(&sig_action, 0, sizeof(struct sigaction));
    sig_action.sa_sigaction = &handle_signal;
    sigemptyset(&sig_action.sa_mask);
    sig_action.sa_flags = SA_RESTART | SA_SIGINFO;
    sigaction(SIGUSR1, &sig_action, NULL);
    sigaction(SIGUSR2, &sig_action, NULL);
    while (1)
        pause();
    return (0);
}