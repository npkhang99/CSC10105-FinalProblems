// reference BT2-Nhom02, practise 2 in Geo problems

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
struct Point
{
	int x,y;
};

int nuatren[1000000];// chua index cua cac diem thuoc nua tren
int nuaduoi[1000000];// chua index cua cac diem thuoc nua duoi
int inuaduoi=0; // so luong diem o nua tren
int inuatren=0; // so luong diem o nua duoi

int dientichds(Point a, Point b, Point c )
{
	return a.x*(c.y-b.y)+b.x*(a.y-c.y)+c.x*(b.y-a.y);
}

int query(vector<Point> G, Point Q, int imin, int imax)
{
	if (Q.x<=G[imin].x || Q.x>=G[imax].x)
	{
		// neu diem Q nam ngoai hinh chu nhat
		//=> Q nam ngoai
		return 0;
	}
	
	
	if (dientichds(G[imin],G[imax],Q)<0)
	//xet tam giac Gimin, Gimax, Q de bit Q nam tren hay nam duoi
	{
		// neu diem Q thuoc nua tren
		int l=0, r=inuatren;
		while(r-l>1)
		{
			// tim kiem nhi phan trong mang nua tren
			int mid=(r+l)/2;
			if (Q.x>G[nuatren[mid]].x)
			{
				l=mid;	
			}else
			r=mid;		
			//---------------------------
		}	
		
		//xet dien tich tam giac tao boi 3 diem theo thu tu
		// Gi+1, Gi, Q , neu nguoc chieu kim dong ho (S<0) thi Q nam ngoai
		// 				neu cung chieu kim dong ho (S>0) thi Q nam trong
		if (dientichds(G[nuatren[l]],G[nuatren[r]],Q)<=0)
		return 0;
		else
		return 1;
	}
	else
	{
		// neu diem Q thuoc nua duoi
		int l=0, r=inuaduoi;
		while(r-l>1)
		{
			//tim kiem nhi phan o nua duoi
			int mid=(r+l)/2;
			if (Q.x>G[nuatren[mid]].x)
			{
				l=mid;	
			}else
			r=mid;		
			//------------------------
		}	
		// xet dien tich tam gia Gi, Gi+1, Q
		// neu nguoc chieu kim dong ho (S<0) thi nam ngoai
		// neu cung chieu kim dong ho (S>0) thi nam trong
		if (dientichds(G[nuaduoi[l]],G[nuaduoi[r]],Q)>=0)
		return 0;
		else
		return 1;	
	}
	
	//truong hop Q thuoc doan thang Gimin, Gimax thi Q nam trong da giac
	return 1;	
}
//-----------------------------------------------

int main()
{
	int n,m;
	cin>>n;
	vector<Point> G;
	// nhap
	for (int i=0;i<n;i++)
	{
		Point a;
		cin>>a.x;
		cin>>a.y;
		G.push_back(a);
	}
	
	int imin=0, imax=0;
		
	// -------------tim xmin, xmax----------
	for (int i=1;i<G.size();i++)
	{
		if (G[imin].x>G[i].x)
			imin=i;
			else
			{
				if (G[imax].x<G[i].x)
					imax=i;	
			}	
	} 
	//-------------------------------------
	
	
	// xay dung danh sach cac diem nua tren
	for (int i=imin;i!=imax;i=(i-1+G.size())%G.size())
	{
		nuatren[inuatren++]=i; // them index cua diem vao mang
	}
	nuatren[inuatren++]=imax; //diem imax la diem cuoi cua mang
	
	// xay dung danh sach cac diem nua duoi
	for (int i=imin;i!=imax;i=(i+1+G.size())%G.size())
	{
		nuaduoi[inuaduoi++]=i;// them index cua diem vao mang
	}
	nuaduoi[inuaduoi++]=imax;//diem imax la diem cuoi cua mang
	
	
	cin>>m;
	
	for (int i=0;i<m;i++)
	{
		Point Q;
		cin>>Q.x>>Q.y;
		
		if (query(G,Q,imin,imax))
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
	}
}


