#include <stdio.h>

int main(void) {

	char ab, kados[50];
	char am [30][6];  
	char nb[22][4];
	int seats; 
	int profit=0;
	int k, c, v, d;

	for(c = 0; c < 22; c++)
	{
		for(v = 0; v < 4; v++)
		{
			nb[c][v]='O';
		}
	}
	for(c = 0; c < 30; c++){
		for(v = 0; v < 6; v++){
			am[c][v]='O';
		}
	}
	while(1){
	d=3;
	k=10;
	c=50;
	v=50;
	do{
		printf("\nChoose an aircraft!\n (A)AM57	(B)NB3842\n");
		scanf("%s", &ab);
	} 
	while(ab!='a'&& ab!='A'&&ab!='b'&&ab!='B');
	printf(" 1	Show available seats\n 2	Book random seat\n 3	Book specific seat\n 4	Book several seats\n 5	Cancel booking\n 6	Show profit\n 7	Leave\n");
	scanf("%d", &k);
	if(k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7) {
	scanf("%s", &kados);
	}
	if(k == 1)
	{
		if(ab =='a' || ab =='A')
		{
			for(c = 0; c < 30; c++){
				printf("\n");
				for(v = 0; v < 6; v++){
					printf("%d-%d: ", c, v);
					if(am[c][v] == 'O') {
					printf("Open	");
				}
					else printf("Taken	"); }
			}
		}
		else
		{
			for(c = 0; c < 22; c++){
				printf("\n");
				for(v = 0; v < 4; v++){
					printf("%d-%d: ", c, v);
					if(nb[c][v] == 'O') {
					printf("Open	");
				}
					else printf("Taken	");
				}
			}
			
		}
	}
	if(k == 2)
	{	
		if(ab=='a' || ab=='A')
		{
				for(c = 0; c < 30; c++)
				{
					for(v = 0; v < 6; v++)
					{
						if(am[c][v] == 'O')
						{
							printf("Seat %d-%d booked", c, v);
							am[c][v]='C';
							d = 2;
							profit = profit+30;
							break;
						}
					}
					if(d == 2)break;
				}
				if(d == 1 || d == 0) {
				printf("\nNo seat available"); 
			}
		}
		else
		{
				for(c = 0; c < 22; c++)
				{
					for(v = 0; v < 4; v++)
					{
						if(nb[c][v] == 'O')
						{
							printf("Seat %d-%d booked", c, v);
							nb[c][v]='C';
							d=2;
							profit=profit+20;
							break;
						}
					}
					if(d == 2)break;
				}
				if(d == 1 || d == 0) {
				printf("No seat available");
			}
		}
	}
	if(k==3)
	{
		if(ab=='a'||ab=='A'){
			printf("Choose a row (0-29)\n");
			scanf("%d", &c);
			if(c<0||c>29){
				printf("\n---------------------------------------------------------------------------\n");
				continue;
			}
			for(v=0; v<6; v++){
				if(am[c][v]=='O'){
					printf("Seat %d-%d booked", c, v);
					d=2;
					am[c][v]='C';
					profit=profit+30;
				}
				if(d==2)break;
			}
			if(d==1||d==0)printf("No seat available");			
		}
		else{
			printf("Choose a row (0-21)\n");
			scanf("%d", &c);
			if(c<0||c>21){
				printf("\n---------------------------------------------------------------------------\n");
				continue;
			}
			for(v=0; v<4; v++){
				if(nb[c][v]=='O'){
					nb[c][v]='C';
					printf("Seat %d-%d booked", c, v);
					d=2;
					profit=profit+20;
				}
				if(d==2)break;
			}
			if(d==1||d==0)printf("No seat available");			
		}
	}
	if(k==4)
	{
		printf("2 or 3 seats? ");
		scanf("%d", &seats);
		if(seats==2){
			if(ab=='a'||ab=='A'){
				for(c=0; c<30; c++){
					for(v=0; v<5; v++){
						if(am[c][v]=='O'&&am[c][v+1]=='O'){
							am[c][v]='C';
							am[c][v+1]='C';
							d=2;
							profit=profit+60;
							printf("Seats %d-%d, %d-%d booked", c, v, c, v+1);
							break;
						}
					}
					if(d==2)break;
				}
				if(d==1||d==0)printf("No seats available");
			}
			else{
				for(c=0; c<22; c++){
					for(v=0; v<3; v++){
						if(nb[c][v]=='O'&&nb[c][v+1]=='O'){
							nb[c][v]='C';
							nb[c][v+1]='C';
							profit=profit+40;
							d=2;
							printf("Seats %d-%d, %d-%d booked", c, v, c, v+1);
							break;
						}
					}
					if(d==2)break;
				}
				if(d==1||d==0)printf("No seats available");
			}
		}
		if(seats==3){
			if(ab=='a'||ab=='A'){
				for(c=0; c<30; c++){
					for(v=0; v<4; v++){
						if(am[c][v]=='O'&&am[c][v+1]=='O'&&am[c][v+2]=='O'){
							am[c][v]='C';
							am[c][v+1]='C';
							am[c][v+2]='C';
							profit=profit+90;
							d=2;
							printf("Seats %d-%d, %d-%d, %d-%d booked", c, v, c, v+1, c, v+2);
							break;
						}
					}
					if(d==2)break;
				}
				if(d==1||d==0)printf("No seats available");
			}
			else{
				for(c=0; c<22; c++){
					for(v=0; v<2; v++){
						if(nb[c][v]=='O'&&nb[c][v+1]=='O'&&nb[c][v+2]=='O'){
							nb[c][v]='C';
							nb[c][v+1]='C';
							nb[c][v+2]='C';
							profit=profit+60;
							d=2;
							printf("Seats %d-%d, %d-%d, %d-%d booked", c, v, c, v+1, c, v+2);
							break;
						}
					}
					if(d==2)break;
				}
				if(d==1||d==0)printf("No seats available");
			}
		}
	}
	if(k==5)
	{
		if(ab=='a'||ab=='A'){
			printf("\nSeat row: ");
			scanf("%d", &c);
			printf("Seat number: ");
			scanf("%d", &v);
			if(c<0||c>29||v<0||v>5){
			printf("\n---------------------------------------------------------------------------\n");
			continue;
			}
			if(am[c][v]=='O')printf("Available seat selected");
			else{
				printf("Successfully unbooked");
				profit=profit+22;
				am[c][v]='O';
			}
		}
		else{
			printf("\nSeat row: ");
			scanf("%d", &c);
			printf("Seat number: ");
			scanf("%d", &v);
			if(c<0||c>21||v<0||v>3){
				printf("\n---------------------------------------------------------------------------\n");
				continue;
			}
			if(nb[c][v]=='O')printf("Available seat selected");
			else{
				printf("Successfully unbooked");
				profit=profit+13;
				nb[c][v]='O';
			}
		}
	}
	if(k==6)
	{
		printf("Total profit: %d", profit);
	}
	if(k==7)
	{
		return 0;
	}
	printf("\n---------------------------------------------------------------------------\n");
	}
}
