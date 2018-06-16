#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n = 0;
int m = 0;
int s = 0;
int d = 0;
int r = 0;
int GameTime = 0;
int CakeHanging = 0;
int BornAnts = 0;
struct Ant;
typedef struct Ant {
		int age;
		int level;
		int living;
		int life;
		int MaxLife;
		int x;
		int y;
		int hanging;
		int lastDir[2];
		struct Ant *next;
} Ant;
typedef struct {
		int value;
		int isOccupied;	
} Point;

Point map[10][10];

typedef struct {
		Ant *first; 
		Ant *last;
		int AntCount;
} AntGroup;
AntGroup ants = {NULL, NULL, 0};

typedef struct {
		int x;
		int y;	
		Ant *target;
} Gun;
Gun gun[21];

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void ant_birth()
{
		BornAnts++;
		int AntLevel = (BornAnts - 1) / 6 + 1;
		//printf("A new ant born.%d\n", AntLevel);
		Ant *new_ant = calloc(1, sizeof(Ant));
		new_ant->age = 0;
		new_ant->level = AntLevel;
		new_ant->living = 1;
		new_ant->MaxLife= new_ant->life = (int)(4.0 * pow(1.1, AntLevel));
		new_ant->x = new_ant->y = 0;
		map[0][0].isOccupied = 1;
		new_ant->next = NULL;
		new_ant->hanging = 0;
		if (ants.AntCount == 0) {
				ants.first = new_ant;
		}
		else{
				ants.last->next = new_ant;
		}
		ants.last = new_ant;
		ants.AntCount++;
}

void hang(Ant *ant)
{
		CakeHanging = 1;
		ant->hanging = 1;
		ant->life += (int) ((double)ant->MaxLife / 2);
		if (ant->life > ant->MaxLife) {
				ant->life = ant->MaxLife;
		}
		int i = 0;	
		for (i = 0; i < s; i++) {
				gun[i].target = ant;
		}
}
void print_ants()
{
		Ant *antNode = ants.first;
		printf("%d\n", ants.AntCount);
		while (antNode != NULL) {
				if (antNode->living) {
						printf("%d %d %d %d %d\n", antNode->age,
							   	antNode->level, antNode->life,
							   	antNode->y, antNode->x);
				}
				antNode = antNode->next;
		}
}
void ant_move(Ant *ant)
{
		int i = 0;	
		int j = 0;	
		//printf("Value:\n");
		for (i = 0; i <= n; i++) {
				for (j = 0; j <= m; j++) {
						//printf("%d ", map[i][j].value);
				}
				//printf("\n");
		}
		int rx = ant->x;
		int ry = ant->y;
		if (ant->hanging == 0) {
				map[ry][rx].value += 2;
		}else{
				map[ry][rx].value += 5;
		}
		int max = -1;	
		int choice = -1;
		//printf("start, %d %d\n", ry, rx);
		for (i = 0; i < 4; i++) {
				//printf("i = %d\n", i);
				//printf("max = %d\n", max);
				int nextx = rx + dir[i][0];
				int nexty = ry + dir[i][1];
				if ((nextx < 0 || nexty < 0) || (nextx > m || nexty > n)) {
						//printf("continued\n");
						continue;
				}
				if ((ant->lastDir[0]==nextx&& ant->lastDir[1]==nexty)) {
						continue;
				}
				if (map[nexty][nextx].isOccupied == 0) {
						if(map[nexty][nextx].value > max){
								max = map[nexty][nextx].value;
								choice = i;
								//printf("choice = %d\n", choice);
						}
				}
		}
		//printf("choice = %d\n", choice);
		if (choice != -1) {
				if (ant->age % 5 == 4) {
						choice--;
						if (choice < 0) {
								choice = 3;
						}
						int nextx = rx + dir[choice][0];
						int nexty = ry + dir[choice][1];
						while ((ant->lastDir[0]==nextx&&
						     ant->lastDir[1]==nexty)||
						     (nextx < 0 || nexty < 0)
						     || (nextx > m || nexty > n)||
							 map[nexty][nextx].isOccupied) {
								choice--;
								if (choice < 0) {
										choice = 3;
								}
								nextx = rx + dir[choice][0];
								nexty = ry + dir[choice][1];
						}
				}
				map[ant->y][ant->x].isOccupied = 0;
				ant->x += dir[choice][0];
				ant->y += dir[choice][1];
				map[ant->y][ant->x].isOccupied = 1;
		}
		ant->lastDir[0] = rx;
		ant->lastDir[1] = ry;
		if (CakeHanging == 0 && ant->x == m && ant->y == n) {
				//printf("Catched %d\n", GameTime);
				hang(ant);
				//print_ants();
		}
}

int can_attack(Gun *gun, Ant *ant, Ant *target)
{
		if (ant == target) {
				return 1;
		}
		double gx = gun->x;
		double gy = gun->y;
		double ax = ant->x;
		double ay = ant->y;
		double tx = target->x;
		double ty = target->y;
		if (((ant->x - gun->x) * (target->x - gun->x) + 
						(ant->y - gun->y) * (target->y - gun->y) < 0) ||
		    ((ant->x - target->x) * (gun->x - target->x) + 
					(ant->y - target->y) * (gun->y - target->y) < 0)) {
				return 0;
		}
		if (gun->x == target->x) {
				if(fabs(gx - ax) <= 0.5)
						return 1;
				else return 0;
		}
		double k = (gy - ty)/(gx - tx);
		double b = gy - k * gx;
		double distance = fabs(ax * k - ay + b) / pow(1 + k * k, 0.5);
		/*
		printf("gun: %d %d\n",gun->x, gun->y);
		printf("target: %d %d\n",target->x, target->y);
		printf("ant: %d %d\n",ant->x, ant->y);
		printf("distance = %f\n", distance);
		*/
		if (distance <= 0.5) {
				//printf("Can attack:\n");
				//printf("gun: %d %d\n",gun->x, gun->y);
				//printf("target: %d %d\n",target->x, target->y);
				//printf("ant: %d %d\n",ant->x, ant->y);
				return 1;
		}else{
				return 0;
		}
}
void attack(Gun *gun)
{
		int MinDistance = r * r + 1;
		Ant *target = NULL;
		Ant *ant = ants.first;
		if (gun->target != NULL &&
				(gun->target->x - gun->x) *(gun->target->x - gun->x) +
			(gun->target->y-gun->y)*(gun->target->y-gun->y)<MinDistance) {
						target = gun->target;
				}
		else{
				while (ant != NULL) {
						int distance = (ant->x - gun->x) 
								*(ant->x - gun->x) 
								+ (ant->y-gun->y)*(ant->y-gun->y);
						if (ant->living && distance < MinDistance) {
								MinDistance = distance;
								target = ant;
						}
						ant = ant->next;
				}
		}
		if (target == NULL) {
				return ;
		}
		ant = ants.first;
		while (ant != NULL) {
				if(ant->living && can_attack(gun, ant, target)){
						ant->life -= d;
						//printf("%d, %d    ", ant->y, ant->x);
				}
				ant = ant->next;
		}
}
int one_second()
{
		GameTime++;
		int flag = 0;
		if (ants.AntCount < 6 && map[0][0].isOccupied == 0) {
				ant_birth();
		}
		Ant *ant = ants.first;
		while (ant != NULL) {
				if (ant->living) {
						ant_move(ant);
				}
				ant = ant->next;
		}
		//printf("GameTime = %d\n", GameTime);
		//printf("After move\n");
		//print_ants();
		int i = 0;	
		for (i = 0; i < s; i++) {
				//printf("Gun %d (%d, %d)", i, gun[i].y, gun[i].x);
				attack(&gun[i]);
				//printf("\n");
		}
		ant = ants.first;
		while (ant != NULL) {
				if (ant->living && ant->life < 0) {
						if (ant->hanging) {
								ant->hanging = 0;
								for (i = 0; i < s; i++) {
										gun[i].target = NULL;
								}
								CakeHanging = 0;
								//printf("Died %d\n", GameTime);
								//print_ants();
						}
						ant->living = 0;
						ants.AntCount--;
						map[ant->y][ant->x].isOccupied = 0;
				}
				if (ant->hanging && ant->x == 0 && ant->y == 0) {
						flag = 1;
				}
				ant = ant->next;
		}
		
		//printf("After shoot\n");
		//print_ants();
		int j = 0;	
		for (i = 0; i <= n; i++) {
				for (j = 0; j <= m; j++) {
						if (map[i][j].value > 0) {
								map[i][j].value--;
						}
						//printf("%d ", map[i][j].value);
				}
				//printf("\n");
		}
		//printf("\n");
		ant = ants.first;
		if(!flag){
				while (ant != NULL) {
						if (ant->living) {
								ant->age++;
						}
						ant = ant->next;
				}
		}
		return flag;
}
int main(void)
{
		scanf("%d%d", &n, &m);
		scanf("%d%d%d", &s, &d, &r);
		int i = 0;	
		int j = 0;	
		int t = 0;
		for (i = 0; i <= n; i++) {
				for (j = 0; j <= m; j++) {
						map[i][j].isOccupied = 0;
						map[i][j].value = 0;
				}
		}
		
		for (i = 0; i < s; i++) {
				scanf("%d%d", &gun[i].y, &gun[i].x);
				gun[i].target = NULL;
				map[gun[i].y][gun[i].x].isOccupied = 1;
				//printf("Read %d %d", gun[i].y, gun[i].x);
		}
		scanf("%d", &t);
		//printf("t = %d\n", t);
		for (i = 0; i < t; i++) {
				if (one_second()) {
						printf("Game over after %d seconds\n", GameTime);
						print_ants();
						return 0;
				}
		}
		printf("The game is going on\n");
		print_ants();
		return 0;
}
