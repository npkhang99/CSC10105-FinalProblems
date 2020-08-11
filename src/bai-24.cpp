// practise 3 in Geo problems

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long n,xp=1e12,yp=1e12,xq=-1e12,yq=-1e12;

struct data
{
    long long x,y;
} a[3005],P,Q;

vector<data>A,B;
vector<data>rs;

long long Dientich(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3)
{
    return (x2-x1)*(y2+y1)+(x3-x2)*(y3+y2)+(x1-x3)*(y1+y3);
}
data makedata(long long x,long long y)
{
    data temp;
    temp.x=x;
    temp.y=y;
    return temp;
}
bool cmp(data x,data y)
{
    if(x.x==y.x)
        return x.y>y.y;
    return x.x<y.x;
}
bool cmp1(data x,data y)
{
    if(x.x==y.x)
        return x.y<y.y;
    return x.x>y.x;
}
void Init()
{
    for(long long i=1; i<=n; ++i)
    {
        if(Dientich(P.x,P.y,Q.x,Q.y,a[i].x,a[i].y)<0)
            A.push_back({a[i].x,a[i].y});
        if(Dientich(P.x,P.y,Q.x,Q.y,a[i].x,a[i].y)>0)
            B.push_back({a[i].x,a[i].y});
    }
}
long long Cal()
{
    long
    long s=0;
    rs.push_back(rs[0]);
    for(long long i=0; i<rs.size()-1; ++i)
        s += (rs[i+1].x-rs[i].x) * (rs[i+1].y+rs[i].y);
    rs.pop_back();
    return abs(s);
}

data S[3005];
int last;
void Build(vector<data>Point, bool (*compare)(data, data), data M, data N)
{
    sort(Point.begin(), Point.end(), cmp);
    Point.push_back(M);
    last = 1;
    S[1] = N;
    for(long long i = 0; i < Point.size(); ++i)
    {
        while(last>1 && Dientich(S[last - 1].x, S[last - 1].y, S[last].x, S[last].y, Point[i].x, Point[i].y) < 0)
            --last;
        S[++last] = Point[i];
    }
}
void buildConvexhull()
{
    Init();
    Build(A, cmp, Q, P);
    for(int i = 1; i <= last; ++i)
        rs.push_back(S[i]);
    Build(B, cmp1, P, Q);
    for(int i = 2; i < last; ++i)
        rs.push_back(S[i]);
}
int main()
{
    cin >> n;
    for(long long i=1; i<=n; ++i)
    {
        cin >> a[i].x >> a[i].y;
        if(a[i].x<=xp)
        {
            if(a[i].x==xp)
            {
                yp=min(yp,a[i].y);
            }
            else
            {
                xp=a[i].x;
                yp=a[i].y;
            }
        }
        if(a[i].x>=xq)
        {
            if(a[i].x==xq)
            {
                yq=max(yq,a[i].y);
            }
            else
            {
                xq=a[i].x;
                yq=a[i].y;
            }
        }
    }
    /// P là điểm trái dưới, Q là điểm phải trên
    Q.x=xq;
    Q.y=yq;
    P.x=xp;
    P.y=yp;
    buildConvexhull();
    long long Dt=0, vt;
    for(int i = 0; i < rs.size(); ++i)
    {
        vt = i+2;
        for(int j = i + 1; j < rs.size(); ++j)
            for(int k = vt; k < rs.size(); ++k)
            {
                    Dt = max(Dt, abs(Dientich(rs[i].x,rs[i].y,rs[j].x,rs[j].y,rs[k].x,rs[k].y)));
                    if(abs(Dientich(rs[i].x,rs[i].y,rs[j].x,rs[j].y,rs[k-1].x,rs[k-1].y)) > abs(Dientich(rs[i].x,rs[i].y,rs[j].x,rs[j].y,rs[k].x,rs[k].y)))
                    {
                        vt=k;
                        break;
                    }
            }
    }
    cout<<Dt/2;
    if(Dt&1)
        cout<<".5";
    else cout<<".0";
}
