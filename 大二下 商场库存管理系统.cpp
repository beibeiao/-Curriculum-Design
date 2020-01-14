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

class shelf//���� 
{
public:
    shelf();
private:
    admin men;//����Ա
    string storeNo;//�ֿ��� 
    string kinds;//��Ʒ����
    string shelfNo;//���ܺ�
};

class ele//��Ʒ 
{
public:
    ele();
private:
    string name;//��Ʒ��
    double price;//�۸�  
    shelf sh;//��������
    long count;//��Ʒ����
};

class mana{//���� 

private:
	admin ap;
    ele aele;
    shelf ashelf;
    admin abs;
public:	
	void enter();			//��¼ 
	void enroll();			//ע��
	void chief_enroll();	//����ע�� 
	void logout();			//ɾ������
	void clogout();			// 
	void logout_logout();	//ɾ��
	void clogout_logout();	//ɾ��
	char zero_face();		//��ҳ 
	
	mana();
    char first_face();//����Ա��ҳ
    char chief_face();//������ҳ
    
    void in_storage();//���
    void out_storage();//����
    void select_admin();//����Ա��Ϣ��ѯ 
    void select_ele();//��Ʒ��ѯ
    void select_name();//����Ʒ���Ʋ�ѯ
    void select_price();//����Ʒ�۸��ѯ
    void select_kind();//�������ѯ
    void call_break();//��Ʒ���� 
};

admin::admin()   
{
    name = "xxx";
    password = "000000";
}

ele::ele():sh()
{
    name = "xxx";//��Ʒ��
    price = 0.0;//�۸�
    count = 0;//��Ʒ����
}                             

shelf::shelf():men()
{
    storeNo = "xxx";//�ֿ���
    kinds = "xxx";//��Ʒ����
    shelfNo = "xxx";;//���ܺ�
}

mana::mana():aele(), ashelf(), abs()
{
	
}

char mana::zero_face()//��ҳ 
{
	system("color 1E");//0=��ɫ 1=��ɫ 2=��ɫ 3=����ɫ 4=��ɫ 5=��ɫ 6=��ɫ 7=��ɫ 8=��ɫ 9=����ɫ
    system("cls");//A=����ɫ B=��ǳ��ɫ C=����ɫ D=����ɫ E=����ɫ F=����ɫ
    cout<< endl << endl;//0E 1E 
    cout<<endl <<"\t    ��������������������������������������������������������"
        <<endl <<"\t    ��                                                    ��"
        <<endl <<"\t    ��                                                    ��"
        <<endl <<"\t    ��                   �̳�������ϵͳ                 ��"
        <<endl <<"\t    ��                                                    ��"
        <<endl <<"\t    ��                                                    ��" 
        <<endl <<"\t    ��                    1.  ��¼ϵͳ                    ��"
        <<endl <<"\t    ��                                                    ��"
        <<endl <<"\t    ��                    2.  ����ע��                    ��"
        <<endl <<"\t    ��                                                    ��"
        <<endl <<"\t    ��                    3.  ɾ���˺�                    ��"    
        <<endl <<"\t    ��                                                    ��" 		     
        <<endl <<"\t    ��                    4.  �˳�ϵͳ                    ��"         
        <<endl <<"\t    ��                                                    ��"
        <<endl <<"\t    ��                                                    ��"
        <<endl <<"\t    ��                                                    ��"
        <<endl <<"\t    ��������������������������������������������������������" 
		<<endl 
		<<endl 
		<<"\t";
    
    return getch();
}

void mana::enter()//��¼ģ�� 
{
	system("cls");      
    cout << endl << endl << endl << "\t��ӭ��¼��������ϵͳ :) " << endl << endl ;
    
	cout << "\t�������û��� : ";
    string admin;
    cin >> admin;
    
    cout << endl <<"\t���������� : ";
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
        cout << endl << endl << "\t�Բ�������δע��:-(" << endl << endl << "\t";
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
            cout<<endl<<endl<<"\t������ȷ" <<endl; 
            first_face();//����Ա��ҳ 
        }
    }
    
    while (cstoreFile >> cadmin1 >> cpassword1 )
	{
        if (cadmin1 == admin&&cpassword1 == password)
        {
            cflag = true;
            flag = true;
            cout<<endl<<endl<<"\t������ȷ" <<endl; 
            chief_face();//������ҳ 
        }
    }
    
    storeFile.close();
    cstoreFile.close();
    
    if (!flag||!cflag)
        cout << endl << endl << "�Բ����û������������:-(";
    cout << endl << endl;
    system("pause");

}

void mana::enroll()//����Աע�� 
{
	system("cls");
	string admin;
	string password;
	
	cout << endl << "��ӭע�����Ա�˺ţ������������Ϣ : " << endl << endl ;	
	
	cout << "\t�û��� : ";
    cin >> admin;
    cout << endl << "\t���� : ";
    cin >> password;
    
    string admin1;
    ifstream storeFile0("admin.txt");
	storeFile0 >> admin1; 

    if (admin1 == admin)
	{ 
    	cout<<endl<<endl<<"\t���û����ѱ�ע�ᣡ" <<endl;
    	cout << endl << endl;
    	system("pause");
    	chief_face();
    }
    
    else{
	    storeFile0.close();
	    
	    ofstream storeFile("admin.txt", ios::app);
	    storeFile << setiosflags(ios::left) << setw(20) <<  admin << " "<< setw(15) << password << endl;
	    storeFile.close();
	    
	    cout << endl << endl << "\tע��ɹ������¼..." << endl << endl << "\t";
	    system("pause");	
	}
	
}

void mana::chief_enroll()//����ע�� 
{
	system("cls");
	string cadmin;
	string cpassword;
	string check="9527"; 
	
	cout << endl << "��ӭע�ᴦ���˺ţ������������Ϣ : " << endl << endl ;	
	
	cout << "\t�û��� : ";
    cin >> cadmin;
    cout << endl << "\t���� : ";
    cin >> cpassword;
    cout << endl << "\t��֤�� : ";
    cin >> check;
    
    if(check=="9527"){
    	
	    string cadmin1;
	    ifstream storeFile0("cadmin.txt");
		storeFile0 >> cadmin1; 
	
	    if (cadmin1 == cadmin)
		{ 
	    	cout<<endl<<endl<<"\t���û����ѱ�ע�ᣡ" <<endl;
	    	cout << endl << endl;
	    	system("pause");
	    	zero_face();
	    }
	    
	    else{
    	
	    	ofstream storeFile("cadmin.txt", ios::app);
		    storeFile << setiosflags(ios::left) << setw(20) <<  cadmin << " "<< setw(15) << cpassword << endl;
		    storeFile.close();
		    
		    cout << endl << endl << "\tע��ɹ������¼..." << endl << endl << "\t";
		    system("pause");
		}
	}
    else{
    	cout << endl << endl << "�Բ�����֤��������޷�ע��:-(";
    	cout << endl << endl;
    	system("pause");
	}
}

void mana::logout()//ɾ������ 
{
	while (1)
    {
		system("cls");		
	    cout<< endl;
	    cout<<endl <<"\t����������������������������������������������������������"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��           ��ȷ��Ҫɾ�����й���Ա�˺ż���Ϣ��       ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��" 
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                       1.  ��                         ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                       2.  ��...                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"     
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t����������������������������������������������������������" 
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

void mana::clogout()//ɾ���������� 
{
	while (1)
    {
		system("cls");		
	    cout<< endl;
	    cout<<endl <<"\t����������������������������������������������������������"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��               ��ȷ��Ҫɾ�����д����˺���           ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��" 
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                       1.  ��                         ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                       2.  ��...                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"     
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t��                                                      ��"
	        <<endl <<"\t����������������������������������������������������������" 
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
 
void mana::logout_logout()//ɾ�� 
{
	system("cls");
    ofstream storeFile1("admin.txt");
    ifstream tempFile1("admins.txt");
    storeFile1 << tempFile1.rdbuf();
    storeFile1.close();
    tempFile1.close();
    
    cout << endl << "\t��ɾ�����й���Ա�˺ż���Ϣ :)" << endl << endl << "\t";
	system("pause");
	chief_face(); 
}

void mana::clogout_logout()//ɾ������
{
	system("cls");
	string check="9527";
	string check1;
	
	cout<< endl << endl << "\t��������֤�룺";
	cin>>check1; 
	if(check1==check)
	{
		ofstream storeFile1("cadmin.txt");
	    ifstream tempFile1("cadmins.txt");
	    storeFile1 << tempFile1.rdbuf();
	    storeFile1.close();
	    tempFile1.close();
	    
	    cout << endl << "\t��ɾ�����д����˺� :)" << endl << endl << "\t";
	}
	else{
		cout<< endl << "\t��֤�����"<< endl << endl <<"\t"; 
	}
	system("pause");
	zero_face();
} 

char mana::first_face()//����Ա��ҳ 
{
    system("cls");
    cout<< endl <<endl;
    cout<<endl <<"\t����������������������������������������������������������"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��              �̳�������ϵͳ������Ա��              ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                                                      ��" 
        <<endl <<"\t��                    1.  ��Ʒ���                      ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                    2.  ��Ʒ����                      ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                    3.  ��ѯͳ��                      ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                    4.  ��Ʒ����                      ��"
        <<endl <<"\t��                                                      ��"     
        <<endl <<"\t��                    5.  �˳�ϵͳ                      ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t����������������������������������������������������������" 
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
	            cout << "\t" << "ллʹ��!!!!" << endl << endl << "\t\t";
	            exit( 0 );
	            break;
	        default:
	            break;
        }		
		men.first_face();
}

char mana::chief_face()//������ҳ
{
    system("cls");
    cout<< endl <<endl;
    cout<<endl <<"\t����������������������������������������������������������"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��               �̳�������ϵͳ��������               ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                                                      ��" 
        <<endl <<"\t��                   1.  ��Ʒ��ѯ                       ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                   2.  ����Ա��Ϣ��ѯ                 ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                   3.  ����Ա�˺�ע��                 ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                   4.  ����Ա�˺�ɾ��                 ��"
		<<endl <<"\t��                                                      ��" 
        <<endl <<"\t��                   5.  ������ҳ                       ��"   
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                   6.  �˳�ϵͳ                       ��"   
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t��                                                      ��"
        <<endl <<"\t����������������������������������������������������������" 
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
	            cmen.select_admin();//�Ź���ԱϢ��ѯ 
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
	            cout << "\t" << "ллʹ��!!!!" << endl << endl << "\t\t";
	            exit( 0 );
	            break;
	        default:
	            break;
        }		
		cmen.chief_face();

} 

void mana::in_storage()//��� 
{
    system("cls");
    string name;//��Ʒ��
    double price;//�۸�                                                                              
    string storeNo;//�ֿ��� 
    string kinds;//��Ʒ����
    string shelfNo;//���ܺ�
    long count = 0; //��Ʒ����
    
    cout << endl << "��Ʒ��⣬�����������Ϣ : " << endl << endl ;
    
	cout << "\t��Ʒ���� : ";                                                                         
    cin >> name;
    cout << endl << "\t��Ʒ�۸� : ";
    cin >> price;
    cout << endl << "\t��Ʒ���� : ";
    cin >> count;
    cout << endl << "\t�ֿ��� : ";                                                            
    cin >> storeNo;
    cout << endl << "\t��Ʒ���� : ";
    cin >> kinds;
    cout << endl << "\t���ܱ�� : " ;
    cin >> shelfNo;                                                                             
    
    ofstream storeFile("store.txt", ios::app);
    storeFile << setiosflags(ios::left) << setw(20) << name << " "
        << setw(15) << price << " " << setw(10) << count << " "
        << setw(10) << storeNo << " " << setw(20) << kinds << " "
        << shelfNo << endl;                                                                         
    storeFile.close();
    
    cout << endl << endl << "\t����Ʒ�Ѿ����......." << endl << endl << "\t";

}

void mana::out_storage()//���� 
{
    system("cls");//ִ�п���̨����cls������CMD�����cls�����������������������ʾ����Ϣ��
    
    string name;//��Ʒ��
    
    cout << endl << "\t��Ʒ���⣬���������Ʒ��Ϣ : " << endl << endl;
    cout << "\t��Ʒ���� : ";
    cin >> name;
    
    ifstream storeFile("store.txt");
    if (!storeFile)
    {
        ofstream storeFile1("store.txt");
        storeFile1.close();
        cout << endl << endl << "\t�ִ�Ϊ��!!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    bool flag = false;//��bool�͵�flag��Ϊ�Ƿ����������ı�ʶ����.�Ͷ���һ���������͵ı�ʶûʲô����
    string name1;//��Ʒ��
    double price1;//�۸�
    string storeNo1;//�ֿ��� 
    string kinds1;//��Ʒ����
    string shelfNo1;//���ܺ�
    long count1 = 0; //��Ʒ����
    
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
        cout << endl << endl << "\t�ֿ���û��������Ʒ!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    
    ofstream storeFile1("store.txt");
    ifstream tempFile1("temp.txt");
    storeFile1 << tempFile1.rdbuf();
    storeFile1.close();
    tempFile1.close();
    
    cout << endl << "\t��Щ��Ʒ�Ѿ�����, ����ϸ���!!!" << endl << endl << "\t";
    system("pause");
}

void mana::select_admin()//��ѯ����Ա��Ϣ 
{
	system("cls");
	string name1;
	string password1;   
    ifstream storeFile("admin.txt");
    if (!storeFile)
    {
        cout << endl << endl << "\t�Բ������Ĺ���Ա��Ϣ��Ϊ��!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    cout << endl    << "   ����Ա�û���    " << "����    " << endl << endl;
    while (storeFile >> name1 >> password1 )
    {
        cout << setiosflags(ios::left) <<"        "<<setw(10) << name1 << "  "<< setw(10) << password1 << endl;
    }
    storeFile.close();
    cout << endl << endl;
    system("pause");
} 

void mana::select_ele()//��ѯ 
{
    while (1)
    {
		system("cls"); 
		cout<< endl <<endl;
    	cout<<" \t����������������������������������������������������������" << endl
         	<< "\t��                                                      ��" << endl
            << "\t��                                                      ��" << endl
            << "\t��                      �� Ʒ �� ѯ                     ��" << endl
            << "\t��                                                      ��" << endl
            << "\t��                                                      ��" << endl
            << "\t��                 1.  ����Ʒ���Ʋ�ѯ                   ��" << endl
            << "\t��                                                      ��" << endl
            << "\t��                 2.  ����Ʒ�۸��ѯ                   ��" << endl
            << "\t��                                                      ��" << endl
            << "\t��                 3.  ����Ʒ�����ѯ                   ��" << endl
            << "\t��                                                      ��" << endl
            << "\t��                 4.  ����                             ��" << endl
            << "\t��                                                      ��" << endl
            << "\t��                                                      ��" << endl
            << "\t��                                                      ��" << endl
            << "\t����������������������������������������������������������" << endl << endl << "\t\t";
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

void mana::select_name()//������ 
{
    system("cls");
    cout << endl << "\t����Ʒ����ѯ : " << endl << endl ;
    cout << "\t������Ʒ�� : ";
    string name;
    cin >> name;

    string name1;//��Ʒ��
    double price1;//���
    string storeNo1;//�ֿ��� 
    string kinds1;//��Ʒ����
    string shelfNo1;//���ܺ�
    long count1 = 0; //��Ʒ����
    
    ifstream storeFile("store.txt");
    if (!storeFile)
    {
        cout << endl << endl << "\t�Բ�����Ŀ��Ϊ��!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    
    bool flag = false;
    cout << endl    << "   ��Ʒ��    " << "��Ʒ�۸�    " << "��Ʒ����    " << "�ֿ���    " << "��Ʒ����    " << "���ܱ��    " << endl << endl;
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
        cout << endl << endl << "�Բ��𣬿����û��������Ʒ!!!";
    cout << endl << endl;
    system("pause");
}

void mana::select_price()//���۸� 
{
    system("cls");
    cout << endl << "\t����Ʒ�۸��ѯ : " << endl << endl ;
    cout << "\t����۸� : ";
    double price;//
   cin >> price;
    
    string name1;//��Ʒ��
    double price1;//��Ʒ�۸�
    string storeNo1;//�ֿ��� 
    string kinds1;//��Ʒ����
    string shelfNo1;//���ܱ� 
    long count1 = 0; //��Ʒ����
    
    ifstream storeFile("store.txt");
    if (!storeFile)
    {
        cout << endl << endl << "\t�Բ�����Ŀ��Ϊ��!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    
    bool flag = false;
    cout << endl    << "   ��Ʒ��    " << "��Ʒ�۸�    " << "��Ʒ����    " << "�ֿ���    " << "��Ʒ����    " << "���ܱ��    " << endl << endl;
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
        cout << endl << endl << "�Բ��𣬿����û������۸����Ʒ!!!";
    cout << endl << endl;
    system("pause");
}

void mana::select_kind()//���� 
{
    system("cls");
    cout << endl << "\t����Ʒ�����ѯ : " << endl << endl ;
    cout << "\t��������� : ";
    string kinds;
    cin >> kinds;
    
    string name1;//��Ʒ��
    double price1;//�۸�
    string storeNo1;//�ֿ��� 
    string kinds1;//��Ʒ����
    string shelfNo1;//���ܺ�
    long count1 = 0; //��Ʒ����
    
    ifstream storeFile("store.txt");
    if (!storeFile)
    {
        cout << endl << endl << "\t�Բ�����Ŀ��Ϊ��!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    
    bool flag = false;
   	cout << endl    << "   ��Ʒ��    " << "��Ʒ�۸�    " << "��Ʒ����    " << "�ֿ���    " << "��Ʒ����    " << "���ܱ��    " << endl << endl;
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
        cout << endl << endl << "�Բ��𣬿����û��������Ʒ!!!";
    cout << endl << endl;
    system("pause");
}

void mana::call_break()//���� 
{
    system("cls");//
   string name;//��Ʒ��
    
    cout << endl << "\t��Ʒ����������Ҫ������Ʒ��Ϣ : " << endl << endl;
    cout << "\t��Ʒ���� : ";
    cin >> name;
    
    ifstream storeFile("store.txt");
    if (!storeFile)
    {
        ofstream storeFile1("store.txt");
        storeFile1.close();
        cout << endl << endl << "\t�ִ�Ϊ��!!!!" << endl << endl << "\t";
        system("pause");
        return;
    }
    
    bool flag = false;
    string name1;//��Ʒ��
    double price1;//��Ʒ�۸�
    string storeNo1;//�ֿ��� 
    string kinds1;//��Ʒ����
    string shelfNo1;//���ܱ��
    long count1 = 0; //��Ʒ����
    
    ofstream tempFile("temp.txt");
    cout << endl << endl << "���뱨����Ʒ��Ϣ���� : " << endl << endl;
    cout << endl << "��Ʒ����         " << "��Ʒ�۸�      " << "��Ʒ����  " << "�ֿ���    " 
        << "��Ʒ����        " << "���ܱ��" << endl << endl;      
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
            shelfNo1 += "(��)";
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
        cout << endl << endl << "�Բ��𣬲ֿ���û��������Ʒ!!!" << endl << endl;
        system("pause");
        return;
    }
    ofstream storeFile1("store.txt");
    ifstream tempFile1("temp.txt");
    storeFile1 << tempFile1.rdbuf();
    storeFile1.close();
    tempFile1.close();
   cout << endl << endl << "��Щ��Ʒ�Ѿ��𻵣��뾡��Ӳֿ���ȡ��!!!" << endl << endl;
    cout << "����ɹ�����¼�Ѿ�����!!!" << endl << endl ;    
    
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
				    cout<<endl <<"\t����������������������������������������������������������"
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t��                                                      ��" 
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t��                   л  л  ʹ  ��  ��                 ��"
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t��                                                      ��"     
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t��                                                      ��"
				        <<endl <<"\t����������������������������������������������������������" 
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

