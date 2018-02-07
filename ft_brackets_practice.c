/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brackets_practice.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:57:28 by bpierce           #+#    #+#             */
/*   Updated: 2017/07/12 15:09:09 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s)
		write(1, &s[0], ft_strlen(s));
}

int		is_open(char c)
{
	return (c == '(' || c == '{' || c == '[');
}

int		is_close(char c)
{
	return (c == ')' || c == '}' || c == ']');
}

int		is_acceptable(char cur_open_bracket, char cur_char)
{
	if (cur_open_bracket == '(')
		return (cur_char == ')');
	if (cur_open_bracket == '{')
		return (cur_char == '}');
	if (cur_open_bracket == '[')
		return (cur_char == ']');
	return (0);
}

int		b_recursive(char *s, int i, int cur_open)
{
	while (s[i])
	{
		if (is_open(s[i]))
			i = b_recursive(s, i + 1, s[i]);
		else if (is_close(s[i]))
			return ((is_acceptable(cur_open, s[i])) ? i + 1 : -1);
		else
			i++;
	}
	return (-1);
}

int		brackets(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (is_close(s[i]))
			return (-1);
		else if (is_open(s[i]))
		{
			i = b_recursive(s, i + 1, s[i]);
			if (i == -1)
				return (-1);
		}
		else
			i++;
	}
	return (1);
}

void	output(int n)
{
	ft_putstr(n == 1 ? "OK\n" : "Error\n");
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc > 1)
	{
		while (argv[++i])
			output(brackets(argv[i]));
	}
	else
		ft_putchar('\n');
	return (1);
}
