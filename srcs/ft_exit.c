#include "lem_in.h"

void	free_anything(void *arg1, ...)
{
    va_list args;
    void *vp;

    free(arg1);
    va_start(args, arg1);
    while ((vp = va_arg(args, void *)) != 0)
        free(vp);
    va_end(args);
}

void	ft_ko(void)
{
	ft_printf("KO\n");
	exit(EXIT_SUCCESS);
}

void	ft_ok(void)
{
	ft_printf("OK\n");
	exit(EXIT_SUCCESS);
}

void	ft_error(void)
{
	ft_dprintf(2, "Error\n");
	exit(EXIT_SUCCESS);
}

void	ft_print_usage(int flag)
{
	ft_printf("usage : ./lem_in [options]\n");
	ft_printf("Options:\n");
	ft_printf("\t-h : display this help\n");
	ft_printf("\t-v : activate verbose mode\n");
	ft_printf("\t-f [input_filemame] : read mine info from a well formated file\n");
	ft_printf("\t-o [output_filemame] : prints to the file passed\n");
	if (flag)
		exit(EXIT_SUCCESS);
}