/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 09:09:59 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:30:41 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYER_H
# define DISPLAYER_H

# include "libsdl.h"
# include "libft.h"

# define WIDTH 2200
# define HEIGHT 1200

# define STATE 5
# define TITLE "Ishobe Take Care of your ants"

# define FONT_TYPE_TXT "./libsdl/fonts/arial.ttf"
# define FONT_SIZE_TXT 30

# define IMG_PATH "libsdl/Images/bk.jpg"
# define MUSIC_PATH "./libsdl/Music/Ants_Walk.ogg"

# define L_WHITE -1
# define L_BLACK 0
# define L_RED	1
# define L_GREEN 2
# define L_YELLOW 3
# define L_BLUE 4
# define L_ORANGE 5
# define L_CYAN 6
# define L_PURPLE 7

typedef struct		s_ant_infos
{
	int				*tab_life;
	int				color;
}					t_ant_infos;

typedef struct		s_room
{
	int				id;
	int				color;
	t_point			coord;
}					t_room;

typedef struct		s_infos
{
	t_chr			*input;
	int				ants;
	int				shots;
	int				v;
	int				start;
	int				end;
	char			**tab_hash;
	t_room			*rooms;
	int				**links;
	t_ant_infos		*tab_ants;
	int				color_paths;
	int				debug;
	t_point			*start_end;
}					t_infos;

typedef struct		s_display
{
	t_sdlenv		env;
	t_infos			infos;
	SDL_Event		event;
	SDL_Color		color_text;
	TTF_Font		*font_text;
	t_point			offset;
	int				start_ants;
	int				end_ants;
	int				moment;
	int				block;
	int				pause;
	int				pass;
	int				mute;
	int				frame[4];
	int				trace;
	int				f;
}					t_display;

int					store_data(int ac, char **av, t_infos *infos);
void				fill_adv_infos(t_infos *infos);
void				fill_start_end(t_infos *infos);
void				fill_tab_ants(t_infos *infos, t_ant_infos *tab_ants,
									char *str, int time);
void				draw_scene(t_display *display);
void				create_tabhash_2(t_infos *infos, t_chr *list);
void				take_cmds(t_infos *infos, char *str);
int					alloc_places(t_infos *infos);
int					the_color(char *str, int def);
void				free_infos(t_infos *infos);
void				free_error(t_infos *infos);
void				init_infos(t_infos *infos);
int					is_strnbr(char *str);
int					is_link(char *str);
int					is_room(char *str);
int					get_teta(t_infos infos, int a, int b);
void				displayer_loop(t_display *display);
void				free_display(t_display *display);
int					init_display(t_display *display);
void				init_vars_display(t_display *display);
void				draw_state(t_display *display, t_infos infos);
void				draw_scene(t_display *display);
void				print_life_ants(t_infos *infos);
void				print_debug(t_infos *infos);
void				print_usage(void);
void				name_color(int macros);
SDL_Color			color_macros(int macros);
void				draw_rooms(t_display *display);
void				draw_ant(t_display *display, t_infos infos, int x);

#endif
