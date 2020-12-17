#pragma once

#pragma region 头文件引用

// Windows 头文件: 
#include <windows.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include  <math.h>   
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <wingdi.h>
#include <mmsystem.h>
#include <Digitalv.h>
#include <tchar.h>
// 资源头文件
#include "resource.h"
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib,"Winmm.lib")



// TODO:  在此处引用程序需要的其他头文件
#include <vector>
#include <math.h>


#pragma endregion


#pragma region 宏定义

#define WINDOW_TITLEBARHEIGHT	12			//标题栏高度
#define WINDOW_WIDTH			1024		//游戏窗口宽度
#define WINDOW_HEIGHT			713	
#define BACKINTRO_WIDTH			922//游戏窗口高度
#define BACKINTRO_HEIGHT			642		
#define CHOOSE1_WIDTH			922//游戏窗口高度
#define CHOOSE1_HEIGHT			642	
#define ROLE_WIDTH			819//游戏窗口高度
#define ROLE_HEIGHT			570	

#define STAGE_STARTMENU			0		//开始画面的ID
#define STAGE_CHOOSE			1		//第一个游戏场景的ID
#define STAGE_INTRODUCTION      2
#define STAGE_BACKGROUND        3
#define STAGE_1                 4  
#define STAGE_2                 5
#define STAGE_STOP              6
#define STAGE_ROLE_1            7
#define STAGE_ROLE_2            8
#define STAGE_SUCCESS           9
#define STAGE_FAIL              10
#define STAGE_PASS         11
#define STAGE_GUA         12
#define STAGE_FREEWARROLE        13
#define STAGE_FREEWAR       14
#define STAGE_SUCCESS1           15
#define STAGE_SUCCESS2           16

#define UNIT_SIZE_X				32	//单位的宽度
#define UNIT_SIZE_Y				32		//单位的高度
#define UNIT_GOALSIZE_X				64	//单位的宽度
#define UNIT_GOALSIZE_Y				64		//单位的高度
#define UNIT_LAST_FRAME			11		//单位的动画帧最大值

//单位阵营定义
#define UNIT_SIDE_PLAYER			10000	//玩家
#define UNIT_SIDE_COMPUTER			10001	//电脑


//单位类型定义
#define UNIT_TYPE_GOLD		0		//蓐收
#define UNIT_TYPE_WOOD		1		//句芒
#define UNIT_TYPE_WATER		2		//玄冥
#define UNIT_TYPE_FIRE      3		//祝融
#define UNIT_TYPE_SOIL	    4		//后土

//单位状态定义
#define UNIT_STATE_HOLD			0		//静止
#define UNIT_STATE_WALK         1       //行走
#define UNIT_STATE_ATTACK		2		//攻击
#define UNIT_STATE_ATTACKED		3		//被攻击

//单位方向定义
#define UNIT_DIRECT_RIGHT		0		//向右
#define UNIT_DIRECT_LEFT		1		//向左


//背景
//其它定义
#define BUTTON_STARTGAME			1001	//开始游戏按钮ID
#define BUTTON_STARTGAME_WIDTH		200			//开始游戏按钮宽度
#define BUTTON_STARTGAME_HEIGHT		80		//开始游戏按钮高度

#define BUTTON_STOPGAME			1002	//暂停游戏按钮ID
#define BUTTON_STOPGAME_WIDTH		60		
#define BUTTON_STOPGAME_HEIGHT		60		

#define BUTTON_CONTINUEGAME		1003	//继续游戏按钮ID
#define BUTTON_CONTINUEGAME_WIDTH		60		
#define BUTTON_CONTINUEGAME_HEIGHT		60		

#define BUTTON_CHOOSE			1004	
#define BUTTON_CHOOSE_WIDTH		350		
#define BUTTON_CHOOSE_HEIGHT		89		

#define BUTTON_BACKGROUND			1005	
#define BUTTON_BACKGROUND_WIDTH		350		
#define BUTTON_BACKGROUND_HEIGHT		89		

#define BUTTON_INTRODUCTION			1006	
#define BUTTON_INTRODUCTION_WIDTH		350		
#define BUTTON_INTRODUCTION_HEIGHT		89		

#define BUTTON_GUANQIA1			1007	
#define BUTTON_GUANQIA1_WIDTH		340		
#define BUTTON_GUANQIA1_HEIGHT		91	

#define BUTTON_GUANQIA2			1008	
#define BUTTON_GUANQIA2_WIDTH		340		
#define BUTTON_GUANQIA2_HEIGHT		91	

#define BUTTON_BACK			1009	
#define BUTTON_BACK_WIDTH			60	
#define BUTTON_BACK_HEIGHT		60	

#define BUTTON_HOME			1010	
#define BUTTON_HOME_WIDTH			60	
#define BUTTON_HOME_HEIGHT		60	

#define BUTTON_BACK2			1011	
#define BUTTON_BACK2_WIDTH			60	
#define BUTTON_BACK2_HEIGHT		60	

#define BUTTON_FIRE			1012	
#define BUTTON_FIRE_WIDTH			450
#define BUTTON_FIRE_HEIGHT		500

#define BUTTON_WATER			1013	
#define BUTTON_WATER_WIDTH			450
#define BUTTON_WATER_HEIGHT		500

#define BUTTON_SOIL			1014	
#define BUTTON_SOIL_WIDTH			450
#define BUTTON_SOIL_HEIGHT		500

#define BUTTON_WOOD			1015	
#define BUTTON_WOOD_WIDTH			450
#define BUTTON_WOOD_HEIGHT		500

#define BUTTON_GOLD		1016	
#define BUTTON_GOLD_WIDTH			450
#define BUTTON_GOLD_HEIGHT		500

#define BUTTON_HOME2		1017
#define BUTTON_FREEWAR		1018

#define TIMER_GAMETIMER				1		//游戏的默认计时器ID
#define TIMER_GAMETIMER_ELAPSE		30	
#define TIMER_GAMETIMERdeath				2	
//默认计时器刷新间隔的毫秒数

#pragma endregion


#pragma region 结构体声明

// 场景结构体
struct Stage
{
	int stageID;		//场景编号
	HBITMAP bg;			//背景图片
	int timeCountDown;	//游戏时间倒计时
	bool timerOn;		//计时器是否运行（游戏是否被暂停）

};


// 按钮结构体
struct Button
{
	int buttonID;	//按钮编号
	bool visible;	//按钮是否可见
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	int width;		//宽度
	int height;		//高度
};



// 单位结构体
struct Unit
{
	HBITMAP image1;	//图片
	HBITMAP image2;
	HBITMAP image3;

	int* frame_sequence;
	int frame_count;		//帧序列的长度
	int frame_id;			//当前显示的是帧序列的第几个
	

	int side;		//单位阵营
	int type;		//单位类型
	int state;		//单位状态

	int x;			//坐标x
	int y;			//坐标y
	double vx;		//速度x
	double vy;		//速度y
	int health;		//生命值
	double vmax;
	double attack;
	int price;
	bool live;
	bool cartoon;
};
struct Role
{
	HBITMAP image1;	//图片


	int* frame_sequence;
	int frame_count;		//帧序列的长度
	int frame_id;			//当前显示的是帧序列的第几个


	int type;		//单位类型

	int x;			//坐标x
	int y;			//坐标y
	
};



//TODO: 添加游戏需要的更多种数据（地物、砖块等）


#pragma endregion


#pragma region 事件处理函数声明


// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

#pragma endregion


#pragma region //其它游戏状态处理函数声明

// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);

// 添加单位函数
Unit* CreateUnit(int side, int type, int x, int y);
Role* CreateRole(int type, int x, int y);
Role* CreateRole2(int type, int x, int y);



// 初始化场景函数
void InitStage(HWND hWnd, int stageID);

// 刷新单位状态函数
void UpdateUnits(HWND hWnd);



//单位行为函数
void UnitBehaviour_1(Unit* unit);
void UnitBehaviour_2(Unit* unit);
void UnitBehaviour_3(Unit* unit);
void UnitBehaviour_4(Unit* unit);
void UnitBehaviour_5(Unit* unit);

//TODO: 添加游戏需要的更多函数
void Cracking(HWND hWnd);
bool Crackingtest(Unit* unit1,Unit *unit2);
MCI_OPEN_PARMS op;
void Death(HWND hWnd);//检查人物是否死亡
void Death2(HWND hWnd);//创建死亡人物
void Judge(HWND hWnd);//检查玩家是否胜利/失败
void baguaJudge(HWND hWnd);//检查玩家是否没钱了
void UpdateRoles1(HWND hWnd);//播放玩家方选择的人物动画
void UpdateRoles2(HWND hWnd);//播放电脑方人物动画
void UpdateRoles3(HWND hWnd);//播放死亡动画
void wordShow(HDC hdc, int iSize, int iXpos, int iYpos, LPCTSTR a, int iColor, int num);//显示人物/八卦数量

#pragma endregion


#pragma region 绘图函数声明

// 绘图函数
void Paint(HWND hWnd);

// 初始化背景函数
HBITMAP InitBackGround(HWND hWnd, HBITMAP bmp_src);

#pragma endregion