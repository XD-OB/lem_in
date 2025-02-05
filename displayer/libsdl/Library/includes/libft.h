/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 01:07:21 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 07:36:52 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "structs.h"
# include "ft_printf.h"
# define BUFF_SIZE 1000
# define HASH_C 2

/*
**	HASH :			-----------------------------------------------------
*/

void				hash_putintab(char **tab, int size, char *s, int *ind);
int					hash_findid(char **tab, int size, char *s);
int					hash_strtoind(char **tab, int size, char *s);
int					hash_filltab(char **tab, int size, char *s);
void				hash_freetab(char ***tab_hash, int size);
unsigned long		hash_str(char *str);

/*
**	BINARY TREE :	-----------------------------------------------------
*/

t_bt				*bt_create_node(void *item);
void				bt_insert_item(t_bt **root, void *item,
									int (*cmpf)(void *, void *));
t_bt				*bt_search_item(t_bt *root, void *data_ref,
									int (*cmpf)(void *, void *));
void				bt_apply_infix(t_bt *root, void (*applyf)(void *));
void				bt_apply_revinfix(t_bt *root, void (*applyf)(void *));
void				bt_apply_prefix(t_bt *root, void (*applyf)(void *));
void				bt_apply_suffix(t_bt *root, void (*applyf)(void *));
int					bt_size_count(t_bt *root);
int					bt_level_count(t_bt *root);
void				bt_free(t_bt **root, void (*freef)(void **));

/*
**	QUEUE :			-----------------------------------------------------
*/

int					qt_enqueue(t_queue *queue, void *content, size_t size);
int					qt_dequeue(t_queue *queue);
int					qt_front(t_queue queue, void *content);
t_queue				*qt_new_queue(void);
int					qt_isempty(t_queue queue);
void				qt_print(t_queue queue, int type, int sep);
void				qt_free(t_queue *queue);

/*
**	STACK :			-----------------------------------------------------
*/

void				sk_push(t_list **top, void *content, size_t size);
void				sk_pop(t_list **top, void *item);
int					sk_isempty(t_list *top);
void				*sk_top(t_list *top);
void				sk_free(t_list **head);

/*
**	LINKED LIST :	-----------------------------------------------------
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnew_sm(void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstextfree(t_list **alst);
void				ft_lstadd(t_list **alst, t_list *new_node);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstprint(t_list *head, int type, int sep);
void				ft_lstadd_last(t_list **lst, t_list *node);
int					ft_list_size(t_list *begin_list);

/*
**	INT CASE:		-----------------------------------------------------
*/

void				ic_pushnode(t_icase **icase, int value);
void				ic_addnode(t_icase **icase, int value);
char				*ic_joinstr(t_icase **icase, int size);
void				ic_lstdel(t_list **alst);
void				ic_free(t_icase **icase);
void				ic_print(t_icase *icase);
int					ic_size(t_icase *icase);
int					ic_lstfind(t_list *list, t_icase *target);
int					ic_ncmp(t_icase *list1, t_icase *list2, size_t n);
int					ic_cmp(t_icase *list1, t_icase *list2);
t_list				*ic_revlstnew(t_icase *path);
t_list				*ic_lstnew_sm(t_icase *path);
t_list				*ic_lstnew(t_icase *path);
t_icase				*ic_revcopy(t_icase *icase);
t_icase				*ic_copy(t_icase *icase);
int					ic_find(t_icase *path, int n);
t_icase				*ic_new(int n);

/*
**	STR LIST :		-----------------------------------------------------
*/

int					chr_len(t_chr *chr);
void				chr_init(t_chr **chr);
void				chr_free(t_chr **chr);
void				chr_print(t_chr *list);
void				chr_revprint(t_chr *list);
void				chr_addnode(t_chr **list, char *str, int len);
void				chr_pushfront(t_chr **list, char *str, int len);
t_chr				*gnl_nsave_chr(int fd, int nbr_lines);
t_chr				*gnl_save_chr(int fd);

/*
**	PRINT/READ:		-----------------------------------------------------
*/

int					get_next_line(const int fd, char **line);
void				ft_printhex(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** CONVERS INT/STR :-----------------------------------------------------
*/

char				*ft_itoa(long long int n);
char				*ft_ltoa(long int n);
char				*ft_lltoa(long long int n);
char				*ft_itoa_base(long long int val, int base);
char				*ft_ulltoa_base(unsigned long long val, int base);
char				*ft_utoa(size_t n);
char				*ft_ultoa(unsigned long int n);
char				*ft_ulltoa(unsigned long long int n);
char				*ft_utoa_base(size_t val, int base);
int					ft_atoibase(char *str, char *base_from);
int					ft_atoi(const char *str);
char				*ft_poslltoa(long long int n);

/*
**	STRING ARRAY :	-----------------------------------------------------
*/

int					len_tab(char **tab);
void				free_tabstr(char ***tab);
void				add_2_tab(char ***tab, char *elem);
char				*join_from_tab(char **tab, int start, char *sep);
char				**copy_char2(char **tab, int start);
char				**copy_2_char(char **tab);

/*
**	INT ARRAY :		-----------------------------------------------------
*/

void				tabint_reset(int *tab, int size, int n);

/*
**	INT MATRIX:		-----------------------------------------------------
*/

void				mxint_free(int ***tab, int size);

/*
**	POINT :			-----------------------------------------------------
*/

t_point				pt_new(int y, int x);
void				pt_swap(t_point *p1, t_point *p2);
int					pt_diffteta(t_point p1, t_point p2);
t_point				pt_rot(t_point c, t_point a, int teta);
t_point				pt_linterp(t_point p1, t_point p2, int a, int t);

/*
**	MEMORY :		-----------------------------------------------------
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
**					-----------------------------------------------------
*/

int					ft_intlen(int n);
int					ft_isxdigit(int c);
int					ft_isblank(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strfreejoin(char **s1, char **s2, int fmode);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_trimstr(char **str);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strstr(const char *str, const char *find);
char				*ft_strnstr(const char *str, const char *find, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strpbrk(const char *s1, const char *s2);
char				*ft_strdup(const char *src);
char				*ft_strndup(const char *src, int n);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *str);
void				ft_strcombin(char **s1, const char *s2);
void				ft_swap(int *a, int *b);
char				*ft_strrev(char *str);
char				*ft_strnjoin(char *s1, char *s2, size_t len);
void				ft_strswap(char **s1, char **s2);
char				*ft_str_pushback(char *str, char c);
char				*ft_strsum(char *str1, char *str2, int base);
char				*ft_strcnew(size_t size, char c);
char				*ft_strmult(char *num1, char *num2, int base);
char				*ft_strpower(int base, int exponent, int x);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
int					ft_sqrt(int nb);
int					ft_prime(int nb);
void				ft_epurstr(char **str);

#endif
