/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   romantoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:02:16 by batuhan           #+#    #+#             */
/*   Updated: 2024/01/25 22:38:46 by batuhan          ###   ########.fr       */
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
 */

#include <stdio.h>

int romanToInt(char *s)
{
	int j = 0;
	int realnum = 0;
	int bircount = 0;
	int xcount = 0;
	int i = 1;
	int v = 5;
	int x = 10;
	int l = 50;
	int c = 100;
	int d = 500;
	int m = 1000;

	while(s[j])
	{
		if (s[j] == 'I' && bircount <= 3)
		{
			if ((s[j + 1] == 'V' || s[j + 1] == 'X') && !s[j + 2] && !bircount)
			{
				j++;
				if (s[j] == 'V') {
					realnum += v - i;
				} else {
					realnum += x - i;
				}
			} else {
				realnum += i;
				bircount++;
			}
		}
		else if (s[j] == 'V' && bircount < 2)
			realnum += v;
		else if (s[j] == 'X' && bircount < 2) {
			realnum += x;
			xcount++;
		}
		if (bircount > 3 || xcount > 3)
		{
			perror("wrong number !");
			return 0;
		} else if (bircount == 2 && (s[j + 1] != 'I' && s[j + 1] != '\0')) {
			perror("wrong number !");
			return 0;
		} else if (bircount == 3 && s[j + 1]) {
			perror("wrong number !");
			return 0;
		} else if (s[j] < s[j + 1]) {
			perror("wrong number !");
			return 0;
		}
		j++;
	}
	return realnum;
}

int main () {
	char x[] = "XXVII";
	int c = 0;
	c = romanToInt(x);
	printf("%d\n", c);
}