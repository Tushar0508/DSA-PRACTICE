class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        for(int  i =0 ; i <  times.size() ;  i++){
            times[i].push_back(i) ;
        }
        priority_queue<int , vector<int> , greater<int>>pq ;
        for(int i = 0 ; i <times.size() ;  i++){
            pq.push(i) ;
        }
        sort(times.begin() ,  times.end()) ;
        priority_queue<vector<int> ,  vector<vector<int>> ,  greater<vector<int>>>pqv ;
        for(int i =0  ; i <times.size() ;  i++){
            int c =  times[i][0] ;
            while( pqv.size() >  0 && pqv.top()[0] -  c <= 0 ){
                int a =  pqv.top()[3] ;
                pqv.pop() ;
                pq.push(a) ;

            }
            if(times[i][2] == targetFriend){
                return  pq.top() ;
            }
            pqv.push({times[i][1] ,  times[i][0] ,  times[i][2] ,  pq.top()}) ;
            pq.pop() ;
        }
        return times.size() ;
    }
};