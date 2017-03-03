#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>

/*unsigned char reverse_bit8(unsigned char x)
  {
  x = ((x) << 1) | ((x) >> 1);
  x = ((x) << 2) | ((x) >> 2);
  return (x << 4) | (x >> 4);
  }*/

void	ft_utf8(int nb)
{
	int	first_octet;
	int	second_octet;
	int	third_octet;
//	int	fourth_octet;

	if (nb <= 0x007f)
		write(1, &nb, 1);
	else if (nb > 0x007f && nb <= 0x07ff)
	{
/*		first_octet = nb << 2;
		first_octet = first_octet & 255;
		first_octet = first_octet >> 2;
		first_octet = first_octet | 128;*/
		first_octet = ((((nb << 2) & 255) >> 2) | 128);
/*		second_octet = nb >> 6;
		second_octet = second_octet & 255;
		second_octet = second_octet << 2;
		second_octet = second_octet & 255;
		second_octet = second_octet >> 2;
		second_octet = second_octet | 192;*/
		second_octet = ((((((nb >> 6) & 255) << 2) & 255) >> 2) | 192);
		write(1, &second_octet, 1);
		write(1, &first_octet, 1);
	}
	else if (nb > 0x07ff && nb <= 0xffff)
	{
		first_octet = ((((nb << 2) & 255) >> 2) | 128);
		printf("%d\n", first_octet);
		second_octet = (((((nb >> 6) & 255) << 2) & 255) >> 2) | 192;
		printf("%d\n", second_octet);
		third_octet = ((nb >> 12) & 255) | 224;
		printf("%d\n", third_octet);
		write(1, &third_octet, 1);
		write(1, &second_octet, 1);
		write(1, &first_octet, 1);
	}
	else if (nb > 0xffff && nb < 0xfffff)
	{
		first_octet = nb | 128;
		second_octet = (nb >> 6) | 192;
		write(1, &second_octet, 1);
		write(1, &first_octet, 1);
	}
}

void	ft_print_bit(int nb)
{
	int	bit;
	int	mask;
	int	i;

	i = 7;
	mask = 128;
	while (i >= 0)
	{
		bit = (nb & mask) >> i;
		printf("%d", bit);
		mask >>= 1;
		i--;
	}
	printf("\n");
}

/*void	ft_print_bit_octet(int nb)
{
	ft_print_bit(nb);
	if (nb > 0x007f && nb <= 0xfffff)
	{
		ft_print_bit(nb >> 8);
		if (nb > 0x07ff && nb <= 0xfffff)
		{
			ft_print_bit(nb >> 16);
			if (nb > 0xffff && nb < 0xfffff)
				ft_print_bit(nb >> 24);
		}
	}
	printf("\n");
}*/
char	*ft_utf(int nb, char *buff)
{
	return (buff);
}

int	main()
{
	int nb;

	setlocale(LC_ALL, "");
	nb = 0x0800;
	printf("%C\n", 0x0800);
	ft_utf8(nb);
//	ft_print_bit_octet(nb);
	return (0);
}
