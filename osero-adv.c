#include <stdio.h>

int main(void){

    int i, f, turn = 0, check=0, A, X, Y, x, y, ta, yo, skip = 0, black = 0, white = 0, Bot = -1, skip_count = 0; 
	float tate, yoko;
    int panel[8][8] = {0};
	int panel2[8][8] = {0};

    panel[3][3] = 2;
    panel[3][4] = 1;
    panel[4][3] = 1;
    panel[4][4] = 2;

	printf("���A�c�̈ʒu�𐔎��Ŏw�肵�čs���I�Z���ł��B\n�u�{�v���u����ꏊ�A�u�E�v���󔒁A�u�Z�v�����A�u���v�����ł��B\n\n1�l�ŗV�ԂȂ� 1 ���A2�l�ŗV�ԂȂ� 2 ����͂��Ă��������B\n");
	scanf("%d", &i);
	if (i==2)  Bot = -1;
	else {
		printf("��s����U���I�����Ă������� ��s�Ȃ� 1 ��U�Ȃ� 2\n");
		scanf("%d", &i);
		if (i == 1) {
			Bot = 0;
		} else Bot = 1;
	}

    while (1) {
	turn++;
	

        black = 0; white = 0;
       	for (i = 0; i <= 7; i++) {
			for (f = 0; f <= 7; f++) {
				if (panel[i][f] == 1) black++;
			}
        }

        for (i = 0; i <= 7; i++) {
			for (f = 0; f <= 7; f++) {
				if (panel[i][f] == 2) white++;
			}
        }


           

	for (i = 0; i <= 7; i++) {
		for (f = 0; f <= 7; f++) {
			if (panel[i][f] == 3) panel[i][f] = 0;
		}
	}


	for (A = 0; A<=7; A++) {
		if (A == 0) {X = 0; Y = -1;}
		if (A == 1) {X = 1; Y = -1;}
		if (A == 2) {X = 1; Y = 0;}
		if (A == 3) {X = 1; Y = 1;}
		if (A == 4) {X = 0; Y = 1;}
		if (A == 5) {X = -1; Y = 1;}
		if (A == 6) {X = -1; Y = 0;}
		if (A == 7) {X = -1; Y = -1;}
		
	for (i = 0; i<=7; i++) {
        for (f = 0; f<=7; f++) {
			if (panel[i+Y][f+X] == 1 && turn%2 == 0 && i+Y >= 0 && i+Y <= 7 && f+X >= 0 && f+X <= 7) 
				{ x = X; y = Y;
				while (panel[i+y][f+x] == 1 && i+y >= 0 && i+y <= 7 && f+x >= 0 && f+x <= 7) {
					x=x+X; y=y+Y;
				}
				if (panel[i+y][f+x] == 2 && panel[i][f] == 0&& i+y >= 0 && i+y <= 7 && f+x >= 0 && f+x <= 7) {
						
					panel[i][f] = 3;
						
                 }
			 } else if (panel[i+Y][f+X] == 2 && turn%2 == 1 && i+Y >= 0 && i+Y <= 7 && f+X >= 0 && f+X <= 7) 
					{ x = X; y = Y;
					while (panel[i+y][f+x] == 2 && i+y >= 0 && i+y <= 7 && f+x >= 0 && f+x <= 7) {
						x=x+X; y=y+Y;
					}
					if (panel[i+y][f+x] == 1 && panel[i][f] == 0 && i+y >= 0 && i+y <= 7 && f+x >= 0 && f+x <= 7) 
						{
						
						panel[i][f] = 3;
						
						
				 }}
           }}}
	
	for (i = 0; i<=7; i++) {
        for (f = 0; f<=7; f++) {
			panel2[i][f] = 0;
		}
	}


	if (turn % 2 == Bot) {
		for (ta = 0; ta <= 7; ta++) {
			for (yo = 0; yo <= 7; yo++) {
				if (panel[ta][yo] == 3) {

					for (A = 0; A<=7; A++) {
						if (A == 0) {X = 0; Y = -1;}
						if (A == 1) {X = 1; Y = -1;}
						if (A == 2) {X = 1; Y = 0;}
						if (A == 3) {X = 1; Y = 1;}
						if (A == 4) {X = 0; Y = 1;}
						if (A == 5) {X = -1; Y = 1;}
						if (A == 6) {X = -1; Y = 0;}
						if (A == 7) {X = -1; Y = -1;}
						
						if (panel[ta+Y][yo+X] == 1 && turn%2 == 0 && ta+Y >= 0 && ta+Y <= 7 && yo+X >= 0 && yo+X <= 7) 
								{ x = X; y = Y;
									while (panel[ta+y][yo+x] == 1 && ta+y >= 0 && ta+y <= 7 && yo+x >= 0 && yo+x <= 7) {
										x=x+X; y=y+Y;
									} 

									if (panel[ta+y][yo+x] == 2 && ta+y >= 0 && ta+y <= 7 && yo+x >= 0 && yo+x <= 7) {
										x=x-X; y=y-Y;
										i = panel2[ta][yo];
										while (panel[ta+y][yo+x] == 1) {
											i++;
											x=x-X; y=y-Y;
											panel2[ta][yo] = i;
										}
										i = 0;
									}       

						
								} else if (panel[ta+Y][yo+X] == 2 && turn%2 == 1 && ta+Y >= 0 && ta+Y <= 7 && yo+X >= 0 && yo+X <= 7) 
									{ x = X; y = Y;
									while (panel[ta+y][yo+x] == 2 && ta+y >= 0 && ta+y <= 7 && yo+x >= 0 && yo+x <= 7) {
										x=x+X; y=y+Y;
									}
				
									if (panel[ta+y][yo+x] == 1 && ta+y >= 0 && ta+y <= 7 && yo+x >= 0 && yo+x <= 7) {
										x=x-X; y=y-Y;
										i = panel2[ta][yo];
										while (panel[ta+y][yo+x] == 2) {
											i++;
											x=x-X; y=y-Y;
											panel2[ta][yo] = i;
										}
										i = 0;
										
								}}}

				}
			}
		}
		ta = 0; yo = 0;
	}




	if (!(turn-skip > 60 || white == 0 || black == 0 || skip_count >= 2)) {
	A = 0;
	for (i = 0; i <= 7; i++) {
		for (f = 0; f <= 7; f++) {
			if (panel[i][f] == 3) A++;
		}
	}
	if (A == 0) A = 1;
	else A = 0;
	} else A = 0;
    if (A == 0) {
	
	if (!(turn-skip > 60 || white == 0 || black == 0 || skip_count >= 2)) {
	skip_count = 0;
    printf("\n%d �^�[����  ", turn);
	if (turn %2 == Bot) printf("BOT"); 
	else printf("   ");
    if (turn%2 == 1) printf("�u���v�̏��Ԃł�\n");
    else printf("�u���v�̏��Ԃł�\n");
	} else printf("\n");
    for (i = -1; i<=7; i++) {
        if (i == -1) printf(" ");
        for (f = -1; f<=7; f++) {
            if (i == -1) {
                if (f==0) printf("�P");
                if (f==1) printf("�Q");
                if (f==2) printf("�R");
                if (f==3) printf("�S");
                if (f==4) printf("�T");
                if (f==5) printf("�U");
                if (f==6) printf("�V");
                if (f==7) printf("�W");
            }
            else if (f == -1) printf("%d",i+1);
            else if (panel[i][f] == 0) printf("�E");
            else if (panel[i][f] == 1) printf("��");
            else if (panel[i][f] == 2) printf("�Z");
			else if (panel[i][f] == 3) printf("�{");
        }
    printf("\n");
    }
		if (turn-skip > 60 || white == 0 || black == 0 || skip_count >= 2) {   
                printf("\n\n�I���I\n����   �� : %d   �� : %d\n", black, white);
				if (white > black) printf("\n���̏����I\n");
					else if (white < black) printf("\n���̏����I\n");
						else printf("\n��������");
				return;
			}

	if (turn % 2 == Bot) {
		A = -1;
		for (i = 0; i<=7; i++) {
        	for (f = 0; f<=7; f++) {
				if (panel2[i][f] > A) {
					A = panel2[i][f];
				}
			}
		}

	for (i = 0; i<=7; i++) {
        for (f = 0; f<=7; f++) {
			if (panel2[f][i] == A && panel[f][i] == 3) {
			tate = i; yoko = f;
			}
		}
	}

	yo = tate; ta = yoko;
	printf("�� ...  %d\n�c ...  %d\n", ta+1, yo+1);
	

	} else { 
	while (1) {
	while (1) {
    printf("�� ...  ");
    scanf("%f", &yoko);
	for (i = 1; i<=8; i++) 
		if (i == yoko) f = 1;
	if (f == 1) break;
	
	printf("�L���Ȑ�������͂��Ă�������\n");
	} f = 0;
	while (1) {
    printf("�c ...  ");
    scanf("%f", &tate);
    for (i = 1; i<=8; i++) 
		if (i == tate) f = 1;
	if (f == 1) break;
	
	printf("�L���Ȑ�������͂��Ă�������\n");
	} f = 0;  ta = tate-1;  yo = yoko-1;
	if (panel[ta][yo] == 3) break;
	printf("�z�u�ł��܂���B�@�I�тȂ����Ă��������B\n\n");
    }
	}
	
	if (turn%2 == 1) panel[ta][yo] = 1;
	else panel[ta][yo] = 2;

	for (A = 0; A<=7; A++) {
		if (A == 0) {X = 0; Y = -1;}
		if (A == 1) {X = 1; Y = -1;}
		if (A == 2) {X = 1; Y = 0;}
		if (A == 3) {X = 1; Y = 1;}
		if (A == 4) {X = 0; Y = 1;}
		if (A == 5) {X = -1; Y = 1;}
		if (A == 6) {X = -1; Y = 0;}
		if (A == 7) {X = -1; Y = -1;}
		
			
			if (panel[ta+Y][yo+X] == 1 && turn%2 == 0 && ta+Y >= 0 && ta+Y <= 7 && yo+X >= 0 && yo+X <= 7) 
				{ x = X; y = Y;
					while (panel[ta+y][yo+x] == 1 && ta+y >= 0 && ta+y <= 7 && yo+x >= 0 && yo+x <= 7) {
						x=x+X; y=y+Y;
					} 

					if (panel[ta+y][yo+x] == 2 && ta+y >= 0 && ta+y <= 7 && yo+x >= 0 && yo+x <= 7) {
						x=x-X; y=y-Y;
						while (panel[ta+y][yo+x] != 2) {
							panel[ta+y][yo+x] = 2;
							x=x-X; y=y-Y;
						}
                    }       

         
				 } else if (panel[ta+Y][yo+X] == 2 && turn%2 == 1 && ta+Y >= 0 && ta+Y <= 7 && yo+X >= 0 && yo+X <= 7) 
					{ x = X; y = Y;
					while (panel[ta+y][yo+x] == 2 && ta+y >= 0 && ta+y <= 7 && yo+x >= 0 && yo+x <= 7) {
						x=x+X; y=y+Y;
					}
 
					if (panel[ta+y][yo+x] == 1 && ta+y >= 0 && ta+y <= 7 && yo+x >= 0 && yo+x <= 7) {
						x=x-X; y=y-Y;
						while (panel[ta+y][yo+x] != 1) {
							panel[ta+y][yo+x] = 1;
							x=x-X; y=y-Y;
						}
						
				 }}}
} else {
        printf("%d �^�[����    ", turn);
    if (turn%2 == 1) printf("�u���v�̏��Ԃ͐ݒu�s�̂��߃X�L�b�v����܂���\n\n");
    else printf("�u���v�̏��Ԃ͐ݒu�s�̂��߃X�L�b�v����܂���\n\n");
    skip++;
	skip_count++;
    }

}}   