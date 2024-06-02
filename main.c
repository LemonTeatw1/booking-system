#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void) {
  int a, b, c;
  int l = 0;

  char dailytime[13] = {'9', '10', '11', '12', '13', '14', '15',
                       '16', '17', '18', '19', '20', '21'};

  char tell[1000], n[1000], date[1000], time[1000];
  char name[1000][1000], phone[1000][1000], datetime[1000][1000],
      clock[1000][1000];

  while (1) {
    printf("\033[1;34m.w.定位系統\n");
    printf("\033[1;34m======使用資訊======\n");
    printf("\033[1;34m1.新增訂位資料\n");
    printf("\033[1;34m2.變更訂位資料\n");
    printf("\033[1;34m3.取消訂位資料\n");
    printf("\033[1;34m4.查詢訂位資料\n");
    printf("\033[0m====================\n");

    // 輸入功能
    printf("\033[1;34m請輸入你要的功能.w.\n");
    scanf("%d", &a);

    switch (a) // 輸入資料
    {
      case 1: {
        printf("請輸入您的大名!!:");
        scanf("%s", n);
        printf("請輸入電話號碼:");
        scanf("%s", tell);

        // 檢查是否定位
        int found = 0;
        for (int i = 0; i < 1000; i++) {
          if (strcmp(tell, phone[i]) == 0) {
            found = 1;
            break;
          }
        }

        if (found) {
          printf("已有定位\n");
          printf("您的資料如下");
          printf("大名:%s\n", n);
          printf("電話號碼:%s\n", tell);
          printf("定位日期:%s\n", date);
          printf("定位時間:%s點\n", time);
        } else {
          strcpy(phone[l], tell);
          strcpy(name[l], n);
          l = l + 1;
          printf("請輸入日期:");
          scanf("%s", date);
          printf("請輸入時間:");
          scanf("%s", time);

          int found2 = 0;
          for (int j = 0; j < 20; j++) {
            if (strcmp(dailytime, datetime[j]) == 0 && strcmp(n, name[j]) == 0) {
              found2 = 1;
              break;
            }
            if (found2) {
              printf("已滿位\n");
              printf("以下是合理的時間\n");
              for (found2 = 1; found2 < 20; found2++) {
                printf("時間:%s\n", time);
              }
            } else {
              for (int k = 0; k < 1000; k++) {
                strcpy(datetime[k], date);
                strcpy(clock[k], time);
              }
            }
          }
        }
        break;
      }
      case 2: {
        printf("請輸入名字:");
        scanf("%s",n);
        printf("請輸入電話號碼:");
        scanf("%s",tell);

        int found3 = 0;
        for (int p = 0; p < 1000; p++) {
          if (strcmp(phone[p], tell) == 0 && strcmp(name[p], n) == 0) {
            found3 = 1;
            break;
          }
          if(found3){
            printf("請問你要修改日期嗎?\n");
            scanf("%d",&b);
            if(b == 1){
              printf("請輸入新日期:");
              scanf("%s",date);
            }
            else if(b == 0){
              printf("不用輸入");
              }
            
              printf("你要修改的時間為何?");
              printf("請輸入新時間:");
              scanf("%s",time);
              int found4 = 0;
              for (int m = 0; m < 20; m++) {
                if (strcmp(dailytime, datetime[m]) == 0 && strcmp(n, name[m]) == 0) 
                  found4 = 1;
                  break;
                }
                if (found4) {
                  printf("已滿位\n");
                  printf("以下是合理的時間\n");
                  for (found4 = 1; found4 < 20; found4++) {
                    printf("時間:%s\n", time);
                  }
                } else {
                  for (int k = 0; k < 1000; k++) {
                    strcpy(datetime[k], date);
                    strcpy(clock[k], time);
                  }
                }
                strcpy(clock[p], time);
                printf("已修改\n");
              
            }
          }

        case 3:{
        }
      }
    }
  }
  return 0; 
 }
