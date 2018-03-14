//
//  main.cpp
//  LCS
//
//  Created by shijia hu on 4/6/17.
//  Copyright © 2017 shijia hu. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

int LCS(char x[], char y[]){
    int m = strlen(x);
    int n = strlen(y);
    int **c;
    char **b;
    c = new int*[101];
    b = new char*[101];
    for (int i = 0; i<m; i++) {
        c[i] = new int[n+1];
        b[i] = new char[n+1];
    }
    for (int i = 0; i<m; i++) {
         c[i][0] = 0;
    }
    for (int j = 0; j<n; j++) {
        c[0][j] = 0;
    }
    
    for (int i = 1; i<=m; i++) {
        for (int j = 1; j<=n; j++) {
            if (x[i-1] == y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'D';
            }else{
                if (c[i][j] >= c[i][j-1]) {
                    c[i][j] = c[i-1][j];
                    b[i][j] = 'U';
                }else{
                    c[i][j] = c[i][j-1];
                    b[i][j] = 'L';
                }
            }
        }
    }
    for (int i = 0; i<m; i++) {
        for (int j = 0; j< n; j++) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i<m; i++) {
        for (int j = 0; j< n; j++) {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    
    char* a = argv[1];

    char x[101]={0};
    strcpy(x, a);
    cout<<a<<endl;
    
    char* b = argv[2];
    
    char y[101]={0};
    strcpy(y, b);
    cout<<a<<endl;
    
    
    LCS(x, y);
//    char *x, *y;
//    x = new char[101];
//    y = new char[101];
    
//    while (cin!=EOF) {
//        <#statements#>
//    }
    //    //    string x;
    //    string y;
//    cin>>x;
//    cin>>y;
    
//    cout<<;
//    cout<<y;
    //cout<<m<<" "<<n<<endl;
    system("pause");
    return 0;
}
