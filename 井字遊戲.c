// ���r�C�� 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main(int argc,char** argv){
	int player = 0;
	int winner = 0;// ��10�� 
	int tens = 0;
	int choice = 0;
	int line = 0;
	int choose = 0;
	int random = 0;
	int dif_random = 0;
	float scoreplayer[4] = {0}, scorecomputer[4] = {0};
	float scoreplayer1[2] = {0}, scoreplayer2[2] = {0};
	int again=49;
	int select[2] = {0};// ��20�� 
	int board[55] = {0};
	int row[4] = {0};
	int column[4] = {0};
	int obliqueLeft[4] = {0};
	int obliqueRight[4] = {0};
	float rate = 0; 
	int a,b,i,j,k;
	for(b=0;b<3;){
		if(b>1){
			for(i=1;i<=11+16*(select[0]-1);){// ��30�� 
				if(select[1]==3 && i==1) i = 2;
				system("cls");
				if(select[0]==1) printf("\n3*3 ");
				else printf("\n5*5 ");
				if(select[1]==1) printf("²��Ҧ�");
				else if(select[1]==2) printf("�x���Ҧ�");
				else printf("���H�C��");
				if(select[0]==1) printf("\n\n\n                ");
				else printf("\n            ");
				for(j=(select[0]-1)*10; j<(9+(select[0]-1)*46);j++){// ��40��
					if(j>9 && j%10>4)
					j=(j/10+1)*10;
					if(board[j]==1)
					printf(" X ");
					else if(board[j]==2)
					printf(" O ");
					else
					printf("%2d ",j+1);
					if(j%(1+select[0]*2)==select[0]*2){
						if(j<(8+(select[0]-1)*46)){// ��50��
							if(select[0]==1) printf("\n                ---+---+---\n                ");
							else printf("\n            ---+---+---+---+---\n            ");
						}
						else if(i!=11+16*(select[0]-1)){
							if(select[0]==1) printf("\n\n");
							if(select[1]==3){
								printf("\n\n       ���a1������: %.0f",scoreplayer1[select[0]-1]);
								printf("\n       ���a2������: %.0f\n",scoreplayer2[select[0]-1]);
							}
							else{// ��60��
								printf("\n\n       ���a������: %.0f",scoreplayer[select[1]-1+(select[0]-1)*2]);
								printf("\n       �q��������: %.0f",scorecomputer[select[1]-1+(select[0]-1)*2]);
								if(scorecomputer[select[1]-1+(select[0]-1)*2]==0){
									if(scoreplayer[select[1]-1]==0) rate = 0;
									else rate = 100;
								}
								else rate = scoreplayer[select[1]-1+(select[0]-1)*2]*100/(scoreplayer[select[1]-1+(select[0]-1)*2]+scorecomputer[select[1]-1+(select[0]-1)*2]);
								printf("\n       ���a���Ӳv�O: %5.2f%%",rate);
							}
							if(select[0]==1 || i==1) printf("\n       ��'0'��^�D��.\n");// ��70��
							else printf("\n       ��'00'��^�D��.\n");
						}
					}
					else
					printf("|");
				}
				if(i==1){
					a=0;
					printf("\n �п�ܥ���(1) OR ���(2). "); 
					do{// ��80��
						choose = getch()-48;
					}while(choose<0 || choose>2);
					if(choose==0){
						b = 0;
						break;
					}
					else i=2;
				}
				else if(i==11+16*(select[0]-1)){
					//�C�������A�ҥH��̲ܳת��ѽL // ��90��
					if(again!=50){
						if(select[1]==3){
							if(winner==1)scoreplayer1[select[0]-1]+=1;
							if(winner==2)scoreplayer2[select[0]-1]+=1;
						}
						else if(winner==choose)scoreplayer[select[1]-1+(select[0]-1)*2]+=1;
						else if(winner!=0)scorecomputer[select[1]-1+(select[0]-1)*2]+=1;
					}
					//��ܵ���
					if(select[0]==1) printf("\n\n");// ��100��
					if(select[1]==3){
						printf("\n\n     ���a1������: %.0f",scoreplayer1[select[0]-1]);
						printf("\n       ���a1������: %.0f\n",scoreplayer2[select[0]-1]);
					}
					else{
						 printf("\n\n       ���a������: %.0f",scoreplayer[select[1]-1+(select[0]-1)*2]);
						printf("\n       �q��������: %.0f",scorecomputer[select[1]-1+(select[0]-1)*2]);
						if(scorecomputer[select[1]-1+(select[0]-1)*2]==0){
							if(scoreplayer[select[1]-1]==0) rate = 0;
							else rate = 100;// ��110��
						}
						else rate = scoreplayer[select[1]-1+(select[0]-1)*2]*100/(scoreplayer[select[1]-1+(select[0]-1)*2]+scorecomputer[select[1]-1+(select[0]-1)*2]);
						printf("\n       ���a���Ӳv�O %5.2f%%",rate);
					}
					printf("\n       ��'0'��^�D��.\n");
					if(winner == 0) printf("\n�h��L�᪺�@��,��������\n");
					else if(select[1]==3) printf("\n����!���a%d,�A�OĹ�a!\n",winner);
					else if(winner == choose) printf("\n����!���a,�A�OĹ�a!\n");
					else printf("\n�q�����.\n");
					printf("\n ���s�}�l(1)   ���s�p��o��(2)    ��^�D��(0)");// ��120��
					do{
						again=getch();
					}while(again<48 || again>50);
					if(again==50){// Recalculate score
						if(select[1]==3){
							scoreplayer1[select[0]-1]=0;
							scoreplayer2[select[0]-1]=0;
						}
						else{
							scoreplayer[select[1]-1+(select[0]-1)*2]=0;// ��130��
							scorecomputer[select[1]-1+(select[0]-1)*2]=0;
						}
					}
					else{
						winner=0;
						for(j=0;j<55;j++) board[j]=0;
						if (again==48){
							b=0;
							break;
						}// ��140��
						else{
							a=(a+1)%2;
							i=2;
						}
					}
				}
				else{
					//��o���Ī����a��}���
					player = (a+i)%2+1;
					if(player==choose || select[1]==3){// ��150��
						if(select[0]==1){
							printf("\n���a");
							if(select[1]==3) printf(" %d",player);
							printf(", �Цb��}�̿�ܤ@�ӼƦr "
								"���Ӧa��O�A�Q�n�� %c. ",
								(player == 1)?'X':'O');
						}
						do{
							if(select[0]==1) choice = getch()-48;
							else{// ��160��
								printf("\n���a");
								if(select[1]==3) printf(" %d",player);
								printf(", �Цb��}�̿�ܤ@�ӼƦr "
									"���Ӧa��O�A�Q�n�� %c: ",
									(player == 1)?'X':'O');
								tens = getche() - 48;
								choice = tens*10 + getche() - 48;
							}
						}while((choice<(select[0]*10-9) || choice>(select[0]*46-37) || (select[0]==2 && (choice%10==0 || choice%10>5))
							  || board[choice-1]!=0) && choice!=0);// ��170��
					}
					else{
		 				// �p�����ܪ��]��
	 					printf("\nloading...");
						do{
							choice = 0;
							for(j=(select[0]-1)*10;j<(9+(select[0]-1)*46);j++){
								if(j>9 && j%10>4)
								j=(j/10+1)*10;
								for(k=0;k<select[0]*2;k++){// ��180��
									row[k]=j+k+1;
									if(row[k]/(1+select[0]*2) > j/(1+select[0]*2))
									row[k]-=(1+select[0]*2);
									column[k]=k*(select[0]*7-4)+j+(select[0]*7-4);
									if(column[k]>=(9+(select[0]-1)*46))
									column[k]-=(9+(select[0]-1)*41);
									obliqueLeft[k]=k*(select[0]*7-3)+j+(select[0]*7-3);
									if(obliqueLeft[k]>=(12+(select[0]-1)*43))
									obliqueLeft[k]-=(12+(select[0]-1)*43);
									obliqueRight[k]=k*(select[0]*7-5)+j+(select[0]*7-5);// ��190��
									if(obliqueRight[k]>=(8+(select[0]-1)*47))
									obliqueRight[k]-=obliqueRight[k]/(6+(select[0]-1)*49)*(6+(select[0]-1)*39);
								}
								if(((board[row[0]]==board[row[1]] && board[row[0]]==board[row[select[0]]]
								  && board[row[0]]==board[row[select[0]*2-1]] && board[row[0]]!=0)
								 || (board[column[0]]==board[column[1]] && board[column[0]]==board[column[select[0]]]
								  && board[column[0]]==board[column[select[0]*2-1]] && board[column[0]]!=0))
								  && board[j]==0){
								 	choice=j+1;
								 	break;// ��200��
								}
								if((j+(select[0]-1))%(select[0]*7-3)==0){
									if((board[obliqueLeft[0]]==board[obliqueLeft[1]] && board[obliqueLeft[0]]==board[obliqueLeft[select[0]]]
									 && board[obliqueLeft[0]]==board[obliqueLeft[select[0]*2-1]] && board[obliqueLeft[0]]!=0)
									 && board[j]==0){
									 	choice=j+1;
									 	break;
									}
								}
								if((j-(select[0]-1)*5)%(select[0]*7-5)==0 && j>0 && (j<=6 || j>9)){//��210��
									if((board[obliqueRight[0]]==board[obliqueRight[1]] && board[obliqueRight[0]]==board[obliqueRight[select[0]]]
									 && board[obliqueRight[0]]==board[obliqueRight[select[0]*2-1]] && board[obliqueRight[0]]!=0)
									 && board[j]==0){
									 	choice=j+1;
									 	break;
									}
								}
							}
							if(choice==0){
								if(i<(select[0]*16-8+a)){// ��220��
									if(select[1]==2){
										if(select[0]==1){
											for(k=0;k<200;k++){
												srand(time(NULL));
							 					random = rand()%5;
												if(board[random*2]==0){
													choice = random*2+1;
													break;
												}
											}// ��230��
										}
										else{
											for(j=10;j<55;j++){
												if(j%10>4)
												j=(j/10+1)*10;
												for(k=0;k<4;k++){
													row[k]=j+k+1;
													if(row[k]/5 > j/5)
													row[k]-=5;
													column[k]=k*10+j+10;// ��240��
													if(column[k]>=55)
													column[k]-=50;
												}
												srand(time(NULL));
												dif_random = rand()%3;
												if(((board[row[dif_random]]==board[row[dif_random+1]] && board[row[dif_random]]!=0)
												 || (board[column[dif_random]]==board[column[dif_random+1]] && board[column[dif_random]]!=0))
												  && board[j]==0){
												 	choice=j+1;
												 	break;// ��250��
												}
											}
										}
									}
									if(choice==0){
										for(k=0;(k<2500 && select[0]==2) || (k<(16+((select[1]%2)*884)) && select[0]==1);k++){
											srand(time(NULL));
											if(select[0]==2){
							 					random=rand()%25;
							 					if(board[(random/5+1)*10+random%5]==0){// ��260��
								 					choice = (random/5+1)*10+random%5+1;
							 						break;
												}
											}
											else{
												random = rand()%(4+((select[1]%2)*5))+select[1]-1;
												if(board[random*select[1]-select[1]+1]==0){
													choice = random*select[1]+(select[1]%2);
													break;
												}// ��270��
											}
										}
									}
								}
								else{
									for(j=(select[0]*10-10);j<(select[0]*46-37);j++){
										if(j>9 && j%10>4)
										j=(j/10+1)*10;
										if(board[j]==0){
											choice = j+1;// ��280��
											break;
										}
									}
								}
							}
						}while(choice<(select[0]*10-9) || choice>(select[0]*46-37) || (select[0]==2 && (choice%10==0 || choice%10>5)) || board[choice-1]!=0);
					}
					//���J���a�лx 
					if(choice==0){
						for(j=0;j<55;j++) board[j] = 0;// ��290��
						b = 0;
						break;
					}
					board[choice-1] = player ;
					//�ˬd��ӽu - �����O�﨤�u
					if((board[select[0]*10-10]==board[select[0]*17-13] && board[select[0]*10-10]==board[select[0]*24-16]
					 && board[select[0]*10-10]==board[select[0]*39-35] && board[select[0]*10-10]==board[select[0]*46-38]
					 && board[select[0]*10-10]!=0)
					|| (board[select[0]*12-10]==board[select[0]*19-15] && board[select[0]*12-10]==board[select[0]*26-20]
					 && board[select[0]*12-10]==board[select[0]*37-33] && board[select[0]*12-10]==board[select[0]*44-38]// ��300��
					 && board[select[0]*12-10]!=0)){
					 	winner = player;
					}	
					else
						//�ˬd��M�C�O�_����Ӧ�
						for(line = 0;line <= 4;line++)
							if((board[line+(select[0]*10-10)]==board[line+(select[0]*17-14)] &&
								board[line+(select[0]*10-10)]==board[line+(select[0]*27-24)] &&
								board[line+(select[0]*10-10)]==board[line+(select[0]*34-28)] &&
								board[line+(select[0]*10-10)]==board[line+(select[0]*44-38)] &&// ��310��
								board[line+(select[0]*10-10)]!=0) ||
								(board[(line+select[0]-1)*(select[0]*7-4)]==board[(line+select[0]-1)*(select[0]*7-4)+1] &&
								board[(line+select[0]-1)*(select[0]*7-4)]==board[(line+select[0]-1)*(select[0]*7-4)+2] &&
								board[(line+select[0]-1)*(select[0]*7-4)]==board[(line+select[0]-1)*(select[0]*7-4)+(select[0]*2-1)] &&
								board[(line+select[0]-1)*(select[0]*7-4)]==board[(line+select[0]-1)*(select[0]*7-4)+(select[0]*2)] &&
								board[(line+select[0]-1)*(select[0]*7-4)]!=0)){
									winner = player;
								}
					if(winner==player) i=11+16*(select[0]-1);
					else i++;//��320��
				}
			}
		}
		else{
			a=0;
			system("cls");
			printf("\n\n        ²�檺���r�C��\n");
			if(b==0){
				for(k=0;k<2;k++){
					if(k<1){// ��330��
						printf("\n\n        �C������:\n");
						printf("\n\n        3 X 3 �Ҧ� (1)\n");
						printf("\n\n        5 X 5 �Ҧ� (2)\n");
						printf("\n\n        �h�X�C��   (0)\n");
					}
					else printf("\n      �A�����]0�^�h�X.\n");
					do{
						select[0] = getch()-48;
					}while(select[0]<0 || select[0]>2);
					if(k<1 && select[0]!=0)break;//��340��
				}
				if(select[0]==0)break;
				else b++;
			}
			else{
				printf("\n\n        �C�������׿��:\n");
				printf("\n\n        ²��Ҧ�   (1)\n");
				printf("\n\n        �x���Ҧ�   (2)\n");
				printf("\n\n        ���H�C��   (3)\n");
				printf("\n\n        ��^�D��   (0)\n");// ��350��
				do{
					select[1] = getch()-48;
				}while(select[1]<0 || select[1]>3);
				if(select[1]==0)b--;
				else b++;
			}
		}
	}
	return 0;
}// ��360��


