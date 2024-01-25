/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   romantoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:02:16 by batuhan           #+#    #+#             */
/*   Updated: 2024/01/26 00:12:19 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief 
 * 
 * Sembol Değeri
	I 1
	V 5
	X 10
	L 50
	C 100
	D 500
	M 1000
 * 
Örneğin, 2 Roma rakamıyla II olarak yazılır, sadece iki bir toplanır. 
12 sayısı XII olarak yazılır, bu da basitçe X + II'dir. 
27 sayısı XXVII olarak yazılır, yani XX + V + II.

Roma rakamları genellikle soldan sağa doğru büyükten küçüğe doğru yazılır.
Ancak, dört rakamının karşılığı IIII değildir. Bunun yerine dört sayısı IV olarak yazılır. 
Bir, beşten önce geldiği için onu çıkararak dört yaparız. 
Aynı ilke IX olarak yazılan dokuz sayısı için de geçerlidir. 
Çıkarma işleminin kullanıldığı altı örnek vardır:

I, 4 ve 9 yapmak için V (5) ve X'in (10) önüne yerleştirilebilir. 
X, 40 ve 90 yapmak için L (50) ve C'den (100) önce yerleştirilebilir. 
C, 400 ve 900 yapmak için D (500) ve M'den (1000) önce yerleştirilebilir.
Bir Roma rakamı verildiğinde, bunu bir tam sayıya dönüştürün.

 * @param s 
 * @return int 
 * 
 * XL 40
 * XC 90
 * CD 400
 * CM 900
 * 
 */

#include <stdio.h>

int romanToInt(char *s)
{
	int j = 0;
	int realnum = 0;
	int icount = 0;
	int	vcount = 0;
	int xcount = 0;
	int	lcount = 0;
	int	ccount = 0;
	int i = 1;
	int v = 5;
	int x = 10;
	int l = 50;
	int c = 100;
	int d = 500;
	int m = 1000;

	while(s[j])
	{
		if (s[j] >= 'a' && s[j] <= 'z') {
			s[j] -= 32;
		}
		if (s[j] == 'I' && icount <= 3)
		{
			if ((s[j + 1] == 'V' || s[j + 1] == 'X') && !s[j + 2] && !icount)
			{
				j++;
				if (s[j] == 'V') {
					realnum += v - i;
					icount++;
				} else {
					realnum += x - i;
					icount++;
				}
			} else if ((s[j + 1] == 'L') || (s[j + 1] == 'C')
				|| (s[j + 1] == 'D') || (s[j + 1] == 'M')) {
				perror("wrong number ! 1");
				return 0;
			} else {
				realnum += i;
				icount++;
			}
		}
		else if (s[j] == 'V' && icount < 2) {
			realnum += v;
			vcount++;
		}
		else if (s[j] == 'X' && icount < 2 && xcount <= 3)
		{
			if ((s[j + 1] == 'L' || s[j + 1] == 'C') && !xcount) 
			{
				j++;
				if (s[j] == 'L') {
					realnum += l - x;
					xcount++;
					lcount++;
				} else {
					realnum += c - x;
					xcount++;
					ccount++;
				}
			}
			else {
				realnum += x;
				xcount++;
			}
		}
		else if (s[j] == 'L') {
			realnum += l;
			lcount++;
		}
		if (icount > 3 || xcount > 3 || vcount > 1 || lcount > 1) {
			perror("wrong number ! 2");
			return 0;
		} else if (icount == 2 && (s[j + 1] != 'I' && s[j + 1] != '\0')) {
			perror("wrong number ! 3");
			return 0;
		} else if (icount == 3 && s[j + 1]) {
			perror("wrong number ! 4");
			return 0;
		} 
		else if (s[j] < s[j + 1]) {
			if (!(s[j] == 'L' || s[j] == 'C') && !(s[j - 1] == 'X')) {
				perror("wrong number 5!");
				return 0;
			}
		}
		j++;
	}
	return realnum;
}

int main () {
	char x[] = "LXXXVIII";
	int c = 0;
	c = romanToInt(x);
	printf("%d\n", c);
}