/*
ASSIGNMENT 8:
Problem Statement: Write a program in C to add two polynomials using linked list.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* createNode(int coeff, int exp){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertTerm(struct Node* head, int coeff, int exp){
    if (coeff == 0) return head;
    
    struct Node* newNode = createNode(coeff, exp);
    
    if (head == NULL || head->exp < exp){
        newNode->next = head;
        return newNode;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->exp > exp){
        temp = temp->next;
    }
    
    if (temp->exp == exp){
        temp->coeff += coeff;
        free(newNode);
        return head;
    } else if (temp->next != NULL && temp->next->exp == exp){
        temp->next->coeff += coeff;
        free(newNode);
        return head;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void display(struct Node* head){
    if (head == NULL){
        printf("0\n");
        return;
    }
    
    int first = 1;
    while (head != NULL){
        if (head->coeff != 0){
            if (!first && head->coeff > 0) printf(" + ");
            else if (head->coeff < 0) printf(" - ");
            
            int c = first ? head->coeff : abs(head->coeff);
            if (head->exp == 0) printf("%d", c);
            else if (head->exp == 1){
                if (abs(head->coeff) == 1) printf("x");
                else printf("%dx", c);
            } else {
                if (abs(head->coeff) == 1) printf("x^%d", head->exp);
                else printf("%dx^%d", c, head->exp);
            }
            first = 0;
        }
        head = head->next;
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* p1, struct Node* p2){
    struct Node* result = NULL;
    
    while (p1 != NULL && p2 != NULL){
        if (p1->exp > p2->exp){
            result = insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp){
            result = insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0) result = insertTerm(result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    while (p1 != NULL){
        result = insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    
    while (p2 != NULL){
        result = insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    
    return result;
}

struct Node* readPolynomial(){
    struct Node* head = NULL;
    int n, coeff, exp;
    
    printf("Enter number of terms: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++){
        printf("Term %d - Coefficient: ", i + 1);
        scanf("%d", &coeff);
        printf("Term %d - Exponent: ", i + 1);
        scanf("%d", &exp);
        head = insertTerm(head, coeff, exp);
    }
    
    return head;
}

void freePoly(struct Node* head){
    struct Node* temp;
    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    struct Node *p1 = NULL, *p2 = NULL, *result = NULL;
    
    printf("\nFirst Polynomial:\n");
    p1 = readPolynomial();
    
    printf("\nSecond Polynomial:\n");
    p2 = readPolynomial();
    
    printf("\nPolynomial 1: ");
    display(p1);
    
    printf("Polynomial 2: ");
    display(p2);
    
    result = addPolynomials(p1, p2);
    
    printf("\nSum: ");
    display(result);
    
    freePoly(p1);
    freePoly(p2);
    freePoly(result);
    
    return 0;
}
