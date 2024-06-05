#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void) {
  int a, b, c;
  int l = 0;

  // 字符串陣列來存儲時間值
  const char* dailytime[13] = {"9", "10", "11", "12", "13", "14", "15",
                               "16", "17", "18", "19", "20", "21"};

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
          printf("您的資料如下\n");
          printf("大名:%s\n", n);
          printf("電話號碼:%s\n", tell);
          printf("定位日期:%s\n", date);
          printf("定位時間:%s點\n", time);
        } else {
          strcpy(phone[l], tell);
          strcpy(name[l], n);
          l++;
          printf("請輸入日期:");
          scanf("%s", date);
          printf("請輸入時間:");
          scanf("%s", time);

          int found2 = 0;
          for (int j = 0; j < 1000; j++) {
            if (strcmp(time, clock[j]) == 0 && strcmp(date, datetime[j]) == 0) {
              found2 = 1;
              break;
            }
          }

          if (found2) {
            printf("已滿位\n");
            printf("以下是合理的時間\n");
            for (int k = 0; k < 13; k++) {
              printf("時間:%s\n", dailytime[k]);
            }
          } else {
            strcpy(datetime[l-1], date);
            strcpy(clock[l-1], time);
            printf("已新增定位\n");
          }
        }
        break;
      }

      case 2: {
        printf("請輸入名字:");
        scanf("%s", n);
        printf("請輸入電話號碼:");
        scanf("%s", tell);

        int found3 = 0;
        int p = -1; // 用於保存匹配的索引
        for (int i = 0; i < 1000; i++) {
          if (strcmp(phone[i], tell) == 0 && strcmp(name[i], n) == 0) {
            found3 = 1;
            p = i;
            break;
          }
        }

        if (found3) {
          printf("請問你要修改日期嗎? (1是/0否)\n");
          scanf("%d", &b);
          if (b == 1) {
            printf("請輸入新日期:");
            scanf("%s", date);
          }

          printf("請輸入新時間:");
          scanf("%s", time);

          int found4 = 0;
          for (int m = 0; m < 1000; m++) {
            if (strcmp(time, clock[m]) == 0 && strcmp(date, datetime[m]) == 0) {
              found4 = 1;
              break;
            }
          }

          if (found4) {
            printf("已滿位\n");
            printf("以下是合理的時間\n");
            for (int k = 0; k < 13; k++) {
              printf("時間:%s\n", dailytime[k]);
            }
          } else {
            if (b == 1) {
              strcpy(datetime[p], date); // 修改日期
            }
            strcpy(clock[p], time); // 修改時間
            printf("已修改\n");
          }
        } else {
          printf("未找到匹配的記錄\n");
        }
        break;
      }

      case 3: {
        printf("請輸入名字:");
        scanf("%s", n);
        printf("請輸入電話號碼:");
        scanf("%s", tell);

        int found5 = 0;
        for (int q = 0; q < 1000; q++) {
          if (strcmp(phone[q], tell) == 0 && strcmp(name[q], n) == 0) {
            found5 = 1;
            for (int r = q; r < 999; r++) {
              strcpy(name[r], name[r + 1]);
              strcpy(phone[r], phone[r + 1]);
              strcpy(datetime[r], datetime[r + 1]);
              strcpy(clock[r], clock[r + 1]);
            }
            l--;
            break;
          }
        }

        if (found5) {
          printf("已取消\n");
        } else {
          printf("未找到匹配的記錄\n");
        }
        break;
      }

      case 4: {
        printf("請輸入電話號碼:");
        scanf("%s", tell);

        int found6 = 0;
        for (int s = 0; s < 1000; s++) {
          if (strcmp(phone[s], tell) == 0) {
            found6 = 1;
            printf("大名:%s\n", name[s]);
            printf("電話號碼:%s\n", phone[s]);
            printf("定位日期:%s\n", datetime[s]);
            printf("定位時間:%s點\n", clock[s]);
            break;
          }
        }

        if (!found6) {
          printf("未找到匹配的記錄\n");
        }
        break;
      }

      default: {
        printf("無效的選項\n");
        break;
      }
    }
  }

  return 0;
}
