#include<ctype.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"lcps.h"

#define max(x,y) (((x) > (y)) ? (x) : (y))
void lcps(int m,int n,int o,int p,char sq1[],char sq2[],char sq3[],char sq4[],bool b,char*output){
//int main(){
    //int m,n,o,p;
    int i,j,k,l;
    /*char sq1[] = "12324";
    char sq2[] = "21324";
    char sq3[] = "42321";
    char sq4[] = "42312";
    m = strlen(sq1);
    n = strlen(sq2);
    o = strlen(sq3);
    p = strlen(sq4);*/
    //int fill_list[m+1][n+1][o+1][p+1];
    int ****fill_list;
    fill_list = (int****)malloc(sizeof(int*)*(m+1));
    for(int i=0;i<m+1;i++){
        fill_list[i] = (int***)malloc(sizeof(int*)*(n+1));
        for(int j=0;j<n+1;j++){
            fill_list[i][j] = (int**)malloc(sizeof(int*)*(o+1));
            for(int k=0;k<m+1;k++){
                fill_list[i][j][k] = (int*)malloc(sizeof(int*)*(p+1));
            }
        }
    }

    for (i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            for(k=0;k<=o;k++){
                for(l=0;l<=p;l++){
                    if(i==0 || j==0 || k==0 || l==0){
                        fill_list[i][j][k][l] = 0;
                    }
                    else if(sq1[i-1] == sq2[j-1] && sq1[i-1] == sq3[k-1] && sq1[i-1] == sq4[l-1]){
                        //printf("%d %d %d %d: %d\n", i, j, k, l, fill_list[i-1][j-1][k-1][l-1]);
                        fill_list[i][j][k][l] = fill_list[i-1][j-1][k-1][l-1] + 1;
                        //count++;

                    }
                    else{
                        fill_list[i][j][k][l] = max(max(max(fill_list[i-1][j][k][l],fill_list[i][j-1][k][l]),fill_list[i][j][k-1][l]),fill_list[i][j][k][l-1]);
                    }
                    
                }
            }
        }
    }
    int pos = fill_list[m][n][o][p];
    //printf("%d\n",pos);
    char lcs[pos+1];
    int lcs_len;
    lcs[pos] = '\0';


    while(m>0 && n>0 && o>0 && p>0){
        if(sq1[m-1] == sq2[n-1] && sq1[m-1] == sq3[o-1] && sq1[m-1] == sq4[p-1]){
            lcs[pos-1] = sq1[m-1];
            m--;
            n--;
            o--;
            p--;
            pos--;        
        }
        else if(fill_list[m-1][n][o][p] >= fill_list[m][n-1][o][p] && fill_list[m-1][n][o][p] >= fill_list[m][n][o-1][p] && fill_list[m-1][n][o][p] >= fill_list[m][n][o][p-1]){
            m--;
        }
        else if(fill_list[m][n-1][o][p] >= fill_list[m-1][n][o][p] && fill_list[m][n-1][o][p] >= fill_list[m][n][o-1][p] && fill_list[m][n-1][o][p] >= fill_list[m][n][o][p-1]){
            n--;
        }
        else if(fill_list[m][n][o-1][p] >= fill_list[m-1][n][o][p] && fill_list[m][n][o-1][p] >= fill_list[m][n-1][o][p] && fill_list[m][n][o-1][p] >= fill_list[m][n][o][p-1]){
            o--;
        }
        else if(fill_list[m][n][o][p-1] >= fill_list[m-1][n][o][p] && fill_list[m][n][o][p-1] >= fill_list[m][n-1][o][p] && fill_list[m][n][o][p-1] >= fill_list[m][n][o-1][p]){
            p--;
        }
        lcs_len = strlen(lcs);
        
    }
    if(b){
        FILE *fp = fopen(output,"w");
        fprintf(fp,"#an lcps with (length = %d)is:\n%s\n", lcs_len, lcs);
        fclose(fp);
    }
    printf("#an lcps with (length = %d)is:\n%s\n", lcs_len, lcs);
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            for(int k=0;k<o+1;k++){
                free(fill_list[i][j][k]);
            }
            free(fill_list[i][j]);
        }
        free(fill_list[i]);
    }
    free(fill_list);
}
