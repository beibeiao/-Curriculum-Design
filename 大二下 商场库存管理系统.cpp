#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
using namespace std;

class admin{
private:
    string name;
	string password;   	
public:
    admin();
};

class shelf//货架 
{
public:
    shelf();
private:
    admin men;//管理员
    string storeNo;//仓库编号 
    string kinds;//商品大类
    string shelfNo;//货架号
};

class ele//物品 
{
public:
    ele();
private:
    string name;//商品名
    double price;//价格  
    shelf sh;//所属货架
    long count;//商品数量
};

class mana{//管理 

private:
	admin ap;
    ele aele;
    shelf ashelf;
    admin abs;
public:	
	void enter();			//登录 
	void enroll();			//注册
	void chief_enroll();	//处长注册 
	void logout();			//删除界面
	void clogout();			// 
	void logout_logout();	//删除
	void clogout_logout();	//删除
	char zero_face();		//零页 
	
	mana();
    char first_face();//管理员首页
    char chief_face();//处长首页
    
    void in_storage();//入库
    void out_storage();//出库
    void select_admin();//管理员信息查询 
    void select_ele();//商品查询
    void select_name();//按商品名称查询
    void select_price();//按商品价格查询
    void select_kind();//按大类查询
    void call_break();//商品报损 
};

admin::admin()   
{
    name = "xxx";
    password = "000000";
}

ele::ele():sh()
{
    name = "xxx";//商品名
    price = 0.0;//价格
    count = 0;//商品数量
}                             

shelf::shelf():men()
{
    storeNo = "xxx";//仓库编号
    kinds = "xxx";//商品大类
    shelfNo = "xxx";;//货架号
}

mana::mana():aele(), ashelf(), abs()
{
	
}

char mana::zero_face()//首页 
{
	system("color 1E");//0=黑色 1=蓝色 2=绿色 3=湖蓝色 4=红色 5=紫色 6=黄色 7=白色 8=灰色 9=淡蓝色
    system("cls");//A=淡绿色 B=淡浅绿色 C=淡红色 D=淡紫色 E=淡黄色 F=亮白色
    cout<< endl << endl;//0E 1E 
    cout<<endl <<"\t    ████████████████████████████"
        <<endl <<"\t    █                                                    █"
        <<endl <<"\t    █                                                    █"
        <<endl <<"\t    █                   商场库存管理系统                 █"
        <<endl <<"\t    █                                                    █"
        <<endl <<"\t    █                                                    █" 
        <<endl <<"\t    █                    1.  登录系统                    █"
        <<endl <<"\t    █                                                    █"
        <<endl <<"\t    █                    2.  处长注册                    █"
        <<endl <<"\t    █                                                    █"
        <<endl <<"\t    █                    3.  删除账号                    █"    
        <<endl <<"\t    █                                                    █" 		     
        <<endl <<"\t    █                    4.  退出系统                    █"         
        <<endl <<"\t    █                                                    █"
        <<endl <<"\t    █                                                    █"
        <<endl <<"\t    █                                                    █"
        <<endl <<"\t    ████████████████████████████" 
		<<endl 
		<<endl 
		<<"\t";
    
    return getch();
}

void mana::enter()//登录模块 
{
	system("cls");      
    cout << endl << endl << endl << "\t欢迎登录工厂管理系统 :) " << endl << endl ;
    
	cout << "\t请输入用户名 : ";
    string admin;
    cin >> admin;
    
    cout << endl <<"\t请输入密码 : ";
    string password;
    cin >> password;

    string admin1;
	string password1;
	string cadmin1;
	string cpassword1;
    
    ifstream storeFile("admin.txt");
    ifstream cstoreFile("cadmin.txt");
    
    if (!storeFile&&!cstoreFile)
    {
        cout << endl << endl << "\t对不起，您还未注册:-(" << endl << endl << "\t";
        system("pause");
        return;
    }
    
    bool flag = false;
    bool cflag = false;
    
	while (storeFile >> admin1 >> password1 )
	{
        if (admin1 == admin&&password1 == password)
        {
            flag = true;
            cflag = true;
            cout<<endl<<endl<<"\t密码正确" <<endl; 
            first_face();//管理员首页 
        }
    }
    
    while (cstoreFile >> cadmin1 >> cpassword1 )
	{
        if (cadmin1 == admin&&cpassword1 == password)
        {
            cflag = true;
            flag = true;
            cout<<endl<<endl<<"\t密码正确" <<endl; 
            chief_face();//处长首页 
        }
    }
    
    storeFile.close();
    cstoreFile.close();
    
    if (!flag||!cflag)
        cout << endl << endl << "对不起，用户名或密码错误！:-(";
    cout << endl << endl;
    system("pause");

}

void mana::enroll()//管理员注册 
{
	system("cls");
	string admin;
	string password;
	
	cout << endl << "欢迎注册管理员账号，请输入相关信息 : " << endl << endl ;	
	
	cout << "\t用户名 : ";
    cin >> admin;
    cout << endl << "\t密码 : ";
    cin >> password;
    
    string admin1;
    ifstream storeFile0("admin.txt");
	storeFile0 >> admin1; 

    if (admin1 == admin)
	{ 
    	cout<<endl<<endl<<"\t该用户名已被注册！" <<endl;
    	cout << endl << endl;
    	system("pause");
    	chief_face();
    }
    
    else{
	    storeFile0.close();
	    
	    ofstream storeFile("admin.txt", ios::app);
	    storeFile << setiosflags(ios::left) << setw(20) <<  admin << " "<< setw(15) << password << endl;
	    storeFile.close();
	    
	    cout << endl << endl << "\t注册成功！请登录..." << endl << endl << "\t";
	    system("pause");	
	}
	
}

void mana::chief_enroll()//处长注册 
{
	system("cls");
	string cadmin;
	string cpassword;
	string check="9527"; 
	
	cout << endl << "欢迎注册处长账号，请输入相关信息 : " << endl << endl ;	
	
	cout << "\t用户名 : ";
    cin >> cadmin;
    cout << endl << "\t密码 : ";
    cin >> cpassword;
    cout << endl << "\t验证码 : ";
    cin >> check;
    
    if(check=="9527"){
    	
	    string cadmin1;
	    ifstream storeFile0("cadmin.txt");
		storeFile0 >> cadmin1; 
	
	    if (cadmin1 == cadmin)
		{ 
	    	cout<<endl<<endl<<"\t该用户名已被注册！" <<endl;
	    	cout << endl << endl;
	    	system("pause");
	    	zero_face();
	    }
	    
	    else{
    	
	    	ofstream storeFile("cadmin.txt", ios::app);
		    storeFile << setiosflags(ios::left) << setw(20) <<  cadmin << " "<< setw(15) << cpassword << endl;
		    storeFile.close();
		    
		    cout << endl << endl << "\t注册成功！请登录..." << endl << endl << "\t";
		    system("pause");
		}
	}
    else{
    	cout << endl << endl << "对不起，验证码错误！您无法注册:-(";
    	cout << endl << endl;
    	system("pause");
	}
}

void mana::logout()//删除界面 
{
	while (1)
    {
		system("cls");		
	    cout<< endl;
	    cout<<endl <<"\t█████████████████████████████"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█           您确定要删除所有管理员账号及信息吗？       █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █" 
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                       1.  是                         █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                       2.  呃...                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"     
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█████████████████████████████" 
			<<endl 
			<<endl 
			<<"\t";		
		char select = getch();
        switch (select)
        {
	        case '1':
	            logout_logout();
	            break;
	        case '2':
	            return;
	        default:
	            break;
        }
	}
}

void mana::clogout()//删除处长界面 
{
	while (1)
    {
		system("cls");		
	    cout<< endl;
	    cout<<endl <<"\t█████████████████████████████"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█               您确定要删除所有处长账号吗？           █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █" 
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                       1.  是                         █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                       2.  呃...                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"     
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█                                                      █"
	        <<endl <<"\t█████████████████████████████" 
			<<endl 
			<<endl 
			<<"\t";		
		char select = getch();
        switch (select)
        {
	        case '1':
	            clogout_logout();
	            break;
	        case '2':
	            return;
	        default:
	            break;
        }
	}
}
 
void mana::logout_logout()//删除 
{
	system("cls");
    ofstream storeFile1("admin.txt");
    ifstream tempFile1("admins.txt");
    storeFile1 << tempFile1.rdbuf();
    storeFile1.close();
    tempFile1.close();
    
    cout << endl << "\t已删除所有管理员账号及信息 :)" << endl << endl << "\t";
	system("pause");
	chief_face(); 
}

void mana::clogout_logout()//删除处长
{
	system("cls");
	string check="9527";
	string check1;
	
	cout<< endl << endl << "\t请输入验证码：";
	cin>>check1; 
	if(check1==check)
	{
		ofstream storeFile1("cadmin.txt");
	    ifstream tempFile1("cadmins.txt");
	    storeFile1 << tempFile1.rdbuf();
	    storeFile1.close();
	    tempFile1.close();
	    
	    cout << endl << "\t已删除所有处长账号 :)" << endl << endl << "\t";
	}
	else{
		cout<< endl << "\t验证码错误！"<< endl << endl <<"\t"; 
	}
	system("pause");
	zero_face();
} 

char mana::first_face()//管理员首页 
{
    system("cls");
    cout<< endl <<endl;
    cout<<endl <<"\t█████████████████████████████"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█              商场库存管理系统（管理员）              █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                                                      █" 
        <<endl <<"\t█                    1.  商品入库                      █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                    2.  商品出库                      █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                    3.  查询统计                      █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                    4.  商品报损                      █"
        <<endl <<"\t█                                                      █"     
        <<endl <<"\t█                    5.  退出系统                      █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█████████████████████████████" 
		<<endl 
		<<endl 
		<<"\t";
    
		mana men;
    	char select = getch();
    	switch (select)
        {
	        case '1':
	            men.in_storage();
	            break;
	        case '2':
	            men.out_storage();
	            break;
	        case '3':
	            men.select_ele();
	            break;
	        case '4':
	            men.call_break();
	            break;
	        case '5':
	            cout << "\t" << "谢谢使用!!!!" << endl << endl << "\t\t";
	            exit( 0 );
	            break;
	        default:
	            break;
        }		
		men.first_face();
}

char mana::chief_face()//处长首页
{
    system("cls");
    cout<< endl <<endl;
    cout<<endl <<"\t█████████████████████████████"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█               商场库存管理系统（处长）               █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                                                      █" 
        <<endl <<"\t█                   1.  商品查询                       █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                   2.  管理员信息查询                 █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                   3.  管理员账号注册                 █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                   4.  管理员账号删除                 █"
		<<endl <<"\t█                                                      █" 
        <<endl <<"\t█                   5.  返回首页                       █"   
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                   6.  退出系统                       █"   
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█                                                      █"
        <<endl <<"\t█████████████████████████████" 
		<<endl 
		<<endl 
		<<"\t";
    
		mana cmen;
    	char select = getch();
    	switch (select)
        {
	        case '1':
	            cmen.select_ele(); 
	            break;
	        case '2':
	            cmen.select_admin();//信管理员息查询 
	            break;
	        case '3':
	            cmen.enroll();
	            break;
	        case '4':
	            cmen.logout(); 
	            break;
	        case '5':
	            cmen.zero_face();
	            break;
	        case '6':
	            cout << "\t" << "谢谢使用!!!!" << endl << endl << "\t\t";
	            exit( 0 );
	            break;
	        default:
	            break;
        }		
		cmen.chief_face();

} 

void mana::in_storage()//入库 
{
    system("cls");
    string name;//商品名
    double price;//价格                                                                              
    string storeNo;//仓库编号 
    string kinds;//商品大类
    string shelfNo;//货架号
    long count = 0; //商品数量
    
    cout << endl << "商品入库，请输入相关信息 : " << endl << endl ;
    
	cout << "\t商品名称 : ";                                                                         
    cin >> name;
    cout << endl << "\t商品价格 : ";
    cin >> price;
    cout << endl << "\t商品数量 : ";
    cin >> count;
    cout << endl << "\t仓库编号 : ";                                                            
    cin >> storeNo;
    cout << endl << "\t商品大类 : ";
    cin >> kinds;
    cout << endl << "\t货架编号 : " ;
    cin >> shelfNo;                                                                             
    
    ofstream storeFile("store.txt", ios::app);
    storeFile << setiosflags(ios::left) << setw(20) << name << " "
        << setw(15) << price << " " << setw(10) << count << " "
        << setw(10) << storeNo << " " << setw(20) << kinds << " "
        << shelfNo << endl;                                                                         
    storeFile.close();
    
    cout << endl << endl << "\t该商品已经入库......." << endl << endl << "\t";

}

void mana::out_storage()//出库 
{
    system("cls");//执行控制台命令cls，就是CMD下面的cls，功能是清屏，清除所有显示的信息。
    
    string name;//商品名
    
    cout << endl << "\t商品出库，输入出库商品信息 : " << endl << endl;
    cout << "\t商品名称 : ";
    cin >> name;
    
    ifstream storeFile("store.txt");
    if (!storeFile)
    {
        ofstream storeFile1("store.txt");
        storeFile1.close();
        cout << endl << endl << "\t仓存为空!!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    bool flag = false;//将bool型的flag作为是否输入完整的标识传递.和定义一个其他类型的标识没什么区别
    string name1;//商品名
    double price1;//价格
    string storeNo1;//仓库编号 
    string kinds1;//商品大类
    string shelfNo1;//货架号
    long count1 = 0; //商品数量
    
    ofstream tempFile("temp.txt");
    
    while (storeFile >> name1 >> price1 >> count1 >> storeNo1 >>  kinds1 >> shelfNo1)
    {
        if (name1==name)
            flag = true;
        else
        {
        tempFile << setiosflags(ios::left) << setw(20) << name1 << " "
            << setw(15) << price1 << " " << setw(10) << count1 << " "
            << setw(10) << storeNo1 << " " << setw(20) << kinds1 << " "
            << shelfNo1 << endl;
        }
    }
    tempFile.close();
    storeFile.close();
    
    if (!flag)
    {
        cout << endl << endl << "\t仓库中没有这种商品!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    
    ofstream storeFile1("store.txt");
    ifstream tempFile1("temp.txt");
    storeFile1 << tempFile1.rdbuf();
    storeFile1.close();
    tempFile1.close();
    
    cout << endl << "\t这些商品已经出库, 请仔细检查!!!" << endl << endl << "\t";
    system("pause");
}

void mana::select_admin()//查询管理员信息 
{
	system("cls");
	string name1;
	string password1;   
    ifstream storeFile("admin.txt");
    if (!storeFile)
    {
        cout << endl << endl << "\t对不起，您的管理员信息库为空!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    cout << endl    << "   管理员用户名    " << "密码    " << endl << endl;
    while (storeFile >> name1 >> password1 )
    {
        cout << setiosflags(ios::left) <<"        "<<setw(10) << name1 << "  "<< setw(10) << password1 << endl;
    }
    storeFile.close();
    cout << endl << endl;
    system("pause");
} 

void mana::select_ele()//查询 
{
    while (1)
    {
		system("cls"); 
		cout<< endl <<endl;
    	cout<<" \t█████████████████████████████" << endl
         	<< "\t█                                                      █" << endl
            << "\t█                                                      █" << endl
            << "\t█                      商 品 查 询                     █" << endl
            << "\t█                                                      █" << endl
            << "\t█                                                      █" << endl
            << "\t█                 1.  按商品名称查询                   █" << endl
            << "\t█                                                      █" << endl
            << "\t█                 2.  按商品价格查询                   █" << endl
            << "\t█                                                      █" << endl
            << "\t█                 3.  按商品大类查询                   █" << endl
            << "\t█                                                      █" << endl
            << "\t█                 4.  返回                             █" << endl
            << "\t█                                                      █" << endl
            << "\t█                                                      █" << endl
            << "\t█                                                      █" << endl
            << "\t█████████████████████████████" << endl << endl << "\t\t";
        char select = getch();
        
        switch (select)
        {
        case '1':
            select_name();
            break;
        case '2':
            select_price();
            break;
        case '3':
            select_kind();
            break;
        case '4':
            return;
        default:
            break;
        }
    }
}

void mana::select_name()//按名称 
{
    system("cls");
    cout << endl << "\t按商品名查询 : " << endl << endl ;
    cout << "\t输入商品名 : ";
    string name;
    cin >> name;

    string name1;//商品名
    double price1;//介格
    string storeNo1;//仓库编号 
    string kinds1;//商品大类
    string shelfNo1;//货架号
    long count1 = 0; //商品数量
    
    ifstream storeFile("store.txt");
    if (!storeFile)
    {
        cout << endl << endl << "\t对不起，你的库存为空!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    
    bool flag = false;
    cout << endl    << "   商品名    " << "商品价格    " << "商品数量    " << "仓库编号    " << "商品大类    " << "货架编号    " << endl << endl;
    while (storeFile >> name1 >> price1 >> count1 >> storeNo1 >> kinds1 >> shelfNo1)
    {
        if (name1 == name)
        {
            flag = true;
            cout << setiosflags(ios::left) <<"   "<<setw(10) << name1 << "  "
                << setw(10) << price1 << "    " << setw(10) << count1 << " "
                << setw(9) << storeNo1 << " " << setw(10) << kinds1 << "   "
                << shelfNo1 << endl;
        }
    }
    storeFile.close();
    
    if (!flag)
        cout << endl << endl << "对不起，库存中没有这种商品!!!";
    cout << endl << endl;
    system("pause");
}

void mana::select_price()//按价格 
{
    system("cls");
    cout << endl << "\t按商品价格查询 : " << endl << endl ;
    cout << "\t输入价格 : ";
    double price;//
   cin >> price;
    
    string name1;//商品名
    double price1;//商品价格
    string storeNo1;//仓库编号 
    string kinds1;//商品大类
    string shelfNo1;//货架编 
    long count1 = 0; //商品数量
    
    ifstream storeFile("store.txt");
    if (!storeFile)
    {
        cout << endl << endl << "\t对不起，你的库存为空!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    
    bool flag = false;
    cout << endl    << "   商品名    " << "商品价格    " << "商品数量    " << "仓库编号    " << "商品大类    " << "货架编号    " << endl << endl;
    while (storeFile >> name1 >> price1 >> count1 >> storeNo1 >> kinds1 >> shelfNo1)
    {
        if (price1 == price)
        {
            flag = true;
            cout << setiosflags(ios::left) <<"   "<<setw(10) << name1 << "  "
                << setw(10) << price1 << "    " << setw(10) << count1 << " "
                << setw(9) << storeNo1 << " " << setw(10) << kinds1 << "   "
                << shelfNo1 << endl;
        }
    }
    storeFile.close();
    
    if (!flag)
        cout << endl << endl << "对不起，库存中没有这个价格的商品!!!";
    cout << endl << endl;
    system("pause");
}

void mana::select_kind()//按类 
{
    system("cls");
    cout << endl << "\t按商品大类查询 : " << endl << endl ;
    cout << "\t输入大类名 : ";
    string kinds;
    cin >> kinds;
    
    string name1;//商品名
    double price1;//价格
    string storeNo1;//仓库编号 
    string kinds1;//商品大类
    string shelfNo1;//货架号
    long count1 = 0; //商品数量
    
    ifstream storeFile("store.txt");
    if (!storeFile)
    {
        cout << endl << endl << "\t对不起，你的库存为空!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    
    bool flag = false;
   	cout << endl    << "   商品名    " << "商品价格    " << "商品数量    " << "仓库编号    " << "商品大类    " << "货架编号    " << endl << endl;
    while (storeFile >> name1 >> price1 >> count1 >> storeNo1 >> kinds1 >> shelfNo1)
    {
        if (kinds1 == kinds)
        {
            flag = true;
            cout << setiosflags(ios::left) <<"   "<<setw(10) << name1 << "  "
                << setw(10) << price1 << "    " << setw(10) << count1 << " "
                << setw(9) << storeNo1 << " " << setw(10) << kinds1 << "   "
                << shelfNo1 << endl;
        }
    }
    storeFile.close();
    
    if (!flag)
        cout << endl << endl << "对不起，库存中没有这类商品!!!";
    cout << endl << endl;
    system("pause");
}

void mana::call_break()//报损 
{
    system("cls");//
   string name;//商品名
    
    cout << endl << "\t商品报损，请输入要报损商品信息 : " << endl << endl;
    cout << "\t商品名称 : ";
    cin >> name;
    
    ifstream storeFile("store.txt");
    if (!storeFile)
    {
        ofstream storeFile1("store.txt");
        storeFile1.close();
        cout << endl << endl << "\t仓存为空!!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    
    bool flag = false;
    string name1;//商品名
    double price1;//商品价格
    string storeNo1;//仓库编号 
    string kinds1;//商品大类
    string shelfNo1;//货架编号
    long count1 = 0; //商品数量
    
    ofstream tempFile("temp.txt");
    cout << endl << endl << "你想报损商品信息如下 : " << endl << endl;
    cout << endl << "商品名称         " << "商品价格      " << "商品数量  " << "仓库编号    " 
        << "商品大类        " << "货架编号" << endl << endl;      
    while (storeFile >> name1 >> price1 >> count1 >> storeNo1 >>  kinds1 >> shelfNo1)
    {
        if (name1==name)
        {
            flag = true;
            cout << setiosflags(ios::left) << setw(15) << name1 << " "
                                           << setw(10) << price1 << " " 
										   << setw(10) << count1 << " "
                                           << setw(10) << storeNo1 << " " 
										   << setw(15) << kinds1 << " "
                << shelfNo1 << endl;
            shelfNo1 += "(损坏)";
        }
        tempFile << setiosflags(ios::left) << setw(20) << name1 << " "
                << setw(15) << price1 << " " << setw(10) << count1 << " "
                << setw(10) << storeNo1 << " " << setw(20) << kinds1 << " "
                << shelfNo1 << endl;
    }
    tempFile.close();
    storeFile.close();
    
    if (!flag)
    {
        cout << endl << endl << "对不起，仓库中没有这种商品!!!" << endl << endl;
        system("pause");
        return;
    }
    ofstream storeFile1("store.txt");
    ifstream tempFile1("temp.txt");
    storeFile1 << tempFile1.rdbuf();
    storeFile1.close();
    tempFile1.close();
   cout << endl << endl << "这些商品已经损坏，请尽快从仓库中取出!!!" << endl << endl;
    cout << "报损成功，记录已经更改!!!" << endl << endl ;    
    
    system("pause");
}

int main()
{
    char choice;
    mana men; 
    while (choice = men.zero_face())
    {
        switch (choice)
        {
	        case '1':
	            men.enter();
	            break;
	        case '2':
	            men.chief_enroll();
	            break;
	        case '3':
				men.clogout();    
	            break;
	        case '4':
	        	{
					system("cls");		
				    cout<< endl;
				    cout<<endl <<"\t█████████████████████████████"
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█                                                      █" 
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█                   谢  谢  使  用  ！                 █"
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█                                                      █"     
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█                                                      █"
				        <<endl <<"\t█████████████████████████████" 
						<<"\t";	
	            		exit( 0 );
	            		break;
	           	}
	        default:
	            break;
        }
    }
    return 0;
} 

