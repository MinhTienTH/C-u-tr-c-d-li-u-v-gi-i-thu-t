#include <iostream>
#define MAXN 1000
using namespace std;
struct node{
    int data;
    node* pLeft;
    node *pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
void KhoiTao(TREE &root)
{
    root=NULL;
}
void InSertNODE(TREE &root,int x)
{
    if(root==NULL)
    {
        NODE *temp = new NODE;
        temp->data = x;
        temp->pLeft = NULL;
        temp->pRight = NULL;
        root = temp;
    }
    else{
        if(x<root->data) InSertNODE(root->pLeft, x);
        else InSertNODE(root->pRight, x);
    }
}
void printEven(TREE root)
{
    if(root!=NULL)
    {
        if(root->data%2==0)
            cout<<root->data<<" ";
        printEven(root->pLeft);
        printEven(root->pRight);
    }
}
int A[MAXN];
int k = 0;
int countFullNode(TREE root)
{
    if(root!=NULL)
    {
        if(root->pLeft!=NULL&&root->pRight!=NULL)
        {
            A[k] = root->data;
            k++;
        }
        countFullNode(root->pLeft);
        countFullNode(root->pRight);
    }
    return A[k];
}
int Tong(TREE root)
{
    if (root == NULL)
        return 0;
    else
        return root->data + Tong(root->pLeft) + Tong(root->pRight);
}

int DemNut(TREE root)
{
    if (root == NULL) return 0;
    if (root->pLeft == NULL && root->pRight == NULL)
        return 1;
    else
        return 1 + DemNut(root->pLeft) + DemNut(root->pRight);
    
}

 float average(TREE root)
 {
    if (root == NULL)
        return 0;
    else
        return (float)Tong(root)/(float)DemNut(root);
 }
int main()
{
    TREE t;
    KhoiTao(t);
    int n, x;
    cout<<"Nhap so luong node can them vao cay nhi phan: ";
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>x;
        InSertNODE(t, x);
    }
    printEven(t);
    cout<<endl;
    countFullNode(t);
    for(int i = k-1;i>=0;i--)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    cout<<average(t);
}

