#include <bits/stdc++.h>
using namespace std;
using ll =  long long;
using ull = unsigned  long;
const double pi = acos(-1);
template<class T> bool chmin(T& a,T b) { if(a > b){a = b; return true;} return false; }
template<class T> bool chmax(T& a,T b) { if(a < b){a = b; return true;} return false; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define all(p) (p).begin(), (p).end()
#define exists(c, e) ((c).find(e) != (c).end())

struct INIT{
 INIT(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cout << fixed << setprecision(20);
 }
}INIT;

struct Point {
     double x;
     double y;
};

Point rotatePoint(Point origin, Point p,  double deg){
    //原点に平行移動
    Point translated;
    translated.x = p.x - origin.x;
    translated.y = p.y - origin.y;

    //回転
    Point rotated;
    rotated.x = translated.x*cos(deg) - translated.y*sin(deg);
    rotated.y = translated.x*sin(deg) + translated.y*cos(deg);

    //元の座標に平行移動
    Point finalPoint;
    finalPoint.x = rotated.x + origin.x;
    finalPoint.y = rotated.y + origin.y;

    return finalPoint;
}

int main() {
     double n;
    cin >> n;
     double px, py;
     double tx, ty;
    cin >> px >> py;
    cin >> tx >> ty;

    Point origin = {(px+tx)/2.0, (py+ty)/2.0};
    Point point = {px, py};
     double deg = 2*pi/n; 

    Point rotatedPoint = rotatePoint(origin, point, deg);
    cout << rotatedPoint.x << ' ' << rotatedPoint.y << endl;
    return 0;
}