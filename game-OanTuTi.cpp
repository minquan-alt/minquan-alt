#include <iostream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct quyTac{
    string arr[4] = {" ","Keo", "Bua", "Bao"};
    int randNum = 1 + rand()%2;
};
void input(string &n){
    getline(cin, n);
    while(n != "1"&& n != "2" && n != "3"){
        cout << "Ban da nhap sai dinh dang" << endl;
        cin >> n;
    }
}
void exchangeData(string n, int &x){
    x = stoi(n);
}

void displayResult(quyTac qt, int n){
    cout << "May ra " <<qt.arr[qt.randNum] << endl;
    cout << "Ban ra " << qt.arr[n] << endl;
    if(qt.randNum == n) cout << "Hoa" << endl;
    else switch (qt.randNum)
    {
    case 1:
        if(n == 2) cout << "YOU WIN" << endl;
        else cout << "YOU LOSE"<< endl;
        break;
    case 2:
       if(n == 1) cout << "YOU LOSE"<< endl;
       else  cout << "YOU WIN" << endl;
       break;
    default:
        if(n == 1) cout << "YOU WIN"<< endl;
        else  cout << "YOU LOSE" << endl;
        break;
    }
}
int main(){
    srand(time(0));
    quyTac qt;
    string h;
    int n;
    cout << "Keo, Bua, Bao\nGo '1' de ra Keo\nGo '2' de ra Bua\nGo '3' de ra bao" << endl;
    input(h);
    exchangeData(h,n);
    displayResult(qt,n);
    return 0;
}
