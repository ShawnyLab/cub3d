/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:00:18 by jinspark          #+#    #+#             */
/*   Updated: 2021/05/07 21:34:31 by jinspark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
해상도, 동서남북, 스프라이트 텍스쳐 , RGB 하늘, 땅 숫자 코드 파싱
*/
static void	parse_identifier(int *flags, t_list *head, t_cub *cub)
{
	char	**info;

	info = cub->info;
	if (!ft_strcmp(*info, "R"))   //ft_strcmp  (문자 비교)   같으면 0 리턴.
	{
		if (parse_resolution(flags, cub) == -1)
			free_info_lst_quit(info, head, cub, ERR_IDENT); //해상도 파싱
	}
	else if (!ft_strcmp(*info, "NO") || !ft_strcmp(*info, "SO") ||
			!ft_strcmp(*info, "WE") || !ft_strcmp(*info, "EA") ||
			!ft_strcmp(*info, "S"))
	{
		if (parse_texture(flags, cub) == -1)
			free_info_lst_quit(info, head, cub, ERR_IDENT);  // 동서남북 스프라이트 텍스쳐 파싱
	}
	else if (!ft_strcmp(*info, "F") || !ft_strcmp(*info, "C"))
	{
		if (parse_color(flags, cub) == -1)
			free_info_lst_quit(info, head, cub, ERR_IDENT);   //RGB 숫자 코드 파싱
	}
	else
		free_info_lst_quit(info, head, cub, ERR_CUB);
}

static void	parse_line(char *line, int *flags, t_list *head, t_cub *cub)
{
	if ((cub->info = ft_split(line, ' ')) == NULL)   //공백으로 스플릿 했는데 널
		free_lst_quit(head, cub, ERR_IDENT);		// Identifier 에러
	if (*(cub->info))								//cub->info 에는 공백으로 스플릿 한 문자들이 들어가 있음.  (char **)
	{
		parse_identifier(flags, head, cub);
	}
	else
		free(cub->info);
}

static void	parse_list(t_list *head, t_cub *cub)
{
	t_list	*trav;
	int		flags;

	flags = 0;
	trav = head;
	while (trav)
	{
		if (flags != IDENTIFIERS)
		{
			parse_line(trav->content, &flags, head, cub);
			trav = trav->next;
		}
		else
			break ;
	}
	if (flags != IDENTIFIERS)
		free_lst_quit(head, cub, ERR_CUB);
	parse_grid(trav, head, cub);
}
/*
 get_next_line 을 통해 읽어온 line 을 t_list 형 head에 차곡차곡 쌓음  (앞으로 쌓음)
*/
static void	lst_add_line(char *line, t_list **head, t_cub *cub)
{
	t_list	*node;

	node = NULL;
	if ((node = ft_lstnew(line)) == NULL)
		free_lst_quit(*head, cub, ERR_MEM);
	ft_lstadd_front(head, node);
}

/*
get_next_line 을 통해 읽어온 line 을 head에 넣음.
그리고 Identifier 을 이용해서 각 텍스쳐, 해상도, RGB 파싱.
*/
void		parse_cub(char *path, t_cub *cub)
{
	int		fd;
	int		error;
	char	*line;
	t_list	*head;

	head = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
		quit_cub(cub, EXIT_FAILURE, "Can't open .cub file");
	line = NULL;
	while ((error = get_next_line(fd, &line)) > 0)
		lst_add_line(line, &head, cub);
	if (error != -1 && *line)
		lst_add_line(line, &head, cub);
	else
		free(line);
	ft_lstrev(&head);  //뒤집어주기
	if (close(fd))    //닫기에 실패
		free_lst_quit(head, cub, "Can't close .cub file");
	parse_list(head, cub);
	ft_lstclear(&head, free);
}
