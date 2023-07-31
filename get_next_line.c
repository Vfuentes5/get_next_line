/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicgonza <vicgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:08:34 by vicgonza          #+#    #+#             */
/*   Updated: 2023/07/31 18:47:11 by vicgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

/*
int	main()
{
	char *str;

	str = get_next_line(0);
	printf("%s", str);
}

void	*ft_free(void **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char *get_next_line (int fd)
{
	static char	*line = NULL;
	char buffer[BUFFER_SIZE + 1];
	int	size_read;
	int	*position;
	int	result;
	int	i;
	int	j;
	int aux;

	if (fd < 0)
		return (NULL);
	size_read = 1;
	while (size_read > 0)
	{
		//reviso si line tine un /n
		//	si tiene hago un corte y guardo el sobrante
		size_read = read(fd, buffer, BUFFER_SIZE);
		// hago un ft_realloc(linea, buffer);
	}
	return (NULL);
	fd = 0;

	 position = strstr(line, '\n');
	 result = malloc(1 * buffer_size + 1);
	 if (position != NULL)
	 {
		 i = 0;
		 while (result[i] != '\n')
		 {a
			 result[i] = line[i];
			 i++;
		 }
		 result = '\n';
	 }
	 else
	 {
		 strlcpy(result,line);
		 result[strlen(line)] = '\n'
	 }

	 i = strlen(result);
	 j = 0;
	 aux = malloc((strlen(line) - strlen(result)) * sizeof(char));
	 while (i < strlen(line))
	 {
		 aux[j] = line [i];
		 j++;
		 i++;
	 }
	 line = aux;

	 return result;
#endif
*/

char *get_next_line (int fd)
{
	static char	*line = NULL;
	char	*aux;
	char	*result;
	int		size_read;
	char	*position;
	int		i;	
	int		j;

	aux = NULL;
	if (!line || strlen(line) == 0) /*abrimos y leemos el archivo*/
	{
		line = malloc(BUFFER_SIZE * sizeof(char));
		size_read = read(fd, line, BUFFER_SIZE);
	}
	/*line = hola\adios, result = hola\n, aux = adios, line*/ 
	position = strstr(line, "\n"); /*compruebo si line tiene o no \n*/
	result = malloc(1 * BUFFER_SIZE);
	if (position != NULL) /*tengo un \n*/
	{
		i = 0;
		while (line[i] != '\n') /*copio hasta que encuentro el salto de línea*/
		{
			result[i] = line[i];
			++i;
		}
		result[i] = '\n';
	}
	else /*no tengo \n*/
	{
		ft_strlcpy(result, line, BUFFER_SIZE);
		result[ft_strlen(line)] = '\n';
	}
	//actualizo mi variable line para que apunte a la continuación de lo que va a devolver
	i = ft_strlen(result);
	j = 0;
	aux = malloc((ft_strlen(line) - ft_strlen(result)) * sizeof(char));
	printf("TEST: %zu\n", ft_strlen(line));
	while (i < ft_strlen(line))
	{
		aux[j] = line[i];
		++j;
		++i;
	}
	line = aux;

	return result;

}
/*
int main(int argc, char **argv)
{
	int fd = open("hola.txt", O_RDONLY | O_CREAT);
	printf("fd = %d\n", fd);

	if (fd == -1) 
	{
		printf("error al abrir el fd\n");
	}

	char* result = get_next_line(fd);
	printf("la línea leída es %s\n", result);

	result = get_next_line(fd);
	printf("la línea leída es %s\n", result);

	result = get_next_line(fd);
	printf("la línea leída es %s\n", result);

	result = get_next_line(fd);
	printf("la línea leída es %s\n", result);

	result = get_next_line(fd);
	printf("la línea leía es %s\n", result);

	if (close(fd) == -1)
	{
		printf("error al cerrar el fd\n");
	}
	return (0);
} */

int	main(void)
{
	char *line;
	int fd;

	fd = open("get_next_line.c", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("TEST\n");
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
