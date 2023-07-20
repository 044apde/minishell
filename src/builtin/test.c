#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_env_list
{
	char				**env;
	char				*key;
	char				*value;
	struct s_env_list	*next;
}	t_env_list;

int	ft_strlen(const char *str)
{
	int len = 0;
	while (str[len])
		len++;
	return len;
}

char	*ft_strchr(const char *s, int c)
{
	size_t	len_s;

	len_s = ft_strlen(s) + 1;
	while (len_s-- > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}


char *ft_strdup(const char *str)
{
	int len = ft_strlen(str);
	char *dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return NULL;
	strncpy(dup, str, len);
	dup[len] = '\0';
	return dup;
}

t_env_list *create_env_node(const char *key, const char *value)
{
	t_env_list *node = (t_env_list *)malloc(sizeof(t_env_list));
	if (!node)
		return NULL;
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->next = NULL;
	return node;
}

void add_env_node(t_env_list **head, t_env_list *node)
{
	if (*head == NULL)
	{
		*head = node;
	}
	else
	{
		t_env_list *current = *head;
		while (current->next)
			current = current->next;
		current->next = node;
	}
}

void free_env_list(t_env_list *head)
{
	t_env_list *current = head;
	while (current)
	{
		t_env_list *temp = current;
		current = current->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_env_list *env_list;
	int env_count;
	char *current_env;
	char *equal_sign;
	char *key;
	char *value;
	t_env_list *node;
	t_env_list *current;

	env_count = 0;
	while (envp[env_count])
		env_count++;
	env_list = NULL;
	for (int i = 0; i < env_count; i++)
	{
		current_env = envp[i];
		equal_sign = ft_strchr(current_env, '=');
		if (!equal_sign)
		{
			printf("Invalid environment variable: %s\n", current_env);
			return 1;
		}

		*equal_sign = '\0';
		key = ft_strdup(current_env);
		value = ft_strdup(equal_sign + 1);

		node = create_env_node(key, value);
		if (!node)
		{
			printf("malloc error\n");
			free_env_list(env_list);
			return 1;
		}
		add_env_node(&env_list, node);
	}
	current = env_list;
	while (current)
	{
		printf("Key: %s\n Value: %s\n", current->key, current->value);
		current = current->next;
	}
	free_env_list(env_list);
	return 0;
}
