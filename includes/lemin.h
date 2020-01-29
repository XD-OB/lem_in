/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 23:02:05 by ishaimou          #+#    #+#             */
/*   Updated: 2019/07/31 07:06:28 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define MAX_VICE 5
# define MAX_HEAD 45
# define MAX_INF 10000

typedef struct		s_paths
{
	int				len;
	int				ants;
}					t_paths;

typedef struct		s_infos
{
	int				n_paths;
	t_paths			*paths;
	int				n_subs;
	int				n_shots;
}					t_infos;

typedef struct		s_room
{
	int				id;
	int				edge_flow;
	int				ext_edge_flow;
	int				forwd;
	int				backwd;
}					t_room;

typedef struct		s_stat_ants
{
	int				finish;
	int				id_path;
	t_icase			*pos;
}					t_stat_ants;

typedef struct		s_lemin
{
	int				ants;
	int				v;
	int				start;
	int				end;
	int				*visited;
	int				*parent;
	int				*exclus;
	char			**tab_hash;
	t_bt			**tab_bt;
	t_list			*best_grp;
	t_list			*list_grp;
	t_list			*list_paths;
	t_chr			*input;
	t_infos			*grp_infos;
	t_infos			*best_infos;
	t_list			*head_grps;
	t_stat_ants		*tab_ants;
	int				ngrp;
}					t_lemin;

void				ft_error(void);
int					is_room(char **line);
int					is_link(char **line);
void				init_tools(t_lemin *lemin);
void				init_lemin(t_lemin *lemin);
void				init_tab_ants(t_stat_ants *tab_ants, int size);
void				free_lemin(t_lemin *lemin, int error);
void				create_tabhash(t_lemin *lemin, t_chr *list_tmp);
int					bfs(t_lemin *lemin);
t_room				*create_room(int room_id);
int					id_cmp(void *item1, void *item2);
int					gnl_error(t_lemin *lemin, char **line);
void				find_best_grp(t_lemin *lemin);
void				parallel_walk(t_lemin *lemin, t_infos *infos,
								t_stat_ants *tab_ants);
void				manage_ants(t_lemin *lemin);
int					find_heads(t_lemin *lemin);
t_list				*find_vices(t_lemin *lemin, t_icase *head);
void				algo_ishobe(t_lemin *lemin);
void				ultimate_ishobe(t_lemin *lemin);
void				fill_grp_infos(t_lemin *lemin, t_list *grp, t_infos *infos);
int					calcul_ants_shots(int ants, t_infos *infos, int n_subs);
void				update_edgeflow(t_lemin *lemin, t_icase *path);
void				update_exclus(t_lemin *lemin, t_icase *path);
void				parse_links(t_lemin *lemin, char **bk_line);
char				*parse_rooms(t_lemin *lemin, t_chr **list_tmp);
void				parse(t_lemin *lemin);
void				ic_lstrevaddlast(t_list **head, t_icase *path, int *cap);
void				exclus_path(t_lemin *lemin, t_icase *path);
int					qtic_free(t_queue *queue);
int					qtic_deq(t_queue *queue);

#endif
