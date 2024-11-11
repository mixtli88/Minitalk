/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:13:08 by mabril            #+#    #+#             */
/*   Updated: 2024/11/11 02:17:46 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

// static g_state = 0;
static int g_state = 0;

char	*new_str(int len)
{
	char	*str;

	// ft_printf("entramos new_str\n");
	str = ft_calloc((len + 1), sizeof(char));
	// ft_printf("str = %s \n", str);
	len = strlen(str);
	// ft_printf("len str serv = %d \n", len);
	
	if (!str)
	{
		// ft_printf("la cadena no exite");
		exit(1);
	}
		
	return (str);
}

int	ft_client_pid(int sig)
{
	static int			bit;
	static unsigned int	num;
	int tem;
	
	tem =0;
	// ft_printf("bit %d = %d  ", bit, num);
	if (sig == SIGUSR1)
	{
		// ft_printf("bit %d = 1\n", bit);
		num |= (1u << bit);
	}
	// else
		// ft_printf("bit %d = 0\n", bit);
	bit++;
	if (bit == 32)
	{
		// ft_printf("entra str \n");
		// ft_printf("str en size = %s \n", str);
		tem = num;
		num = 0;
		bit = 0;
		g_state = 1;
		return (tem);
	}
	return (num);
}
char	*ft_handler_size(int sig)
{
	static int			bit;
	static unsigned int	num;
	char				*str;

	str = NULL;
	// ft_printf("sig size = %d ", sig);
	if (sig == SIGUSR1)
	{
		// ft_printf("bit %d = 1\n", bit);
		num |= (1u << bit);
	}
	// else
		// ft_printf("bit %d = 0\n", bit);
	bit++;
	if (bit == 32)
	{
		// ft_printf("len = %d \n", num);

		str = new_str(num);
		// ft_printf("str en size = %s \n", str);
	 	g_state = 2;
		bit = 0;
		num = 0;
		return (str);
	}
	return (str);
}

char	*ft_handler_char(int sig, char *str)
{
	static int	bit;
	static int	c;
	static int	i;

	// ft_printf("str en hand char = %s \n", str);
	// ft_printf("sig = %d ", sig);
	// ft_printf("bit = %d ", bit);
	if (sig == SIGUSR1)
	{
		// ft_printf("bit %d = 1\n", bit);
		c |= (0x01 << bit);
	}
	// else
		// ft_printf("bit %d = 0\n", bit);
	bit++;
	if (bit == 8)
	{
		str[i++] = c;
		
		// ft_printf("i = %d \n", i);
		// ft_printf("str[0] = %c \n", str[i]);
		// ft_printf("str[1] = %c \n", str[i]);
		// ft_printf("str[2] = %c \n", str[i]);
		// ft_printf("str[3] = %c \n", str[i]);
		// ft_printf("str[4] = %c \n", str[i]);
		// ft_printf("str[5] = %c \n", str[i]);
		// ft_printf("str[6] = %c \n", str[i]);
		if (c == '\0')
		{
			
			// ft_printf("estamos entrano b- 0\n");
			ft_printf("%s", str);
			ft_printf("%c", '\n');
			free(str);
			str = NULL;
		 	g_state = 0;
			i = 0;
		}
		bit = 0;
		c = 0;
	}
	return (str);
}

// void ft_handler(int sig)
// {
// 	static int bit;
// 	static int char_bin;

// 	// ft_printf("%d --", sig);
// 	if (sig == SIGUSR1)
// 	{
// 		// ft_printf("bit %d = 1\n", bit);
// 		char_bin |= (0x01 << bit);
// 	}
// 	// else
// 	// 	ft_printf("bit %d = 0\n", bit);
// 	bit++;
// 	if (bit == 8)
// 	{
// 		ft_printf("%c", char_bin);
// 		if(char_bin == '\n')
// 		{
// 			exit(1);
			
// 		}
// 			bit = 0;
// 			char_bin = 0;
		
// 	}
// }

void	ft_handler(int sig)
{
	static char	*str;
	static int c_pid;
	// int len=0;
	
	
	
	if  (g_state == 0)
	{
		c_pid = ft_client_pid(sig);
		
		// len = ft_strlen(str);
		// ft_printf("c_pid = %d  \n", c_pid);
		// ft_printf("len hande = %d  \n", len);
	}
	else if  (g_state == 1)
	{
		str = ft_handler_size(sig);
		// ft_printf("c_pid = %s  \n", str);
		
		// len = ft_strlen(str);
		// ft_printf("str en hand = %s  \n", str);
		// ft_printf("len hande = %d  \n", len);
	}
	else if (g_state == 2)
	{
		// ft_printf("entramos para hacer poner los c\n");

		str = ft_handler_char(sig, str);
	}
	if (c_pid)
        kill(c_pid, SIGUSR1); 
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 1 && av)
	{
		ft_printf(RED "error\n" RESET);
		ft_printf(YELLOW "Try: ./server\n" RESET);
	}
	pid = getpid();
	ft_printf(BLUE "%s" CYAN "%s" RESET "%d\n", "PID", " -> ", pid);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}

// addssdsfsdfsdfsfdsdsfdsfdsfsfsdfsdfsdfdsfdsfsdfdsfsfsdfdsfsfdsssdfsdfsdfdsfsdsdtequieroasdfsdffasdfasdfasdfasdfasdfasdfasdfdsafasdfasdfasdfasdfasdfsadfsadfasfasdfasdfasdfasdfasdfasdfasdfasdfsdfasdfasdfasdfasdfasdfasdfasdfasdfsadfasdfasdfaasdfssdfdsfsfsdffsdsfsdffsfdfsdsfdsdfsdsfsfdsfsdfsdfsdffsfjsdhfksjdhjkfshkfhsdfhksdfhdskjfhsjkfhsjkfhsdjkfhdjkhfjkdshfjksdhfjdksfhdjkshfkdjshfjkdhskjfhdskjfhkjsdhfjkshkjdhfjkshfkjshfkjsdhfjsdhfdksdhjkhfkjsdhfjkdshfjshdfkjdshfkjdshfjkdshfjksdhfkjdsfhsdjkfhdsjkfhuwehriuhriuwehiuewhuiheuifheiuhferuygheurhfeuifhdsuifhfjaksjdfjksagfhkeuyfghjbdkaefwygfiekywgfhjdsabfhjcbbhruewhruewbckfjbdjkhakufgdasufhkudcbkyasbuehuyegwuifhejkacgsfkjagjdscgfuyfwiuygwqeoegieygyrglkuewrowqgeyobweyucreqwgrcoborewbugruiebcrgwqobecruigewbioructiuweryoceiruwcbowequbcoiuwebcroybcuiwqeyriucbhdfkfjefhiuheiufwehiruewhriuyqruiwyrxonuyeriuonqerxgerofguihnuiehwiuhdiuewhddisuhflusdkhafuihkjsldajfljdsakjflkjasdlkfjsakldjfklsdjfklsdjfdlksjfdkslafjklsdjfklsjfsakljfdklsajlfjioewjriowrhqweiorhiudfhiudayfduiashufidafhouiqhweiurghufdshaflashiuqguiyegfoiuhsdoafhiugdyudshfuisdahuisadhfuiahfiufbyeubcuffsdfadsfasdfasdfasdfsdfasdfsdafasdfadshjkasdfhgjsadfgksajdgfhjsgdhjfgsahjdfghjsagjhfkashdfgkasghdjfhgksadgfjhshagdfdsafasdfsdfsdfdsfdsfdsfsdafdfdsfsdfsfdsfdsfsdffewrwerwertettyrtyrtyrtyrtyryrtytrytreryeyttttttttttttttttertyertyertyertyertytryrtryeyyyyyysalsa