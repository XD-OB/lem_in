/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsdl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 18:29:53 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/25 02:34:26 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSDL_H
# define LIBSDL_H

# define SDL_INIT_FLAGS	(SDL_INIT_VIDEO | SDL_INIT_AUDIO)
# define IMG_INIT_FLAGS (IMG_INIT_PNG | IMG_INIT_JPG)

# include "./Library/includes/libft.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL_ttf.h>

typedef struct		s_sdlenv
{
	SDL_Window		*window;
	SDL_Renderer	*render;
	Mix_Music		*music;
	int				img:1;
	int				ttf:1;
	int				mixer:1;
}					t_sdlenv;

typedef struct		s_bline
{
	t_point			pi;
	t_point			pf;
	int				bold;
}					t_bline;

typedef struct		s_bcircle
{
	t_point			c;
	int				r;
	int				bold;
}					t_bcircle;

int					sdl_init(t_sdlenv env);
void				sdl_close(t_sdlenv *env);
void				sdlenv_init(t_sdlenv *env, int img, int ttf, int mixer);
int					sdlenv_fill(t_sdlenv *env, char *title,
								int height, int width);
SDL_Texture			*img_texture(SDL_Renderer *renderer, char *path_img);
SDL_Texture			*ttf_texture(SDL_Renderer *render, TTF_Font *font,
								char *str, SDL_Color color);
int					load_music(t_sdlenv *env, char *path_music);
void				sdl_bline(t_sdlenv env, SDL_Color color, t_bline bline);
void				sdl_line(t_sdlenv env, SDL_Color color,
								t_point pi, t_point pf);
void				sdl_circle(t_sdlenv env, SDL_Color color, t_point c, int r);
void				sdl_disk(t_sdlenv env, SDL_Color color, t_point c, int r);
void				sdl_bcircle(t_sdlenv env, SDL_Color color,
								t_bcircle bcircle);
void				sdl_quad(t_sdlenv env, SDL_Color color, int n_pts, ...);
void				sdl_bquad(t_sdlenv env, SDL_Color color,
								int bold, int n_pts, ...);
void				sdl_rect_e(t_sdlenv env, SDL_Color color,
								t_point a, t_point b);
void				sdl_brect_e(t_sdlenv env, SDL_Color color, t_bline info);
void				sdl_rect_a(t_sdlenv env, SDL_Color color, SDL_Rect rect);
void				sdl_rect_c(t_sdlenv env, SDL_Color color, SDL_Rect rect);
void				sdl_square_a(t_sdlenv env, SDL_Color color,
								t_point a, int l);
void				sdl_fsquare_a(t_sdlenv env, SDL_Color color[2],
								t_point a, int l);
void				sdl_square_c(t_sdlenv env, SDL_Color color,
								t_point c, int l);
void				sdl_fsquare_c(t_sdlenv env, SDL_Color color[2],
								t_point a, int l);
SDL_Color			sdl_color(int r, int g, int b, int a);
SDL_Color			sdl_rgb(int r, int g, int b);
SDL_Rect			rect_new(int height, int width, int y, int x);
t_bline				bline_new(t_point pi, t_point pf, int bold);
t_bcircle			bcircle_new(t_point c, int r, int bold);

#endif
