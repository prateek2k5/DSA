// Template
#include<bits/stdc++.h>
using namespace std;
int main(){
    return 0;
}


//Print
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cout<<"Enter the value of a ";
    cin>>a;
    cout<<a<<endl<<"Hello";
    return 0;
}

//Add two numbers using user input
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter two numbers a and b"<<endl;
    cin>>a>>b;
    int c=a+b;
    cout<<"Answer is = "<<c;
    return 0;
}

//if-else
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=10;
    if(a%2==0){
        cout<<"Even"<<endl;
    }
    else{
        cout<<"Odd"<<endl;
    }
    return 0;
}

//Loop
#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=1;i<11;i++){
        cout<<i<<endl;
    }
    return 0;
}

//Function
#include<bits/stdc++.h>
using namespace std;
int twice_number(int n){
    int result=n*n;
    return result;
}
int main(){
    int a=20;
    cout<<twice_number(a)<<endl;
    return 0;
}


