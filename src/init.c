/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:19:26 by mabril            #+#    #+#             */
/*   Updated: 2024/11/07 20:26:49 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mach/mach.h>
#include <libproc.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <process_command>\n", argv[0]);
        return 1;
    }

    pid_t *pid_list;
    int pid_count;

    // Get the list of all running processes
    pid_count = proc_listpids(PROC_ALL_PIDS, 0, NULL, 0);
    if (pid_count <= 0) {
        fprintf(stderr, "Failed to get process list\n");
        return 1;
    }

    pid_list = malloc(pid_count * sizeof(pid_t));
    pid_count = proc_listpids(PROC_ALL_PIDS, 0, pid_list, pid_count * sizeof(pid_t));

    // Search for the process with the given command
    for (int i = 0; i < pid_count; i++) {
        char process_name[PROC_PIDPATHINFO_MAXSIZE];
        if (proc_pidpath(pid_list[i], process_name, sizeof(process_name)) > 0) {
            if (strstr(process_name, argv[1])) {
                ft_printf("Found process '%s' with PID %d\n", argv[1], pid_list[i]);
                free(pid_list);
                return 0;
            }
        }
    }

    free(pid_list);
    ft_printf("Failed to find process '%s'\n", argv[1]);
    return 1;
}