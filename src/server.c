/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:13:08 by mabril            #+#    #+#             */
/*   Updated: 2024/11/07 20:26:49 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void ft_handler(int sig)
{
	static int bit;
	static int char_bin;

	if (sig == SIGUSR1)
		char_bin |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", char_bin);
		// if(char_bin == '\n')
		// 	exit(1);
		bit = 0;
		char_bin = 0;
	}
}
int	main(int ac, char **av)
{
	int pid;
	
	if(ac != 1 && av)
	{
		ft_printf(RED "error\n" RESET);
		ft_printf(YELLOW "Try: ./server\n" RESET);
	}
	
	
		pid = getpid();
		ft_printf( BLUE "%s" CYAN "%s" RESET "%d\n", "PID",  " -> ", pid);
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		while (1)
		{
			pause();
		}	
	
	return (0);
}


// addssdsfsdfsdfsfdsdsfdsfdsfsfsdfsdfsdfdsfdsfsdfdsfsfsdfdsfsfdsssdfsdfsdfdsfsdsdtequieroasdfsdffasdfasdfasdfasdfasdfasdfasdfdsafasdfasdfasdfasdfasdfsadfsadfasfasdfasdfasdfasdfasdfasdfasdfasdfsdfasdfasdfasdfasdfasdfasdfasdfasdfsadfasdfasdfaasdfssdfdsfsfsdffsdsfsdffsfdfsdsfdsdfsdsfsfdsfsdfsdfsdffsfjsdhfksjdhjkfshkfhsdfhksdfhdskjfhsjkfhsjkfhsdjkfhdjkhfjkdshfjksdhfjdksfhdjkshfkdjshfjkdhskjfhdskjfhkjsdhfjkshkjdhfjkshfkjshfkjsdhfjsdhfdksdhjkhfkjsdhfjkdshfjshdfkjdshfkjdshfjkdshfjksdhfkjdsfhsdjkfhdsjkfhuwehriuhriuwehiuewhuiheuifheiuhferuygheurhfeuifhdsuifhfjaksjdfjksagfhkeuyfghjbdkaefwygfiekywgfhjdsabfhjcbbhruewhruewbckfjbdjkhakufgdasufhkudcbkyasbuehuyegwuifhejkacgsfkjagjdscgfuyfwiuygwqeoegieygyrglkuewrowqgeyobweyucreqwgrcoborewbugruiebcrgwqobecruigewbioructiuweryoceiruwcbowequbcoiuwebcroybcuiwqeyriucbhdfkfjefhiuheiufwehiruewhriuyqruiwyrxonuyeriuonqerxgerofguihnuiehwiuhdiuewhddisuhflusdkhafuihkjsldajfljdsakjflkjasdlkfjsakldjfklsdjfklsdjfdlksjfdkslafjklsdjfklsjfsakljfdklsajlfjioewjriowrhqweiorhiudfhiudayfduiashufidafhouiqhweiurghufdshaflashiuqguiyegfoiuhsdoafhiugdyudshfuisdahuisadhfuiahfiufbyeubcuffsdfadsfasdfasdfasdfsdfasdfsdafasdfadshjkasdfhgjsadfgksajdgfhjsgdhjfgsahjdfghjsagjhfkashdfgkasghdjfhgksadgfjhshagdfdsafasdfsdfsdfdsfdsfdsfsdafdfdsfsdfsfdsfdsfsdffewrwerwertettyrtyrtyrtyrtyryrtytrytreryeyttttttttttttttttertyertyertyertyertytryrtryeyyyyyysalsa