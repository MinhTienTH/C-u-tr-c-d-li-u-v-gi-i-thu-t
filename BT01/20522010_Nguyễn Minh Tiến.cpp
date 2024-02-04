
#include <iostream>
#include <cmath>
using namespace std;


struct ToaDo
{
    float x, y;
};

struct Node
{
    ToaDo data;
    Node* pNext;
};

struct PointList
{
    Node* pHead;
    Node* pTail;
};

Node* CreateNode(ToaDo data)
{
    Node* pNode = new Node;
    pNode->data = data;
    pNode->pNext = NULL;
    return pNode;
}

void Initialize(PointList& list)
{
    list.pHead = list.pTail = NULL;
}

istream& operator>>(istream& is, ToaDo& a)
{
    cout<<"Nhap x,y: ";
    is >> a.x;
    is >> a.y;
    return is;
}

ostream& operator<<(ostream& os, ToaDo a)
{
    cout << "(" << a.x << ", " << a.y << ")";
    return os;
}

void InsertLast(PointList& list, ToaDo temp)
{
    Node* pNode = CreateNode(temp);
    if (list.pHead == NULL)
    {
        list.pHead = list.pTail = pNode;
    }
    else
    {
        list.pTail->pNext = pNode;
        list.pTail = pNode;
    }
}

int SizeofList(PointList list)
{
    int count = 0;
    for (Node* pTemp = list.pHead; pTemp != NULL; pTemp = pTemp->pNext)
    {
        count++;
    }
    return count;
}

void DeleteList(PointList& list)
{
    while (list.pHead != NULL)
    {
        Node* pTemp = list.pHead;
        list.pHead = list.pHead->pNext;
        pTemp->pNext = NULL;
        delete pTemp;
        pTemp = NULL;
    }

}

void NhapDS(PointList& l)
{
    ToaDo temp;
    cin >> temp;
    while (temp.x != 0 || temp.y != 0)
    {
        InsertLast(l, temp);
        cin >> temp;
    }
}

void XuatDanhSach(PointList l)
{
    Node* pTemp = l.pHead;
    cout << endl;
    while (pTemp != NULL)
    {
        cout << pTemp->data << " ";
        pTemp = pTemp->pNext;
    }

    delete pTemp;
    pTemp = NULL;
}

bool SoSanhToaDo(ToaDo TD1, ToaDo TD2)
{
    if (TD1.x == TD2.x && TD1.y == TD2.y)
        return true;
    return false;
}

void GopDS(PointList l1, PointList l2, PointList &r)
{
    for (Node* pTemp_1 = l1.pHead; pTemp_1 != NULL; pTemp_1 = pTemp_1->pNext)
    {
        for (Node* pTemp_2 = l2.pHead; pTemp_2 != NULL; pTemp_2 = pTemp_2->pNext)
        {
            if (SoSanhToaDo(pTemp_1->data, pTemp_2->data) == true)
            {
                InsertLast(r, pTemp_1->data);
            }
        }
    }
}

void TimTrongTam(PointList l)
{
    if (l.pHead == NULL)
        {
            cout << "\nDanh sach rong";
            return;
        }
        if (SizeofList(l) == 1)
        {
            cout << "\nDanh sach chi co 1 diem, khong the tim trong tam";
            return;
        }
        ToaDo Temp;
        Temp.x = Temp.y = 0;
        for (Node* pTemp = l.pHead; pTemp != NULL; pTemp = pTemp->pNext)
        {
            Temp.x += pTemp->data.x;
            Temp.y += pTemp->data.y;
        }
        Temp.x /= SizeofList(l);
        Temp.y /= SizeofList(l);
        cout << "\n\nDiem trong tam: " << Temp;
}

int main()
{
    PointList l1, l2, r;
    Initialize(l1);
    Initialize(l2);
    cout<<"Nhap l1: "<<endl;
    NhapDS(l1);
    cout<<"Nhap l2: "<<endl;
    NhapDS(l2);
    XuatDanhSach(l1);
    XuatDanhSach(l2);
    Initialize(r);
    GopDS(l1, l2, r);
    TimTrongTam(r);
    return 0;
}
