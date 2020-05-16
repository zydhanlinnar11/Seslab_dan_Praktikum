#include <stdio.h>

int main() {
	int semua, halah;
	char sa, sb, sc, sd, se;
	scanf("%d", &semua);

	int i=1;
	while(i<=semua) {
		scanf(" %c", &se);
		if((se == 'E' || se == 'W' || se == 'P') && (se != 'T' || se != 'S')) {
			sd = se;
			sa = sb;
			sb = sc;
			sc = sd;	
		} else if(se == 'T') {
			if((sa == 'E' && sb == 'W' && sc == 'P') || (sa == 'E' && sb == 'P' && sc == 'W') || (sa == 'W' && sb == 'E' && sc == 'P') || (sa == 'W' && sb == 'P' && sc == 'E') || (sa == 'P' && sb == 'E' && sc == 'W') || (sa == 'P' && sb == 'W' && sc == 'E')) {
				halah = 2;
			} else if ((sa == 'E' && sb == 'W') || (sb == 'E' && sc == 'W') || (sa == 'W' && sb == 'E') || (sb == 'W' && sc == 'E')) {
				halah = 1;
			} else if((sa == 'P' && sb == 'E') || (sb == 'P' && sc == 'E') || (sa == 'E' && sb == 'P') || (sb == 'E' && sc == 'P')) {
				halah = 3;
			}
			sa = 'L';
			sb = 'L';
			sc = 'L';
		} else if(se == 'S') {
			if(halah == 3) {
				printf("Energy Burst\n");
			} else if(halah == 2) {
				printf("Power Punch\n");
			} else if(halah == 1) {
				printf("Wind Blade\n");
			}
		} else {
			i--;
		}
		i++;
	}	
}
