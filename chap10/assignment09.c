/*
* 작성자: 김수경
* 파일명: assignment09
* 작성일: 2025.07.24
* 내용: PRODUCT 구조체를 매개변수로 전달받아 주문 처리를 하는 order 함수를 정의하시오.
* order 함수는 PRODUCT 구조체와 주문 수량을 매개변수로 전달받는 함수이다.
* 재고가 주문 수량보다 적으면 주문할 수 없으므로 0을 리턴하고,
* 재고가 주문 수량보다 많으면 주문 수량만큼 재고를 감소시키고 결제 금액을 리턴한다.
* 주문 수량으로 0이 입력될때까지 반복해서 주문 처리를 하는 프로그램을 작성하시오
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    char name[50];
    int price;
    int stock;
} PRODUCT;