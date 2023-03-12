#include <bits/stdc++.h>
// #include <boost/algorithm/string.hpp>
using namespace std;

long long differenceTime(string t2,string t1){

    int h1=stoi(t1.substr(0,2)),m1=stoi(t1.substr(3,5)),s1=stoi(t1.substr(6,8));       
    int h2=stoi(t2.substr(0,2)),m2=stoi(t2.substr(3,5)),s2=stoi(t2.substr(6,8));

    long long totalSeconds=0; 
    totalSeconds=(h2*3600)+(m2*60)+s2 - (h1*3600)-(m1*60)-s1;
    return totalSeconds;
}

string toTimestamp(int sec){
    int h,m,s;
    h=sec/3600;
    sec=sec%3600;
    m=sec/60;
    sec=sec%60;
    s=sec;

    return ((h<10)?"0":"") + to_string(h)+ ":" + ((m<10)?"0":"") +to_string(m)+":" + ((s<10)?"0":"") +to_string(s);
}

int main(){

    map<string,int> v;
    v["clock-in"]=1;
    v["clock-out"]=2;
    v["break-start"]=3;
    v["break-stop"]=4;

    int n;
    cin>>n;

    unordered_map<string,pair<double,pair<string,int>>> mp;
    string s,eid,datee,timee,st,preDate="0000:00:00";
    getline(cin,s);
    for(int i=0;i<n;i++){
        getline(cin,s);
        vector<string> words;
        string word="";
        for(char x:s){
            if(x==' '){
                if(word.size()!=0)
                    words.push_back(word);
                word="";
            }
            else{
                word=word+x;
            }
        }
        words.push_back(word);

        string eid=words[0];
        string datee=words[1];
        string timee=words[2];
        string st=words[3];


        if(mp.size()>0 && stoi(preDate.substr(5,7))!=stoi(datee.substr(5,7))){
            long long minn=LONG_MAX,maxx=0,avg=0,a;
            for(auto i:mp){
                if(i.second.second.second==0){
                    i.second.first=i.second.first+min((long long)21600,differenceTime("19:30:00",i.second.second.first));
                }

                a=i.second.first;
                if(a>maxx)
                    maxx=a;
                if(a<minn)
                    minn=a;
                avg+=a;
            }

            avg=avg/mp.size();
            cout<<toTimestamp(maxx)<<" "<<toTimestamp(minn)<<" "<<toTimestamp(avg)<<endl;
            mp.clear();

        }
        
        int x=v[st];
        if(x==1){
            mp[eid].second.first=timee;
        }
        else if(x==2){
            auto x=mp[eid];
            mp[eid].first=x.first+differenceTime(timee,x.second.first);
            mp[eid].second={timee,1};
        }
        else if(x==3){
            if(mp.find(eid)==mp.end()){
                mp[eid]={0,{timee,0}};
            }
            else{
                auto x=mp[eid];
                // cout<<timee<<"mmmmmmm "<<x.second.first<<endl;
                mp[eid].first=x.first+differenceTime(timee,x.second.first);
                mp[eid].second={timee,0};
            }
            
        }
        else{
            mp[eid].second.first=timee;
        }
        
        preDate=datee;
    }

    long long minn=LONG_MAX,maxx=0,avg=0,a;
            for(auto i:mp){
                a=i.second.first;
                if(a>maxx)
                    maxx=a;
                if(a<minn)
                    minn=a;
                avg+=a;
            }

            avg=avg/mp.size();
            cout<<toTimestamp(maxx)<<" "<<toTimestamp(minn)<<" "<<toTimestamp(avg)<<endl;
            mp.clear();

    return 0;
}