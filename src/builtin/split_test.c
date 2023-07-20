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

t_env_list	*create_env_node(char *key, char *value)
{
	t_env_list	*node;

	node = (t_env_list *)malloc(sizeof(t_env_list));
	if (!node)
		return (NULL);
	node->key = key;
	node->value = value;
	node->next = NULL;


	return (node);
}

void	add_env_node(t_env_list **env_list, t_env_list *node)
{
	if (*env_list == NULL)
	{
		*env_list = node;
		return ;
	}

	
	node->next = *env_list;
	*env_list = node;
}

t_env_list	*build_env_list(char **envp, int env_count)
{
	t_env_list	*env_list;
	t_env_list	*node;
	char		*key;
	char		*value;
	char		*current_env;
	char		*equal_sign;
	int			i;

	i = 0;
	env_list = NULL;
	while (i < env_count)
	{
		current_env = envp[i];
		equal_sign = strchr(current_env, '=');
		if (!equal_sign)
			return (NULL);
		*equal_sign = '\0';
		key = strdup(current_env);
		value = strdup(equal_sign + 1);
		node = create_env_node(key, value);
		if (!node)
			return (NULL);
		add_env_node(&env_list, node);
		i++;
	}
	return (env_list);
}

void	print_env_list(t_env_list *env_list)
{
	t_env_list	*current;
	int			i;

	current = env_list;
	while (current)
	{
		i = 0;
		while (current->env[i])
		{
			printf("%s\n", current->env[i]);
			i++;
		}
		current = current->next;
	}
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	int			env_count;
	t_env_list	*env_list;

	env_count = 0;
	while (envp[env_count])
		env_count++;
	env_list = build_env_list(envp, env_count);
	if (!env_list)
		return (1);
	print_env_list(env_list);
}