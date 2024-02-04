#include<iostream>
#include<string>
using namespace std;
#define MAX  100
#define TRUE  1
#define FALSE  0
    int n;
    int first[MAX];
    int stillnot[MAX];
    int queue[MAX];
    int A[MAX][MAX];
    int s;
    int t;
    int q;
    int u, v;
    string Name[MAX];
    void Initialize() {
    cout << "Nhap so luong tram dung chan: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ten tram thu " << i+1 << ": ";
        fflush(stdin);
        getline(cin,Name[i]);
    }
    cout << "Nhap dinh dau:"; cin >> s;
    cout << "Nhap dinh cuoi:"; cin >> t;
    cout << "So duong di: "; cin >> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = 0;
    for (int i = 0; i < q; i++)
    {
        cin>>u;
        cin>>v;
        A[u][v] = 1;
    }
    for (int i = 1; i <= n; i++) {
        stillnot[i] = TRUE;
        first[i] = 0;
    }
}
void Ket_Qua() {
    if (first[t] == 0) {
        cout << "Khong co duong di tu " << s << " den " << t;
        return;
    }
    cout << "Duong di tu " << s << " den " << t << " la: ";
    int j = t;
    cout << Name[t] << "<=";
    while (first[j] != s) {
        cout << Name[first[j]] << "<=";
        j = first[j];
    }
    cout << Name[s];
}
void BFS(int s)
{
    int dauQueue = 1;
    int cuoiQueue = 1;
    int u;
    queue[dauQueue] = s; stillnot[s] = FALSE;
    while (dauQueue <= cuoiQueue)
    {
        u = queue[dauQueue];
        dauQueue = dauQueue + 1;
        for (int p = 1; p <= n; p++) {
            if (A[u][p] && stillnot[p]) {
                cuoiQueue = cuoiQueue + 1;
                queue[cuoiQueue] = p;
                stillnot[p] = FALSE;
                first[p] = u;
            }
        }
    }
}
int main() {
    Initialize();
    BFS(s);
    Ket_Qua();
    return 0;
}
