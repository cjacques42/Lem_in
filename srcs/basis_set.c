#include "ft_set.h"

void	ft_set_init(t_set *set, int (*ft_match)(void *k1, void *k2)
		, void (*ft_destroy)(void *data))
{
	ft_list_init(set, ft_destroy);
	set->ft_match = ft_match;
}

int		ft_set_insert(t_set *set, void *data)
{
	if (ft_set_ismember(set, data) == 1)
		return (1);
	if (ft_list_ins_next(set, set->tail, data) == -1)
		return (-1);
	return (0);
}

int		ft_set_remove(t_set *set, void **data)
{
	t_listelem		*tmp;
	t_listelem		*ptr;

	tmp = LIST_HEAD(set);
	while (tmp != NULL)
	{
		if (set->ft_match(*data, LIST_DATA(tmp)) == 0)
			break;
		ptr = tmp;
		LIST_NEXT(tmp);
	}
	if (tmp == NULL)
		return (-1);
	return (ft_list_rem_next(set, ptr, data));
}

int		ft_set_ismember(t_set *set, void *data)
{
	t_listelem		*tmp;

	tmp = LIST_HEAD(set);
	while (tmp != NULL)
	{
		if (set->ft_match(data, LIST_DATA(tmp)))
			return (1);
		LIST_NEXT(tmp);
	}
	return (0);
}

int		ft_set_issubnet(t_set *set1, t_set *set2)
{
	
}
