#include <iostream>
using namespace std;

int main(){
    int bucket[200], amt=0, choice, ii, addval, posi, flaggy;
    while(true){
        cout<<"\n1.Create  2.Display  3.Insert  4.Delete  5.Linear Search  6.Exit\n";
        cin>>choice;
        if(choice==1){
            cout<<"size? ";  cin>>amt;
            for(ii=0; ii<amt; ii++) cin>>bucket[ii];
        }
        else if(choice==2){
            for(ii=0; ii<amt; ii++) cout<<bucket[ii]<<" ";
        }
        else if(choice==3){
            cout<<"val pos ";  cin>>addval>>posi;
            for(ii=amt; ii>posi; ii--) bucket[ii]=bucket[ii-1];
            bucket[posi]=addval; amt++;
        }
        else if(choice==4){
            cout<<"pos "; cin>>posi;
            for(ii=posi; ii<amt-1; ii++) bucket[ii]=bucket[ii+1];
            amt--;
        }
        else if(choice==5){
            cout<<"val? "; cin>>addval; flaggy=0;
            for(ii=0; ii<amt; ii++){
                if(bucket[ii]==addval){ cout<<"found at "<<ii<<"\n"; flaggy=1; break; }
            }
            if(!flaggy) cout<<"not found\n";
        }
        else if(choice==6) break;
    }
}


//Q2

#include <iostream>
using namespace std;
int main(){
    int sack[90], total, a, b, c;
    cin>>total;
    for(a=0; a<total; a++) cin>>sack[a];
    for(a=0; a<total; a++){
        for(b=a+1; b<total; b++){
            if(sack[a]==sack[b]){
                for(c=b; c<total-1; c++) sack[c]=sack[c+1];
                total--; b--;
            }
        }
    }
    for(a=0; a<total; a++) cout<<sack[a]<<" ";
}



//Q3
1 0 0 0 0

//Q4(A)
#include <iostream>
using namespace std;
int main(){
    int bag[50], len, m, swapper;
    cin>>len;
    for(m=0; m<len; m++) cin>>bag[m];
    for(m=0; m<len/2; m++){
        swapper = bag[m];
        bag[m] = bag[len-1-m];
        bag[len-1-m] = swapper;
    }
    for(m=0; m<len; m++) cout<<bag[m]<<" ";
}

//Q4 (B)
#include <iostream>
using namespace std;
int main(){
    int rA, cA, rB, cB, p, q, r;
    int matA[20][20], matB[20][20], res[20][20];
    cin>>rA>>cA;
    for(p=0; p<rA; p++) for(q=0; q<cA; q++) cin>>matA[p][q];
    cin>>rB>>cB;
    for(p=0; p<rB; p++) for(q=0; q<cB; q++) cin>>matB[p][q];
    if(cA!=rB) return 0;
    for(p=0; p<rA; p++){
        for(q=0; q<cB; q++){
            res[p][q]=0;
            for(r=0; r<cA; r++) res[p][q]+=matA[p][r]*matB[r][q];
        }
    }
    for(p=0; p<rA; p++){ for(q=0; q<cB; q++) cout<<res[p][q]<<" "; cout<<"\n"; }
}

//Q4(C)
#include <iostream>
using namespace std;
int main(){
    int rr, cc, i2, j2, mat[25][25];
    cin>>rr>>cc;
    for(i2=0; i2<rr; i2++) for(j2=0; j2<cc; j2++) cin>>mat[i2][j2];
    for(i2=0; i2<cc; i2++){ for(j2=0; j2<rr; j2++) cout<<mat[j2][i2]<<" "; cout<<"\n"; }
}

//Q5
#include <iostream>
using namespace std;
int main(){
    int ro, co, i3, j3, tab[30][30], sumz;
    cin>>ro>>co;
    for(i3=0; i3<ro; i3++) for(j3=0; j3<co; j3++) cin>>tab[i3][j3];
    for(i3=0; i3<ro; i3++){ sumz=0; for(j3=0; j3<co; j3++) sumz+=tab[i3][j3]; cout<<"row"<<i3<<"="<<sumz<<"\n"; }
    for(j3=0; j3<co; j3++){ sumz=0; for(i3=0; i3<ro; i3++) sumz+=tab[i3][j3]; cout<<"col"<<j3<<"="<<sumz<<"\n"; }
}