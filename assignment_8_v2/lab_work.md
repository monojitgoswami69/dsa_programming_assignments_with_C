<h1 align="center">ASSIGNMENT - 8 (V2): Polynomial Addition using Linked Lists</h1>

---

### Problem Statement
Write a program in C to add two polynomials using linked list.


### Algorithm

1. START
2. Define `struct Node` with:
   - `int coeff` (coefficient)
   - `int exp` (exponent)
   - `struct Node *next` (pointer to next node)
3. For each polynomial:
   - Accept number of terms n
   - For each term, read coefficient and exponent
   - Insert each term in descending order of exponents using insertTerm
4. For **insertTerm(head, coeff, exp)**:
   - If coefficient is 0, do not insert
   - Create new node with `malloc()`
   - If list is empty or new term has highest exponent, insert at beginning
   - If a node with same exponent exists, add coefficients
   - Else, insert at correct position to maintain order
5. For **addPolynomials(p1, p2)**:
   - Initialize result = NULL
   - While both p1 and p2 are not NULL:
     - If p1->exp > p2->exp, insert p1 term into result, move p1
     - If p1->exp < p2->exp, insert p2 term into result, move p2
     - If exponents equal, add coefficients, insert sum if not zero, move both
   - Insert any remaining terms from p1 or p2 into result
6. For **display(head)**:
   - If head is NULL, print 0
   - Else, traverse and print each term in standard polynomial format
7. Free all nodes before exit
8. STOP


### Source Code

```c
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
```


### Sample Output

```
First Polynomial:
Enter number of terms: 4
Term 1 - Coefficient: 5
Term 1 - Exponent: 3
Term 2 - Coefficient: 4
Term 2 - Exponent: 2
Term 3 - Coefficient: -3
Term 3 - Exponent: 1
Term 4 - Coefficient: 7
Term 4 - Exponent: 0

Second Polynomial:
Enter number of terms: 4
Term 1 - Coefficient: 3
Term 1 - Exponent: 3
Term 2 - Coefficient: -4
Term 2 - Exponent: 2
Term 3 - Coefficient: 5
Term 3 - Exponent: 1
Term 4 - Coefficient: 2
Term 4 - Exponent: 0

Polynomial 1: 5x^3 + 4x^2 - 3x + 7
Polynomial 2: 3x^3 - 4x^2 + 5x + 2

Sum: 8x^3 + 2x + 9
```

