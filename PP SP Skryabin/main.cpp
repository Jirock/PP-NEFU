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
                default: cout<<"Не верный выбор/n";         
            }     
        } 
    } 
 
    void enter_new()                         // ф-ция ввода новой структуры 
    {  
        if(sch<30) //вводим новую запись только, если счетчик полных записей меньше максимального количества записей  
    {     
        cout<<"Запись номер"<<sch+1; //выводим номер записи   
		cout<<"\nВыберите вид программирования (1 - Веб, 2 - Десктоп)\n";   
        cin>>mas[sch].type;  
        cout<<"\nВведите Имя\n";  
        cin>>mas[sch].name;   
        cout<<"Введите Фамилию \n";  
        cin>>mas[sch].fam;   
        cout<<"Введите опыт работы(в годах)\n";   
        cin>>mas[sch].opyt;   
        cout<<"Введите ЯП\n";   
        cin>>mas[sch].prog;   
        cout<<"Введите технологию\n";   
        cin>>mas[sch].tech;   
        sch++; //увеличиваем счетчик полных записей на единицу  
    }  
       else cout<<"Введено максимальное кол-во записей"; 
    } 
 

    int menu() 
    { 
        int er;  
        cout<<"Введите:\n";  
        cout<<"1-для удаления записи\n";  
        cout<<"2-для ввода новой записи\n";  
        cout<<"3-для изменения записи\n";  
        cout<<"4-для вывода записи(ей)\n"; 
        cout<<"5-для поиска \n";  
        cout<<"6-для выхода\n";  
        cin>>er;  
        return er; 
    } 
 
    void out()    //ф-ция вывода записей 
    {    
        int sw;   // переключатель для выбора выводить все записи или одну    
        int k;    //номер структуры, кот. надо вывести    
        if (sch==0) //если счетсик количества структур равен 0, то выводим, что нет записей
               cout<<"\nНет запичей: \n";    
        else    
    {   
        cout<<"\nВведите: \n";    
        cout<<"1-если хотите вывести какую-либо запсь\n";    
        cout<<"2-если хотите вывести все записи\n";   
        cin>>sw;    
        if(sw==1)    
        {    
            cout<<"Введите номер записи, которую нужно вывести\n";        
            cin>>k;        
            cout<<endl;     
        if (mas[k-1].type==1)   
            cout<<"Веб"<<endl;     
        else   
            cout<<"Десктоп"<<endl;     
            cout<<"Имя:"<<mas[k-1].name<<endl;     
            cout<<"Фамилия:"<<mas[k-1].fam<<endl;        
            cout<<"Опыт работы:"<<mas[k-1].opyt<<endl;     
            cout<<"Яп:"<<mas[k-1].prog<<endl;     
            cout<<"Технология:"<<mas[k-1].tech<<endl;     
            cout<<"____________"<<endl; 
        }    
        if(sw==2)    
        {  
            for(int i=0;i<sch;i++) //выводим в цикле все записи       
            {       
                if (mas[i].type==1)   
                cout<<"Веб"<<endl;     
                else   
                cout<<"Десктоп"<<endl;      
				cout<<"Имя:"<<mas[i].name<<endl;//выводим на экран значение name i-ой структуры из массива структур mas      
				cout<<"Фамилия:"<<mas[i].fam<<endl;        
				cout<<"Опыт работы:"<<mas[i].opyt<<endl;      
                cout<<"ЯП:"<<mas[i].prog<<endl;      
                cout<<"Технология:"<<mas[i].tech<<endl;      
                cout<<"____________"<<endl;    
            }   
        }    
    } 
} 
 
void del()        //ф-ция удаления записи 
{ 	
    int d;        //номер записи, которую нужно удалить     
    cout<<"\nВведите номер записи, которую необходимо удалить\n";    
    cout<<"Если необходимо удалить все записи,нажмите '99'\n";     
    cin>>d;     
    if (d!=99)    
    {   
        for (int i=(d-1);i<sch;i++) //цикл для удаления заданной записи, начинаем цикл с удаляемой записи        
        mas[i]=mas[i+1]; //замещаем текущую запись следующей за ней       
        sch=sch-1; //уменяьшаем счетчик полных записей на 1  
    }     
    if (d==99) 
    {    
        for(int i=0;i<30;i++)//цикл по все записям от первой до 30-ой            
        mas[i]=tmp; //замещаем каждую структуру в массиве пустой структурой   
        sch=0; //счетчик структур обнуляем, т.к. все записи удалены  
    } 
} 
 
    void change() //функция для изменения записи 
    {  	 
        int c;                         //номер записи, которую нужно изменить     
        int per;  
        cout<<"\nВведите номер записи\n";  
        cin>> c;  
    do    
    {  	
        cout<<"Введите: \n";  
        cout<<"1-для изменения Имени\n";  
        cout<<"2-для изменения Фамилии\n";  
        cout<<"3-для изменения Опыта работы\n";  
        cout<<"4-для изменения ЯП\n";  
        cout<<"5-для изменения ЯП\n";  
        cout<<"6-для изменения Технологии\n";  
        cout<<"7-для прекращения\n";  
        cin>>per;  
        switch (per)  
        { 
            case 1: cout<<"\nВведите новый вид (1 - Веб, 2 - Десктоп)\n";   
                cin>>mas[c-1].type;   
                break;   
            case 2: cout<<"\nВведите новое имя\n";   
                cin>>mas[c-1].name;   
                break;   
            case 3: cout<<"Введите новую Фамилию \n";   
                cin>>mas[c-1].fam;   
                break;   
            case 4: cout<<"Введите новый Опыт работы\n";   
                cin>>mas[c-1].opyt;   
                break;   
            case 5: cout<<"Введите новый ЯП\n";   
                cin>>mas[c-1].prog;   
                break;   
            case 6: cout<<"Введите новую Технологию\n";   
                cin>>mas[c-1].tech;   
                break;   
            case 7: return;  
        } 
    }
    while(1); 
} 
 
void find()   //ф-ция поиска записей 
{   int sw;     // переключатель    
    if (sch==0)       
        cout<<"\nНет запичей: \n";    
    else    
    {    	
        cout<<"\nВведите: \n";    
        cout<<"1-все Вебы\n";   
        cout<<"2-все Десктопы\n";    
        cin>>sw; 

 
    for(int i=0;i<sch;i++) //в цикле просматриваем все структуры из массива структур  
        if (mas[i].type==sw)   
        {     
            if (mas[i].type==1)   
                cout<<"Веб"<<endl;     
            else   
                cout<<"Десктоп"<<endl;      
				cout<<"Имя:"<<mas[i].name<<endl;      
				cout<<"Фамилия.:"<<mas[i].fam<<endl;         
				cout<<"Опыт работы:"<<mas[i].opyt<<endl;      
                cout<<"ЯП:"<<mas[i].prog<<endl;      
                cout<<"Технологии:"<<mas[i].tech<<endl;      
                cout<<"____________"<<endl;  
        }     
    } 
}

