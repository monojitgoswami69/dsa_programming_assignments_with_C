<h1 align="center">ASSIGNMENT - 8 (V2): Polynomial Addition using Linked Lists</h1>

---

### Problem Statement
Write a program in C to add two polynomials using linked list.

### Algorithm

1. START
2. Define `struct Node` with:
   - `int coeff` (coefficient of term)
   - `int exp` (exponent of term)
   - `struct Node *next` (pointer to next term)
3. **Input Phase:**
   - For each polynomial:
     - Accept number of terms n
     - For each term i (1 to n):
       - Read coefficient and exponent
       - Insert term in sorted order (descending exponents)
4. **insertTerm(head, coeff, exp)**:
   - Skip if coefficient is 0
   - Create new node
   - **Case 1:** Empty list or highest exponent
     - Insert at beginning
   - **Case 2:** Same exponent exists
     - Add coefficients instead of creating new node
   - **Case 3:** Find correct position
     - Traverse to find insertion point
     - Insert maintaining descending order
5. **addPolynomials(p1, p2)**:
   - Initialize result = NULL
   - **While both p1 and p2 exist:**
     - **If p1->exp > p2->exp:**
       - Add p1 term to result
       - Move p1 forward
     - **Else if p1->exp < p2->exp:**
       - Add p2 term to result
       - Move p2 forward
     - **Else (p1->exp == p2->exp):**
       - Add (p1->coeff + p2->coeff) to result
       - Move both forward
   - **Add remaining terms** from p1 (if any)
   - **Add remaining terms** from p2 (if any)
   - Return result
6. **display(head)**:
   - Handle empty polynomial (print "0")
   - For each term:
     - Print sign (+ or -)
     - Print coefficient (handle special case: ±1)
     - Print variable and exponent:
       - exp=0: constant (no x)
       - exp=1: linear (x, not x^1)
       - exp>1: x^exp
7. **Memory Cleanup:**
   - Free all nodes from all three polynomials
8. STOP

**Time Complexity:**
- Insert term: O(n) worst case
- Add polynomials: O(m + n) where m, n are term counts
- Display: O(n)

**Space Complexity:** O(m + n) for result polynomial

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

**Step-by-step Addition Process:**

```
P1: [5,3] → [4,2] → [-3,1] → [7,0] → NULL
P2: [3,3] → [-4,2] → [5,1] → [2,0] → NULL

Step 1: Compare exp=3 with exp=3
        5 + 3 = 8
        Result: [8,3]

Step 2: Compare exp=2 with exp=2
        4 + (-4) = 0 (skip zero)
        Result: [8,3]

Step 3: Compare exp=1 with exp=1
        -3 + 5 = 2
        Result: [8,3] → [2,1]

Step 4: Compare exp=0 with exp=0
        7 + 2 = 9
        Result: [8,3] → [2,1] → [9,0]

Final: 8x³ + 2x + 9
```

**Another Example - Sparse Polynomials:**

```
First Polynomial:
Enter number of terms: 3
Term 1 - Coefficient: 5
Term 1 - Exponent: 100
Term 2 - Coefficient: 3
Term 2 - Exponent: 5
Term 3 - Coefficient: 1
Term 3 - Exponent: 0

Second Polynomial:
Enter number of terms: 3
Term 1 - Coefficient: 2
Term 1 - Exponent: 50
Term 2 - Coefficient: -3
Term 2 - Exponent: 5
Term 3 - Coefficient: 4
Term 3 - Exponent: 0

Polynomial 1: 5x^100 + 3x^5 + 1
Polynomial 2: 2x^50 - 3x^5 + 4

Sum: 5x^100 + 2x^50 + 5
```

**Example with Cancellation:**

```
First Polynomial:
Enter number of terms: 3
Term 1 - Coefficient: 5
Term 1 - Exponent: 2
Term 2 - Coefficient: 3
Term 2 - Exponent: 1
Term 3 - Coefficient: 2
Term 3 - Exponent: 0

Second Polynomial:
Enter number of terms: 3
Term 1 - Coefficient: -5
Term 1 - Exponent: 2
Term 2 - Coefficient: 4
Term 2 - Exponent: 1
Term 3 - Coefficient: -2
Term 3 - Exponent: 0

Polynomial 1: 5x^2 + 3x + 2
Polynomial 2: -5x^2 + 4x - 2

Sum: 7x

(Note: x² and constant terms cancelled out)
```

**Visual Representation of Data Structure:**

```
Polynomial: 5x³ + 4x² - 3x + 7

Linked List Representation:
head → [coeff:5, exp:3, next] → [coeff:4, exp:2, next] → [coeff:-3, exp:1, next] → [coeff:7, exp:0, next:NULL]

Memory Layout:
┌─────┬─────┬──────┐   ┌─────┬─────┬──────┐   ┌──────┬─────┬──────┐   ┌─────┬─────┬──────┐
│  5  │  3  │  •───┼──>│  4  │  2  │  •───┼──>│  -3  │  1  │  •───┼──>│  7  │  0  │ NULL │
└─────┴─────┴──────┘   └─────┴─────┴──────┘   └──────┴─────┴──────┘   └─────┴─────┴──────┘
```

**Key Features:**
1. ✅ **Sorted Order**: Terms stored in descending order of exponents
2. ✅ **No Zero Terms**: Zero coefficients are skipped
3. ✅ **Like Terms Combined**: Same exponents are automatically merged
4. ✅ **Efficient Storage**: Only non-zero terms stored
5. ✅ **Clean Output**: Proper formatting with signs and special cases handled

---
