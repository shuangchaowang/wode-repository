#include<ctype.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"lps.h"

void lps(int sl, char sq2[],bool d,char*output){
    //int sl = 6;
    //char sq2[] = "12213";
    int n = sl;
    int i,j,cl;
    int l[n][n];
    //printf("n is:%d\n",n);
    //printf("str is:%s\n",sq2);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            l[i][j] = 0;
            if(i == j){
                l[i][j] = 1;
            }
            //printf("%d ",l[i][j]);
        }
        //printf("\n");
    }
    for(cl=2;cl<=n;cl++){
        for(i=0;i<n-cl+1;i++){
            j=i+cl-1;
            if(sq2[i] == sq2[j] && cl == 2){
                l[i][j] = 2;
            }
            else if (sq2[i] == sq2[j]){
                l[i][j] = l[i + 1][j - 1] + 2;
            }
            else{
                //l[i][j] = max(l[i][j-1],l[i+1][j]);
                if(l[i][j-1] > l[i+1][j]){
                    l[i][j] = l[i][j-1];
                    //printf("%d\n",l[i][j]);
                }

                else{
                    l[i][j] = l[i+1][j];
                    //printf("%d\n",l[i][j]);
                }
            }
        }
    }
    int a = 0;
    int m = n-1;
    int rmb = l[a][m];
    //int pos = l[a][m];
    //char lps[m + 1];
    char *lps;
    lps = malloc(sizeof(char)*(m+1));
    while(l[a][m] >= 1){
        if(sq2[a] == sq2[m]){
            lps[a] = sq2[a];


            lps[a+1] = '\0';
            a++;
            m--;
        }
        else{
            if(l[a+1][m] > l[a][m-1]){
                a++;
            }
            else{
                m--;
            }
        }
    }
    int b;
    if((rmb % 2) == 0){
	b = rmb/2 - 1;
	int v = b + 1;
	for(int i=b;i>=0;i--){
            lps[v] = lps[i];
            lps[v+1] = '\0';
            v++;
        }
    }

    else{
	b = rmb/2 ;
	int v =b + 1;
	for(int i=b-1;i>=0;i--){
            lps[v] = lps[i];
            lps[v+1] = '\0';
            v++;
        }
    }
    if(d){
        FILE *fp = fopen(output,"w");
        fprintf(fp,"# an LPS (length = %d) for the second sequence is:\n%s\n",strlen(lps),lps);
        fclose(fp);
    }
    else{
        printf("# an LPS (length = %d) for the second sequence is:\n%s\n",strlen(lps),lps);
    }
    free(lps);
}