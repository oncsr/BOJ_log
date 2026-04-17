#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    auto dist = [](ld a, ld b, ld c, ld d) -> ld {
        return sqrt((a-c)*(a-c) + (b-d)*(b-d));
    };

    ld ax, ay, bx, by, cx, cy, dx, dy;
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;

    ld d1 = dist(ax,ay,bx,by), d2 = dist(cx,cy,dx,dy);
    ld s = 0, e = 1, t1 = s + (e-s)/3, t2 = s + (e-s)*2/3;
    while(e-s > 0.000000001){
        ld px, py, qx, qy;

        px = (bx-ax) * t1 + ax, py = (by-ay) * t1 + ay;
        qx = (dx-cx) * t1 + cx, qy = (dy-cy) * t1 + cy;

        ld D1 = dist(px,py,qx,qy);
        
        px = (bx-ax) * t2 + ax, py = (by-ay) * t2 + ay;
        qx = (dx-cx) * t2 + cx, qy = (dy-cy) * t2 + cy;
        
        ld D2 = dist(px,py,qx,qy);

        if(D1 < D2) e = t2;
        else    s = t1;
        t1 = s + (e-s)/3, t2 = s + (e-s)*2/3;
    }
    ld px, py, qx, qy;
    
    px = (bx-ax) * t1 + ax, py = (by-ay) * t1 + ay;
    qx = (dx-cx) * t1 + cx, qy = (dy-cy) * t1 + cy;

    cout.precision(10);
    cout<<fixed<<dist(px,py,qx,qy);

}