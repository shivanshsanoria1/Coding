#include <iostream>
using namespace std;

void triangleQuad1(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<"--------------------"<<endl<<endl;
}

void triangleQuad2(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++)
            cout<<" ";
        for(int j=0; j<i+1; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<"--------------------"<<endl<<endl;
}

void triangleQuad3(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++)
            cout<<" ";
        for(int j=i; j<n; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<"--------------------"<<endl<<endl;
}

void triangleQuad4(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<"--------------------"<<endl<<endl;
}

void triangleQuad12(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++)
            cout<<" ";
        for(int j=0; j<2*i+1; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<"--------------------"<<endl<<endl;
}

void triangleQuad23(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++)
            cout<<" ";
        for(int j=0; j<=i; j++)
            cout<<"*";
        cout<<endl;
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<=i; j++)
            cout<<" ";
        for(int j=0; j<n-i-1; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<"--------------------"<<endl<<endl;
}

void triangleQuad34(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++)
            cout<<" ";
        for(int j=0; j<2*n-1-2*i; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<"--------------------"<<endl<<endl;
}

void triangleQuad41(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++)
            cout<<"*";
        cout<<endl;
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<"--------------------"<<endl<<endl;
}

void triangleQuad1234(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++)
            cout<<" ";
        for(int j=0; j<2*i+1; j++)
            cout<<"*";
        cout<<endl;
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<=i; j++)
            cout<<" ";
        for(int j=0; j<2*n-3-2*i; j++)
            cout<<"*";
        cout<<endl;
    }

    cout<<"--------------------"<<endl<<endl;
}

int main(){
    int n = 8;

    triangleQuad1(n);
    triangleQuad2(n);
    triangleQuad3(n);
    triangleQuad4(n);
    triangleQuad12(n);
    triangleQuad23(n);
    triangleQuad34(n);
    triangleQuad41(n);
    triangleQuad1234(n);

    return 0;
}
