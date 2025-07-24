/*
* �ۼ���: �����
* ���ϸ�: assignment10
* �ۼ���: 2025.07.24
* ����: product ����ü �迭�� �̿��ؼ� ��ǰ���� �Է¹޾� �˻� �� �ֹ� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
* �ֹ� ������ �Է¹޾� ���� �ݾ��� �˷��ְ�, ��ǰ ��� �ֹ� ������ŭ ���ҽ��Ѿ��Ѵ�.
* ��ǰ������ �˻��Ҽ� ���ų� ã�� ��ǰ�� ��� �ֹ� �������� ������ ���� �޼����� ����Ѵ�.
* product ����ü �迭�� ũ�Ⱑ 5�� �迭�� �����ϰ� ������ ������ �ʱ�ȭ�ؼ� ����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define NAME_LEN     50

typedef struct {
    char name[NAME_LEN];
    int  price;
    int  stock;
} Product;

void    RunOrderSystem(void);
Product* FindProduct(const char* name, Product items[], int size);
int     ProcessOrder(Product* p, int quantity);
void    PrintFinalStocks(const Product items[], int size);

int main(void)
{
    RunOrderSystem();
    return 0;
}

void RunOrderSystem(void)
{
    Product items[MAX_PRODUCTS] = {
        {"�Ƹ޸�ī��", 4000, 5},
        {"ī���",     4500,  7},
        {"�÷�ȭ��Ʈ",   5000, 10},
        {"����������",   2500,  3},
        {"���̽�Ƽ",     2000,  8}
    };

    char    input[NAME_LEN];
    int     qty, total;
    Product* p;

    while (1) {
        printf("�ֹ��� ��ǰ��? ");
        scanf(" %49s", input);

        if (strcmp(input, ".") == 0)
            break;

        p = FindProduct(input, items, MAX_PRODUCTS);
        if (p == NULL) {
            printf("%s ��ǰ�� �������� �ʽ��ϴ�.\n\n", input);
            continue;
        }

        printf("�ֹ� ����: ");
        scanf("%d", &qty);

        total = ProcessOrder(p, qty);
        if (total == 0)
        {
            printf("��� �����մϴ�. (���: %d��)\n\n", p->stock);
        }
        else
        {
            printf("���� �ݾ�: %d�� / ��ǰ��: %s / ���: %d��\n\n",
                total, p->name, p->stock);
        }
    }

    PrintFinalStocks(items, MAX_PRODUCTS);
}

Product* FindProduct(const char* name, Product items[], int size)
{
    for (int i = 0; i < size; i++) {
        if (strcmp(items[i].name, name) == 0)
            return &items[i];
    }
    return NULL;
}

int ProcessOrder(Product* p, int quantity)
{
    if (quantity <= 0 || p->stock < quantity)
        return 0;

    p->stock -= quantity;
    return quantity * p->price;
}

void PrintFinalStocks(const Product items[], int size)
{
    printf("\n=== ���� ��� ===\n");
    for (int i = 0; i < size; i++) {
        printf("[%s %d�� ���:%d��]\n",
            items[i].name,
            items[i].price,
            items[i].stock);
    }
}