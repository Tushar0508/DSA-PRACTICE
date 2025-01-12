class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        stack<int>lock,unlock;
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                unlock.push(i);
            }else{
                if(s[i]=='('){
                    lock.push(i);
                }else{
                    if(!lock.empty()){
                        lock.pop();
                    }
                    else if(!unlock.empty()){
                        unlock.pop();
                    }
                    else return false;
                }
            }
        }
        while(!lock.empty() && !unlock.empty()){
            if(lock.top()<unlock.top()){
                lock.pop();
                unlock.pop();
            }
            else return false;
        }
        if(!lock.empty()) return false;
        if(unlock.size()&1)return false;
        return true;
    }
};