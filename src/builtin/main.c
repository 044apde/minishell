#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_env_list
{
	char				**env;
	char				*key;
	char				*value;
	struct s_env_list	*next;
}	t_env_list;

// int	ft_isdigit(int c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	return (0);
// }


int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;

	if (dst == 0 && src == 0)
		return (0);
	dest = (unsigned char *) dst;
	source = (unsigned char *) src;
	while (n-- > 0)
		*dest++ = *source++;
	return (dst);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (len_src + 1 <= dstsize)
	{
		ft_memcpy (dst, src, len_src + 1);
	}
	else if (dstsize != 0)
	{
		ft_memcpy (dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (len_src);
}


// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	len_s;

// 	len_s = ft_strlen(s);
// 	while (len_s-- > 0)
// 		write(fd, s++, 1);
// }


// int	ft_atoi(const char *str)
// {
// 	int	result;
// 	int	f_minus;

// 	result = 0;
// 	f_minus = 1;
// 	while ((*str >= 9 && *str <= 13) || *str == 32)
// 		str++;
// 	if (*str == '+' || *str == '-')
// 	{
// 		if (*str == '-')
// 			f_minus = -1;
// 		str++;
// 	}
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		result = result * 10 + (*str - 48);
// 		str++;
// 	}
// 	return (result * f_minus);
// }

// int	print_error_exit(char *str, int flag)
// {
// 	int	exit_num;
// 	if (flag == 1)
// 	{
// 		ft_putstr_fd("ohmybash# exit: ", 2);
// 		ft_putstr_fd(str, 2);
// 		ft_putstr_fd(": numeric argument required\n", 2);
// 		exit_num = 255;
// 	}
// 	else if (flag == 2)
// 	{
// 		exit_num = 1;
// 		ft_putstr_fd("ohmybash# exit: too many arguments\n", 2);
// 	}
// 	return (exit_num);
// }


// int	check_num(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 		i++;
// 	if (!str[i])
// 		return (0);
// 	while (str[i])
// 	{
// 		if (!ft_isdigit(str[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// void	ft_exit(int argc, char **argv)
// {
// 	int	i;
// 	int	exit_num;

// 	i = 0;
// 	ft_putstr_fd("exit\n", 2);
// 	if (argc > 1)
// 	{
// 		if (check_num(argv[1]) != 1) // 숫자가 아니면 에러 메시지 출력 후 종료
// 		{
// 			exit_num = print_error_exit(argv[1], 1);
// 		}
// 		else if (argc == 2)
// 			exit(ft_atoi(argv[1]));
// 		if (argc > 2) // 인자가 2개 이상이면 에러 메시지 출력 후 종료안됨
// 		{
// 			ft_putstr_fd("ohmybash# exit: too many arguments\n", 2);
// 			exit_num = 1;
// 		}
// 	}
// }

// void	ft_pwd(void)
// {
// 	char	*buf;

// 	buf = getcwd(NULL, 0);
// 	ft_putstr_fd(buf, 1);
// 	ft_putstr_fd("\n", 1);
// 	free(buf);
// }

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	int		env_count;
	char	**env_list;
	int		i;

	env_count = 0;
	while (envp[env_count])
		env_count++;
	i = 0;
	env_list = (char **)malloc(sizeof(char *) * (env_count + 1));
	if (!env_list)
	{
		printf("malloc error\n");
		return (1);
	}
	while (i < env_count)
	{
		env_list[i] = (char *)malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
		if (!env_list[i])
		{
			i = 0;
			while (i < env_count)
				free(env_list[i++]);
			return (1);
		}
		ft_strlcpy(env_list[i], envp[i], ft_strlen(envp[i]) + 1);
		i++;
	}
	env_list[i] = NULL;

	for (int i = 0; i < env_count; i++)
	{
		printf("%s\n", envp[i]);
	}
	return (0);
}
