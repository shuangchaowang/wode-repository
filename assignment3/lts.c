#include<ctype.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"lts.h"

void lcs2(int m,int n,char sq1[], char sq2[],char *ltsptr){
	//int fill_list[m+1][n+1];
	int **fill_list;
	fill_list = (int**)malloc(sizeof(int*)*(m+1));
	for(int z=0;z<m+1;z++){
		fill_list[z] = (int*)malloc(sizeof(int)*(n+1));
	}
	int i,j;
	// fill the 2d list following the rule of lcs
	for (i=0; i<=m; i++){
     		for (j=0; j<=n; j++){
       			if (i == 0 || j == 0){//set first row and colunm all zeros
         			fill_list[i][j] = 0;
			}
       			else if (sq1[i-1] == sq2[j-1]){//plus one when finding a common character
         			fill_list[i][j] = fill_list[i-1][j-1] + 1;
			}
       			else{
         			if(fill_list[i-1][j] > fill_list[i][j-1]){
					fill_list[i][j] = fill_list[i-1][j];
				}
				else{
					fill_list[i][j] = fill_list[i][j-1];

				}
			}
		}
	}

	int pos = fill_list[m][n];//start from the right_bottom index, which is the last index of fill_list
	//largest value is set as the length of lcs
	char lcs[pos+1];
	lcs[pos] = '\0';

	// start from the bottom pick up the common characters from the path
	while(m && n){
        	if(sq1[m-1] == sq2[n-1]){
                	lcs[pos-1]= sq1[m-1];
                        m--;
			n--;
			pos--;
                }
                else if(fill_list[m-1][n] >fill_list[m][n-1] ){
			m--;
		}
		else{
			n--;
		}
        }
	int lcs_len = strlen(lcs);
	//printf("# an LCS (length = %d) is:%s\n",lcs_len,lcs);
	//return lcs;
	for(int i=0;i<lcs_len;i++){
		*(ltsptr +i) = lcs[i];
	}
	for(int i=0;i<m+1;i++){
		int* cptr = fill_list[i];
		free(cptr); 
	}


}

void lts(int fl, char sq1[],bool b,char*output){
    //int fl = 7;
    //char sq1[] = "123125";
	//printf("in lts");
	char l_half[fl];
	char r_half[fl];
	char lts[fl];
	int max_len = 0;
	char max_lts[fl];
	int length;
	char * ltsptr = lts; 

	for(int i =1;i<fl;i++){
		if (strlen(sq1) < 2){
			//char dummy[2] = "\0";
			lts[0] = '\0';
		}
		else{
			for(int j = 0;j<i;j++){
				l_half[j] = sq1[j];
				l_half[j+1] = '\0';
			}
			//printf("l_half is:%s\n",l_half);
			int a =0;
			for(int j = i;j<fl;j++){
				r_half[a] = sq1[j];
				r_half[a + 1] = '\0';
				a++;
			}
			//printf("r_half is:%s\n",r_half);
			int llen = strlen(l_half);
			int rlen = strlen(r_half);
			lcs2(llen,rlen,l_half,r_half,ltsptr);
			length = strlen(lts);
			//printf(" lts lenth is:%d\n",length);
			//printf("%s\n",lts);
			if(length > max_len){
				max_len = length;
				strcpy(max_lts,lts);
			}


		}
	}
	if(b){
		FILE *fp = fopen(output,"w");
        fprintf(fp,"# an LTS (length = %d) for the first sequence is:\n%s%s\n",(max_len-1) * 2,max_lts,max_lts);
        fclose(fp);
	}
	else{
		printf("# an LTS (length = %d) for the first sequence is:\n%s%s\n",(max_len-1) * 2,max_lts,max_lts);
	}
}

