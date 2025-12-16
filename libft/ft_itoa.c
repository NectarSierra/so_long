/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:06:13 by nsaillez          #+#    #+#             */
/*   Updated: 2024/10/18 15:16:57 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_str_size(int n)
{
	int	i;
	int	negative;

	negative = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		negative = 1;
	}
	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i + negative);
}

static char	*min_int(char *str)
{
	int		i;
	char	*number;

	i = 11;
	number = "-2147483648";
	str[11] = '\0';
	while (i > 0)
	{
		str[i] = number[i];
		i--;
	}
	str[i] = number[i];
	return (str);
}

static char	*neg_int(char *str, int n, int str_size)
{
	str[0] = '-';
	str[str_size] = '\0';
	n = -n;
	while (str_size > 1)
	{
		str[str_size] = (n % 10) + '0';
		n = n / 10;
		str_size--;
	}
	str[str_size] = (n % 10) + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		str_size;

	str_size = get_str_size(n);
	str = malloc((str_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (min_int(str));
	str[str_size] = '\0';
	str_size--;
	if (n < 0)
		return (neg_int(str, n, str_size));
	while (str_size > 0)
	{
		str[str_size] = (n % 10) + '0';
		n = n / 10;
		str_size--;
	}
	str[str_size] = (n % 10) + '0';
	return (str);
}

/*int main()
{
	int n = -123;
	printf("%s\n",ft_itoa(n));
}*/
