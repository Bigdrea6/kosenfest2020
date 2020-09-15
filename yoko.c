#include <time.h>
#include <unistd.h>
#include <stdio.h>
char num_1[10][5]={".###","..#.",".###",".###",".#.#",".###",".###",".###",".###",".###"};
char num_2[10][5]={".#.#",".##.","...#","...#",".#.#",".#..",".#..","...#",".#.#",".#.#"};
char num_3[10][5]={".#.#","..#.",".###",".###",".###",".###",".###","...#",".###",".###"};
char num_4[10][5]={".#.#","..#.",".#..","...#","...#","...#",".#.#","...#",".#.#","...#"};
char num_5[10][5]={".###",".###",".###",".###","...#",".###",".###","...#",".###",".###"};
//                  0     1      2      3      4      5      6      7      8      9

char chr_1[2][3]={".#",".."};
char chr_2[2][3]={".#",".#"};
char chr_3[2][3]={".#",".."};
char chr_4[2][3]={".#",".#"};
char chr_5[2][3]={".#",".."};
//                 |    :

int n[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};

int number(int a,int num){  //数字を分ける関数
  while(num>0){
    n[13-a]=num%10;
    num=num/10;
    a++;
  }
}

int print(int a[13],char b[10][5],char c[2][3]){ //bitごとに表示するやつ
  for (int i=0;i<14;i++){
    printf("%s",b[a[i]]);
    if (i==3||i==5||i==7){
      printf("%s",c[0]);
    }else if (i==9||i==11){
      printf("%s",c[1]);
    }
  }printf("\n");
}

int main(){
  for(int i=0;i<60;i++){
    struct tm tm;
    time_t t=time(NULL);
    localtime_r(&t,&tm);
    printf("%04d/%02d/%02d %02d:%02d:%02d\n", tm.tm_year+1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    int year=tm.tm_year+1900;
    int mon=tm.tm_mon+1;
    int day=tm.tm_mday;
    int hour=tm.tm_hour;
    int min=tm.tm_min;
    int sec=tm.tm_sec;

    number(0,sec); number(2,min); number(4,hour); number(6,day); number(8,mon); number(10,year);
    print(n,num_1,chr_1); print(n,num_2,chr_2); print(n,num_3,chr_3); print(n,num_4,chr_4); print(n,num_5,chr_5);

    for (int a=0;a<14;a++){
      n[a]=0;
    }
    int delay=1;
    sleep(delay);
  }
  return 0;
}
