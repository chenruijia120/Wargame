// WarGame.cpp : 定义应用程序的入口点。
//

#include "WarGame.h"

using namespace std;



#pragma region 全局变量

#define MAX_LOADSTRING			100		

// 全局变量: 
HINSTANCE hInst; // 当前窗体实例
WCHAR szTitle[MAX_LOADSTRING]; // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING]; // 主窗口类名




HBITMAP bmp_Grass;		
HBITMAP bmp_Pass;
HBITMAP bmp_Freewar;
HBITMAP bmp_Freewarrole;
HBITMAP bmp_Gua;
HBITMAP bmp_TEW;
HBITMAP bmp_Success;
HBITMAP bmp_Success1;
HBITMAP bmp_Success2;
HBITMAP bmp_Fail;
HBITMAP bmp_Stage1;		
HBITMAP bmp_Stage2;	
HBITMAP bmp_Role;
HBITMAP bmp_Picture;//背景图像资源
HBITMAP bmp_StartButton;
HBITMAP bmp_StopButton;
HBITMAP bmp_ContinueButton;
HBITMAP bmp_ChooseButton;
HBITMAP bmp_IntroductionButton;
HBITMAP bmp_BackgroundButton;
HBITMAP bmp_Choose;
HBITMAP bmp_Introduction;
HBITMAP bmp_Background;
HBITMAP bmp_Guanqia1Button;
HBITMAP bmp_Guanqia2Button;
HBITMAP bmp_BackButton;
HBITMAP bmp_HomeButton;
HBITMAP bmp_BAGUA;//开始按钮图像资源
HBITMAP bmp_WATER;
HBITMAP bmp_WATER1;	
HBITMAP bmp_WATER2;
HBITMAP bmp_WATER3;
HBITMAP bmp_FIRE;
HBITMAP bmp_FIRE1;
HBITMAP bmp_FIRE2;
HBITMAP bmp_FIRE3;
HBITMAP bmp_SOIL;
HBITMAP bmp_SOIL1;
HBITMAP bmp_SOIL2;
HBITMAP bmp_SOIL3;
HBITMAP bmp_GOLD;
HBITMAP bmp_GOLD1;
HBITMAP bmp_GOLD2;
HBITMAP bmp_GOLD3; 
HBITMAP bmp_WOOD;
HBITMAP bmp_WOOD1;
HBITMAP bmp_WOOD2;
HBITMAP bmp_WOOD3;
	//生成的背景图像



Stage* currentStage = NULL; 
Stage* formerStage = NULL; //当前场景状态
vector<Unit*> units;		//单位
vector<Button*> buttons;	//按钮
vector<Role*>roles1;
vector<Role*>roles2;
vector<Role*>roles3;

int mouseX = 0;
int mouseY = 0;
bool mouseDown = false;
bool keyUpDown = false;
bool keyDownDown = false;
bool keyLeftDown = false;
bool keyRightDown = false;
bool keyESCDown = false;
bool choose = false;
bool choose1 = false;
bool choose2 = false;
bool increase_the_roles = true;

int type;
//帧
int FRAMES_PICTURE[5][4] = {7,7,8,12,4,4,7,7,7,7,7,18};
int FRAMES_GOLD_HOLDWALK[] = {0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6};
int FRAMES_GOLD_HOLDWALK_COUNT = 21;
int FRAMES_GOLD_ATTACK[] = { 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13};
int FRAMES_GOLD_ATTACK_COUNT = 42;
int FRAMES_GOLD_ATTACKED[] = { 0,0,0,1,1,1,2,2,2,3,3,3,4.4,4,5,5,5,6,6,6,7,7,7,8,8,8,0,0,0,1,1,1,2,2,2,3,3,3,4.4,4,5,5,5,6,6,6,7,7,7,8,8,8 };
int FRAMES_GOLD_ATTACKED_COUNT=54;

int FRAMES_WOOD_HOLDWALK[] = { 0,0,0,1,1,1,2,2,2,3,3,3};
int FRAMES_WOOD_HOLDWALK_COUNT = 12;
int FRAMES_WOOD_ATTACK[] = { 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6 };
int FRAMES_WOOD_ATTACK_COUNT = 21;
int FRAMES_WOOD_ATTACKED[] = { 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8};
int FRAMES_WOOD_ATTACKED_COUNT = 54;

int FRAMES_WATER_HOLDWALK[] = { 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6};
int FRAMES_WATER_HOLDWALK_COUNT = 21;
int FRAMES_WATER_ATTACK[] = { 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11};
int FRAMES_WATER_ATTACK_COUNT = 36;
int FRAMES_WATER_ATTACKED[] = { 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8, 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8 };
int FRAMES_WATER_ATTACKED_COUNT = 54;

int FRAMES_FIRE_HOLDWALK[] = { 0,0,0,1,1,1,2,2,2,3,3,3};
int FRAMES_FIRE_HOLDWALK_COUNT = 12;
int FRAMES_FIRE_ATTACK[] = { 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6 };
int FRAMES_FIRE_ATTACK_COUNT = 21;
int FRAMES_FIRE_ATTACKED[] = { 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6 };
int FRAMES_FIRE_ATTACKED_COUNT = 42;

int FRAMES_SOIL_HOLDWALK[] = { 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6 };
int FRAMES_SOIL_HOLDWALK_COUNT =21;
int FRAMES_SOIL_ATTACK[] = { 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11,12,12,12,13,13,13,14,14,14,15,15,15,16,16,16,17,17,17 };
int FRAMES_SOIL_ATTACK_COUNT = 54;
int FRAMES_SOIL_ATTACKED[] = { 0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8 };
int FRAMES_SOIL_ATTACKED_COUNT = 54;


// TODO: 在此添加其它全局变量
TCHAR cnum_of_bagua[10];
TCHAR cnum_of_fire[10];
TCHAR cnum_of_water[10];
TCHAR cnum_of_gold[10];
TCHAR cnum_of_soil[10];
TCHAR cnum_of_wood[10];
TCHAR cbaguanotenough[] = _T("您的八卦余额不足");
TCHAR cnum_of_role[10];

int num_of_bagua = 1000;
int num_of_bagua2 = 1000;
int num_of_fire = 0;
int num_of_water = 0;
int num_of_gold = 0;
int num_of_soil = 0;
int num_of_wood = 0;
int num_of_role = 0;
int num_of_role1 = 0;
int num_of_role2 = 0;

int UNIT_SPEED_GOLD = 2.5;		//单位行走速度	
int UNIT_SPEED_WOOD = 1.5;
int UNIT_SPEED_WATER = 3;
int UNIT_SPEED_FIRE = 3;
int UNIT_SPEED_SOIL = 1.5;

int UNIT_ARRACK_GOLD = 1;	
int UNIT_ARRACK_WOOD = 5;
int UNIT_ARRACK_WATER = 10;
int UNIT_ARRACK_FIRE = 5;
int UNIT_ARRACK_SOIL =3;

int stage = 1;
bool stage1 = false;
bool stage2 = false;

double const PI = acos(double(-1));


#pragma endregion


#pragma region Win32程序框架



// 此代码模块中包含的函数的前向声明: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);




int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    mciSendString(L"open ./res/one.mp3 alias music ", NULL, 0, NULL);
	mciSendString(L"play music repeat", NULL, 0, NULL);
	formerStage = new Stage();
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WARGAME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WARGAME));

    MSG msg;

    // 主消息循环: 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WARGAME);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON2));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindow(szWindowClass, szTitle,
	   WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // 设置窗口样式，不可改变大小，不可最大化,
	   CW_USEDEFAULT, 
	   CW_USEDEFAULT,
	   WINDOW_WIDTH,
	   WINDOW_HEIGHT + WINDOW_TITLEBARHEIGHT,
	   nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
		// 初始化游戏窗体
		InitGame(hWnd, wParam, lParam);
		break;
	case WM_KEYDOWN:
		// 键盘按下事件
		KeyDown(hWnd, wParam, lParam);
		break;
	case WM_KEYUP:
		// 键盘松开事件
		KeyUp(hWnd, wParam, lParam);
		break;
	case WM_MOUSEMOVE:
		// 鼠标移动事件
		MouseMove(hWnd, wParam, lParam);
		break;
	case WM_LBUTTONDOWN:
		// 鼠标左键按下事件
		LButtonDown(hWnd, wParam, lParam);
		break;
	case WM_LBUTTONUP:
		// 鼠标左键松开事件
		LButtonUp(hWnd, wParam, lParam);
		break;
	case WM_TIMER:
		// 定时器事件
		if(currentStage!=NULL && currentStage->timerOn) TimerUpdate(hWnd, wParam, lParam);
		break;
    case WM_PAINT:
		// 绘图
		Paint(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


#pragma endregion


#pragma region 事件处理函数

// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam) 
{
	//加载图像资源
	bmp_Grass = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_GRASS));
	bmp_Pass = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_TONGGUAN));
	bmp_Freewar = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_FREEWAR));
	bmp_Freewarrole = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_FREEWARROLE));
	bmp_Gua = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_GUA));
	bmp_TEW = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_TEW));
	bmp_Success = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_SUCCESS));
	bmp_Success1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_SUCCESS1));
	bmp_Success2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_SUCCESS2));
	bmp_Fail = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_FAIL));
	bmp_Stage1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STAGE1));
	bmp_Stage2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STAGE2));
	bmp_Role = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_ROLE));
	bmp_StartButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_START));
	bmp_ContinueButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_CONTINUE));
	bmp_StopButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_STOP));
	bmp_ChooseButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_CHOOSE));
	bmp_BackgroundButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BACKGROUND));
	bmp_IntroductionButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_INTRODUCTION));
	bmp_Choose = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_CHOOSE1));
	bmp_Background = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BACKGROUND1));
	bmp_Introduction = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_INTRODUCTION1));
	bmp_BackButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BACK));
	bmp_HomeButton = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_HOME));
	bmp_Guanqia1Button = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_GUANQIA1));
	bmp_Guanqia2Button = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_GUANQIA2));
	bmp_BAGUA = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_BAGUA));
	bmp_FIRE = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_FIRE));
	bmp_FIRE1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_FIRE1));
	bmp_FIRE2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_FIRE2));
	bmp_FIRE3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_FIRE3));
	bmp_GOLD = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_GOLD));
	bmp_GOLD1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_GOLD1));
	bmp_GOLD2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_GOLD2));
	bmp_GOLD3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_GOLD3));
	bmp_WATER = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_WATER));
	bmp_WATER1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_WATER1));
	bmp_WATER2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_WATER2));
	bmp_WATER3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_WATER3));
	bmp_SOIL = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_SOIL));
	bmp_SOIL1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_SOIL1));
	bmp_SOIL2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_SOIL2));
	bmp_SOIL3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_SOIL3));
	bmp_WOOD = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_WOOD));
	bmp_WOOD1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_WOOD1));
	bmp_WOOD2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_WOOD2));
	bmp_WOOD3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BITMAP_WOOD3));

	//添加按钮

	Button* startButton = CreateButton(BUTTON_STARTGAME, bmp_StartButton, BUTTON_STARTGAME_WIDTH, BUTTON_STARTGAME_HEIGHT, 
		70, 28);
	buttons.push_back(startButton);
	Button* continueButton = CreateButton(BUTTON_CONTINUEGAME, bmp_ContinueButton, BUTTON_CONTINUEGAME_WIDTH, BUTTON_CONTINUEGAME_HEIGHT,
		(WINDOW_WIDTH - BUTTON_CONTINUEGAME_WIDTH) /2+100, (WINDOW_HEIGHT - BUTTON_CONTINUEGAME_HEIGHT) / 2+20);
	buttons.push_back(continueButton);
	Button* stopButton = CreateButton(BUTTON_STOPGAME, bmp_StopButton, BUTTON_STOPGAME_WIDTH, BUTTON_STOPGAME_HEIGHT,
		(WINDOW_WIDTH - BUTTON_STOPGAME_WIDTH) - 20, BUTTON_STOPGAME_HEIGHT-30);
	buttons.push_back(stopButton);
	Button* chooseButton = CreateButton(BUTTON_CHOOSE, bmp_ChooseButton, BUTTON_CHOOSE_WIDTH, BUTTON_CHOOSE_HEIGHT,
		(WINDOW_WIDTH - BUTTON_CHOOSE_WIDTH) / 2, (WINDOW_WIDTH - BUTTON_CHOOSE_HEIGHT) / 2-100);
	buttons.push_back(chooseButton);
	Button* backgroundButton = CreateButton(BUTTON_BACKGROUND, bmp_BackgroundButton, BUTTON_BACKGROUND_WIDTH, BUTTON_BACKGROUND_HEIGHT,
		(WINDOW_WIDTH - BUTTON_BACKGROUND_WIDTH) / 2, (WINDOW_WIDTH - BUTTON_BACKGROUND_HEIGHT) / 2+100);
	buttons.push_back(backgroundButton);
	Button* introductionButton = CreateButton(BUTTON_INTRODUCTION, bmp_IntroductionButton, BUTTON_INTRODUCTION_WIDTH, BUTTON_INTRODUCTION_HEIGHT,
		(WINDOW_WIDTH - BUTTON_INTRODUCTION_WIDTH) / 2, (WINDOW_WIDTH - BUTTON_INTRODUCTION_HEIGHT) / 2);
	buttons.push_back(introductionButton);
	Button* guanqia1Button = CreateButton(BUTTON_GUANQIA1, bmp_Guanqia1Button, BUTTON_GUANQIA1_WIDTH, BUTTON_GUANQIA1_HEIGHT,
		(WINDOW_WIDTH - BUTTON_GUANQIA1_WIDTH) / 2, (WINDOW_HEIGHT - BUTTON_GUANQIA1_HEIGHT) / 2-120);
	buttons.push_back(guanqia1Button);
	Button* guanqia2Button = CreateButton(BUTTON_GUANQIA2, bmp_Guanqia2Button, BUTTON_GUANQIA2_WIDTH, BUTTON_GUANQIA2_HEIGHT,
		(WINDOW_WIDTH - BUTTON_GUANQIA2_WIDTH) / 2, (WINDOW_HEIGHT - BUTTON_GUANQIA2_HEIGHT) / 2+140);
	buttons.push_back(guanqia2Button);
	Button* backButton = CreateButton(BUTTON_BACK, bmp_BackButton, BUTTON_BACK_WIDTH, BUTTON_BACK_HEIGHT,
		(WINDOW_WIDTH - BUTTON_BACK_WIDTH) - 180, (WINDOW_HEIGHT - BUTTON_BACK_HEIGHT)/2  +220);
	buttons.push_back(backButton);
	Button* backButton2 = CreateButton(BUTTON_BACK2, bmp_BackButton, BUTTON_BACK_WIDTH, BUTTON_BACK_HEIGHT,
		(WINDOW_WIDTH - BUTTON_BACK_WIDTH)/2-100, (WINDOW_HEIGHT - BUTTON_BACK_HEIGHT) / 2+20);
	buttons.push_back(backButton2);
	Button* homeButton = CreateButton(BUTTON_HOME, bmp_HomeButton, BUTTON_HOME_WIDTH, BUTTON_HOME_HEIGHT,
		(WINDOW_WIDTH - BUTTON_HOME_WIDTH)/2 , (WINDOW_HEIGHT - BUTTON_HOME_HEIGHT) / 2+20);
	buttons.push_back(homeButton);
	Button* homeButton2 = CreateButton(BUTTON_HOME2, bmp_HomeButton, BUTTON_HOME_WIDTH, BUTTON_HOME_HEIGHT,
		(WINDOW_WIDTH - BUTTON_HOME_WIDTH) / 2, 50);
	buttons.push_back(homeButton2);
	Button* fireButton = CreateButton(BUTTON_FIRE, bmp_FIRE, BUTTON_FIRE_WIDTH, BUTTON_FIRE_HEIGHT,
		10, 195);
	buttons.push_back(fireButton);
	Button* waterButton = CreateButton(BUTTON_WATER, bmp_WATER, BUTTON_FIRE_WIDTH, BUTTON_FIRE_HEIGHT,
		10, 195);
	buttons.push_back(waterButton);
	Button* woodButton = CreateButton(BUTTON_WOOD, bmp_WOOD, BUTTON_FIRE_WIDTH, BUTTON_FIRE_HEIGHT,
		10, 195);
	buttons.push_back(woodButton);
	Button* soilButton = CreateButton(BUTTON_SOIL, bmp_SOIL, BUTTON_FIRE_WIDTH, BUTTON_FIRE_HEIGHT,
		10, 195);
	buttons.push_back(soilButton);
	Button* goldButton = CreateButton(BUTTON_GOLD, bmp_GOLD, BUTTON_FIRE_WIDTH, BUTTON_FIRE_HEIGHT,
		10, 195);
	buttons.push_back(goldButton);
	Button* freewarButton = CreateButton(BUTTON_FREEWAR, bmp_Freewar, BUTTON_GUANQIA1_WIDTH, BUTTON_GUANQIA1_HEIGHT,
		(WINDOW_WIDTH - BUTTON_GUANQIA1_WIDTH) / 2, WINDOW_HEIGHT-BUTTON_GUANQIA1_HEIGHT -50);
	buttons.push_back(freewarButton);
	//初始化背景
	bmp_Picture = InitBackGround(hWnd, bmp_Stage1);


	//初始化开始场景
	InitStage(hWnd, STAGE_STARTMENU);

	//初始化主计时器
	SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);
}

// 键盘按下事件处理函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_UP:
		keyUpDown = true;
		break;
	case VK_DOWN:
		keyDownDown = true;
		break;
	case VK_LEFT:
		keyLeftDown = true;
		break;
	case VK_RIGHT:
		keyRightDown = true;
		break;
	case VK_ESCAPE:
		keyESCDown = true;
		formerStage->stageID = currentStage->stageID;
		InitStage(hWnd, STAGE_STOP);
		break;
	default:
		break;
	}
}

// 键盘松开事件处理函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// TODO
	switch (wParam)
	{
	case VK_UP:
		keyUpDown = false;
		break;
	case VK_DOWN:
		keyDownDown = false;
		break;
	case VK_LEFT:
		keyLeftDown = false;
		break;
	case VK_RIGHT:
		keyRightDown = false;
		break;
	case VK_ESCAPE:
		keyESCDown = false;
		break;
	default:
		break;
	}
}

// 鼠标移动事件处理函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
}

// 鼠标左键按下事件处理函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = true;
	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);
	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	if (currentStage->stageID == STAGE_FREEWARROLE) {
		if (mouseX <= 850 && mouseX >= 776 && mouseY <= 227 && mouseY >= 205 && num_of_role <= 10 && increase_the_roles == true) {
			num_of_role++;
		}
		if (mouseX <= 985 && mouseX >= 895 && mouseY >= 150 && mouseY <= 248 && choose1 == true) {
			choose2 = true;
			choose1 = false;
		}
		if (mouseX <= 985 && mouseX >= 895 && mouseY >= 150 && mouseY <= 248 && increase_the_roles == true&&choose2==false&&num_of_role>0) {
			increase_the_roles = false;
			choose1 = true;
		}
		
	}
	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (currentStage->stageID == STAGE_ROLE_1 || currentStage->stageID == STAGE_ROLE_2) {

			if (num_of_bagua > 0) {
				if (mouseX <= 450 && mouseX >= 365 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_GOLD && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_WOOD || button2->buttonID == BUTTON_WATER || button2->buttonID == BUTTON_FIRE || button2->buttonID == BUTTON_SOIL) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_GOLD && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_GOLD;
					}
				}
				if (choose == true && type == UNIT_TYPE_GOLD && mouseY >= 350 && num_of_bagua >= 150) {
					roles1.push_back(CreateRole(UNIT_TYPE_GOLD, mouseX, mouseY));
					num_of_bagua -= 150;
					num_of_gold++;
					choose = false;
				}
				

				if (mouseX <= 585 && mouseX >= 500 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_WOOD && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_GOLD || button2->buttonID == BUTTON_WATER || button2->buttonID == BUTTON_FIRE || button2->buttonID == BUTTON_SOIL) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_WOOD && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_WOOD;
					}
				}
				if (choose == true && type == UNIT_TYPE_WOOD && mouseY >= 350 && num_of_bagua >= 100) {
					roles1.push_back(CreateRole(UNIT_TYPE_WOOD, mouseX, mouseY));
					num_of_bagua -= 100;
					num_of_wood++;
					choose = false;
				}
			

				if (mouseX <= 720 && mouseX >= 635 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_WATER && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_GOLD || button2->buttonID == BUTTON_WOOD || button2->buttonID == BUTTON_FIRE || button2->buttonID == BUTTON_SOIL) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_WATER && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_WATER;
					}
				}
				if (choose == true && type == UNIT_TYPE_WATER && mouseY >= 350 && num_of_bagua >= 300) {
					roles1.push_back(CreateRole(UNIT_TYPE_WATER, mouseX, mouseY));
					num_of_bagua -= 300;
					num_of_water++;
					choose = false;
				}
				

				if (mouseX <= 853 && mouseX >= 767 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_FIRE && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_GOLD || button2->buttonID == BUTTON_WOOD || button2->buttonID == BUTTON_WATER || button2->buttonID == BUTTON_SOIL) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_FIRE && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_FIRE;
					}
				}
				if (choose == true && type == UNIT_TYPE_FIRE && mouseY >= 350 && num_of_bagua >= 250) {
					roles1.push_back(CreateRole(UNIT_TYPE_FIRE, mouseX, mouseY));
					num_of_bagua -= 250;
					num_of_fire++;
					choose = false;
				}
			

				if (mouseX <= 985 && mouseX >= 900 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_SOIL && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_GOLD || button2->buttonID == BUTTON_WOOD || button2->buttonID == BUTTON_WATER || button2->buttonID == BUTTON_FIRE) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_SOIL && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_SOIL;
					}
				}
				if (choose == true && type == UNIT_TYPE_SOIL && mouseY >= 350 && num_of_bagua >= 200) {
					roles1.push_back(CreateRole(UNIT_TYPE_SOIL, mouseX, mouseY));
					num_of_bagua -= 200;
					num_of_soil++;
					choose = false;
				}
				
			}


		}

		if (currentStage->stageID == STAGE_FREEWARROLE) {
			
			if (choose1==true&&increase_the_roles==false&&num_of_role1<num_of_role) {
				if (mouseX <= 450 && mouseX >= 365 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_GOLD && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_WOOD || button2->buttonID == BUTTON_WATER || button2->buttonID == BUTTON_FIRE || button2->buttonID == BUTTON_SOIL) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_GOLD && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_GOLD;
					}
				}
				if (choose == true && type == UNIT_TYPE_GOLD && mouseY >= 350&&choose1==true) {
					roles1.push_back(CreateRole(UNIT_TYPE_GOLD, mouseX, mouseY));
					num_of_role1++;
					choose = false;
				}
				

				if (mouseX <= 585 && mouseX >= 500 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_WOOD && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_GOLD || button2->buttonID == BUTTON_WATER || button2->buttonID == BUTTON_FIRE || button2->buttonID == BUTTON_SOIL) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_WOOD && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_WOOD;
					}
				}
				if (choose == true && type == UNIT_TYPE_WOOD && mouseY >= 350 && choose1==true) {
					roles1.push_back(CreateRole(UNIT_TYPE_WOOD, mouseX, mouseY));
					num_of_role1++;
					choose = false;
				}

				if (mouseX <= 720 && mouseX >= 635 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_WATER && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_GOLD || button2->buttonID == BUTTON_WOOD || button2->buttonID == BUTTON_FIRE || button2->buttonID == BUTTON_SOIL) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_WATER && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_WATER;
					}
				}
				if (choose == true && type == UNIT_TYPE_WATER && mouseY >= 350 && choose1==true) {
					roles1.push_back(CreateRole(UNIT_TYPE_WATER, mouseX, mouseY));
					num_of_role1++;
					choose = false;
				}
				

				if (mouseX <= 853 && mouseX >= 767 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_FIRE && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_GOLD || button2->buttonID == BUTTON_WOOD || button2->buttonID == BUTTON_WATER || button2->buttonID == BUTTON_SOIL) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_FIRE && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_FIRE;
					}
				}
				if (choose == true && type == UNIT_TYPE_FIRE && mouseY >= 350 && choose1==true) {
					roles1.push_back(CreateRole(UNIT_TYPE_FIRE, mouseX, mouseY));
					num_of_role1++;
					choose = false;
				}
				

				if (mouseX <= 985 && mouseX >= 900 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_SOIL && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_GOLD || button2->buttonID == BUTTON_WOOD || button2->buttonID == BUTTON_WATER || button2->buttonID == BUTTON_FIRE) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_SOIL && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_SOIL;
					}
				}
				if (choose == true && type == UNIT_TYPE_SOIL && mouseY >= 350 && choose1==true) {
					roles1.push_back(CreateRole(UNIT_TYPE_SOIL, mouseX, mouseY));
					num_of_role1++;
					choose = false;
				}
		
			}

			if (choose2 == true && increase_the_roles == false&&choose1==false&& num_of_role2<num_of_role) {
				if (mouseX <= 450 && mouseX >= 365 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_GOLD && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_WOOD || button2->buttonID == BUTTON_WATER || button2->buttonID == BUTTON_FIRE || button2->buttonID == BUTTON_SOIL) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_GOLD && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_GOLD;
					}
				}
				if (choose == true && type == UNIT_TYPE_GOLD && mouseY >= 350 && choose2 == true) {
					roles2.push_back(CreateRole(UNIT_TYPE_GOLD, mouseX, mouseY));
					num_of_role2++;
					choose = false;
				}


				if (mouseX <= 585 && mouseX >= 500 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_WOOD && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_GOLD || button2->buttonID == BUTTON_WATER || button2->buttonID == BUTTON_FIRE || button2->buttonID == BUTTON_SOIL) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_WOOD && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_WOOD;
					}
				}
				if (choose == true && type == UNIT_TYPE_WOOD && mouseY >= 350 && choose2 == true) {
					roles2.push_back(CreateRole(UNIT_TYPE_WOOD, mouseX, mouseY));
					num_of_role2++;
					choose = false;
				}

				if (mouseX <= 720 && mouseX >= 635 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_WATER && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_GOLD || button2->buttonID == BUTTON_WOOD || button2->buttonID == BUTTON_FIRE || button2->buttonID == BUTTON_SOIL) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_WATER && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_WATER;
					}
				}
				if (choose == true && type == UNIT_TYPE_WATER && mouseY >= 350 && choose2 == true) {
					roles2.push_back(CreateRole(UNIT_TYPE_WATER, mouseX, mouseY));
					num_of_role2++;
					choose = false;
				}


				if (mouseX <= 853 && mouseX >= 767 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_FIRE && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_GOLD || button2->buttonID == BUTTON_WOOD || button2->buttonID == BUTTON_WATER || button2->buttonID == BUTTON_SOIL) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_FIRE && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_FIRE;
					}
				}
				if (choose == true && type == UNIT_TYPE_FIRE && mouseY >= 350 && choose2 == true) {
					roles2.push_back(CreateRole(UNIT_TYPE_FIRE, mouseX, mouseY));
					num_of_role2++;
					choose = false;
				}


				if (mouseX <= 985 && mouseX >= 900 && mouseY <= 115 && mouseY >= 30) {
					if (button->buttonID == BUTTON_SOIL && button->visible == false) {
						for (int j = 0; j < buttons.size(); j++)
						{
							Button* button2 = buttons[j];
							if (button2->buttonID == BUTTON_GOLD || button2->buttonID == BUTTON_WOOD || button2->buttonID == BUTTON_WATER || button2->buttonID == BUTTON_FIRE) {
								button2->visible = false;
							}
						}
						button->visible = true;
						choose = false;
					}
					else if (button->buttonID == BUTTON_SOIL && button->visible == true) {
						button->visible = false;
						choose = true;
						type = UNIT_TYPE_SOIL;
					}
				}
				if (choose == true && type == UNIT_TYPE_SOIL && mouseY >= 350 && choose2== true) {
					roles2.push_back(CreateRole(UNIT_TYPE_SOIL, mouseX, mouseY));
					num_of_role2++;
					choose = false;
				}

			}

		}

		if (button->visible)
		{
			if (button->x <= mouseX
				&& button->x + button->width >= mouseX
				&& button->y <= mouseY
				&& button->y + button->height >= mouseY)
			{
				switch (button->buttonID) {
				case BUTTON_CHOOSE:
				{
					formerStage->stageID = currentStage->stageID;//TODO：判断进入哪个关卡
					InitStage(hWnd, STAGE_CHOOSE);
				}
				break;
				case BUTTON_BACKGROUND: {
					formerStage->stageID = currentStage->stageID;
					InitStage(hWnd, STAGE_BACKGROUND);
				}
									  break;
				case BUTTON_INTRODUCTION: {
					formerStage->stageID = currentStage->stageID;
					InitStage(hWnd, STAGE_INTRODUCTION);
				}
										break;
				case BUTTON_STOPGAME: {
					formerStage->stageID = currentStage->stageID;
					InitStage(hWnd, STAGE_STOP);
				}
									break;
				case BUTTON_CONTINUEGAME: {
					if (currentStage->stageID == STAGE_SUCCESS && stage == 1) {
						stage = 2;
						formerStage->stageID = currentStage->stageID;
						InitStage(hWnd, STAGE_ROLE_2);
					}
					if (currentStage->stageID == STAGE_FAIL && stage == 1) {
						stage = 2;
						formerStage->stageID = currentStage->stageID;
						InitStage(hWnd, STAGE_ROLE_2);
					}
					if (currentStage->stageID == STAGE_SUCCESS && stage == 2 && stage1 == true && stage2 == true) {
						stage = 1;
						formerStage->stageID = currentStage->stageID;
						InitStage(hWnd, STAGE_PASS);
					}
					if (currentStage->stageID == STAGE_FAIL && stage == 2) {
						formerStage->stageID = currentStage->stageID;
						InitStage(hWnd, STAGE_CHOOSE);
					}
					if (currentStage->stageID == STAGE_SUCCESS1 || currentStage->stageID == STAGE_SUCCESS2 ) {
						formerStage->stageID = currentStage->stageID;
						InitStage(hWnd, STAGE_CHOOSE);
					}
					if (currentStage->stageID == STAGE_STOP) {
						InitStage(hWnd, formerStage->stageID);
					}
					
				}
										break;
				case BUTTON_GUANQIA1: {
					formerStage->stageID = currentStage->stageID;
					InitStage(hWnd, STAGE_ROLE_1);
					stage = 1;
				}
									break;
				case BUTTON_GUANQIA2: {
					formerStage->stageID = currentStage->stageID;
					InitStage(hWnd, STAGE_ROLE_2);
					stage = 2;
				}
									break;
				case BUTTON_STARTGAME: {
					if (currentStage->stageID == STAGE_ROLE_1) {
						formerStage->stageID = STAGE_1;
						InitStage(hWnd, STAGE_1);
					}
					if (currentStage->stageID == STAGE_ROLE_2) {
						formerStage->stageID = STAGE_2;
						InitStage(hWnd, STAGE_2);
					}
					if (currentStage->stageID == STAGE_FREEWARROLE) {
						formerStage->stageID = STAGE_FREEWAR;
						InitStage(hWnd, STAGE_FREEWAR);
					}
				}
									 break;
				case BUTTON_BACK: {
					if (currentStage->stageID == STAGE_CHOOSE || currentStage->stageID == STAGE_BACKGROUND || currentStage->stageID == STAGE_INTRODUCTION) {
						formerStage->stageID = currentStage->stageID;
						InitStage(hWnd, STAGE_STARTMENU);
					}
					
				}
								break;
				case BUTTON_HOME: {
					formerStage->stageID = currentStage->stageID;
					InitStage(hWnd, STAGE_STARTMENU);

				}
								break;
				case BUTTON_HOME2: {
					formerStage->stageID = currentStage->stageID;
					InitStage(hWnd, STAGE_STARTMENU);

				}
								break;
				case BUTTON_BACK2:
				{if ((currentStage->stageID == STAGE_FAIL || currentStage->stageID == STAGE_SUCCESS || currentStage->stageID == STAGE_1) && stage == 1) {
					vector <Unit*>().swap(units);
					formerStage->stageID = currentStage->stageID;
					InitStage(hWnd, STAGE_ROLE_1);
				}
				if ((currentStage->stageID == STAGE_FAIL || currentStage->stageID == STAGE_SUCCESS || currentStage->stageID == STAGE_2) && stage == 2) {
					vector <Unit*>().swap(units);
					formerStage->stageID = currentStage->stageID;
					InitStage(hWnd, STAGE_ROLE_2);
				}		
				if (formerStage->stageID == STAGE_1) {
					formerStage->stageID = STAGE_ROLE_1;
					vector <Unit*>().swap(units);
					InitStage(hWnd, STAGE_ROLE_1);
				}
				if (formerStage->stageID == STAGE_2) {
					formerStage->stageID = STAGE_ROLE_2;
					vector <Unit*>().swap(units);
					InitStage(hWnd, STAGE_ROLE_2);
				}
				if (formerStage->stageID == STAGE_FREEWAR) {
					formerStage->stageID = STAGE_FREEWARROLE;
					vector <Unit*>().swap(units);
					InitStage(hWnd, STAGE_FREEWARROLE);
				}
				if (currentStage->stageID == STAGE_FREEWARROLE|| currentStage->stageID == STAGE_ROLE_1|| currentStage->stageID == STAGE_ROLE_2) {
					InitStage(hWnd, STAGE_CHOOSE);
				}
				else {
					InitStage(hWnd, STAGE_STARTMENU);
				}break;
				}
				case BUTTON_FREEWAR: {
					formerStage->stageID = currentStage->stageID;
					InitStage(hWnd, STAGE_FREEWARROLE);
				}
								   break;
				}
			}

		}
	}
}

// 鼠标左键松开事件处理函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = false;
}

// 定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	UpdateUnits(hWnd);
	UpdateRoles1(hWnd);
	UpdateRoles2(hWnd);
	UpdateRoles3(hWnd);
	Death(hWnd);
	Death2(hWnd);
	Judge(hWnd);
	Cracking(hWnd);
	baguaJudge(hWnd);
	InvalidateRect(hWnd, NULL, FALSE);
}


#pragma endregion


#pragma region //其它游戏状态处理函数



//TODO: 添加游戏需要的更多函数
void Cracking(HWND hWnd)
{
	bool yes = false;
	double tx, ty;
	for (int i = 0; i < units.size(); i++) {
		for (int j = 0; j < units.size(); j++) {
			yes = false;
			yes = Crackingtest(units[i], units[j]);
			if (yes == true) {
				tx = units[i]->vx;
				ty = units[i]->vy;
				units[i]->vx = -units[j]->vx;
				units[i]->vy = -units[j]->vy;
				units[j]->vx = -tx;
				units[j]->vy = -ty;
			}
		}

	}
	for (int i = 0; i < units.size(); i++) {
		if (units[i]->x < 5 ) {
			units[i]->x = units[i]->x+20;
		}
		if (units[i]->x > 1010) {
			units[i]->x = units[i]->x - 20;
		}
		if (units[i]->y < 350 ) {
			units[i]->y = units[i]->y + 20;
		}
		if (units[i]->y > 708) {
			units[i]->y = units[i]->y - 20;
		}
	}
}
bool Crackingtest(Unit* unit1, Unit* unit2) {
	bool yes = false;
	if (abs(unit1->x - unit2->x) <= UNIT_SIZE_X && abs(unit1->y - unit2->y) <= UNIT_SIZE_Y){
	yes = true;
}
return yes;
}
void wordShow(HDC hdc, int iSize, int iXpos, int iYpos, LPCTSTR a, int iColor,int num)
{
	LOGFONT   logfont;       //改变输出字体
	ZeroMemory(&logfont, sizeof(LOGFONT));
	logfont.lfCharSet = GB2312_CHARSET;
	logfont.lfHeight = iSize;      //设置字体的大小
	HFONT   hFont = CreateFontIndirect(&logfont);
	SetTextColor(hdc, iColor);
	SetBkMode(hdc, TRANSPARENT);
	SelectObject(hdc, hFont);
	TextOut(hdc, iXpos, iYpos, a,num);
	DeleteObject(hFont);
}
// 添加按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y)
{
	Button* button = new Button();
	button->buttonID = buttonID;
	button->img = img;
	button->width = width;
	button->height = height;
	button->x = x;
	button->y = y;

	button->visible = false;
	return button;
}

// 添加主角函数
Unit* CreateUnit(int side, int type, int x, int y)
{
	Unit* unit = new Unit();
	unit->side = side;
	unit->type=type;
	unit->live = true;
	unit->cartoon = false;
	switch (unit->type) {
	case UNIT_TYPE_FIRE:
			unit->image1 = bmp_FIRE1;
			unit->image2 = bmp_FIRE2;
			unit->image3 = bmp_FIRE3;
			unit->frame_sequence = FRAMES_FIRE_HOLDWALK;
			unit->frame_count = FRAMES_FIRE_HOLDWALK_COUNT;
			unit->attack = UNIT_ARRACK_FIRE;
			unit->health = 1500;
			break;
	case UNIT_TYPE_WATER:
		unit->image1 = bmp_WATER1;
		unit->image2 = bmp_WATER2;
		unit->image3 = bmp_WATER3;
		unit->frame_sequence = FRAMES_WATER_HOLDWALK;
		unit->frame_count = FRAMES_WATER_HOLDWALK_COUNT;
		unit->attack = UNIT_ARRACK_WATER;
		unit->health = 1000;
		break; 
	case UNIT_TYPE_WOOD:
			unit->image1 = bmp_WOOD1;
			unit->image2 = bmp_WOOD2;
			unit->image3 = bmp_WOOD3;
			unit->frame_sequence = FRAMES_WOOD_HOLDWALK;
			unit->frame_count = FRAMES_WOOD_HOLDWALK_COUNT;
			unit->attack = UNIT_ARRACK_WOOD;
			unit->health = 2000;
			break;
	case UNIT_TYPE_SOIL:
		unit->image1 = bmp_SOIL1;
		unit->image2 = bmp_SOIL2;
		unit->image3 = bmp_SOIL3;
		unit->frame_sequence = FRAMES_SOIL_HOLDWALK;
		unit->frame_count = FRAMES_SOIL_HOLDWALK_COUNT;
		unit->attack = UNIT_ARRACK_SOIL;
		unit->health = 1500;
		break;
	case UNIT_TYPE_GOLD:
		unit->image1 = bmp_GOLD1;
		unit->image2 = bmp_GOLD2;
		unit->image3 = bmp_GOLD3;
		unit->frame_sequence = FRAMES_GOLD_HOLDWALK;
		unit->frame_count = FRAMES_GOLD_HOLDWALK_COUNT;
		unit->attack = UNIT_ARRACK_GOLD;
		unit->health = 2500;
		break;
	}
	unit->state = UNIT_STATE_HOLD;
	unit->frame_id = 0;

	unit->x = x;
	unit->y = y;
	unit->vx = 0.5;
	unit->vy = 0.5;
	return unit;
}
Role* CreateRole(int type, int x, int y){
	Role* role = new Role();
	role->type = type;
	switch (role->type) {
	case UNIT_TYPE_FIRE:
		role->image1 = bmp_FIRE1;
		role->frame_sequence = FRAMES_FIRE_HOLDWALK;
		role->frame_count = FRAMES_FIRE_HOLDWALK_COUNT;
		break;
	case UNIT_TYPE_WATER:
		role->image1 = bmp_WATER1;
		role->frame_sequence = FRAMES_WATER_HOLDWALK;
		role->frame_count = FRAMES_WATER_HOLDWALK_COUNT;
		break;
	case UNIT_TYPE_WOOD:
		role->image1 = bmp_WOOD1;
		role->frame_sequence = FRAMES_WOOD_HOLDWALK;
		role->frame_count = FRAMES_WOOD_HOLDWALK_COUNT;
		break;
	case UNIT_TYPE_SOIL:
		role->image1 = bmp_SOIL1;
		role->frame_sequence = FRAMES_SOIL_HOLDWALK;
		role->frame_count = FRAMES_SOIL_HOLDWALK_COUNT;
		break;
	case UNIT_TYPE_GOLD:
		role->image1 = bmp_GOLD1;
		role->frame_sequence = FRAMES_GOLD_HOLDWALK;
		role->frame_count = FRAMES_GOLD_HOLDWALK_COUNT;
		break;
	}
	role->frame_id = 0;

	role->x = x;
	role->y = y;
	return role;
}
Role* CreateRole2(int type, int x, int y) {
	Role* role = new Role();
	role->type = type;
	switch (role->type) {
	case UNIT_TYPE_FIRE:
		role->image1 = bmp_FIRE3;
		role->frame_sequence = FRAMES_FIRE_ATTACKED;
		role->frame_count = FRAMES_FIRE_ATTACKED_COUNT;
		break;
	case UNIT_TYPE_WATER:
		role->image1 = bmp_WATER3;
		role->frame_sequence = FRAMES_WATER_ATTACKED;
		role->frame_count = FRAMES_WATER_ATTACKED_COUNT;
		break;
	case UNIT_TYPE_WOOD:
		role->image1 = bmp_WOOD3;
		role->frame_sequence = FRAMES_WOOD_ATTACKED;
		role->frame_count = FRAMES_WOOD_ATTACKED_COUNT;
		break;
	case UNIT_TYPE_SOIL:
		role->image1 = bmp_SOIL3;
		role->frame_sequence = FRAMES_SOIL_ATTACKED;
		role->frame_count = FRAMES_SOIL_ATTACKED_COUNT;
		break;
	case UNIT_TYPE_GOLD:
		role->image1 = bmp_GOLD3;
		role->frame_sequence = FRAMES_GOLD_ATTACKED;
		role->frame_count = FRAMES_GOLD_ATTACKED_COUNT;
		break;
	}
	role->frame_id = 0;

	role->x = x;
	role->y = y;
	return role;
}

// 初始化游戏场景函数
void InitStage(HWND hWnd, int stageID)
{
	// 初始化场景实例
	if (currentStage != NULL) delete currentStage;
	currentStage = new Stage();
	currentStage->stageID = stageID;
	

	if (stageID == STAGE_STARTMENU) {
		currentStage->bg = bmp_Picture;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		//显示开始界面的按钮
		for(int i=0;i<buttons.size();i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_CHOOSE|| button->buttonID == BUTTON_BACKGROUND|| button->buttonID == BUTTON_INTRODUCTION )
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


	}
	else if ((stageID >= STAGE_1 && stageID <= STAGE_2)||stageID==STAGE_FREEWAR) //TODO：添加多个游戏场景
	{
		currentStage->bg = bmp_Stage2;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = true;

		//显示游戏界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_STOPGAME) //TODO：加载游戏界面需要的按钮
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}


		// 按场景初始化单位
		switch (stageID) {
		case STAGE_1:
			units.push_back(CreateUnit(UNIT_SIDE_COMPUTER, UNIT_TYPE_FIRE, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 - 40));
			units.push_back(CreateUnit(UNIT_SIDE_COMPUTER, UNIT_TYPE_WATER, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 +30));
			units.push_back(CreateUnit(UNIT_SIDE_COMPUTER, UNIT_TYPE_WOOD, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 100));
			units.push_back(CreateUnit(UNIT_SIDE_COMPUTER, UNIT_TYPE_GOLD, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 170));
			units.push_back(CreateUnit(UNIT_SIDE_COMPUTER, UNIT_TYPE_SOIL, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 240));
			for (int i = 0; i < roles1.size(); i++)
			{
				Role* role = roles1[i];
				switch (role->type) {
				case UNIT_TYPE_GOLD:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_GOLD, role->x, role->y));
					break;
				case UNIT_TYPE_WOOD:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_WOOD, role->x, role->y));
					break;
				case UNIT_TYPE_WATER:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_WATER, role->x, role->y));
					break;
				case UNIT_TYPE_FIRE:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_FIRE, role->x, role->y));
					break;
				case UNIT_TYPE_SOIL:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_SOIL, role->x, role->y));
					break;
				}

			}
			roles1.clear();
			roles2.clear();
			roles3.clear();
			break;
		default:
			break;

		case STAGE_2:
			units.push_back(CreateUnit(UNIT_SIDE_COMPUTER,UNIT_TYPE_FIRE, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 30));
			units.push_back(CreateUnit(UNIT_SIDE_COMPUTER,UNIT_TYPE_FIRE, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 100));
			units.push_back(CreateUnit(UNIT_SIDE_COMPUTER,UNIT_TYPE_WOOD, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 170));
			units.push_back(CreateUnit(UNIT_SIDE_COMPUTER,UNIT_TYPE_WATER, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 230));
			units.push_back(CreateUnit(UNIT_SIDE_COMPUTER,UNIT_TYPE_WATER, WINDOW_WIDTH / 3 * 2 - 150, WINDOW_HEIGHT / 2 + 100));
			units.push_back(CreateUnit(UNIT_SIDE_COMPUTER,UNIT_TYPE_SOIL, WINDOW_WIDTH / 3 * 2 - 150, WINDOW_HEIGHT / 2 + 170));
			for (int i = 0; i < roles1.size(); i++)
			{
				Role* role = roles1[i];
				switch (role->type) {
				case UNIT_TYPE_GOLD:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_GOLD, role->x, role->y));
					break;
				case UNIT_TYPE_WOOD:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_WOOD, role->x, role->y));
					break;
				case UNIT_TYPE_WATER:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_WATER, role->x, role->y));
					break;
				case UNIT_TYPE_FIRE:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_FIRE, role->x, role->y));
					break;
				case UNIT_TYPE_SOIL:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_SOIL, role->x, role->y));
					break;
				}

			}
			roles1.clear();
			roles2.clear();
			roles3.clear();
			break;
		case STAGE_FREEWAR: {
			for (int i = 0; i < roles1.size(); i++)
			{
				Role* role = roles1[i];
				switch (role->type) {
				case UNIT_TYPE_GOLD:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_GOLD, role->x, role->y));
					break;
				case UNIT_TYPE_WOOD:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_WOOD, role->x, role->y));
					break;
				case UNIT_TYPE_WATER:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_WATER, role->x, role->y));
					break;
				case UNIT_TYPE_FIRE:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_FIRE, role->x, role->y));
					break;
				case UNIT_TYPE_SOIL:
					units.push_back(CreateUnit(UNIT_SIDE_PLAYER, UNIT_TYPE_SOIL, role->x, role->y));
					break;
				}

			}
			for (int i = 0; i < roles2.size(); i++)
			{
				Role* role = roles2[i];
				switch (role->type) {
				case UNIT_TYPE_GOLD:
					units.push_back(CreateUnit(UNIT_SIDE_COMPUTER, UNIT_TYPE_GOLD, role->x, role->y));
					break;
				case UNIT_TYPE_WOOD:
					units.push_back(CreateUnit(UNIT_SIDE_COMPUTER, UNIT_TYPE_WOOD, role->x, role->y));
					break;
				case UNIT_TYPE_WATER:
					units.push_back(CreateUnit(UNIT_SIDE_COMPUTER, UNIT_TYPE_WATER, role->x, role->y));
					break;
				case UNIT_TYPE_FIRE:
					units.push_back(CreateUnit(UNIT_SIDE_COMPUTER, UNIT_TYPE_FIRE, role->x, role->y));
					break;
				case UNIT_TYPE_SOIL:
					units.push_back(CreateUnit(UNIT_SIDE_COMPUTER, UNIT_TYPE_SOIL, role->x, role->y));
					break;
				}

			}
			roles1.clear();
			roles2.clear();
			roles3.clear();
			break;
		}
		}
	}
	
	
	else if (stageID >= STAGE_ROLE_1 && stageID <= STAGE_ROLE_2) //TODO：添加多个游戏场景
	{
		currentStage->bg = bmp_Stage2;
		currentStage->timeCountDown = 10000;
		currentStage->timerOn = true;
		num_of_bagua = num_of_bagua2;
		num_of_fire = 0;
		num_of_gold = 0;
		num_of_water = 0;
		num_of_wood= 0;
		num_of_soil = 0;
		vector <Role*>().swap(roles1);
		vector <Role*>().swap(roles2);
		vector <Unit*>().swap(units);
		//显示游戏界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_STARTGAME) //TODO：加载游戏界面需要的按钮
			{
				button->visible = true;
			}
			else if(button->buttonID!=BUTTON_FIRE&& button->buttonID != BUTTON_WATER&& button->buttonID != BUTTON_WOOD&& button->buttonID != BUTTON_SOIL&& button->buttonID != BUTTON_GOLD)
			{
				button->visible = false;
			}
		}
		if (currentStage->stageID == STAGE_ROLE_1) {
			roles2.push_back(CreateRole(UNIT_TYPE_FIRE, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 - 40));
			roles2.push_back(CreateRole(UNIT_TYPE_WOOD, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 30));
			roles2.push_back(CreateRole(UNIT_TYPE_WATER, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 100));
			roles2.push_back(CreateRole(UNIT_TYPE_SOIL, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 170));
			roles2.push_back(CreateRole(UNIT_TYPE_GOLD, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 240));
		}
		else {
			roles2.push_back(CreateRole(UNIT_TYPE_FIRE, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 30));
			roles2.push_back(CreateRole(UNIT_TYPE_FIRE, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 +100));
			roles2.push_back(CreateRole(UNIT_TYPE_WOOD, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 170));
			roles2.push_back(CreateRole(UNIT_TYPE_WATER, WINDOW_WIDTH / 3 * 2, WINDOW_HEIGHT / 2 + 230));
			roles2.push_back(CreateRole(UNIT_TYPE_WATER, WINDOW_WIDTH / 3 * 2-150, WINDOW_HEIGHT / 2 + 100));
			roles2.push_back(CreateRole(UNIT_TYPE_SOIL, WINDOW_WIDTH / 3 * 2-150, WINDOW_HEIGHT / 2 + 170));
		}
		


	}
	else if (stageID ==STAGE_CHOOSE) {
		currentStage->bg = bmp_Choose;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		//显示开始界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_GUANQIA1 || button->buttonID == BUTTON_GUANQIA2 || button->buttonID == BUTTON_BACK)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
			if (stage1 == true && stage2 == true) {
				if (button->buttonID == BUTTON_FREEWAR) {
				button->visible = true;
				}
			}
		}
	 }
	else if (stageID == STAGE_BACKGROUND) {
		currentStage->bg = bmp_Background;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		//显示开始界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_BACK)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_INTRODUCTION) {
		currentStage->bg = bmp_Introduction;
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		//显示开始界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_BACK)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_STOP) {
	currentStage->bg = bmp_Choose;
	currentStage->timeCountDown = 0;
	currentStage->timerOn = false;

	//显示开始界面的按钮
	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->buttonID == BUTTON_CONTINUEGAME || button->buttonID == BUTTON_BACK2 || button->buttonID == BUTTON_HOME)
		{
			button->visible = true;
		}
		else
		{
			button->visible = false;
		}
	}
	}
	else if (stageID == STAGE_SUCCESS||stageID == STAGE_FAIL||stageID==STAGE_SUCCESS1||stageID==STAGE_SUCCESS2) {
	currentStage->bg = bmp_Choose;
	currentStage->timeCountDown = 0;
	currentStage->timerOn = false;
	/*if (currentStage->stageID == STAGE_SUCCESS) {
		mciSendString(L"open ./res/win.mp3 alias music ", NULL, 0, NULL);
		mciSendString(L"play music", NULL, 0, NULL);
	}
	else {
		mciSendString(L"open ./res/fail.mp3 alias music ", NULL, 0, NULL);
		mciSendString(L"play music", NULL, 0, NULL);
	}*/
	//显示开始界面的按钮
	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->buttonID == BUTTON_CONTINUEGAME || button->buttonID == BUTTON_BACK2 || button->buttonID == BUTTON_HOME)
		{
			button->visible = true;
		}
		else
		{
			button->visible = false;
		}
	}
	}
	else if (stageID == STAGE_PASS) {
	currentStage->bg = bmp_Choose;
	currentStage->timeCountDown = 0;
	currentStage->timerOn = false;
	num_of_bagua = 1000;
	num_of_bagua2 = 1000;
	mciSendString(L"open ./res/winfinally.mp3 alias music ", NULL, 0, NULL);
	mciSendString(L"play music", NULL, 0, NULL);
	//显示开始界面的按钮
	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->buttonID == BUTTON_HOME2||button->buttonID==BUTTON_FREEWAR)
		{
			button->visible = true;
		}
		else
		{
			button->visible = false;
		}
	}
	}
	else if (stageID == STAGE_GUA) {
	currentStage->bg = bmp_Choose;
	currentStage->timeCountDown = 0;
	currentStage->timerOn = false;
	num_of_bagua = 1000;
	num_of_bagua2 = 1000;
	mciSendString(L"open ./res/failfinally.mp3 alias music ", NULL, 0, NULL);
	mciSendString(L"play music", NULL, 0, NULL);
	//显示开始界面的按钮
	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->buttonID == BUTTON_HOME2)
		{
			button->visible = true;
		}
		else
		{
			button->visible = false;
		}
	}
	}
	else if (stageID == STAGE_STOP) {
	currentStage->bg = bmp_Choose;
	currentStage->timeCountDown = 0;
	currentStage->timerOn = false;

	//显示开始界面的按钮
	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->buttonID == BUTTON_CONTINUEGAME || button->buttonID == BUTTON_BACK2 || button->buttonID == BUTTON_HOME)
		{
			button->visible = true;
		}
		else
		{
			button->visible = false;
		}
	}
	}
	else if (stageID == STAGE_FREEWARROLE) 
	{
	currentStage->bg = bmp_Stage2;
	currentStage->timeCountDown = 10000;
	currentStage->timerOn = true;
	num_of_role = 0;
	num_of_role1 = 0;
	num_of_role2 = 0;
	choose1 = false;
	choose2 = false;
	increase_the_roles = true;
	vector <Role*>().swap(roles1);
	vector <Role*>().swap(roles2);
	vector <Unit*>().swap(units);
	//显示游戏界面的按钮
	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->buttonID == BUTTON_STARTGAME) //TODO：加载游戏界面需要的按钮
		{
			button->visible = true;
		}
		else if (button->buttonID != BUTTON_FIRE && button->buttonID != BUTTON_WATER && button->buttonID != BUTTON_WOOD && button->buttonID != BUTTON_SOIL && button->buttonID != BUTTON_GOLD)
		{
			button->visible = false;
		}
	}
	



	}
	//刷新显示
	InvalidateRect(hWnd, NULL, FALSE);
}

void UpdateRoles1(HWND hWnd)
{
	for (int i = 0; i < roles1.size(); i++) {
		Role* role = roles1[i];
		role->frame_id++;
		role->frame_id = role->frame_id % role->frame_count;
	}
	InvalidateRect(hWnd, NULL, FALSE);
}
void UpdateRoles2(HWND hWnd)
{
	for (int i = 0; i < roles2.size(); i++) {
		Role* role = roles2[i];
		role->frame_id++;
		role->frame_id = role->frame_id % role->frame_count;
	}
	InvalidateRect(hWnd, NULL, FALSE);
}
void UpdateRoles3(HWND hWnd)
{
	for (int i = 0; i < roles3.size(); i++) {
		Role* role = roles3[i];
		if (role->frame_id < role->frame_count-1)
		{
			role->frame_id++;
		}
		
	}
	InvalidateRect(hWnd, NULL, FALSE);
}
// 刷新单位状态函数
void UpdateUnits(HWND hWnd)
{
	for(int i=0;i<units.size();i++){
		Unit* unit = units[i];
		if (unit->live == true) {



			//根据单位类型选择行为函数
			switch (unit->type) {
			case UNIT_TYPE_GOLD:
				UnitBehaviour_1(unit);
				break;
			case UNIT_TYPE_WOOD:
				UnitBehaviour_2(unit);
				break;
			case UNIT_TYPE_WATER:
				UnitBehaviour_3(unit);
				break;
			case UNIT_TYPE_FIRE:
				UnitBehaviour_4(unit);
				break;
			case UNIT_TYPE_SOIL:
				UnitBehaviour_5(unit);

				break;
			}
		}


	}


}
void Death(HWND hWnd) {
	for (int i = 0; i < units.size(); i++) {
		Unit* unit = units[i];
		if (unit->health <= 0) {
				unit->live = false;
			}
	}
}
void Death2(HWND hWnd) {
	for (int i = 0; i < units.size(); i++) {
		Unit* unit = units[i];
		if (unit->live == false && unit->cartoon == false) {
			unit->cartoon = true;
			switch (unit->type) {
			case UNIT_TYPE_GOLD:
				roles3.push_back(CreateRole2(UNIT_TYPE_GOLD, unit->x, unit->y));
				break;
			case UNIT_TYPE_WOOD:
				roles3.push_back(CreateRole2(UNIT_TYPE_WOOD, unit->x, unit->y));
				break;
			case UNIT_TYPE_WATER:
				roles3.push_back(CreateRole2(UNIT_TYPE_WATER, unit->x, unit->y));
				break;
			case UNIT_TYPE_FIRE:
				roles3.push_back(CreateRole2(UNIT_TYPE_FIRE, unit->x, unit->y));
				break;
			case UNIT_TYPE_SOIL:
				roles3.push_back(CreateRole2(UNIT_TYPE_SOIL, unit->x, unit->y));
				break;
			}
		}
	}
}
void Judge(HWND hWnd) {
	int l1 = 0, l2 = 0;
	if (currentStage->stageID == STAGE_1 || currentStage->stageID == STAGE_2) {
		for (int i = 0; i < units.size(); i++) {
			Unit* unit = units[i];
			if (unit->side == UNIT_SIDE_COMPUTER&&unit->live==true) {
				l1++;
			}
			if(unit->side == UNIT_SIDE_PLAYER&& unit->live == true) {
				l2++;
			}
		}
		if (l1 == 0&&l2!=0) {
			int a = 0;
			for (int i = 0; i < roles3.size(); i++) {
				Role* role = roles3[i];
				if (role->frame_id == role->frame_count-1) {
					a++;
				}
			}
			if (a >= roles3.size() - 1||a==0) {
				num_of_bagua2 += 600;
			num_of_bagua = num_of_bagua2;
			if (currentStage->stageID == STAGE_1) {
				stage1 = true;
			}
			else {
				stage2 = true;
			}
			formerStage->stageID = currentStage->stageID;
			InitStage(hWnd, STAGE_SUCCESS);
			}
			
		}
		if(l2==0&&l1!=0) {
			int b = 0;
			for (int i = 0; i < roles3.size(); i++) {
				Role* role = roles3[i];
				if (role->frame_id == role->frame_count - 1) {
					b++;
				}
			}
			if (b >= roles3.size() - 1||b==0) {
				num_of_bagua2 -= 400;
				num_of_bagua = num_of_bagua2;
				formerStage->stageID = currentStage->stageID;
				InitStage(hWnd, STAGE_FAIL);
			}
		}
	}
	if (currentStage->stageID == STAGE_FREEWAR) {
		for (int i = 0; i < units.size(); i++) {
			Unit* unit = units[i];
			if (unit->side == UNIT_SIDE_COMPUTER && unit->live == true) {
				l1++;
			}
			if (unit->side == UNIT_SIDE_PLAYER && unit->live == true) {
				l2++;
			}
		}
		if (l1 == 0 && l2 != 0) {
			int a = 0;
			for (int i = 0; i < roles3.size(); i++) {
				Role* role = roles3[i];
				if (role->frame_id == role->frame_count - 1) {
					a++;
				}
			}
			if (a >= roles3.size() - 1||a==0) {

				formerStage->stageID = currentStage->stageID;
				InitStage(hWnd, STAGE_SUCCESS1);
			}

		}
		if (l2 == 0 && l1 != 0) {
			int b = 0;
			for (int i = 0; i < roles3.size(); i++) {
				Role* role = roles3[i];
				if (role->frame_id == role->frame_count - 1) {
					b++;
				}
			}
			if (b >= roles3.size() - 1 || b == 0) {
				formerStage->stageID = currentStage->stageID;
				InitStage(hWnd, STAGE_SUCCESS2);
			}
		}
	}
}
void baguaJudge(HWND hWnd) {
	if (num_of_bagua2 <= 0) {
		InitStage(hWnd, STAGE_GUA);
	}
}
//单位行为函数
void UnitBehaviour_1(Unit* unit){
	bool yes = false;
	vector<Unit*> goals1;
	vector<Unit*> goals2;
	vector<Unit*> goals3;
	vector<Unit*> goals4;
	double dirX;
	double dirY;
	double dirLen;
	double v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
	for (int i = 0; i < units.size(); i++) {
		Unit* unitother = units[i];
		if (unitother->type == UNIT_TYPE_WATER && unitother->side == unit->side&& unitother->live==true) {
			yes = true;
			goals1.push_back(units[i]);
		}
		if (unitother->type == UNIT_TYPE_WOOD && unitother->side == unit->side && unitother->live == true) {
			goals2.push_back(units[i]);
		}
		if (unitother->type == UNIT_TYPE_WOOD && unitother->side != unit->side && unitother->live == true) {
			goals3.push_back(units[i]);
		}
		if (unitother->type == UNIT_TYPE_GOLD && unitother->side != unit->side && unitother->live == true) {
			goals4.push_back(units[i]);
		}
	}
	if (yes != true) {
		for (int i = 0; i < units.size(); i++) {
			Unit* unitother = units[i];
			if (unitother->side != unit->side&& unitother->live == true) {
				yes= true;
				goals1.push_back(units[i]);
			}
		}
	}
	if (yes == true) {
		dirX = goals1[0]->x - unit->x;
		dirY = goals1[0]->y - unit->y;
		dirLen = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
	}
	else {
		dirLen = 0;
	}
	
	//判断当前状态, 以及判断是否需要状态变化
	int next_state = unit->state;
	switch (unit->state) {
	case UNIT_STATE_HOLD:
		if (dirLen > 120) {
			next_state = UNIT_STATE_WALK;
		}
		else if (dirLen <= 120) {
			next_state = UNIT_STATE_ATTACK;
		}
		else {
			for (int i = 0; i < goals3.size(); i++) {
				Unit* unitother = goals3[i];
				unitother->attack = 2;
			}
			for (int i = 0; i < goals1.size(); i++) {
				Unit* unitother = goals1[i];
				unitother->attack = 10;
			}
		}
		break;
	case UNIT_STATE_WALK:
		if (dirLen == 0) {
			next_state = UNIT_STATE_HOLD;
		}
		else if (dirLen <= 120) {
			next_state = UNIT_STATE_ATTACK;
		}
		else {
			v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
			if (v < UNIT_SPEED_GOLD) {
				unit->vx = dirX / dirLen * UNIT_SPEED_GOLD*0.6+unit->vx;
				unit->vy = dirY / dirLen * UNIT_SPEED_GOLD*0.6+ unit->vy;
			}
			else {
				if (dirX * unit->vx < 0) {
					unit->vx = dirX / dirLen * UNIT_SPEED_GOLD+ unit->vx;
					unit->vy = dirY / dirLen * UNIT_SPEED_GOLD + unit->vy;
				}
				if (dirX * unit->vx > 0) {
					unit->vx = dirX / dirLen * UNIT_SPEED_GOLD;
					unit->vy = dirY / dirLen * UNIT_SPEED_GOLD;
				}
			}
			
		}
		break;
	case UNIT_STATE_ATTACK:
		if (dirLen >= 120) {
			next_state = UNIT_STATE_WALK;
		}
		else if (dirLen == 0) {
			next_state = UNIT_STATE_HOLD;
		}
		else {
			for (int i = 0; i < goals1.size(); i++) {
				Unit* unitother = goals1[i];
				double dirX1 = unitother->x - unit->x;
				double dirY1 = unitother->y - unit->y;
				double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
				if (dirLen1 < 120) {
					unitother->health += UNIT_ARRACK_GOLD;
				    unitother->attack =20;
				}
				
			}
			for (int i = 0; i < goals2.size(); i++) {
				Unit* unitother = goals2[i];
				double dirX1 = unitother->x - unit->x;
				double dirY1 = unitother->y - unit->y;
				double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
				if (dirLen1 < 200) {
					unitother->health += UNIT_ARRACK_GOLD;
				}
			}
			for (int i = 0; i < goals3.size(); i++) {
				Unit* unitother = goals3[i];
				double dirX1 = unitother->x - unit->x;
				double dirY1 = unitother->y - unit->y;
				double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
				if (dirLen1 < 120) {
					unitother->attack = 1;
				}
			}
			for (int i = 0; i < goals4.size(); i++) {
				Unit* unitother = goals4[i];
				double dirX1 = unitother->x - unit->x;
				double dirY1 = unitother->y - unit->y;
				double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
				if (dirLen1 < 120) {
					unitother->health -= UNIT_ARRACK_GOLD;
				}
			}
			break;
		}
	}

	if(next_state != unit->state){
		//状态变化
		unit->state = next_state;
		unit->frame_id = 0;

		switch(unit->state){
			case UNIT_STATE_HOLD:
				unit->frame_sequence = FRAMES_GOLD_HOLDWALK;
				unit->frame_count = FRAMES_GOLD_HOLDWALK_COUNT;
				unit->vx=0;
				unit->vy=0;
				break;
			case UNIT_STATE_WALK:
				unit->frame_sequence = FRAMES_GOLD_HOLDWALK;
				unit->frame_count = FRAMES_GOLD_HOLDWALK_COUNT;
				v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
				if (v < UNIT_SPEED_GOLD) {
					unit->vx = dirX / dirLen * UNIT_SPEED_GOLD * 0.6 + unit->vx;
					unit->vy = dirY / dirLen * UNIT_SPEED_GOLD * 0.6 + unit->vy;
				}
				else {
					if ( dirX * unit->vx < 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_GOLD  + unit->vx;
						unit->vy = dirY / dirLen * UNIT_SPEED_GOLD + unit->vy;
					}
					if ( dirX * unit->vx > 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_GOLD;
						unit->vy = dirY / dirLen * UNIT_SPEED_GOLD;
					}
				}
				
				break;
			case UNIT_STATE_ATTACK:
				unit->frame_sequence = FRAMES_GOLD_ATTACK;
				unit->frame_count = FRAMES_GOLD_ATTACK_COUNT;
				unit->vx=0;
				unit->vy=0;
				break;
			case UNIT_STATE_ATTACKED:
				unit->frame_sequence = FRAMES_GOLD_ATTACKED;
				unit->frame_count = FRAMES_GOLD_ATTACKED_COUNT;
				unit->vx = 0;
				unit->vy = 0;
				break;
		};
	}

	//动画运行到下一帧
	unit->x += unit->vx;
	unit->y += unit->vy;

	unit->frame_id++;
	unit->frame_id = unit->frame_id % unit->frame_count;
	vector <Unit*>().swap(goals1);
	vector <Unit*>().swap(goals2);
	vector <Unit*>().swap(goals3);
	vector <Unit*>().swap(goals4);
}

void UnitBehaviour_2(Unit* unit) {

		bool yes = false;
		vector<Unit*> goals1;
		vector<Unit*> goals2;
		vector<Unit*> goals3;
		double dirX;
		double dirY;
		double dirLen;
		double v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
		for (int i = 0; i < units.size(); i++) {
			Unit* unitother = units[i];
			if (unitother->type == UNIT_TYPE_WATER && unitother->side!= unit->side && unitother->live == true) {
				yes= true;
				goals1.push_back(units[i]);
			}
			if (unitother->side != unit->side && unitother->live == true) {
				goals2.push_back(units[i]);
			}
			
		}
		if (yes != true) {
			if(goals2.size()>0){
				goals1.push_back(units[0]);
				yes = true;
			}
		}
		if (yes == true) {
			dirX = goals1[0]->x - unit->x;
			dirY = goals1[0]->y - unit->y;
			dirLen = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
		}
		else {
			dirLen = 0;
		}

		//判断当前状态, 以及判断是否需要状态变化
		int next_state = unit->state;
		switch (unit->state) {
		case UNIT_STATE_HOLD:
			if (dirLen > 170) {
				next_state = UNIT_STATE_WALK;
			}
			else if (dirLen <= 170) {
				next_state = UNIT_STATE_ATTACK;
			}
			break;
		case UNIT_STATE_WALK:
			if (dirLen == 0) {
				next_state = UNIT_STATE_HOLD;
			}
			else if (dirLen <= 170) {
				next_state = UNIT_STATE_ATTACK;
			}
			else {
				v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
				if (v < UNIT_SPEED_WOOD) {
					unit->vx = dirX / dirLen * UNIT_SPEED_WOOD * 0.6 + unit->vx;
					unit->vy = dirY / dirLen * UNIT_SPEED_WOOD * 0.6 + unit->vy;
				}
				else {
					if (dirX * unit->vx < 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_WOOD + unit->vx;
						unit->vy = dirY / dirLen * UNIT_SPEED_WOOD + unit->vy;
					}
					if (dirX * unit->vx > 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_WOOD;
						unit->vy = dirY / dirLen * UNIT_SPEED_WOOD;
					}
				}

			}

			break;
		case UNIT_STATE_ATTACK:
			if (dirLen >= 170) {
				next_state = UNIT_STATE_WALK;
			}
			else if (dirLen == 0) {
				next_state = UNIT_STATE_HOLD;
			}
			else {
				for (int i = 0; i < goals1.size(); i++) {
					Unit* unitother = goals1[i];
					double dirX1 = unitother->x - unit->x;
					double dirY1 = unitother->y - unit->y;
					double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
					if (dirLen1 < 170) {
						if (goals1[i]->type == UNIT_TYPE_SOIL) {
							unitother->health -= UNIT_ARRACK_WOOD;
						}
					}

				}
				for (int i = 0; i < goals2.size(); i++) {
					Unit* unitother = goals2[i];
					double dirX1 = unitother->x - unit->x;
					double dirY1 = unitother->y - unit->y;
					double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
					if (dirLen1 < 170) {
						unitother->health -= UNIT_ARRACK_WOOD;
					}
				}
				break;
			};
		}
			if (next_state != unit->state) {
				//状态变化
				unit->state = next_state;
				unit->frame_id = 0;

				switch (unit->state) {
				case UNIT_STATE_HOLD:
					unit->frame_sequence = FRAMES_WOOD_HOLDWALK;
					unit->frame_count = FRAMES_WOOD_HOLDWALK_COUNT;
					unit->vx = 0;
					unit->vy = 0;
					break;
				case UNIT_STATE_WALK:
					unit->frame_sequence = FRAMES_WOOD_HOLDWALK;
					unit->frame_count = FRAMES_WOOD_HOLDWALK_COUNT;
					v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
					if (v < UNIT_SPEED_WOOD) {
						unit->vx = dirX / dirLen * UNIT_SPEED_WOOD * 0.6 + unit->vx;
						unit->vy = dirY / dirLen * UNIT_SPEED_WOOD * 0.6 + unit->vy;
					}
					else {
						if ( dirX * unit->vx < 0) {
							unit->vx = dirX / dirLen * UNIT_SPEED_WOOD + unit->vx;
							unit->vy = dirY / dirLen * UNIT_SPEED_WOOD + unit->vy;
						}
						if (dirX * unit->vx > 0) {
							unit->vx = dirX / dirLen * UNIT_SPEED_WOOD;
							unit->vy = dirY / dirLen * UNIT_SPEED_WOOD;
						}
					}
					
					break;
				case UNIT_STATE_ATTACK:
					unit->frame_sequence = FRAMES_WOOD_ATTACK;
					unit->frame_count = FRAMES_WOOD_ATTACK_COUNT;
					unit->vx = 0;
					unit->vy = 0;
					break;
				case UNIT_STATE_ATTACKED:
					unit->frame_sequence = FRAMES_WOOD_ATTACKED;
					unit->frame_count = FRAMES_WOOD_ATTACKED_COUNT;
					unit->vx = 0;
					unit->vy = 0;
					break;
				};
			}
		
			//动画运行到下一帧
			unit->x += unit->vx;
			unit->y += unit->vy;

			unit->frame_id++;
			unit->frame_id = unit->frame_id % unit->frame_count;



		
		vector <Unit*>().swap(goals1);
		vector <Unit*>().swap(goals2);
		vector <Unit*>().swap(goals3);
	}
void UnitBehaviour_3(Unit* unit) {
		bool yes = false;
		vector<Unit*> goals1;
		vector<Unit*> goals2;
		vector<Unit*> goals3;
		double dirX;
		double dirY;
		double dirLen;
		double v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
		for (int i = 0; i < units.size(); i++) {
			Unit* unitother = units[i];
			if (unitother->type == UNIT_TYPE_FIRE && unitother->side != unit->side && unitother->live == true) {
				yes = true;
				goals1.push_back(units[i]);
			}
			if (unitother->type != UNIT_TYPE_FIRE && unitother->side != unit->side && unitother->live == true) {
				goals2.push_back(units[i]);
			}
		}
		if (yes != true) {
			if (goals2.size() > 0) {
				goals1.push_back(units[0]);
				yes = true;
			}
		}
		if (yes == true) {
			dirX = goals1[0]->x - unit->x;
			dirY = goals1[0]->y - unit->y;
			dirLen = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
		}
		else {
			dirLen = 0;
		}

		//判断当前状态, 以及判断是否需要状态变化
		int next_state = unit->state;
		switch (unit->state) {
		case UNIT_STATE_HOLD:
			if (dirLen > 120) {
				next_state = UNIT_STATE_WALK;
			}
			else if (dirLen <= 120) {
				next_state = UNIT_STATE_ATTACK;
			}
			break;
		case UNIT_STATE_WALK:
			if (dirLen == 0) {
				next_state = UNIT_STATE_HOLD;
			}
			else if (dirLen <= 120 && !(goals1.size() > 0 && goals2.size() == 0 && goals3.size() == 0)) {
				next_state = UNIT_STATE_ATTACK;
			}
			else {
				v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
				if (v < UNIT_SPEED_WATER) {
					unit->vx = dirX / dirLen * UNIT_SPEED_WATER * 0.6 + unit->vx;
					unit->vy = dirY / dirLen * UNIT_SPEED_WATER * 0.6 + unit->vy;
				}
				else {
					if (dirX * unit->vx < 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_WATER + unit->vx;
						unit->vy = dirY / dirLen * UNIT_SPEED_WATER + unit->vy;
					}
					if (dirX * unit->vx > 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_WATER;
						unit->vy = dirY / dirLen * UNIT_SPEED_WATER;
					}
				}

			}

			break;
		case UNIT_STATE_ATTACK:
			if (dirLen >= 120) {
				next_state = UNIT_STATE_WALK;
			}
			if (dirLen == 0) {
				next_state = UNIT_STATE_HOLD;
			}
			else {
				if (dirLen <= 80) {
					for (int i = 0; i < goals1.size(); i++) {
						Unit* unitother = goals1[i];
						double dirX1 = unitother->x - unit->x;
						double dirY1 = unitother->y - unit->y;
						double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
						unitother->health -= UNIT_ARRACK_WATER;
					}
				}
				if (dirLen <= 120) {
					for (int i = 0; i < goals2.size(); i++) {
						Unit* unitother = goals2[i]; double dirX1 = unitother->x - unit->x;
						double dirY1 = unitother->y - unit->y;
						double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
						if (dirLen1 < 120) {
							unitother->health -= UNIT_ARRACK_WATER;
						}
					}
					break;
				}
				if (dirLen > 80 && dirLen <= 120) {
					if (goals1.size() > 0 && goals2.size() == 0 && goals3.size() == 0) {
						next_state = UNIT_STATE_WALK;
						break;
					}
				}
			}
		}

		if (next_state != unit->state) {
			//状态变化
			unit->state = next_state;
			unit->frame_id = 0;

			switch (unit->state) {
			case UNIT_STATE_HOLD:
				unit->frame_sequence = FRAMES_WATER_HOLDWALK;
				unit->frame_count = FRAMES_WATER_HOLDWALK_COUNT;
				unit->vx = 0;
				unit->vy = 0;
				break;
			case UNIT_STATE_WALK:
				unit->frame_sequence = FRAMES_WATER_HOLDWALK;
				unit->frame_count = FRAMES_WATER_HOLDWALK_COUNT;
				v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
				if (v < UNIT_SPEED_WATER) {
					unit->vx = dirX / dirLen * UNIT_SPEED_WATER * 0.6 + unit->vx;
					unit->vy = dirY / dirLen * UNIT_SPEED_WATER * 0.6 + unit->vy;
				}
				else {
					if (dirX * unit->vx < 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_WATER + unit->vx;
						unit->vy = dirY / dirLen * UNIT_SPEED_WATER + unit->vy;
					}
					if (dirX * unit->vx > 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_WATER;
						unit->vy = dirY / dirLen * UNIT_SPEED_WATER;
					}
				}
				break;
			case UNIT_STATE_ATTACK:
				unit->frame_sequence = FRAMES_WATER_ATTACK;
				unit->frame_count = FRAMES_WATER_ATTACK_COUNT;
				unit->vx = 0;
				unit->vy = 0;
				break;
			case UNIT_STATE_ATTACKED:
				unit->frame_sequence = FRAMES_WATER_ATTACKED;
				unit->frame_count = FRAMES_WATER_ATTACKED_COUNT;
				unit->vx = 0;
				unit->vy = 0;
				break;
			};
		}

		//动画运行到下一帧
		unit->x += unit->vx;
		unit->y += unit->vy;

		unit->frame_id++;
		unit->frame_id = unit->frame_id % unit->frame_count;
		vector <Unit*>().swap(goals1);
		vector <Unit*>().swap(goals2);
		vector <Unit*>().swap(goals3);

	}
void UnitBehaviour_4(Unit* unit) {
		bool yes = false;
		vector<Unit*> goals1;
		vector<Unit*> goals2;
		vector<Unit*> goals3;
		vector<Unit*> goals4;
		double dirX;
		double dirY;
		double dirLen;
		double v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
		for (int i = 0; i < units.size(); i++) {
			Unit* unitother = units[i];
			if (unitother->type == UNIT_TYPE_WOOD && unitother->side != unit->side && unitother->live == true) {
				yes= true;
				goals1.push_back(units[i]);
			}
			if (unitother->type == UNIT_TYPE_GOLD && unitother->side != unit->side && unitother->live == true) {
				goals2.push_back(units[i]);
			}
			if ((unitother->type == UNIT_TYPE_FIRE|| unitother->type == UNIT_TYPE_SOIL )&& unitother->side != unit->side && unitother->live == true) {
				goals3.push_back(units[i]);
			}
			if (unitother->type == UNIT_TYPE_WATER && unitother->side != unit->side && unitother->live == true) {
				goals4.push_back(units[i]);
			}
		}
		if (yes != true) {
			if (goals2.size() > 0) {
				goals1.push_back(units[0]);
				yes = true;
			}
			else if (goals3.size() > 0) {
				goals1.push_back(units[0]);
				yes = true;
			}
			else if (goals4.size() > 0) {
				goals1.push_back(units[0]);
				yes = true;
			}
		}
		if (yes == true) {
			dirX = goals1[0]->x - unit->x;
			dirY = goals1[0]->y - unit->y;
			dirLen = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
		}
		else {
			dirLen = 0;
		}

		//判断当前状态, 以及判断是否需要状态变化
		int next_state = unit->state;
		switch (unit->state) {
		case UNIT_STATE_HOLD:
			if (dirLen > 90) {
				next_state = UNIT_STATE_WALK;
			}
			else if (dirLen <= 90) {
				next_state = UNIT_STATE_ATTACK;
			}
			break;
		case UNIT_STATE_WALK:
			if (dirLen == 0) {
				next_state = UNIT_STATE_HOLD;
			}
			else if (dirLen <= 90) {
				next_state = UNIT_STATE_ATTACK;
			}
			else {
				v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
				if (v < UNIT_SPEED_FIRE) {
					unit->vx = dirX / dirLen * UNIT_SPEED_FIRE *0.6 + unit->vx;
					unit->vy = dirY / dirLen * UNIT_SPEED_FIRE*0.6 + unit->vy ;
				}
				else {
					if ( dirX * unit->vx < 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_FIRE + unit->vx;
						unit->vy = dirY / dirLen * UNIT_SPEED_FIRE + unit->vy;
					}
					if (dirX * unit->vx > 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_FIRE;
						unit->vy = dirY / dirLen * UNIT_SPEED_FIRE;
					}
				}
					
				}
			
			break;
		case UNIT_STATE_ATTACK:
			if (dirLen >= 90) {
				next_state = UNIT_STATE_WALK;
			}
			else if (dirLen == 0) {
				next_state = UNIT_STATE_HOLD;
			}
			else {
				for (int i = 0; i < goals1.size(); i++) {
					Unit* unitother = goals1[i];
					double dirX1 = unitother->x - unit->x;
					double dirY1 = unitother->y - unit->y;
					double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
					if (dirLen1 < 90) {
						unitother->health -= 2 * UNIT_ARRACK_FIRE;
					}
				}
				for (int i = 0; i < goals2.size(); i++) {
					Unit* unitother = goals2[i];
					double dirX1 = unitother->x - unit->x;
					double dirY1 = unitother->y - unit->y;
					double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
					if (dirLen1 < 90) {
						unitother->health -= 2 * UNIT_ARRACK_FIRE;
					}
				}
				for (int i = 0; i < goals3.size(); i++) {
					Unit* unitother = goals3[i];
					double dirX1 = unitother->x - unit->x;
					double dirY1 = unitother->y - unit->y;
					double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
					if (dirLen1 < 90) {
						unitother->health-= UNIT_ARRACK_FIRE;
					}
				}
				for (int i = 0; i < goals4.size(); i++) {
					Unit* unitother = goals4[i];
					double dirX1 = unitother->x - unit->x;
					double dirY1 = unitother->y - unit->y;
					double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
					if (dirLen1 < 90) {
						unitother->health -= 1;
					}
				}
				break;
			}
		}

		if (next_state != unit->state) {
			//状态变化
			unit->state = next_state;
			unit->frame_id = 0;

			switch (unit->state) {
			case UNIT_STATE_HOLD:
				unit->frame_sequence = FRAMES_FIRE_HOLDWALK;
				unit->frame_count = FRAMES_FIRE_HOLDWALK_COUNT;
				unit->vx = 0;
				unit->vy = 0;
				break;
			case UNIT_STATE_WALK:
				unit->frame_sequence = FRAMES_FIRE_HOLDWALK;
				unit->frame_count = FRAMES_FIRE_HOLDWALK_COUNT;
				v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
				if (v < UNIT_SPEED_FIRE) {
					unit->vx = dirX / dirLen * UNIT_SPEED_FIRE * 0.6 + unit->vx;
					unit->vy = dirY / dirLen * UNIT_SPEED_FIRE * 0.6 + unit->vy;
				}
				else {
					if (dirX * unit->vx < 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_FIRE + unit->vx;
						unit->vy = dirY / dirLen * UNIT_SPEED_FIRE + unit->vy;
					}
					if (dirX * unit->vx > 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_FIRE;
						unit->vy = dirY / dirLen * UNIT_SPEED_FIRE;
					}
				}
				
				break;
			case UNIT_STATE_ATTACK:
				unit->frame_sequence = FRAMES_FIRE_ATTACK;
				unit->frame_count = FRAMES_FIRE_ATTACK_COUNT;
				unit->vx = 0;
				unit->vy = 0;
				break;
			case UNIT_STATE_ATTACKED:
				unit->frame_sequence = FRAMES_FIRE_ATTACKED;
				unit->frame_count = FRAMES_FIRE_ATTACKED_COUNT;
				unit->vx = 0;
				unit->vy = 0;
				break;
			};
		}

		//动画运行到下一帧
		unit->x += unit->vx;
		unit->y += unit->vy;

		unit->frame_id++;
		unit->frame_id = unit->frame_id % unit->frame_count;

		vector <Unit*>().swap(goals1);
		vector <Unit*>().swap(goals2);
		vector <Unit*>().swap(goals3);
		vector <Unit*>().swap(goals4);
	}
void UnitBehaviour_5(Unit* unit) {
		bool yes = false;
		vector<Unit*> goals1;
		vector<Unit*> goals2;
		vector<Unit*> goals3;
		double dirX;
		double dirY;
		double dirLen;
		double v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
		for (int i = 0; i < units.size(); i++) {
			Unit* unitother = units[i];
			if (unitother->type == UNIT_TYPE_WATER && unitother->side != unit->side && unitother->live == true) {
				yes = true;
				goals1.push_back(units[i]);
			}
			if (unitother->type != UNIT_TYPE_WOOD && unitother->side != unit->side && unitother->live == true) {
				goals2.push_back(units[i]);
			}
			if (unitother->type == UNIT_TYPE_FIRE && unitother->side != unit->side && unitother->live == true) {
				goals3.push_back(units[i]);
			}
		}
		if (yes != true) {
			if (goals2.size() > 0) {
				goals1.push_back(units[0]);
				yes = true;
			}
		}
		if (yes == true) {
			dirX = goals1[0]->x - unit->x;
			dirY = goals1[0]->y - unit->y;
			dirLen = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
		}
		else {
			dirLen = 0;
		}
		//判断当前状态, 以及判断是否需要状态变化
		int next_state = unit->state;
		switch (unit->state) {
		case UNIT_STATE_HOLD:
			if (dirLen > 170) {
				next_state = UNIT_STATE_WALK;
			}
			else if (dirLen <= 170) {
				next_state = UNIT_STATE_ATTACK;
			}
			else {
				for (int i = 0; i < goals1.size(); i++) {
					Unit* unitother = goals1[i];
					unitother->attack = 10;
				}
				for (int i = 0; i < goals3.size(); i++) {
					Unit* unitother = goals2[i];
					unitother->attack = 5;
				}
			}
			break;
		case UNIT_STATE_WALK:
			if (dirLen == 0) {
				next_state = UNIT_STATE_HOLD;
			}
			else if (dirLen <= 170) {
				next_state = UNIT_STATE_ATTACK;
			}
			else {
				v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
				if (v < UNIT_SPEED_SOIL) {
					unit->vx = dirX / dirLen * UNIT_SPEED_SOIL * 0.6 + unit->vx;
					unit->vy = dirY / dirLen * UNIT_SPEED_SOIL * 0.6 + unit->vy;
				}
				else {
					if (dirX * unit->vx < 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_SOIL + unit->vx;
						unit->vy = dirY / dirLen * UNIT_SPEED_SOIL + unit->vy;
					}
					if (dirX * unit->vx > 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_SOIL;
						unit->vy = dirY / dirLen * UNIT_SPEED_SOIL;
					}
				}
				for (int i = 0; i < goals1.size(); i++) {
					Unit* unitother = goals1[i];
					unitother->attack = 10;
				}
				for (int i = 0; i < goals3.size(); i++) {
					Unit* unitother = goals2[i];
					unitother->attack = 5;
				}

				break;
		case UNIT_STATE_ATTACK:
			if (dirLen >= 170) {
				next_state = UNIT_STATE_WALK;
			}
			else if (dirLen == 0) {
				next_state = UNIT_STATE_HOLD;
			}
			else {
				for (int i = 0; i < goals1.size(); i++) {
					Unit* unitother = goals1[i];
					double dirX1 = unitother->x - unit->x;
					double dirY1 = unitother->y - unit->y;
					double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
					if (dirLen1 < 170) {
						unitother->health -= 1.5 * UNIT_ARRACK_SOIL;
						unitother->attack = 5;
					}
				}
				for (int i = 0; i < goals2.size(); i++) {
					Unit* unitother = goals2[i];
					double dirX1 = unitother->x - unit->x;
					double dirY1 = unitother->y - unit->y;
					double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
					if (dirLen1 < 170) {
						unitother->health -= UNIT_ARRACK_SOIL;
					}
				}
				for (int i = 0; i < goals3.size(); i++) {
					Unit* unitother = goals3[i];
					double dirX1 = unitother->x - unit->x;
					double dirY1 = unitother->y - unit->y;
					double dirLen1 = sqrt(dirX * dirX + dirY * dirY) + 0.0001;
					if (dirLen1 < 170) {
						unitother->attack = 3;
					}
				}
				break;
			}
			}
		}

		if (next_state != unit->state) {
			//状态变化
			unit->state = next_state;
			unit->frame_id = 0;

			switch (unit->state) {
			case UNIT_STATE_HOLD:
				unit->frame_sequence = FRAMES_SOIL_HOLDWALK;
				unit->frame_count = FRAMES_SOIL_HOLDWALK_COUNT;
				unit->vx = 0;
				unit->vy = 0;
				break;
			case UNIT_STATE_WALK:
				unit->frame_sequence = FRAMES_SOIL_HOLDWALK;
				unit->frame_count = FRAMES_SOIL_HOLDWALK_COUNT;
				v = sqrt(unit->vx * unit->vx + unit->vy * unit->vy) + 0.0001;
				if (v < UNIT_SPEED_SOIL) {
					unit->vx = dirX / dirLen * UNIT_SPEED_SOIL * 0.6 + unit->vx;
					unit->vy = dirY / dirLen * UNIT_SPEED_SOIL * 0.6 + unit->vy;
				}
				else {
					if (dirX * unit->vx < 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_SOIL + unit->vx;
						unit->vy = dirY / dirLen * UNIT_SPEED_SOIL + unit->vy;
					}
					if (dirX * unit->vx > 0) {
						unit->vx = dirX / dirLen * UNIT_SPEED_SOIL;
						unit->vy = dirY / dirLen * UNIT_SPEED_SOIL;
					}
				}
				break;
			case UNIT_STATE_ATTACK:
				unit->frame_sequence = FRAMES_SOIL_ATTACK;
				unit->frame_count = FRAMES_SOIL_ATTACK_COUNT;
				unit->vx = 0;
				unit->vy = 0;
				break;
			case UNIT_STATE_ATTACKED:
				unit->frame_sequence = FRAMES_SOIL_ATTACKED;
				unit->frame_count = FRAMES_SOIL_ATTACKED_COUNT;
				unit->vx = 0;
				unit->vy = 0;
				break;
			};
		}

		//动画运行到下一帧
		unit->x += unit->vx;
		unit->y += unit->vy;

		unit->frame_id++;
		unit->frame_id = unit->frame_id % unit->frame_count;

		vector <Unit*>().swap(goals1);
		vector <Unit*>().swap(goals2);
		vector <Unit*>().swap(goals3);
	}
#pragma endregion


#pragma region 绘图函数
// 绘图函数
void Paint(HWND hWnd)
{

	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//初始化缓存
	HBITMAP	blankBmp = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, blankBmp);

	// 绘制背景到缓存
	SelectObject(hdc_loadBmp, currentStage->bg);
	switch (currentStage->stageID) 
	{
	case STAGE_STARTMENU:
	{SelectObject(hdc_loadBmp, bmp_Stage1);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY); 
	}
	break;
	case STAGE_1:
	{SelectObject(hdc_loadBmp, bmp_Stage2);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY); }
	break;

	case STAGE_2:
	{SelectObject(hdc_loadBmp, bmp_Stage2);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY); }
	break;
	case STAGE_FREEWAR:
	{SelectObject(hdc_loadBmp, bmp_Stage2);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY); }
	break;
	case STAGE_ROLE_1:
	{SelectObject(hdc_loadBmp, bmp_Stage2);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY); 
	SelectObject(hdc_loadBmp, bmp_Role);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY); }
	
	break;

	case STAGE_ROLE_2:
	{SelectObject(hdc_loadBmp, bmp_Stage2);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	SelectObject(hdc_loadBmp, bmp_Role);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY); }
	break;
	case STAGE_FREEWARROLE:
	{SelectObject(hdc_loadBmp, bmp_Freewarrole);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	}
	break;
	case STAGE_CHOOSE:
	{
		SelectObject(hdc_loadBmp, bmp_Stage1);
		BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
		SelectObject(hdc_loadBmp, bmp_Choose);
		BitBlt(hdc_memBuffer, (WINDOW_WIDTH - CHOOSE1_WIDTH) / 2, (WINDOW_HEIGHT - CHOOSE1_HEIGHT) / 2, CHOOSE1_WIDTH, CHOOSE1_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY); }
	break;
	case STAGE_BACKGROUND:
	{SelectObject(hdc_loadBmp, bmp_Picture);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	SelectObject(hdc_loadBmp, bmp_Background);
	BitBlt(hdc_memBuffer, (WINDOW_WIDTH - BACKINTRO_WIDTH) / 2, (WINDOW_HEIGHT - BACKINTRO_HEIGHT) / 2, BACKINTRO_WIDTH, BACKINTRO_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	break;
	case STAGE_INTRODUCTION:
	{SelectObject(hdc_loadBmp, bmp_Stage1);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	SelectObject(hdc_loadBmp, bmp_Introduction);
	BitBlt(hdc_memBuffer, (WINDOW_WIDTH - BACKINTRO_WIDTH) / 2, (WINDOW_HEIGHT - BACKINTRO_HEIGHT) / 2, BACKINTRO_WIDTH, BACKINTRO_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	break;
	}
	case STAGE_STOP:
	{SelectObject(hdc_loadBmp, bmp_Stage2);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	SelectObject(hdc_loadBmp, bmp_Choose);
	TransparentBlt(hdc_memBuffer, (WINDOW_WIDTH - BACKINTRO_WIDTH) / 2, (WINDOW_HEIGHT - BACKINTRO_HEIGHT / 2) / 2, BACKINTRO_WIDTH, BACKINTRO_HEIGHT / 2, hdc_loadBmp, 0, 0, BACKINTRO_WIDTH, BACKINTRO_HEIGHT, RGB(255, 255, 255));
	//BitBlt(hdc_memBuffer, (WINDOW_WIDTH - BACKINTRO_WIDTH) / 2, (WINDOW_HEIGHT - BACKINTRO_HEIGHT) / 2, BACKINTRO_WIDTH, BACKINTRO_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	}
	break;
	case STAGE_SUCCESS:

	{	SelectObject(hdc_loadBmp, bmp_Stage2);
		BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY); 
		SelectObject(hdc_loadBmp, bmp_Success);
	TransparentBlt(hdc_memBuffer, (WINDOW_WIDTH - 500) / 2, (WINDOW_HEIGHT - 576) / 2, 500, 576, hdc_loadBmp, 0, 0, 500, 576, RGB(255, 255, 255));
	}
	break;
	case STAGE_PASS:

	{	SelectObject(hdc_loadBmp, bmp_Stage2);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	SelectObject(hdc_loadBmp, bmp_Pass);
	TransparentBlt(hdc_memBuffer, (WINDOW_WIDTH - 600) / 2, (WINDOW_HEIGHT - 340) / 2, 600,340, hdc_loadBmp, 0, 0, 600, 340, RGB(255, 255, 255));
	}
	break;
	case STAGE_SUCCESS1:

	{	SelectObject(hdc_loadBmp, bmp_Stage2);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	SelectObject(hdc_loadBmp, bmp_Success1);
	TransparentBlt(hdc_memBuffer, (WINDOW_WIDTH - 600) / 2, (WINDOW_HEIGHT - 340) / 2, 600, 340, hdc_loadBmp, 0, 0, 600, 340, RGB(255, 255, 255));
	}
	break;
	case STAGE_SUCCESS2:

	{	SelectObject(hdc_loadBmp, bmp_Stage2);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	SelectObject(hdc_loadBmp, bmp_Success2);
	TransparentBlt(hdc_memBuffer, (WINDOW_WIDTH - 600) / 2, (WINDOW_HEIGHT - 340) / 2, 600, 340, hdc_loadBmp, 0, 0, 600, 340, RGB(255, 255, 255));
	}
	break;
	case STAGE_GUA:

	{	SelectObject(hdc_loadBmp, bmp_Stage2);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	SelectObject(hdc_loadBmp, bmp_Gua);
	TransparentBlt(hdc_memBuffer, (WINDOW_WIDTH - 600) / 2, (WINDOW_HEIGHT - 332) / 2, 600, 332, hdc_loadBmp, 0, 0, 600, 332, RGB(255, 255, 255));
	}
	break;
	case STAGE_FAIL:

	{	SelectObject(hdc_loadBmp, bmp_Stage2);
	BitBlt(hdc_memBuffer, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_loadBmp, 0, 0, SRCCOPY);
	SelectObject(hdc_loadBmp, bmp_Fail);
	TransparentBlt(hdc_memBuffer, (WINDOW_WIDTH - 500) / 2, (WINDOW_HEIGHT - 576) / 2, 500, 576, hdc_loadBmp, 0, 0, 500, 576, RGB(255, 255, 255));
	}
	break;
	}}
	// 按场景分类绘制内容到缓存
	if (currentStage->stageID == STAGE_ROLE_1|| currentStage->stageID == STAGE_ROLE_2||currentStage->stageID==STAGE_FREEWARROLE) {
		for (int i = 0; i < roles1.size(); i++) {
			Role* role = roles1[i];
		SelectObject(hdc_loadBmp, role->image1);
			TransparentBlt(
				hdc_memBuffer, role->x - 0.5 * UNIT_GOALSIZE_X, role->y - 0.5 * UNIT_GOALSIZE_Y,
				UNIT_GOALSIZE_X, UNIT_GOALSIZE_Y,
				hdc_loadBmp, UNIT_SIZE_X * role->frame_sequence[role->frame_id], 0, UNIT_SIZE_X, UNIT_SIZE_Y,
				RGB(255, 255, 255));
		}
		for (int i = 0; i < roles2.size(); i++) {
			Role* role = roles2[i];
			SelectObject(hdc_loadBmp, role->image1);
			TransparentBlt(
				hdc_memBuffer, role->x - 0.5 * UNIT_GOALSIZE_X, role->y - 0.5 * UNIT_GOALSIZE_Y,
				UNIT_GOALSIZE_X, UNIT_GOALSIZE_Y,
				hdc_loadBmp, UNIT_SIZE_X * role->frame_sequence[role->frame_id], 0, UNIT_SIZE_X, UNIT_SIZE_Y,
				RGB(255, 255, 255));
		}
	}
	else if ((currentStage->stageID >= STAGE_1 && currentStage->stageID <= STAGE_2)||currentStage->stageID==STAGE_FREEWAR) //TODO：添加多个游戏场景
	{
		// 绘制单位到缓存
		for (int i = 0; i < roles3.size(); i++) {
			Role* role = roles3[i];
			SelectObject(hdc_loadBmp, role->image1);
			if (role->frame_id != role->frame_count - 1) {
				TransparentBlt(
					hdc_memBuffer, role->x - 0.5 * UNIT_GOALSIZE_X, role->y - 0.5 * UNIT_GOALSIZE_Y,
					UNIT_GOALSIZE_X, UNIT_GOALSIZE_Y,
					hdc_loadBmp, UNIT_SIZE_X * role->frame_sequence[role->frame_id], 0, UNIT_SIZE_X, UNIT_SIZE_Y,
					RGB(255, 255, 255));
			}
		}
		for (int i = 0; i < units.size(); i++) {
			Unit* unit = units[i];
			if (unit->live == true) {
				if (unit->state == UNIT_STATE_HOLD || unit->state == UNIT_STATE_WALK) {
					SelectObject(hdc_loadBmp, unit->image1);
				}
				if (unit->state == UNIT_STATE_ATTACK) {
					SelectObject(hdc_loadBmp, unit->image2);
				}
				if (unit->state == UNIT_STATE_ATTACKED) {
					SelectObject(hdc_loadBmp, unit->image3);
				}
				TransparentBlt(
					hdc_memBuffer, unit->x - 0.5 * UNIT_GOALSIZE_X, unit->y - 0.5 * UNIT_GOALSIZE_Y,
					UNIT_GOALSIZE_X, UNIT_GOALSIZE_Y,
					hdc_loadBmp, UNIT_SIZE_X * unit->frame_sequence[unit->frame_id], 0, UNIT_SIZE_X, UNIT_SIZE_Y,
					RGB(255, 255, 255));
			}
		}

		
		
	}


	// 绘制按钮到缓存

	for(int i=0;i<buttons.size();i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			SelectObject(hdc_loadBmp, button->img);
			TransparentBlt(
				hdc_memBuffer, button->x, button->y,
				button->width, button->height,
				hdc_loadBmp, 0, 0, button->width, button->height,
				RGB(255, 255, 255)
			);
		}
	}
	if (currentStage->stageID == STAGE_ROLE_1 || currentStage->stageID == STAGE_ROLE_2)
	{

		_itow(num_of_gold, cnum_of_gold, 10);
		_itow(num_of_wood, cnum_of_wood, 10);
		_itow(num_of_water, cnum_of_water, 10);
		_itow(num_of_fire, cnum_of_fire, 10);
		_itow(num_of_soil, cnum_of_soil, 10);
		_itow(num_of_bagua, cnum_of_bagua, 10);

		
		wordShow(hdc_memBuffer, 25, 403, 76, cnum_of_gold, RGB(255, 255, 255), wcslen(cnum_of_gold));
		wordShow(hdc_memBuffer, 25, 535, 76, cnum_of_wood, RGB(255, 255, 255), wcslen(cnum_of_wood));
		wordShow(hdc_memBuffer, 25,670, 76, cnum_of_water, RGB(255, 255, 255), wcslen(cnum_of_water));
		wordShow(hdc_memBuffer, 25, 803, 76, cnum_of_fire, RGB(255, 255, 255), wcslen(cnum_of_fire));
		wordShow(hdc_memBuffer, 25, 937, 76, cnum_of_soil, RGB(255, 255, 255), wcslen(cnum_of_soil));
		wordShow(hdc_memBuffer, 25, 790, 200, cnum_of_bagua, RGB(255, 255, 255), wcslen(cnum_of_bagua));
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->visible)
			{
				SelectObject(hdc_loadBmp, button->img);
				TransparentBlt(
					hdc_memBuffer, button->x, button->y,
					button->width, button->height,
					hdc_loadBmp, 0, 0, button->width, button->height,
					RGB(255, 255, 255)
				);
			}
		}
	}
	if (currentStage->stageID == STAGE_FREEWARROLE)
	{

		_itow(num_of_role, cnum_of_role, 10);

		wordShow(hdc_memBuffer, 25, 806, 200, cnum_of_role, RGB(255, 255, 255), wcslen(cnum_of_role));
	}
	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);
	//(LPCTSTR)num_of_bagua
	// 回收资源所占的内存（非常重要）
	DeleteObject(blankBmp);
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);
}



// 初始化背景函数
HBITMAP InitBackGround(HWND hWnd, HBITMAP bmp_src)
{

	srand(time(NULL));
	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//初始化缓存
	HBITMAP	bmp_output = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, bmp_output);

	//加载资源
	SelectObject(hdc_loadBmp, bmp_src);


			TransparentBlt(
				hdc_memBuffer, 0, 0,
				WINDOW_WIDTH, WINDOW_HEIGHT,
				hdc_loadBmp, 0, 0, 
				WINDOW_WIDTH, WINDOW_HEIGHT,
				RGB(255, 255, 255)
			);


	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存（非常重要）
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);

	return bmp_output;
}

#pragma endregion