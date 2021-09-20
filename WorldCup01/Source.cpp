#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

struct football {
	char name[20];
	int n = 0;
	int score = 0;
	int win = 0;
	int lose = 0;
	int rank = 0;
};

int main() {
	int a[4][4];
	struct football team[4];
	for (int i = 0; i < 4; i++) {
		int j = 0;
		while (1) {
			scanf_s("%c", &team[i].name[j]);
			if (team[i].name[j] == '\n') {
				team[i].name[j] = '\0';
				break;
			}
			j++;
		}
		team[i].n = j;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf_s("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			team[i].win += a[i][j];
			team[i].lose += a[j][i];
			if (a[i][j] > a[j][i]) {
				team[i].score += 3;
			}
			else if (a[i][j] == a[j][i]) {
				team[i].score += 1;
			}
		}
		team[i].score--;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i != j) {
				if (team[i].score < team[j].score) {
					team[i].rank++;
				}
				else if (team[i].score == team[j].score) {
					if (team[i].win - team[i].lose < team[j].win - team[j].lose) {
						team[i].rank++;
					}
					else if (team[i].win - team[i].lose == team[j].win - team[j].lose) {
						if (team[i].win < team[j].win) {
							team[i].rank++;
						}
					}
				}
			}
		}
	}
	/*for (int i = 0; i < 4; i++) {
		printf("%s %d %d %d = %d\n", team[i].name, team[i].score, team[i].win, team[i].lose, team[i].rank);
	}*/
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (team[j].rank == i) {
				printf("%s %d", team[j].name, team[j].score);
				break;
			}
		}
		if (i < 3) {
			printf("\n");
		}
	}
}