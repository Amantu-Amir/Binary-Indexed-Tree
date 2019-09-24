///**Bismillahir Rahmanir Rahim.**
///Accepted

#include <bits/stdc++.h>
#define clr(a, v)             memset(a, v, sizeof a)
#define all(v)                v.begin(), v.end()
#define ast(v)                sort(v.begin(),v.end())
#define dst(v)                sort(v.begin(),v.end(), greater <int> ())
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ass(tmp, v)           tmp.assign(v.begin(), v.end())
#define rep(i, l, r)          for (int i = l; i < r; i++)
#define rep2(i, l, r)         for (int i = l-1; i >= r; i--)
#define sf(n)                 scanf("%d", &n)
#define sff(n, m)             scanf("%d %d",&n,&m)
#define sfl(n)                scanf("%lld", &n)
#define sfu(n)                scanf("%llu", &n)
#define sffl(n, m)            scanf("%lld %lld",&n,&m)
#define sfff(n, m, o)         scanf("%d %d %d",&n,&m, &o)
#define pf(n)                 printf("%d", n)
#define sp                    printf(" ")
#define nl                    printf("\n")
#define prln(n)               printf("%d\n", n)
#define pfl(n)                printf("%lld", n)
#define pfu(n)                printf("%llu", n)
#define pb                    push_back
#define pii                   pair<int,int>
#define mp                    make_pair
#define S                     second
#define F                     first
#define PI                    3.1415926

struct greaters
{
    bool operator()(const long& a, const long& b) const
    {
        return a > b;
    }
};

//-----------------------------------***********************----------------------------------------------//


typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
const int N = 1050;
const int mod = 1e9+7;

int tree[N][N];
bool f[N][N];
int maxX;
int maxY;

int read(int x, int y)
{
    int sum = 0;
    while(x > 0)
    {
        int y1 = y;
        while(y1 > 0)
        {
            sum += tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return sum;
}

void update(int x, int y, int val)
{
    while(x <= maxX)
    {
        int y1 = y;
        while(y1 <= maxY)
        {
            tree[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

int query(int x1, int y1, int x2, int y2)
{
    return read(x2, y2) - read(x2, y1-1) - read(x1-1, y2) + read(x1-1, y1-1);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);


    int x1, y1, x2, y2, tc, n, m;
    scanf("%d", &tc);
    getchar();

    maxX = maxY = 1001;
    for(int t = 1; t <= tc; t++)
    {
        scanf("%d", &n);
        printf("Case %d:\n", t);

        memset(tree, 0, sizeof tree);
        memset(f, 0, sizeof f);

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &m);
            int x, y;
            if(m == 0)
            {
                scanf("%d %d", &x, &y);
                x++, y++;
                if(!f[x][y])
                {
                    f[x][y] = true;
                    update(x, y, 1);
                }
            }
            else
            {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1++, y1++, x2++, y2++;
                printf("%d\n", query(x1, y1, x2, y2));
            }
        }
    }

    return 0;
}
