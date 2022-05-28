#include <iostream>
#include <fstream>
using namespace std;
//Program poredi ispravne test slucaje sa ucenickim outputom i ispise broj ispranvih
int main()
{
    int broj=0;
    for(int i=0;i<=10;i++){
		//promijeniti jedan path da pokazuje u folder sa kodovima generisanim sa strane drugog programa
		//drugi path pokazuje na folder sa ispravnim outputima. Ne na fajlove, nego u folder sa svim fajlovima!
        string path1="C:\\Users\\Zakir\\Desktop\\Rezultati i testovi skolskog takmicenja 2021\\Z1 testovi za zadatak\\output";
        string path2="C:\\Users\\Zakir\\Desktop\\output";
		path1+="\\output";
		path2+="\\output";
        if(i==10){
        path1+="10.txt";
        path2+="10.txt";
        } else {
        path1+="0";
        path2+="0";
        path1+=i+'0';
        path2+=i+'0';
        path1+=".txt";
        path2+=".txt";
    }
        cout<<path1<<endl;
        fstream file1;
        fstream file2;
        file1.open(path1.c_str(),ios::in);
        file2.open(path2.c_str(),ios::in);
        if(!file1.is_open()){
            cout<<"file1 nije otvoren";
        }
        if(!file1.is_open()){
            cout<<"file2 nije otvoren";
        }
        bool flag=1;

        while(file1.good()&&file2.good()){
            int a,b;
            file1>>a;
            file2>>b;
            if(a!=b){
                cout<<"FAILED"<<endl;
                flag=0;
                break;
            }
        }
        if(flag){
            broj++;
        }
        file1.close();
        file2.close();
    }
         cout<<"PASSED: "<<broj<<" TESTS!"<<endl;

    return 0;
}
