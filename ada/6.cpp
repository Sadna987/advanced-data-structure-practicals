#include <iostream>
#include <string>
using namespace std;
void KMPFailureFunction(const string& P, int f[]) {
    int m = P.length();
    int j = 0;
    f[0] = 0;
    int i=1; 
    while(i<m)
    {
        if (P[j]==P[i])
        {
            f[i]=j+1;
            i=i+1;
            j=j+1;
        }
        else if (j<0)
        {
            j=f[j-1];
        }
        else
        {
            f[i]=0;
            i=i+1;
        }
    }
}

int KMPMatch(const string& T, const string& P) {
    int n = T.length();
    int m = P.length();
    int f[m];
    KMPFailureFunction(P, f);
    int i = 0, j = 0;

    while (i < n) {
        if (P[j] == T[i]) 
        {
            if (j == m - 1) 
            {
                return i - m + 1; 
            }
            i++;
            j++;
        } 
        else if (j > 0) 
        {
            j = f[j - 1];
        } 
        else 
        {
            i++;
        }
    }
    return -1;
}

int main() {
    string T;
    string P;
    cout<<"\nEnter string:";
    cin>>T;
    cout<<"\nEnter the pattern to be matched:";
    cin>>P;
    int result = KMPMatch(T, P);

    if (result != -1) {
        cout << "Pattern found at index " << result << endl;
    } else {
        cout << "There is no substring of T matching P." << endl;
    }

    return 0;
}
