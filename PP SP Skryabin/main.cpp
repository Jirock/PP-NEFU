#include <iostream> 
#include <string>
#include <windows.h> 
using namespace std; 
 
struct sklad  
{
    char name[30];    
    char fam[30];       
    float opyt;         
    char prog[30];            
    char tech[30];        
    int type;           
}; 
 
    struct sklad mas[30]; 
    struct sklad tmp; 
    int sch=0;       
    int er;            
 
    void enter_new(); 
    int menu(); 
    void out(); 
    void del();  
    void change(); 
    void find(); 
 
   int main() 
    {  
        setlocale(LC_ALL,"Russian");  
        while(1)  
    { 	    
            switch(menu())   
            {
                case 1:del();break; 
                case 2:enter_new();break; 
                case 3:change();break;
                case 4:out();break;  
                case 5:find();break; 
                case 6: return 0; 
                default: cout<<"�� ������ �����/n";         
            }     
        } 
    } 
 
    void enter_new()                         // �-��� ����� ����� ��������� 
    {  
        if(sch<30) //������ ����� ������ ������, ���� ������� ������ ������� ������ ������������� ���������� �������  
    {     
        cout<<"������ �����"<<sch+1; //������� ����� ������   
		cout<<"\n�������� ��� ���������������� (1 - ���, 2 - �������)\n";   
        cin>>mas[sch].type;  
        cout<<"\n������� ���\n";  
        cin>>mas[sch].name;   
        cout<<"������� ������� \n";  
        cin>>mas[sch].fam;   
        cout<<"������� ���� ������(� �����)\n";   
        cin>>mas[sch].opyt;   
        cout<<"������� ��\n";   
        cin>>mas[sch].prog;   
        cout<<"������� ����������\n";   
        cin>>mas[sch].tech;   
        sch++; //����������� ������� ������ ������� �� �������  
    }  
       else cout<<"������� ������������ ���-�� �������"; 
    } 
 

    int menu() 
    { 
        int er;  
        cout<<"�������:\n";  
        cout<<"1-��� �������� ������\n";  
        cout<<"2-��� ����� ����� ������\n";  
        cout<<"3-��� ��������� ������\n";  
        cout<<"4-��� ������ ������(��)\n"; 
        cout<<"5-��� ������ \n";  
        cout<<"6-��� ������\n";  
        cin>>er;  
        return er; 
    } 
 
    void out()    //�-��� ������ ������� 
    {    
        int sw;   // ������������� ��� ������ �������� ��� ������ ��� ����    
        int k;    //����� ���������, ���. ���� �������    
        if (sch==0) //���� ������� ���������� �������� ����� 0, �� �������, ��� ��� �������
               cout<<"\n��� �������: \n";    
        else    
    {   
        cout<<"\n�������: \n";    
        cout<<"1-���� ������ ������� �����-���� �����\n";    
        cout<<"2-���� ������ ������� ��� ������\n";   
        cin>>sw;    
        if(sw==1)    
        {    
            cout<<"������� ����� ������, ������� ����� �������\n";        
            cin>>k;        
            cout<<endl;     
        if (mas[k-1].type==1)   
            cout<<"���"<<endl;     
        else   
            cout<<"�������"<<endl;     
            cout<<"���:"<<mas[k-1].name<<endl;     
            cout<<"�������:"<<mas[k-1].fam<<endl;        
            cout<<"���� ������:"<<mas[k-1].opyt<<endl;     
            cout<<"��:"<<mas[k-1].prog<<endl;     
            cout<<"����������:"<<mas[k-1].tech<<endl;     
            cout<<"____________"<<endl; 
        }    
        if(sw==2)    
        {  
            for(int i=0;i<sch;i++) //������� � ����� ��� ������       
            {       
                if (mas[i].type==1)   
                cout<<"���"<<endl;     
                else   
                cout<<"�������"<<endl;      
				cout<<"���:"<<mas[i].name<<endl;//������� �� ����� �������� name i-�� ��������� �� ������� �������� mas      
				cout<<"�������:"<<mas[i].fam<<endl;        
				cout<<"���� ������:"<<mas[i].opyt<<endl;      
                cout<<"��:"<<mas[i].prog<<endl;      
                cout<<"����������:"<<mas[i].tech<<endl;      
                cout<<"____________"<<endl;    
            }   
        }    
    } 
} 
 
void del()        //�-��� �������� ������ 
{ 	
    int d;        //����� ������, ������� ����� �������     
    cout<<"\n������� ����� ������, ������� ���������� �������\n";    
    cout<<"���� ���������� ������� ��� ������,������� '99'\n";     
    cin>>d;     
    if (d!=99)    
    {   
        for (int i=(d-1);i<sch;i++) //���� ��� �������� �������� ������, �������� ���� � ��������� ������        
        mas[i]=mas[i+1]; //�������� ������� ������ ��������� �� ���       
        sch=sch-1; //���������� ������� ������ ������� �� 1  
    }     
    if (d==99) 
    {    
        for(int i=0;i<30;i++)//���� �� ��� ������� �� ������ �� 30-��            
        mas[i]=tmp; //�������� ������ ��������� � ������� ������ ����������   
        sch=0; //������� �������� ��������, �.�. ��� ������ �������  
    } 
} 
 
    void change() //������� ��� ��������� ������ 
    {  	 
        int c;                         //����� ������, ������� ����� ��������     
        int per;  
        cout<<"\n������� ����� ������\n";  
        cin>> c;  
    do    
    {  	
        cout<<"�������: \n";  
        cout<<"1-��� ��������� �����\n";  
        cout<<"2-��� ��������� �������\n";  
        cout<<"3-��� ��������� ����� ������\n";  
        cout<<"4-��� ��������� ��\n";  
        cout<<"5-��� ��������� ��\n";  
        cout<<"6-��� ��������� ����������\n";  
        cout<<"7-��� �����������\n";  
        cin>>per;  
        switch (per)  
        { 
            case 1: cout<<"\n������� ����� ��� (1 - ���, 2 - �������)\n";   
                cin>>mas[c-1].type;   
                break;   
            case 2: cout<<"\n������� ����� ���\n";   
                cin>>mas[c-1].name;   
                break;   
            case 3: cout<<"������� ����� ������� \n";   
                cin>>mas[c-1].fam;   
                break;   
            case 4: cout<<"������� ����� ���� ������\n";   
                cin>>mas[c-1].opyt;   
                break;   
            case 5: cout<<"������� ����� ��\n";   
                cin>>mas[c-1].prog;   
                break;   
            case 6: cout<<"������� ����� ����������\n";   
                cin>>mas[c-1].tech;   
                break;   
            case 7: return;  
        } 
    }
    while(1); 
} 
 
void find()   //�-��� ������ ������� 
{   int sw;     // �������������    
    if (sch==0)       
        cout<<"\n��� �������: \n";    
    else    
    {    	
        cout<<"\n�������: \n";    
        cout<<"1-��� ����\n";   
        cout<<"2-��� ��������\n";    
        cin>>sw; 

 
    for(int i=0;i<sch;i++) //� ����� ������������� ��� ��������� �� ������� ��������  
        if (mas[i].type==sw)   
        {     
            if (mas[i].type==1)   
                cout<<"���"<<endl;     
            else   
                cout<<"�������"<<endl;      
				cout<<"���:"<<mas[i].name<<endl;      
				cout<<"�������.:"<<mas[i].fam<<endl;         
				cout<<"���� ������:"<<mas[i].opyt<<endl;      
                cout<<"��:"<<mas[i].prog<<endl;      
                cout<<"����������:"<<mas[i].tech<<endl;      
                cout<<"____________"<<endl;  
        }     
    } 
}

