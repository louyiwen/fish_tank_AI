#ifndef ___CH___ATT_H______
#define ___CH___ATT_H______
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include "fish.h"

class others_ch_att
{
	public:
	long hp,dietime,sp,x,y,lastx,lasty;	//
	long maxmove;
	bool status;
	
	others_ch_att();
};

class ch_att:public fish
{
	private:
	long myID,x,y,lev,point,exp,hp,maxhp,att,sp;
	long g[N+1][M+1];
	
	others_ch_att p[MAX_PLAYER+1];
	void getInfo();
	void getMap();
	void assignPoints();
	long targetSpeed();
	bool emergency();
	bool normalAtt();
	bool healthyAtt();
	bool multiHit(long);
	double risk(long x,long y);
	double benefit(long x,long y);
	void run(double);
	long levelUpRequire()const {return (lev+1)*(lev+2)/2-1-exp;}
	bool legal(long x,long y)const {return (1<=x && x<=N && 1<=y && y<=M);}
	long estLevel(long id)const {return (long)(p[id].sp/(log(p[id].dietime+1)+1));}
	
    public:
    
	ch_att():myID(0),x(0),y(0),lev(0),point(0),exp(0),hp(0),maxhp(0),att(0),sp(0){memset(g,0,sizeof(g));}
	
	virtual void init();

    virtual void play();

    virtual void revive(int &,int &){}

};

//可自行增加所需函数所需函数及变量，但需保证上面每个函数的完整与可调用

//不要使用全局变量！！
#endif
