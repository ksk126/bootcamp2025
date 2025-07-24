/*
* 작성자: 김수경
* 파일명: assignment10
* 작성일: 2025.07.24
* 내용: product 구조체 배열을 이용해서 제품명을 입력받아 검색 후 주문 처리하는 프로그램을 작성하시오.
* 주문 수량을 입력받아 결제 금액을 알려주고, 제품 재고를 주문 수량만큼 감소시켜야한다.
* 제품명으로 검색할수 없거나 찾은 제품의 재고가 주문 수량보다 적으면 에러 메세지를 출력한다.
* product 구조체 배열은 크기가 5인 배열로 선언하고 적당한 값으로 초기화해서 사용한다.
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
        {"아메리카노", 4000, 5},
        {"카페라떼",     4500,  7},
        {"플랫화이트",   5000, 10},
        {"에스프레소",   2500,  3},
        {"아이스티",     2000,  8}
    };

    char    input[NAME_LEN];
    int     qty, total;
    Product* p;

    while (1) {
        printf("주문할 제품명? ");
        scanf(" %49s", input);

        if (strcmp(input, ".") == 0)
            break;

        p = FindProduct(input, items, MAX_PRODUCTS);
        if (p == NULL) {
            printf("%s 제품이 존재하지 않습니다.\n\n", input);
            continue;
        }

        printf("주문 수량: ");
        scanf("%d", &qty);

        total = ProcessOrder(p, qty);
        if (total == 0)
        {
            printf("재고가 부족합니다. (재고: %d개)\n\n", p->stock);
        }
        else
        {
            printf("결제 금액: %d원 / 제품명: %s / 재고: %d개\n\n",
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
    printf("\n=== 최종 재고 ===\n");
    for (int i = 0; i < size; i++) {
        printf("[%s %d원 재고:%d개]\n",
            items[i].name,
            items[i].price,
            items[i].stock);
    }
}