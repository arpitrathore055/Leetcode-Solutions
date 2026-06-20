#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void backtrack(int currPart,int& n,int currSegment,string& curripaddress,vector<string>& addressCollection,string& s){
        
        //basecase
        if(currSegment == 4){
            //check
            if(currPart == n){
                addressCollection.push_back(curripaddress);
            }
            return;
        }
        
        for(int choice=currPart;choice<(currPart+3) && choice < n;choice++){
            
            //prunning
            string strValue=s.substr(currPart,choice-currPart+1);
            int value=stoi(strValue);
            
            if(value < 0 || value > 255){
                continue;
            }
            
            if(strValue[0] == '0' && strValue.size() > 1){
                continue;
            }
            
            //apply and undo
            int newCharactersAdded=0;
            curripaddress+=strValue;
            newCharactersAdded+=strValue.size();
            if(currSegment != 3){
                curripaddress.push_back('.');
                newCharactersAdded++;
            }
            
            backtrack(choice+1,n,currSegment+1,curripaddress,addressCollection,s);
            
            while(newCharactersAdded--){
                curripaddress.pop_back();
            }
            
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) {

        vector<string> addressCollection;
        string curripaddress="";
        
        int n=s.length();
        int currPart=0;
        int currSegment=0;
        
        backtrack(currPart,n,currSegment,curripaddress,addressCollection,s);
        
        return addressCollection;      

    }
};