/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:47:28 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/27 17:56:01 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "get_next_line.h"

int				create_bmp(t_list *stock)
{
	int height;
	int width;

	height = stock->wdw_height - 1;
	width = stock->wdw_width;
	generate_bitmap_image(stock, height, width);
	return (0);
}

void			write_rgb(t_list *all, int height, int width, int fd)
{
	unsigned char	abc[3];
	int				i_j[2];

	i_j[0] = 0;
	while (i_j[0] < height)
	{
		i_j[1] = 0;
		while (i_j[1] < width)
		{
			abc[0] = (240 & (all->data_wdw[(height - i_j[0]) *
			width + i_j[1]]) >> 16);
			abc[1] = (240 & (all->data_wdw[(height - i_j[0]) *
			width + i_j[1]]) >> 8);
			abc[2] = (240 & all->data_wdw[(height - i_j[0]) *
			width + i_j[1]]);
			write(fd, abc + 2, 1);
			write(fd, abc + 1, 1);
			write(fd, abc, 1);
			i_j[1]++;
		}
		i_j[0]++;
	}
}

void			generate_bitmap_image(t_list *all, int height, int width)
{
	int				fd;
	unsigned char	*file_header;
	unsigned char	*info_header;

	file_header = create_bitmap_file_header(height, width,
	(4 - (width * BYTES_PER_PIXEL) % 4) % 4);
	info_header = create_bitmap_info_header(height, width);
	fd = open(SCREENSHOT_PATH, O_WRONLY);
	write(fd, file_header, FILE_HEADER_SIZE);
	write(fd, info_header, INFO_HEADER_SIZE);
	write_rgb(all, height, width, fd);
	close(fd);
}

unsigned char	*create_bitmap_file_header(int height,
				int width, int padding_size)
{
	int						file_size;
	static unsigned char	file_header[] = {
		0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
	};

	file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE +
	(BYTES_PER_PIXEL * width + padding_size) * height;
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	return (file_header);
}

unsigned char	*create_bitmap_info_header(int height, int width)
{
	static unsigned char info_header[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	info_header[0] = (unsigned char)(INFO_HEADER_SIZE);
	info_header[4] = (unsigned char)(width);
	info_header[5] = (unsigned char)(width >> 8);
	info_header[6] = (unsigned char)(width >> 16);
	info_header[7] = (unsigned char)(width >> 24);
	info_header[8] = (unsigned char)(height);
	info_header[9] = (unsigned char)(height >> 8);
	info_header[10] = (unsigned char)(height >> 16);
	info_header[11] = (unsigned char)(height >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(BYTES_PER_PIXEL * 8);
	return (info_header);
}
