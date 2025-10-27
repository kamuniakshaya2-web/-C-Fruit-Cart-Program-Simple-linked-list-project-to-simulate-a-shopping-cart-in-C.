#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct item{
    int itemname;
    struct item*nextitem;
};
struct itemprice{
    int price;
    struct itemprice*nextitpr;
};
struct item*firstitem=NULL;
struct itemprice*firstitemprice=NULL;
struct item*newnode;
struct itemprice*nodenew;
struct item*temp;
struct itemprice*temppri;
void itemdisplay(){
    printf("\n====== WELCOME ======\nHere are some available fruits:\n");
    printf("1.Apples - 40\n2.Orange - 30\n3.Grapes - 50\n4.Avacado - 100\n5.viewcart\n");
}
struct StringItem {
    char text[MAX];
};
struct StringItem list[4] = {
    {"Apple"},
    {"Orange"},
    {"Grapes"},
    {"Avacado"}
};
void cartitems(){
    printf("\nYour cart items:\n");
    struct item*itemtemp=firstitem;
    struct itemprice*prtemp=firstitemprice;
    int s=0;
    while(itemtemp!=NULL){
        printf("%s   %d\n",list[itemtemp->itemname-1].text,prtemp->price);
        s+=prtemp->price;
        itemtemp=itemtemp->nextitem;
        prtemp=prtemp->nextitpr;
    }
    printf("Total Amount: %dRs",s);
    printf("Thank you, Visit Again");
}
void itemaddcart(int n,int q,int price){
    newnode=(struct item*)malloc(sizeof(struct item));
    nodenew=(struct itemprice*)malloc(sizeof(struct itemprice));
        newnode->itemname=n;
        newnode->nextitem=NULL;
        if(firstitem==NULL){
            firstitem=newnode;
            temp=firstitem;
        }else{
            temp->nextitem=newnode;
            temp=temp->nextitem;
        }
        nodenew->price=q*price;
        nodenew->nextitpr=NULL;
        if(firstitemprice==NULL){
            firstitemprice=nodenew;
            temppri=firstitemprice;
        }
        else{
            temppri->nextitpr=nodenew;
            temppri=temppri->nextitpr;
        }

    }
int main() {
	// your code goes here
	while(1){
	    itemdisplay();
	    int choice;
	    printf("Select any type of fruit from the above menu:  ");
	    scanf("%d",&choice);
	    int q;
	    switch(choice){
	        case 1: printf("Enter quantity(in kg)\n");
                     scanf("%d",&q);
                      printf("Apples are added to your cart\n");
	                  itemaddcart(1,q,40);
                     break;
            case 2: printf("Enter quantity(in kg)\n");
                     scanf("%d",&q);
                      printf("Oranges are added to your cart\n");
	                 itemaddcart(2,q,30);
                     break;
            case 3: printf("Enter quantity(in kg)\n");
                     scanf("%d",&q);
                     printf("Grapes are added to your cart\n");
	                 itemaddcart(3,q,50);
                     break;
            case 4: printf("Enter quantity(in kg)\n");
                     scanf("%d",&q);
                     printf("Avacado are added to your cart\n");
	                 itemaddcart(4,q,100);
                     break;
            case 5: cartitems();
                    exit(0);
            default:printf("invalid\n");
	    }
	}
    cartitems();
	return 0;
}