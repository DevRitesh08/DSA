#include<bits/stdc++.h>
using namespace std;

void PrintVec(vector<pair<int , char >> &v)
{
    cout<<"size of vector : "<<v.size()<<endl ;// TIME COMPLEXITY OF v.size() is O(1) .
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout<< v[i].first <<" "<<v[i].second<<endl;
    }
    cout<<endl ;
}


int main()
{


    // Input
    
    // method-1
    vector<pair<int , char >> vec1 = { {1,'a'} , {2,'b'} , {3,'c'},{4,'d'} } ;
    // PrintVec(vec1);

    // method-2

    vector<pair<int , char >> vec2 ;
    int n ; 
    cout<<"enter the number of pairs to enter : ";
    cin>>n ;
    for(int i = 0 ; i < n ; i++)
    {
        int x ;
        char y ; // for second element of pair .
        cin>>x>>y ;
        vec2.push_back({x,y});
        //vec2.push_back(make_pair(x,y)); // this can also be used 
    
    }
    PrintVec(vec2) ;

}