////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-06-06 23:30:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5258
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1608KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 602_1001.cpp
      > Author: Netcan
      > Blog: http://www.netcan.xyz
      > Mail: 1469709759@qq.com
      > Created Time: Sat 06 Jun 2015 03:44:46 PM CST
 ************************************************************************/
 
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <sstream>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <stack>
#include <set>
#include <numeric>
#include <utility>
#include <cstring>
using namespace std;
struct l {
    int x1, x2, y1, y2;
} l1[30],l2[30]; // ���� ��
 
bool cmp1(const l &a, const l &b) { // ��ľ���������С��������
    return a.x1 < b.x1;
}
bool cmp2(const l &a, const l &b) { // ��ľ��������Ӵ�С����
    return a.y1 > b.y1;
}
 
int main()
{
#ifdef Oj
    freopen("602_1001.in", "r", stdin);
#endif
    int T;
    cin >> T;
    int Case = 1;
    while(T--) {
        int n;
        cin >> n;
        int lc1=0, lc2=0; // ������ľ������
        int x1, x2, y1, y2;
        for (int i = 0; i < n; ++i) {
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 == x2) { // ��ľ��
                l1[lc1].x1 = l1[lc1].x2 = x1;
                l1[lc1].y1 = min(y1, y2); // ������С�ķ���y1����ķ���y2
                l1[lc1].y2 = max(y1, y2);
                ++lc1;
            }
            else { // ��ľ��
                l2[lc2].y1 = l2[lc2].y2 = y1;
                l2[lc2].x1 = min(x1, x2); // ������С�ķ���x1����ķ���x2
                l2[lc2].x2 = max(x1, x2);
                ++lc2;
            }
        }
        sort(l1, l1+lc1, cmp1); // ��ľ�����Ϻ������С��������
        sort(l2, l2+lc2, cmp2); // ��ľ��������Ӵ�С����
        int counts = 0; // ���θ���
 
        for(int i=0; i<lc1; ++i) {
            for(int j=i+1; j<lc1; ++j) { //  ��ľ��i, j
                for(int k=0; k<lc2; ++k)  {
                    for(int m=k+1; m<lc2; ++m) { // ��ľ��k, m
                        if(l2[k].y1 <= min(l1[i].y2, l1[j].y2) && 
                        l2[m].y1 >= max(l1[i].y1, l1[j].y1) && 
                        l1[i].x1 >= max(l2[k].x1, l2[m].x1) && 
                        l1[j].x2 <= min(l2[k].x2, l2[m].x2))
                            ++counts;
                    }
 
                }
            }
        }
        printf("Case #%d:\n", Case++);
        cout << counts << endl;
    }
    return 0;
}