#include <stdbool.h>

bool isPalindrome(int x) {
	int nbr = x;
	if (x < 0)
		return false;
	long long int reverse = 0;
	while (x > 0) {
	reverse = reverse * 10 + x % 10;
	x = x / 10;
	} if (reverse == nbr)
		return true;
	return false;
}
