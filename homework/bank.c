#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_USERS 10
#define MAX_ACCOUNTS 10
#define ID_LEN 19
#define ACC_LEN 7

// 用户账户结构体
typedef struct {
    char id[ID_LEN];      // 身份证号
    char acc[ACC_LEN];    // 银行账号
    double balance;       // 余额
} Account;

// 账户列表结构体
typedef struct {
    Account accounts[MAX_ACCOUNTS];
    int count;
} AccountList;

// 从 master.txt 加载账户数据
void load_accounts(AccountList *list) {
    FILE *fp = fopen("master.txt", "r");
    if (!fp) {
        printf("无法打开文件 master.txt\n");
        exit(1);
    }
    list->count = 0;
    while (fscanf(fp, "%18s %6s %lf", list->accounts[list->count].id,
                  list->accounts[list->count].acc,
                  &list->accounts[list->count].balance) == 3) {
        list->count++;
        if (list->count >= MAX_ACCOUNTS) break;
    }
    fclose(fp);
}

// 将账户数据保存回 master.txt
void save_accounts(AccountList *list) {
    FILE *fp = fopen("master.txt", "w");
    if (!fp) {
        printf("无法写入文件 master.txt\n");
        exit(1);
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(fp, "%s %s %.2lf\n",
                list->accounts[i].id,
                list->accounts[i].acc,
                list->accounts[i].balance);
    }
    fclose(fp);
}

// 查询某用户所有账号余额
void query_user(AccountList *list, const char *id) {
    int found = 0;
    printf("身份证号：%s 的所有账号及余额：\n", id);
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->accounts[i].id, id) == 0) {
            printf("账号：%s  余额：%.2lf\n",
                   list->accounts[i].acc,
                   list->accounts[i].balance);
            found = 1;
        }
    }
    if (!found) printf("未找到该用户信息。\n");
}

// 处理结算业务，读取 yearmonthname.txt 文件并更新账户余额
void settle(AccountList *list, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("无法打开文件：%s\n", filename);
        return;
    }

    char month[10], id[ID_LEN], acc[ACC_LEN];
    char type;
    double amount;

    while (fscanf(fp, "%s %s %s %c %lf", month, id, acc, &type, &amount) == 5) {
        for (int i = 0; i < list->count; i++) {
            if (strcmp(list->accounts[i].id, id) == 0 &&
                strcmp(list->accounts[i].acc, acc) == 0) {
                if (type == 'L') {
                    if (amount > 0) {
                        list->accounts[i].balance += amount;
                        printf("存款成功：+%.2lf\n", amount);
                    } else {
                        printf("错误：存款金额必须大于0。\n");
                    }
                } else if (type == 'D') {
                    if (amount > 0 && amount <= list->accounts[i].balance) {
                        list->accounts[i].balance -= amount;
                        printf("取款成功：-%.2lf\n", amount);
                    } else if (amount > list->accounts[i].balance) {
                        printf("错误：取款金额超过余额！\n");
                    } else {
                        printf("错误：取款金额必须大于0。\n");
                    }
                }
            }
        }
    }

    fclose(fp);
    save_accounts(list);

    printf("\n结算完成，最新账户信息如下：\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s %s %.2lf\n",
               list->accounts[i].id,
               list->accounts[i].acc,
               list->accounts[i].balance);
    }
}

// 主程序入口
int main() {
    setlocale(LC_ALL, "zh_CN.UTF-8");

    AccountList list;
    load_accounts(&list);

    int choice;
    char id[ID_LEN], filename[100];

    while (1) {
        printf("\n银行综合储蓄业务系统\n");
        printf("1. 查询用户所有账号余额\n");
        printf("2. 业务结算\n");
        printf("3. 退出\n");
        printf("请选择: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("请输入身份证号（最多18位）: ");
            scanf("%18s", id);  // 防止缓冲区溢出
            query_user(&list, id);
        } else if (choice == 2) {
            printf("请输入结算文件名（如 yearmonthname.txt）: ");
            scanf("%99s", filename);  // 防止缓冲区溢出
            settle(&list, filename);
        } else if (choice == 3) {
            break;
        } else {
            printf("无效选择，请重试。\n");
        }
    }

    save_accounts(&list);
    return 0;
}
