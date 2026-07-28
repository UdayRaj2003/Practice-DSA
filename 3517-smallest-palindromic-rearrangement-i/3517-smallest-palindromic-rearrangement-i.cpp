class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>mp(26,0);
        for(auto ch:s){
            mp[ch-97]++;

        }
        string mid  = "";
        for(int k=0;k<26;k++){
            if(mp[k] % 2){
                mid = char(k+97);
                mp[k]--;
                
            }
        }
        string ans ="";
        for(int i=0; i<26;i++){
            mp[i] /= 2;
            while(mp[i]){
                  
                ans += char(i+97);
                mp[i]--;

            }
        }
        string temp = ans;
        reverse(ans.begin(),ans.end());
        ans= temp + mid + ans ;
        return ans;


    }
};