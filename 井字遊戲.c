// 井字遊戲 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main(int argc,char** argv){
	int player = 0;
	int winner = 0;// 第10行 
	int tens = 0;
	int choice = 0;
	int line = 0;
	int choose = 0;
	int random = 0;
	int dif_random = 0;
	float scoreplayer[4] = {0}, scorecomputer[4] = {0};
	float scoreplayer1[2] = {0}, scoreplayer2[2] = {0};
	int again=49;
	int select[2] = {0};// 第20行 
	int board[55] = {0};
	int row[4] = {0};
	int column[4] = {0};
	int obliqueLeft[4] = {0};
	int obliqueRight[4] = {0};
	float rate = 0; 
	int a,b,i,j,k;
	for(b=0;b<3;){
		if(b>1){
			for(i=1;i<=11+16*(select[0]-1);){// 第30行 
				if(select[1]==3 && i==1) i = 2;
				system("cls");
				if(select[0]==1) printf("\n3*3 ");
				else printf("\n5*5 ");
				if(select[1]==1) printf("簡單模式");
				else if(select[1]==2) printf("困難模式");
				else printf("雙人遊玩");
				if(select[0]==1) printf("\n\n\n                ");
				else printf("\n            ");
				for(j=(select[0]-1)*10; j<(9+(select[0]-1)*46);j++){// 第40行
					if(j>9 && j%10>4)
					j=(j/10+1)*10;
					if(board[j]==1)
					printf(" X ");
					else if(board[j]==2)
					printf(" O ");
					else
					printf("%2d ",j+1);
					if(j%(1+select[0]*2)==select[0]*2){
						if(j<(8+(select[0]-1)*46)){// 第50行
							if(select[0]==1) printf("\n                ---+---+---\n                ");
							else printf("\n            ---+---+---+---+---\n            ");
						}
						else if(i!=11+16*(select[0]-1)){
							if(select[0]==1) printf("\n\n");
							if(select[1]==3){
								printf("\n\n       玩家1的分數: %.0f",scoreplayer1[select[0]-1]);
								printf("\n       玩家2的分數: %.0f\n",scoreplayer2[select[0]-1]);
							}
							else{// 第60行
								printf("\n\n       玩家的分數: %.0f",scoreplayer[select[1]-1+(select[0]-1)*2]);
								printf("\n       電腦的分數: %.0f",scorecomputer[select[1]-1+(select[0]-1)*2]);
								if(scorecomputer[select[1]-1+(select[0]-1)*2]==0){
									if(scoreplayer[select[1]-1]==0) rate = 0;
									else rate = 100;
								}
								else rate = scoreplayer[select[1]-1+(select[0]-1)*2]*100/(scoreplayer[select[1]-1+(select[0]-1)*2]+scorecomputer[select[1]-1+(select[0]-1)*2]);
								printf("\n       玩家的勝率是: %5.2f%%",rate);
							}
							if(select[0]==1 || i==1) printf("\n       按'0'返回主頁.\n");// 第70行
							else printf("\n       按'00'返回主頁.\n");
						}
					}
					else
					printf("|");
				}
				if(i==1){
					a=0;
					printf("\n 請選擇先手(1) OR 後手(2). "); 
					do{// 第80行
						choose = getch()-48;
					}while(choose<0 || choose>2);
					if(choose==0){
						b = 0;
						break;
					}
					else i=2;
				}
				else if(i==11+16*(select[0]-1)){
					//遊戲結束，所以顯示最終的棋盤 // 第90行
					if(again!=50){
						if(select[1]==3){
							if(winner==1)scoreplayer1[select[0]-1]+=1;
							if(winner==2)scoreplayer2[select[0]-1]+=1;
						}
						else if(winner==choose)scoreplayer[select[1]-1+(select[0]-1)*2]+=1;
						else if(winner!=0)scorecomputer[select[1]-1+(select[0]-1)*2]+=1;
					}
					//顯示結束
					if(select[0]==1) printf("\n\n");// 第100行
					if(select[1]==3){
						printf("\n\n     玩家1的分數: %.0f",scoreplayer1[select[0]-1]);
						printf("\n       玩家1的分數: %.0f\n",scoreplayer2[select[0]-1]);
					}
					else{
						 printf("\n\n       玩家的分數: %.0f",scoreplayer[select[1]-1+(select[0]-1)*2]);
						printf("\n       電腦的分數: %.0f",scorecomputer[select[1]-1+(select[0]-1)*2]);
						if(scorecomputer[select[1]-1+(select[0]-1)*2]==0){
							if(scoreplayer[select[1]-1]==0) rate = 0;
							else rate = 100;// 第110行
						}
						else rate = scoreplayer[select[1]-1+(select[0]-1)*2]*100/(scoreplayer[select[1]-1+(select[0]-1)*2]+scorecomputer[select[1]-1+(select[0]-1)*2]);
						printf("\n       玩家的勝率是 %5.2f%%",rate);
					}
					printf("\n       按'0'返回主頁.\n");
					if(winner == 0) printf("\n多麼無聊的一局,此為平局\n");
					else if(select[1]==3) printf("\n恭喜!玩家%d,你是贏家!\n",winner);
					else if(winner == choose) printf("\n恭喜!玩家,你是贏家!\n");
					else printf("\n電腦獲勝.\n");
					printf("\n 重新開始(1)   重新計算得分(2)    返回主頁(0)");// 第120行
					do{
						again=getch();
					}while(again<48 || again>50);
					if(again==50){// Recalculate score
						if(select[1]==3){
							scoreplayer1[select[0]-1]=0;
							scoreplayer2[select[0]-1]=0;
						}
						else{
							scoreplayer[select[1]-1+(select[0]-1)*2]=0;// 第130行
							scorecomputer[select[1]-1+(select[0]-1)*2]=0;
						}
					}
					else{
						winner=0;
						for(j=0;j<55;j++) board[j]=0;
						if (again==48){
							b=0;
							break;
						}// 第140行
						else{
							a=(a+1)%2;
							i=2;
						}
					}
				}
				else{
					//獲得有效的玩家方陣選擇
					player = (a+i)%2+1;
					if(player==choose || select[1]==3){// 第150行
						if(select[0]==1){
							printf("\n玩家");
							if(select[1]==3) printf(" %d",player);
							printf(", 請在方陣裡選擇一個數字 "
								"哪個地方是你想要打 %c. ",
								(player == 1)?'X':'O');
						}
						do{
							if(select[0]==1) choice = getch()-48;
							else{// 第160行
								printf("\n玩家");
								if(select[1]==3) printf(" %d",player);
								printf(", 請在方陣裡選擇一個數字 "
									"哪個地方是你想要打 %c: ",
									(player == 1)?'X':'O');
								tens = getche() - 48;
								choice = tens*10 + getche() - 48;
							}
						}while((choice<(select[0]*10-9) || choice>(select[0]*46-37) || (select[0]==2 && (choice%10==0 || choice%10>5))
							  || board[choice-1]!=0) && choice!=0);// 第170行
					}
					else{
		 				// 計算機選擇的因素
	 					printf("\nloading...");
						do{
							choice = 0;
							for(j=(select[0]-1)*10;j<(9+(select[0]-1)*46);j++){
								if(j>9 && j%10>4)
								j=(j/10+1)*10;
								for(k=0;k<select[0]*2;k++){// 第180行
									row[k]=j+k+1;
									if(row[k]/(1+select[0]*2) > j/(1+select[0]*2))
									row[k]-=(1+select[0]*2);
									column[k]=k*(select[0]*7-4)+j+(select[0]*7-4);
									if(column[k]>=(9+(select[0]-1)*46))
									column[k]-=(9+(select[0]-1)*41);
									obliqueLeft[k]=k*(select[0]*7-3)+j+(select[0]*7-3);
									if(obliqueLeft[k]>=(12+(select[0]-1)*43))
									obliqueLeft[k]-=(12+(select[0]-1)*43);
									obliqueRight[k]=k*(select[0]*7-5)+j+(select[0]*7-5);// 第190行
									if(obliqueRight[k]>=(8+(select[0]-1)*47))
									obliqueRight[k]-=obliqueRight[k]/(6+(select[0]-1)*49)*(6+(select[0]-1)*39);
								}
								if(((board[row[0]]==board[row[1]] && board[row[0]]==board[row[select[0]]]
								  && board[row[0]]==board[row[select[0]*2-1]] && board[row[0]]!=0)
								 || (board[column[0]]==board[column[1]] && board[column[0]]==board[column[select[0]]]
								  && board[column[0]]==board[column[select[0]*2-1]] && board[column[0]]!=0))
								  && board[j]==0){
								 	choice=j+1;
								 	break;// 第200行
								}
								if((j+(select[0]-1))%(select[0]*7-3)==0){
									if((board[obliqueLeft[0]]==board[obliqueLeft[1]] && board[obliqueLeft[0]]==board[obliqueLeft[select[0]]]
									 && board[obliqueLeft[0]]==board[obliqueLeft[select[0]*2-1]] && board[obliqueLeft[0]]!=0)
									 && board[j]==0){
									 	choice=j+1;
									 	break;
									}
								}
								if((j-(select[0]-1)*5)%(select[0]*7-5)==0 && j>0 && (j<=6 || j>9)){//第210行
									if((board[obliqueRight[0]]==board[obliqueRight[1]] && board[obliqueRight[0]]==board[obliqueRight[select[0]]]
									 && board[obliqueRight[0]]==board[obliqueRight[select[0]*2-1]] && board[obliqueRight[0]]!=0)
									 && board[j]==0){
									 	choice=j+1;
									 	break;
									}
								}
							}
							if(choice==0){
								if(i<(select[0]*16-8+a)){// 第220行
									if(select[1]==2){
										if(select[0]==1){
											for(k=0;k<200;k++){
												srand(time(NULL));
							 					random = rand()%5;
												if(board[random*2]==0){
													choice = random*2+1;
													break;
												}
											}// 第230行
										}
										else{
											for(j=10;j<55;j++){
												if(j%10>4)
												j=(j/10+1)*10;
												for(k=0;k<4;k++){
													row[k]=j+k+1;
													if(row[k]/5 > j/5)
													row[k]-=5;
													column[k]=k*10+j+10;// 第240行
													if(column[k]>=55)
													column[k]-=50;
												}
												srand(time(NULL));
												dif_random = rand()%3;
												if(((board[row[dif_random]]==board[row[dif_random+1]] && board[row[dif_random]]!=0)
												 || (board[column[dif_random]]==board[column[dif_random+1]] && board[column[dif_random]]!=0))
												  && board[j]==0){
												 	choice=j+1;
												 	break;// 第250行
												}
											}
										}
									}
									if(choice==0){
										for(k=0;(k<2500 && select[0]==2) || (k<(16+((select[1]%2)*884)) && select[0]==1);k++){
											srand(time(NULL));
											if(select[0]==2){
							 					random=rand()%25;
							 					if(board[(random/5+1)*10+random%5]==0){// 第260行
								 					choice = (random/5+1)*10+random%5+1;
							 						break;
												}
											}
											else{
												random = rand()%(4+((select[1]%2)*5))+select[1]-1;
												if(board[random*select[1]-select[1]+1]==0){
													choice = random*select[1]+(select[1]%2);
													break;
												}// 第270行
											}
										}
									}
								}
								else{
									for(j=(select[0]*10-10);j<(select[0]*46-37);j++){
										if(j>9 && j%10>4)
										j=(j/10+1)*10;
										if(board[j]==0){
											choice = j+1;// 第280行
											break;
										}
									}
								}
							}
						}while(choice<(select[0]*10-9) || choice>(select[0]*46-37) || (select[0]==2 && (choice%10==0 || choice%10>5)) || board[choice-1]!=0);
					}
					//插入玩家標誌 
					if(choice==0){
						for(j=0;j<55;j++) board[j] = 0;// 第290行
						b = 0;
						break;
					}
					board[choice-1] = player ;
					//檢查獲勝線 - 首先是對角線
					if((board[select[0]*10-10]==board[select[0]*17-13] && board[select[0]*10-10]==board[select[0]*24-16]
					 && board[select[0]*10-10]==board[select[0]*39-35] && board[select[0]*10-10]==board[select[0]*46-38]
					 && board[select[0]*10-10]!=0)
					|| (board[select[0]*12-10]==board[select[0]*19-15] && board[select[0]*12-10]==board[select[0]*26-20]
					 && board[select[0]*12-10]==board[select[0]*37-33] && board[select[0]*12-10]==board[select[0]*44-38]// 第300行
					 && board[select[0]*12-10]!=0)){
					 	winner = player;
					}	
					else
						//檢查行和列是否有獲勝行
						for(line = 0;line <= 4;line++)
							if((board[line+(select[0]*10-10)]==board[line+(select[0]*17-14)] &&
								board[line+(select[0]*10-10)]==board[line+(select[0]*27-24)] &&
								board[line+(select[0]*10-10)]==board[line+(select[0]*34-28)] &&
								board[line+(select[0]*10-10)]==board[line+(select[0]*44-38)] &&// 第310行
								board[line+(select[0]*10-10)]!=0) ||
								(board[(line+select[0]-1)*(select[0]*7-4)]==board[(line+select[0]-1)*(select[0]*7-4)+1] &&
								board[(line+select[0]-1)*(select[0]*7-4)]==board[(line+select[0]-1)*(select[0]*7-4)+2] &&
								board[(line+select[0]-1)*(select[0]*7-4)]==board[(line+select[0]-1)*(select[0]*7-4)+(select[0]*2-1)] &&
								board[(line+select[0]-1)*(select[0]*7-4)]==board[(line+select[0]-1)*(select[0]*7-4)+(select[0]*2)] &&
								board[(line+select[0]-1)*(select[0]*7-4)]!=0)){
									winner = player;
								}
					if(winner==player) i=11+16*(select[0]-1);
					else i++;//第320行
				}
			}
		}
		else{
			a=0;
			system("cls");
			printf("\n\n        簡單的井字遊戲\n");
			if(b==0){
				for(k=0;k<2;k++){
					if(k<1){// 第330行
						printf("\n\n        遊戲類型:\n");
						printf("\n\n        3 X 3 模式 (1)\n");
						printf("\n\n        5 X 5 模式 (2)\n");
						printf("\n\n        退出遊戲   (0)\n");
					}
					else printf("\n      再次按（0）退出.\n");
					do{
						select[0] = getch()-48;
					}while(select[0]<0 || select[0]>2);
					if(k<1 && select[0]!=0)break;//第340行
				}
				if(select[0]==0)break;
				else b++;
			}
			else{
				printf("\n\n        遊戲難易度選擇:\n");
				printf("\n\n        簡單模式   (1)\n");
				printf("\n\n        困難模式   (2)\n");
				printf("\n\n        雙人遊玩   (3)\n");
				printf("\n\n        返回主頁   (0)\n");// 第350行
				do{
					select[1] = getch()-48;
				}while(select[1]<0 || select[1]>3);
				if(select[1]==0)b--;
				else b++;
			}
		}
	}
	return 0;
}// 第360行


