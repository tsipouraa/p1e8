#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	char name_am[30][6][20];
	char name_nb[22][4][20];
	char ab, kados[50];
	char am [30][6];  
	char nb[22][4];
	int seats, letter, profit_a=0, profit_b=0, k, c, v, d;
	int pin_am[30][6], pin_nb[22][4], pin_try;
	srand(time(NULL));
	for(c=0; c<22; c++)
	{
		for(v=0; v<4; v++)
		{
			nb[c][v]='O';
			for(letter=0; letter<20; letter++){
				name_nb[c][v][letter]=0;
			}
		}
	}
	for(c=0; c<30; c++){
		for(v=0; v<6; v++){
			am[c][v]='O';
			for(letter=0; letter<20; letter++){
				name_am[c][v][letter]=0;
			}
		}
	}
	while(1){//extra input messes w aircraft selection
	d=3;
	k=10;
	c=50;
	v=50;
	do{
		printf("\nChoose an aircraft!\n (A)AM57	(B)NB3842\n");
		scanf("%s", &ab);//AS LONG AS THE 1ST ONE IS A/B IT TAKES IT AS CORRECT
	}while(ab!='a'&&ab!='A'&&ab!='b'&&ab!='B');
	printf(" 1	Show available seats\n 2	Book random seat\n 3	Book specific seat\n 4	Book several seats\n 5	Cancel booking\n 6	Show profit\n 7	Show booking name\n 8	Leave\n");
	scanf("%d", &k);
	if(k!=1&&k!=2&&k!=3&&k!=4&&k!=5&&k!=6&&k!=7)scanf("%s", &kados);//an c 2plo choose, an s thelei 2 arithmous
	if(k==1)
	{
		if(ab=='a'||ab=='A')
		{
			for(c=0; c<30; c++){
				printf("\n");
				for(v=0; v<6; v++){
					printf("%d-%d: ", c, v);
					if(am[c][v]=='O')printf("Open	");
					else printf("Taken	");
					if(v==2)printf("|	|	");
				}
			}
		}
		else
		{
			for(c=0; c<22; c++){
				printf("\n");
				for(v=0; v<4; v++){
					printf("%d-%d: ", c, v);
					if(nb[c][v]=='O')printf("Open	");
					else printf("Taken	");
					if(v==1)printf("|	|	");
				}
			}
			
		}
	}
	if(k==2)
	{	
		if(ab=='a'||ab=='A')
		{
			for(c=0; c<30; c++)
			{
				for(v=0; v<6; v++)
				{
					if(am[c][v]=='O'){
						d=2;
						break;
					}
				}
				if(d==2)break;
			}
			if(d==1||d==0)printf("\nNo seat available");
			if(d==2){
				do{
					c=rand()%30;
					v=rand()%6;
				}while(am[c][v]=='C');
				printf("Enter a last name up to 20 characters: ");
				scanf("%20s", &name_am[c][v]);
				printf("Enter a pin number: ");
				scanf("%d", &pin_am[c][v]);
				am[c][v]='C';
				profit_a+=30;
				printf("Seat %d-%d booked for %s", c, v, name_am[c][v]);
			}
		}
		else{	
			for(c=0; c<22; c++)	{
				for(v=0; v<4; v++){
					if(nb[c][v]=='O'){
						d=2;
						break;
					}
				}
				if(d==2)break;
			}
			if(d==1||d==0)printf("\nNo seat available");
			if(d==2){
				do{
					c=rand()%22;
					v=rand()%4;
				}while(nb[c][v]=='C');
				printf("Enter a last name up to 20 characters: ");
				scanf("%20s", &name_nb[c][v]);
				printf("Enter a pin number: ");
				scanf("%d", &pin_nb[c][v]);
				nb[c][v]='C';
				profit_b+=20;
				printf("Seat %d-%d booked for %s", c, v, name_nb[c][v]);
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
					do{
						v=rand()%6;
					}while(am[c][v]!='O');
					printf("Enter a last name up to 20 characters: ");
					scanf("%20s", &name_am[c][v]);
					printf("Seat %d-%d booked for %s", c, v, name_am[c][v]);
					printf("\nEnter a pin number: ");
					scanf("%d", &pin_am[c][v]);
					d=2;
					am[c][v]='C';
					profit_a+=30;
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
					do{
						v=rand()%4;
					}while(nb[c][v]!='O');
					printf("Enter a last name up to 20 characters: ");
					scanf("%20s", &name_nb[c][v]);
					printf("Enter a pin number: ");
					scanf("%d", &pin_nb[c][v]);
					nb[c][v]='C';
					printf("Seat %d-%d booked for %s", c, v, name_nb[c][v]);
					d=2;
					profit_b+=20;
				}
				if(d==2)break;
			}
			if(d==1||d==0)printf("No seat available");			
		}
	}
	if(k==4)
	{
		printf("2 or 3 seats?(3 is not available for nb3842): ");
		scanf("%d", &seats);
		if(seats==2){
			if(ab=='a'||ab=='A'){
				for(c=0; c<30; c++){
					for(v=0; v<2; v++){
						if(am[c][v]=='O'&&am[c][v+1]=='O'){
							printf("Enter a last name up to 20 characters: ");
							scanf("%20s", &name_am[c][v]);
							for(letter=0; letter<20; letter++)name_am[c][v+1][letter]=name_am[c][v][letter];
							printf("Enter a pin number: ");
							scanf("%d", &pin_am[c][v]);
							pin_am[c][v+1]=pin_am[c][v];
							am[c][v]='C';
							am[c][v+1]='C';
							d=2;
							profit_a+=60;
							printf("Seats %d-%d, %d-%d booked for %s", c, v, c, v+1, name_am[c][v+1]);
							break;
						}
					}
					if(d==2)break;
					for(v=3; v<5; v++){
						if(am[c][v]=='O'&&am[c][v+1]=='O'){
							printf("Enter a last name up to 20 characters: ");
							scanf("%20s", &name_am[c][v]);
							for(letter=0; letter<20; letter++)name_am[c][v+1][letter]=name_am[c][v][letter];
							printf("Enter a pin number: ");
							scanf("%d", &pin_am[c][v]);
							pin_am[c][v+1]=pin_am[c][v];
							am[c][v]='C';
							am[c][v+1]='C';
							d=2;
							profit_a+=60;
							printf("Seats %d-%d, %d-%d booked for %s", c, v, c, v+1, name_am[c][v]);
							break;
						}
					}
					if(d==2)break;
				}
				if(d==1||d==0)printf("No seats available");
			}
			else{
				for(c=0; c<22; c++){
						if(nb[c][0]=='O'&&nb[c][1]=='O'){
							printf("Enter a last name up to 20 characters: ");
							scanf("%20s", &name_nb[c][0]);
							for(letter=0; letter<20; letter++)name_nb[c][1][letter]=name_nb[c][0][letter];
							printf("Enter a pin number: ");
							scanf("%d", pin_nb[c][0]);
							pin_nb[c][1]=pin_nb[c][0];
							nb[c][0]='C';
							nb[c][1]='C';
							profit_b+=40;
							d=2;
							printf("Seats %d-0, %d-1 booked for %s", c, c, name_nb[c][1]);
							break;
							}
						if(nb[c][2]=='O'&&nb[c][3]=='O'){
							printf("Enter a last name up to 20 characters: ");
							scanf("%20s", &name_nb[c][2]);
							for(letter=0; letter<20; letter++)name_nb[c][3][letter]=name_nb[c][2][letter];
							printf("Enter a pin number: ");
							scanf("%d", &pin_nb[c][2]);
							pin_nb[c][3]=pin_nb[c][2];
							nb[c][2]='C';
							nb[c][3]='C';
							profit_b+=40;
							d=2;
							printf("Seats %d-2, %d-3 booked for %s", c, c, name_nb[c][3]);
							break;
							}
				}
				if(d==1||d==0)printf("No seats available");
			}
		}
		if(seats==3){
			if(ab=='a'||ab=='A'){
				for(c=0; c<30; c++){
					if(am[c][0]=='O'&&am[c][1]=='O'&&am[c][2]=='O'){
						printf("Enter a last name up to 20 characters: ");
						scanf("%20s", &name_am[c][0]);
						for(letter=0; letter<20; letter++)name_am[c][2][letter]=name_am[c][1][letter]=name_am[c][0][letter];
						printf("Enter a pin number: ");
						scanf("%d", &pin_am[c][0]);
						pin_am[c][2]=pin_am[c][1]=pin_am[c][0];
						am[c][0]='C';
						am[c][1]='C';
						am[c][2]='C';
						d=2;
						profit_a+=90;
						printf("Seats %d-0, %d-1, %d-2 booked for %s", c, c, c, name_am[c][2]);
						break;
					}
					if(am[c][3]=='O'&&am[c][4]=='O'&&am[c][5]=='O'){
						printf("Enter a last name up to 20 characters: ");
						scanf("%20s", &name_am[c][3]);
						for(letter=0; letter<20; letter++)name_am[c][5][letter]=name_am[c][4][letter]=name_am[c][3][letter];
						printf("Enter a pin number: ");
						scanf("%d", &pin_am[c][3]);
						pin_am[c][5]=pin_am[c][4]=pin_am[c][3];
						am[c][3]='C';
						am[c][4]='C';
						am[c][5]='C';
						d=2;
						profit_a+=90;
						printf("Seats %d-3, %d-4, %d-5 booked for %s", c, c, c, name_am[c][5]);
						break;
					}
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
				printf("Enter pin: ");
				scanf("%d", &pin_try);
				if(pin_try!=pin_am[c][v]){
				printf("Wrong pin\n---------------------------------------------------------------------------\n");
				continue;
				}
				printf("Successfully unbooked");
				profit_a+=22;
				am[c][v]='O';
				for(letter=0; letter<20; letter++){
					name_am[c][v][letter]=0;
				}
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
				printf("Enter pin: ");
				scanf("%d", &pin_try);
				if(pin_try!=pin_nb[c][v]){
					printf("Wrong pin\n---------------------------------------------------------------------------\n");
					continue;
				}
				printf("Successfully unbooked");
				profit_b+=13;
				for(letter=0; letter<20; letter++){
					name_nb[c][v][letter]=0;
				}
				nb[c][v]='O';
			}
		}
	}
	if(k==6)
	{
		if(ab=='a'||ab=='A')printf("AM57 profit: %d", profit_a);
		if(ab=='b'||ab=='B')printf("NB3842 profit: %d", profit_b);
	}
	if(k==7)
	{
		if(ab=='a'||ab=='A'){
			printf("Choose a seat row: ");
			scanf("%d", &c);
			printf("Choose a seat number: ");
			scanf("%d", &v);
			if(c<0||c>29||v<0||v>5){
				printf("\n---------------------------------------------------------------------------\n");
				continue;
			}
			if(name_am[c][v][0]==0){
				printf("Seat booked by no one");
				printf("\n---------------------------------------------------------------------------\n");	
				continue;
			}
			printf("Seat booked by %s", name_am[c][v]);			
		}
		else{
			printf("Choose a seat row: ");
			scanf("%d", &c);
			printf("Choose a seat number: ");
			scanf("%d", &v);
			if(c<0||c>21||v<0||v>3){
				printf("\n---------------------------------------------------------------------------\n");
				continue;
			}
			if(name_nb[c][v][0]==0){
				printf("Seat booked by no one");
				printf("\n---------------------------------------------------------------------------\n");	
				continue;
			}
			printf("Seat booked by %s", name_nb[c][v]);		
		}
	}
	if(k==8)
	{
		return 0;
	}
	printf("\n---------------------------------------------------------------------------\n");
	}
}
