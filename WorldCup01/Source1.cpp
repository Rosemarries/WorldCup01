#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void swap(int* n, int* m) {
	int temp;
	temp = *n;
	*n = *m;
	*m = temp;
}
void swap2(char* str1, char* str2)
{
	char* temp = (char*)malloc((strlen(str1) + 1) * sizeof(char));
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
	free(temp);
}
int main() {
	int a[4][4], b[4][4], score[4], win[4], lose[4], temp, * p;
	char name[4][20], tempname[20];
	for (int i = 0; i < 4; i++) {
		int j = 0;
		while (1) {
			scanf_s("%c", &name[i][j]);
			if (name[i][j] == '\n') {
				name[i][j] = '\0';
				break;
			}
			j++;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < 4; i++) {
		win[i] = 0;
		lose[i] = 0;
		score[i] = 0;
		for (int j = 0; j < 4; j++) {
			b[i][j] = a[j][i];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			win[i] += a[i][j];
			lose[i] += b[i][j];
			if (a[i][j] > b[i][j]) {
				score[i] += 3;
			}
			else if (a[i][j] == b[i][j]) {
				score[i] += 1;
			}
		}
		score[i]--;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i != j) {
				if (score[i] < score[j]) {
					swap(&score[i], &score[j]);
					swap(&win[i], &win[j]);
					swap(&lose[i], &lose[j]);
					swap2(name[i], name[j]);
				}
				else if (score[i] == score[j]) {
					if (win[i] - lose[i] < win[j] - lose[j]) {
						swap(&score[i], &score[j]);
						swap(&win[i], &win[j]);
						swap(&lose[i], &lose[j]);
						swap2(name[i], name[j]);
					}
					else if (win[i] - lose[i] == win[j] - lose[j]) {
						if (win[i] < win[j]) {
							swap(&score[i], &score[j]);
							swap(&win[i], &win[j]);
							swap(&lose[i], &lose[j]);
							swap2(name[i], name[j]);
						}
					}
				}
			}
		}
	}
	for (int i = 3; i >= 0; i--) {
		printf("%s %d\n", name[i], score[i]);
	}
	return 0;
}