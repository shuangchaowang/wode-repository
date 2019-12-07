#include<ctype.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"lcs.h"

void lcs(int m,int n,char sq1[], char sq2[],bool b,char*output){
	int fill_list[m+1][n+1];
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
    printf("%d\n",pos);
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
    if(b){
        FILE *fp = fopen(output,"w");
        fprintf(fp,"# an LCS (length = %d) is:\n%s\n",lcs_len,lcs);
        fclose(fp);
    }
    else{
	    printf("# an LCS (length = %d) is:\n%s\n",lcs_len,lcs);
    }


}
