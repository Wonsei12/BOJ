#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>


using namespace std;
const double eps = 1e-10;
//点
class Point
{
public:
    double x, y;

    Point(){}
    Point(double x, double y):x(x),y(y){}

    bool operator < (const Point &_se) const
    {
        return x<_se.x || (x==_se.x && y<_se.y);
    }
    /*******判断ta与tb的大小关系*******/
    static int sgn(double ta,double tb)
    {
        if(fabs(ta-tb)<eps)return 0;
        if(ta<tb)   return -1;
        return 1;
    }
    static double xmult(const Point &po, const Point &ps, const Point &pe)
    {
        return (ps.x - po.x) * (pe.y - po.y) - (pe.x - po.x) * (ps.y - po.y);
    }
    friend Point operator + (const Point &_st,const Point &_se)
    {
        return Point(_st.x + _se.x, _st.y + _se.y);
    }
    friend Point operator - (const Point &_st,const Point &_se)
    {
        return Point(_st.x - _se.x, _st.y - _se.y);
    }
    //点位置相同(double类型)
    bool operator == (const Point &_off) const
    {
        return  Point::sgn(x, _off.x) == 0 && Point::sgn(y, _off.y) == 0;
    }
    //点位置不同(double类型)
    bool operator != (const Point &_Off) const
    {
        return ((*this) == _Off) == false;
    }
    //两点间距离的平方
    static double dis2(const Point &_st,const Point &_se)
    {
        return (_st.x - _se.x) * (_st.x - _se.x) + (_st.y - _se.y) * (_st.y - _se.y);
    }
    //两点间距离
    static double dis(const Point &_st, const Point &_se)
    {
        return sqrt((_st.x - _se.x) * (_st.x - _se.x) + (_st.y - _se.y) * (_st.y - _se.y));
    }
};
//两点表示的向量
class Line
{
public:
    Point s, e;//两点表示，起点[s]，终点[e]
    double a, b, c;//一般式,ax+by+c=0

    Line(){}
    Line(const Point &s, const Point &e):s(s),e(e){}
    Line(double _a,double _b,double _c):a(_a),b(_b),c(_c){}

    //向量与点的叉乘,参数：点[_Off]
    //[点相对向量位置判断]
    double operator /(const Point &_Off) const
    {
        return (_Off.y - s.y) * (e.x - s.x) - (_Off.x - s.x) * (e.y - s.y);
    }
    //向量与向量的叉乘,参数：向量[_Off]
    friend double operator /(const Line &_st,const Line &_se)
    {
        return (_st.e.x - _st.s.x) * (_se.e.y - _se.s.y) - (_st.e.y - _st.s.y) * (_se.e.x - _se.s.x);
    }
    friend double operator *(const Line &_st,const Line &_se)
    {
        return (_st.e.x - _st.s.x) * (_se.e.x - _se.s.x) - (_st.e.y - _st.s.y) * (_se.e.y - _se.s.y);
    }
    //从两点表示转换为一般表示
    //a=y2-y1,b=x1-x2,c=x2*y1-x1*y2
    bool pton()
    {
        a = e.y - s.y;
        b = s.x - e.x;
        c = e.x * s.y - e.y * s.x;
        return true;
    }

    //-----------点和直线（向量）-----------
    //点在向量左边（右边的小于号改成大于号即可,在对应直线上则加上=号）
    //参数：点[_Off],向量[_Ori]
    friend bool operator<(const Point &_Off, const Line &_Ori)
    {
        return (_Ori.e.y - _Ori.s.y) * (_Off.x - _Ori.s.x)
            < (_Off.y - _Ori.s.y) * (_Ori.e.x - _Ori.s.x);
    }

    //点在直线上,参数：点[_Off]
    bool lhas(const Point &_Off) const
    {
        return Point::sgn((*this) / _Off, 0) == 0;
    }
    //点在线段上,参数：点[_Off]
    bool shas(const Point &_Off) const
    {
        return lhas(_Off)
            && Point::sgn(_Off.x - min(s.x, e.x), 0) > 0 && Point::sgn(_Off.x - max(s.x, e.x), 0) < 0
            && Point::sgn(_Off.y - min(s.y, e.y), 0) > 0 && Point::sgn(_Off.y - max(s.y, e.y), 0) < 0;
    }

    //点到直线/线段的距离
    //参数： 点[_Off], 是否是线段[isSegment](默认为直线)
    double dis(const Point &_Off, bool isSegment = false)
    {
        ///化为一般式
        pton();

        //到直线垂足的距离
        double td = (a * _Off.x + b * _Off.y + c) / sqrt(a * a + b * b);

        //如果是线段判断垂足
        if(isSegment)
        {
            double xp = (b * b * _Off.x - a * b * _Off.y - a * c) / ( a * a + b * b);
            double yp = (-a * b * _Off.x + a * a * _Off.y - b * c) / (a * a + b * b);
            double xb = max(s.x, e.x);
            double yb = max(s.y, e.y);
            double xs = s.x + e.x - xb;
            double ys = s.y + e.y - yb;
            if(xp > xb + eps || xp < xs - eps || yp > yb + eps || yp < ys - eps)
                td = min(Point::dis(_Off,s), Point::dis(_Off,e));
        }

        return fabs(td);
    }

    //关于直线对称的点
    Point mirror(const Point &_Off) const
    {
        ///注意先转为一般式
        Point ret;
        double d = a * a + b * b;
        ret.x = (b * b * _Off.x - a * a * _Off.x - 2 * a * b * _Off.y - 2 * a * c) / d;
        ret.y = (a * a * _Off.y - b * b * _Off.y - 2 * a * b * _Off.x - 2 * b * c) / d;
        return ret;
    }
    //计算两点的中垂线
    static Line ppline(const Point &_a, const Point &_b)
    {
        Line ret;
        ret.s.x = (_a.x + _b.x) / 2;
        ret.s.y = (_a.y + _b.y) / 2;
        //一般式
        ret.a = _b.x - _a.x;
        ret.b = _b.y - _a.y;
        ret.c = (_a.y - _b.y) * ret.s.y + (_a.x - _b.x) * ret.s.x;
        //两点式
        if(std::fabs(ret.a) > eps)
        {
            ret.e.y = 0.0;
            ret.e.x = - ret.c / ret.a;
            if(ret.e == ret. s)
            {
                ret.e.y = 1e10;
                ret.e.x = - (ret.c - ret.b * ret.e.y) / ret.a;
            }
        }
        else
        {
            ret.e.x = 0.0;
            ret.e.y = - ret.c / ret.b;
            if(ret.e == ret. s)
            {
                ret.e.x = 1e10;
                ret.e.y = - (ret.c - ret.a * ret.e.x) / ret.b;
            }
        }
        return ret;
    }

    //------------直线和直线（向量）-------------
    //直线重合,参数：直线向量[_st],[_se]
    static bool equal(const Line &_st, const Line &_se)
    {
        return _st.lhas(_se.e) && _se.lhas(_se.s);
    }
    //直线平行，参数：直线向量[_st],[_se]
    static bool parallel(const Line &_st,const Line &_se)
    {
        return Point::sgn(_st / _se, 0) == 0;
    }
    //两直线（线段）交点，参数：直线向量[_st],[_se],交点
    //返回-1代表平行，0代表重合，1代表相交
    static bool crossLPt(const Line &_st,const Line &_se,Point &ret)
    {
        if(Line::parallel(_st,_se))
        {
            if(Line::equal(_st,_se)) return 0;
            return -1;
        }
        ret = _st.s;
        double t = (Line(_st.s,_se.s)/_se)/(_st/_se);
        ret.x += (_st.e.x - _st.s.x) * t;
        ret.y += (_st.e.y - _st.s.y) * t;
        return 1;
    }
    //------------线段和直线（向量）----------
    //线段和直线交
    //参数：直线[_st],线段[_se]
    friend bool crossSL(const Line &_st,const Line &_se)
    {
        return Point::sgn((_st / _se.s) * (_st / _se.e) ,0) <= 0;
    }

    //------------线段和线段（向量）----------
    //判断线段是否相交(注意添加eps)，参数：线段[_st],线段[_se]
    static bool isCrossSS(const Line &_st,const Line &_se)
    {
        //1.快速排斥试验判断以两条线段为对角线的两个矩形是否相交
        //2.跨立试验（等于0时端点重合）
        return
            max(_st.s.x, _st.e.x) >= min(_se.s.x, _se.e.x) &&
            max(_se.s.x, _se.e.x) >= min(_st.s.x, _st.e.x) &&
            max(_st.s.y, _st.e.y) >= min(_se.s.y, _se.e.y) &&
            max(_se.s.y, _se.e.y) >= min(_st.s.y, _st.e.y) &&
            Point::sgn((_st / Line(_st.s, _se.s)) * (_st / Line(_st.s, _se.e)), 0) <= 0 &&
            Point::sgn((_se / Line(_se.s, _st.s)) * (_se / Line(_se.s, _st.e)), 0) <= 0;
    }
};
class Polygon
{
public:
    const static int maxpn = 100;
    Point pt[maxpn];//点（顺时针或逆时针）
    int n;//点的个数

    Point& operator[](int _p)
    {
        return pt[_p];
    }

    //求多边形面积，多边形内点必须顺时针或逆时针
    double area() const
    {
        double ans = 0.0;
        for(int i = 0; i < n; i ++)
        {
            int nt = (i + 1) % n;
            ans += pt[i].x * pt[nt].y - pt[nt].x * pt[i].y;
        }
        return fabs(ans / 2.0);
    }
    //求多边形重心，多边形内点必须顺时针或逆时针
    Point gravity() const
    {
        Point ans;
        ans.x = ans.y = 0.0;
        double area = 0.0;
        for(int i = 0; i < n; i ++)
        {
            int nt = (i + 1) % n;
            double tp = pt[i].x * pt[nt].y - pt[nt].x * pt[i].y;
            area += tp;
            ans.x += tp * (pt[i].x + pt[nt].x);
            ans.y += tp * (pt[i].y + pt[nt].y);
        }
        ans.x /= 3 * area;
        ans.y /= 3 * area;
        return ans;
    }
    //判断点在凸多边形内，参数：点[_Off]
    bool chas(const Point &_Off) const
    {
        double tp = 0, np;
        for(int i = 0; i < n; i ++)
        {
            np = Line(pt[i], pt[(i + 1) % n]) / _Off;
            if(tp * np < -eps)
                return false;
            tp = (fabs(np) > eps)?np: tp;
        }
        return true;
    }
    //判断点是否在任意多边形内[射线法]，O(n)
    bool ahas(const Point &_Off) const
    {
        int ret = 0;
        double infv = 1e-10;//坐标系最大范围
        Line l = Line(_Off, Point( -infv ,_Off.y));
        for(int i = 0; i < n; i ++)
        {
            Line ln = Line(pt[i], pt[(i + 1) % n]);
            if(fabs(ln.s.y - ln.e.y) > eps)
            {
                Point tp = (ln.s.y > ln.e.y)? ln.s: ln.e;
                if(fabs(tp.y - _Off.y) < eps && tp.x < _Off.x + eps)
                    ret ++;
            }
            else if(Line::isCrossSS(ln,l))
                ret ++;
        }
        return (ret % 2 == 1);
    }
    //凸多边形被直线分割,参数：直线[_Off]
    Polygon split(Line _Off)
    {
        //注意确保多边形能被分割
        Polygon ret;
        Point spt[2];
        double tp = 0.0, np;
        bool flag = true;
        int i, pn = 0, spn = 0;
        for(i = 0; i < n; i ++)
        {
            if(flag)
                pt[pn ++] = pt[i];
            else
                ret.pt[ret.n ++] = pt[i];
            np = _Off / pt[(i + 1) % n];
            if(tp * np < -eps)
            {
                flag = !flag;
                Line::crossLPt(_Off,Line(pt[i], pt[(i + 1) % n]),spt[spn++]);
            }
            tp = (fabs(np) > eps)?np: tp;
        }
        ret.pt[ret.n ++] = spt[0];
        ret.pt[ret.n ++] = spt[1];
        n = pn;
        return ret;
    }


    /** 卷包裹法求点集凸包，_p为输入点集，_n为点的数量 **/
    void ConvexClosure(Point _p[],int _n)
    {
        sort(_p,_p+_n);
        n=0;
        for(int i=0;i<_n;i++)
        {
            while(n>1&&Point::sgn(Line(pt[n-2],pt[n-1])/Line(pt[n-2],_p[i]),0)<=0)
                n--;
            pt[n++]=_p[i];
        }
        int _key=n;
        for(int i=_n-2;i>=0;i--)
        {
            while(n>_key&&Point::sgn(Line(pt[n-2],pt[n-1])/Line(pt[n-2],_p[i]),0)<=0)
                n--;
            pt[n++]=_p[i];
        }
        if(n>1)   n--;//除去重复的点，该点已是凸包凸包起点
    }
//    /****** 寻找凸包的graham 扫描法********************/
//    /****** _p为输入的点集,_n为点的数量****************/
//    /**使用时需把gmp函数放在类外，并且看情况修改pt[0]**/
//    bool gcmp(const Point &ta,const Point &tb)/// 选取与最后一条确定边夹角最小的点，即余弦值最大者
//    {
//        double tmp=Line(pt[0],ta)/Line(pt[0],tb);
//        if(Point::sgn(tmp,0)==0)
//            return Point::dis(pt[0],ta)<Point::dis(pt[0],tb);
//        else if(tmp>0)
//            return 1;
//        return 0;
//    }
//    void graham(Point _p[],int _n)
//    {
//        int cur=0;
//        for(int i=1;i<_n;i++)
//            if(Point::sgn(_p[cur].y,_p[i].y)>0 || (Point::sgn(_p[cur].y,_p[i].y)==0 && Point::sgn(_p[cur].x,_p[i].x)>0))
//                cur=i;
//        swap(_p[cur],_p[0]);
//        n=0,pt[n++]=_p[0];
//        if(_n==1)   return;
//        sort(_p+1,_p+_n,Polygon::gcmp);
//        pt[n++]=_p[1],pt[n++]=_p[2];
//        for(int i=3;i<_n;i++)
//        {
//            while(Point::sgn(Line(pt[n-2],pt[n-1])/Line(pt[n-2],_p[i]),0)<0)
//                n--;
//            pt[n++]=_p[i];
//        }
//    }
    //凸包旋转卡壳(注意点必须顺时针或逆时针排列)
    //返回值凸包直径的平方（最远两点距离的平方）
    double rotating_calipers()
    {
        int i = 1;
        double ret = 0.0;
        pt[n] = pt[0];
        for(int j = 0; j < n; j ++)
        {
            while(fabs(Point::xmult(pt[i+1],pt[j], pt[j + 1])) > fabs(Point::xmult(pt[i],pt[j], pt[j + 1])) + eps)
                i = (i + 1) % n;
            //pt[i]和pt[j],pt[i + 1]和pt[j + 1]可能是对踵点
            ret = (ret, max(Point::dis(pt[i],pt[j]), Point::dis(pt[i + 1],pt[j + 1])));
        }
        return ret;
    }

    //凸包旋转卡壳(注意点必须逆时针排列)
    //返回值两凸包的最短距离
    double rotating_calipers(Polygon &_Off)
    {
        int i = 0;
        double ret = 1e10;//inf
        pt[n] = pt[0];
        _Off.pt[_Off.n] = _Off.pt[0];
        //注意凸包必须逆时针排列且pt[0]是左下角点的位置
        while(_Off.pt[i + 1].y > _Off.pt[i].y)
            i = (i + 1) % _Off.n;
        for(int j = 0; j < n; j ++)
        {
            double tp;
            //逆时针时为 >,顺时针则相反
            while((tp = Point::xmult(_Off.pt[i + 1],pt[j], pt[j + 1]) - Point::xmult(_Off.pt[i], pt[j], pt[j + 1])) > eps)
                i = (i + 1) % _Off.n;
            //(pt[i],pt[i+1])和(_Off.pt[j],_Off.pt[j + 1])可能是最近线段
            ret = min(ret, Line(pt[j], pt[j + 1]).dis(_Off.pt[i], true));
            ret = min(ret, Line(_Off.pt[i], _Off.pt[i + 1]).dis(pt[j + 1], true));
            if(tp > -eps)//如果不考虑TLE问题最好不要加这个判断
            {
                ret = min(ret, Line(pt[j], pt[j + 1]).dis(_Off.pt[i + 1], true));
                ret = min(ret, Line(_Off.pt[i], _Off.pt[i + 1]).dis(pt[j], true));
            }
        }
        return ret;
    }

    //-----------半平面交-------------
    //复杂度:O(nlog2(n))
    //#include <algorithm>
    //半平面计算极角函数[如果考虑效率可以用成员变量记录]
    static double hpc_pa(const Line &_Off)
    {
        return atan2(_Off.e.y - _Off.s.y, _Off.e.x - _Off.s.x);
    }
    //半平面交排序函数[优先顺序: 1.极角 2.前面的直线在后面的左边]
    static bool hpc_cmp(const Line &l, const Line &r)
    {
        double lp = hpc_pa(l), rp = hpc_pa(r);
        if(fabs(lp - rp) > eps)
            return lp < rp;
        return Point::xmult(r.s,l.s, r.e) < -eps;
    }
    static int judege(const Line &_lx,const Line &_ly,const Line &_lz)
    {
        Point tmp;
        Line::crossLPt(_lx,_ly,tmp);
        return Point::sgn(Point::xmult(_lz.s,tmp,_lz.e),0);
    }
    //获取半平面交的多边形（多边形的核）
    //参数：向量集合[l]，向量数量[ln];(半平面方向在向量左边）
    //函数运行后如果n[即返回多边形的点数量]为0则不存在半平面交的多边形（不存在区域或区域面积无穷大）
    Polygon& halfPanelCross(Line _Off[], int ln)
    {
        Line dequeue[maxpn];//用于计算的双端队列
        int i, tn, bot, top;
        sort(_Off, _Off + ln, hpc_cmp);
        //平面在向量左边的筛选
        for(i = tn = 1; i < ln; i ++)
            if(fabs(hpc_pa(_Off[i]) - hpc_pa(_Off[i - 1])) > eps)
                _Off[tn ++] = _Off[i];
        ln = tn, n = 0, bot = 0, top = 1;
        dequeue[0] = _Off[0];
        dequeue[1] = _Off[1];
        for(i = 2; i < ln; i ++)
        {
            while(bot < top &&  Polygon::judege(dequeue[top],dequeue[top-1],_Off[i]) > 0)
                top --;
            while(bot < top &&  Polygon::judege(dequeue[bot],dequeue[bot+1],_Off[i]) > 0)
                bot ++;
            dequeue[++ top] = _Off[i];
        }
        while(bot < top && Polygon::judege(dequeue[top],dequeue[top-1],dequeue[bot]) > 0)
            top --;
        while(bot < top && Polygon::judege(dequeue[bot],dequeue[bot+1],dequeue[top]) > 0)
            bot ++;
        //计算交点(注意不同直线形成的交点可能重合)
        if(top <= bot + 1)
            return (*this);
        for(i = bot; i < top; i ++)
            Line::crossLPt(dequeue[i],dequeue[i + 1],pt[n++]);
        if(bot < top + 1)
            Line::crossLPt(dequeue[bot],dequeue[top],pt[n++]);
        return (*this);
    }
};

Point pt[100];
Line ln[100],ls[100];
Polygon py;
int n;

void ml(Line &lx,Line &ly,double t)
{
    Point tmp=lx.e-lx.s,of;
    of=Point(-tmp.y,tmp.x);
    double dis=sqrt(of.x*of.x+of.y*of.y);
    of.x=of.x*t/dis,of.y=of.y*t/dis;
    ly.s=lx.s+of,ly.e=lx.e+of;
}
int sc(double x)
{
    for(int i=0;i<n;i++)
        ml(ln[i],ls[i],x);
    //for(int i=0;i<n;i++)
    //    printf("%.2f %.2f %.2f %.2f\n",ls[i].s.x,ls[i].s.y,ls[i].e.x,ls[i].e.y);
    py.halfPanelCross(ls,n);
    //printf("==%d\n",py.n);
    //for(int i=0;i<py.n;i++)
    //    printf("%.2f %.2f\n",py.pt[i].x,py.pt[i].y);
    return py.n;
}
int main()
{
    while(scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&pt[i].x,&pt[i].y);
        pt[n]=pt[0];
        for(int i=0;i<n;i++)
            ln[i]=Line(pt[i],pt[i+1]);
        //for(int i=0;i<n;i++)
        //    printf("%.2f %.2f %.2f %.2f\n",ln[i].s.x,ln[i].s.y,ln[i].e.x,ln[i].e.y);
        double l=0,r=1e8;
        while(fabs(r-l)>=1e-9)
        {
            double mid=(r+l)/2.0;
            if(sc(mid)) l=mid;
            else    r=mid;
        }
        printf("%.6f\n",r);
    }
    return 0;
}