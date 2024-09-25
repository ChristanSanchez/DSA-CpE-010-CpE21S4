#include <iostream>
#include <queue>
using namespace std;


    void display(queue<string>pl)
    {
        while(true){
            
            if(!pl.empty())
            {
                cout<<pl.front()<<endl;
                pl.pop();
            }
        else
            {
                cout<<endl;
                cout<<"Stack is Empty"<<endl;
                break;
            }
        }
    }
            
int main()
{
    queue <string>pl;

    cout<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="<<endl;
    cout<<endl;
    cout<<"Push elements into queue"<<endl;

    cout<<endl;
    
    pl.push("1) C++");
    pl.push("");
    pl.push("2) Python");
    pl.push("");
    pl.push("3) Java");

    
    display(pl);
    cout<<endl;
    cout<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="<<endl;
    
    return 0;
}
