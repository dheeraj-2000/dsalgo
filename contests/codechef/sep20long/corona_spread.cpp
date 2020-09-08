#include<bits/stdc++.h>
using namespace std;
#define ll long long int
double int_max = 1e9;

void solve(){
    int r;
    cin>>r;
    double v[r];
    for(auto& z:v) cin>>z;
    int min_affected = 1000;
    int max_affected = -1;
    double a[r][r];
    memset(a , int_max , sizeof(a));
    
    for(int i=0; i<r; i++){
        for(int j=i+1; j<r; j++){
                double dec_temp;
                if(v[i] != v[j]){
                     dec_temp = (double)(i-j)/(v[j]-v[i]);
                    if(dec_temp < 0) dec_temp = int_max;
                }else{
                    dec_temp = int_max;
                }
                a[i][j] = dec_temp;
                a[j][i] = dec_temp;
        }
    }

    for(int x=0; x<r; x++){
            double time_inf[r];
            for(int i=0; i<r; i++){
               time_inf[i] = -1;
            }
            time_inf[x] = 0;
            for(int q=0; q<10; q++){
                for(int i=0; i<r; i++){
                    if(time_inf[i] != -1){
                        for(int j=0; j<r ; j++){
                            if(time_inf[j] == -1){
                                if(a[i][j] < int_max && a[i][j] >= time_inf[i]){
                                    time_inf[j] = a[i][j];
                              }}}}}}

            int tinf = 0;
            for(int i=0; i<r; i++){
                if(time_inf[i] != -1){
                    tinf++;
                }
            }

            max_affected = max(max_affected , tinf);
            min_affected = min(min_affected , tinf);
    }
   cout<<min_affected<<"   "<<max_affected<<endl;

}

int main(){
    int t;cin>>t;
    while(t--) solve();
}
